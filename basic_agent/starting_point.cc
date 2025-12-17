// ----- #include <> -----
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>

// ----- #include "" -----
extern "C"
{
#include "screen_print_c.h"
}
// #include "Clothoids.hh"
#include "logvars.h"
#include "primitives.h"
#include "rrt_clothoid.h"
#include "rrt_read.h" // debug
#include "rrt_star.h"
#include "rrt_star_refine.h"
#include "screen_print.h"
#include "server_lib.h"

using namespace std;
using namespace G2lib;

// ----- #define -----
#define DEFAULT_SERVER_IP "127.0.0.1" // IP Address
#define SERVER_PORT 30000             // Server ports
#define DT 0.05                       // Time step_size
#define COST_DIRT_ROAD 3.0            // Multiply this to the distance between nodes
#define COST_ASPHALT_ROAD 1.0         // Multiply this to the distance between nodes
#define GREEN_TL 1                    // State corresponding to green  traffic light
#define YELLOW_TL 2                   // State corresponding to yellow  traffic light
#define RED_TL 3                      // State corresponding to red  traffic light
#define ID_OBJ_TRAFFIC_CONE 1         // ID of Traffic Cone coming fron PyDrivingSim
#define ID_OBJ_ROCK 3                 // ID of the rock coming fron PyDrivingSim
#define ID_OBJ_TARGET 5               // ID of the Target coming fron PyDrivingSim
#define ID_OBJ_ASPHALT 6              // ID of an asphalt road segment
#define ID_OBJ_DIRT 7                 // ID of a dirt road segment
#define ID_OBJ_GPS 99                 // ID of the object GPS
#define MAX_TRAJ_POINTS 20            // Send this number of point to PyDrivingSim
#define TH_NODE_REACHED 1.5           // Distance to consider a node reached
#define SCAN_DIST_CURVE 20.0          // Distance of the lookahead if high curvature

typedef struct
{
    double s, n, xi;
} position;

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) { server_run = 0; }

// ----- PROTOTYPES -----
void copy_m(double m1[6], double m2[6]);
bool isAllZero(double m[6]);
void free_flow(double v0, double a0, double x_f, double v_r, double m_star[6], double *v1, double *T1);
bool positionReached(const node &nd, double x_veh, double y_veh);
void get_vehicle_position(int gps_index, input_data_str *in, position &vehicle_position);

// ----- MAIN -----
int main(int argc, const char *argv[])
{
    FILE *fileDebug = fopen("debugMain.txt", "w"); // fileDebug for debug purposes
    fprintf(fileDebug, "main START\n");

    logger.enable(true);

    // Messages variables
    scenario_msg_t scenario_msg;
    manoeuvre_msg_t manoeuvre_msg;
    size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
    size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
    uint32_t message_id = 0;

#if not defined(_MSC_VER) and not defined(_WIN32)
    // More portable way of supporting signals on UNIX
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
#else
    signal(SIGINT, intHandler);
#endif

    server_agent_init(DEFAULT_SERVER_IP, SERVER_PORT);

    // Start server of the Agent
    printLine();
    printTable("Waiting for scenario message...", 0);
    printLine();

    bool firstCycle = true;
    vector<road_segment> road;
    node startNode, goalNode;
    vector<node> path_to_follow; // rrt* fills this
    int idxNodeToReach = 0, nextIdxToReach = MAX_TRAJ_POINTS;
    vector<obstacle> obstacle_list;
    ClothoidList path_clothoid("RRT_trajectory");

    while (server_run == 1)
    {

        // Clean the buffer
        memset(scenario_msg.data_buffer, '\0', scenario_msg_size);

        // Receive scenario message from the environment
        if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0)
        {
            // Init time
            static auto start = chrono::system_clock::now();
            auto time = chrono::system_clock::now() - start;
            double num_seconds = chrono::duration_cast<chrono::milliseconds>(time).count() / 1000.0;
            printLogTitle(message_id, "received message");

            // Data struct
            input_data_str *in = &scenario_msg.data_struct;
            manoeuvre_msg.data_struct.CycleNumber = in->CycleNumber;
            manoeuvre_msg.data_struct.Status = in->Status;

            // Starting position of the car
            int gps_index;
            static double path_len = 0;

            // ----- TRAJECTORY -----
            // Calculate the trajectory using rrt*
            if (firstCycle)
            {
                fprintf(fileDebug, "\nfirstCycle START\n");
                firstCycle = false;

                // save position of the car at the beginning
                for (int i = 0; i < in->NrObjs; i++)
                {

                    if (in->ObjID[i] == ID_OBJ_GPS)
                    {
                        startNode.p.x = in->ObjX[i];
                        startNode.p.y = in->ObjY[i];
                        gps_index = i;
                        break;
                    }
                }
                double initialYaw = in->LaneHeading;
                double cos_theta = cos(initialYaw);
                double sin_theta = sin(initialYaw);

                // define objects
                for (int i = 0; i < in->NrObjs; i++)
                {
                    // transform coordinates because everything is w.r.t. the car
                    double x_local = in->ObjX[i];
                    double y_local = in->ObjY[i];
                    double x_global = x_local * cos_theta - y_local * sin_theta + startNode.p.x;
                    double y_global = x_local * sin_theta + y_local * cos_theta + startNode.p.y;
                    switch (in->ObjID[i])
                    {
                    case ID_OBJ_TRAFFIC_CONE:
                    case ID_OBJ_ROCK:
                        obstacle obs;
                        obs.ID = in->ObjID[i];
                        obs.x = x_global;
                        obs.y = y_global;
                        obs.length = in->ObjLen[i];
                        obs.width = in->ObjWidth[i];
                        obstacle_list.push_back(obs);
                        fprintf(fileDebug, "\tObstacle ID=%d; x=%f; y=%f; lenght=%f; width=%f\n",
                                obs.ID, obs.x, obs.y, obs.length, obs.length);
                        break;
                    case ID_OBJ_TARGET:
                        goalNode.p.x = x_global;
                        goalNode.p.y = y_global;
                        fprintf(fileDebug, "\tGoal x=%f; y=%f\n", goalNode.p.x, goalNode.p.y);
                        break;
                    case ID_OBJ_ASPHALT:
                    case ID_OBJ_DIRT:
                        road_segment seg;
                        seg.ID = in->ObjID[i];
                        seg.x = x_global;
                        seg.y = y_global;
                        seg.length = in->ObjLen[i];
                        seg.width = in->ObjWidth[i];

                        if (seg.ID == ID_OBJ_DIRT)
                        {
                            seg.cost = COST_DIRT_ROAD;
                        }
                        else
                        {
                            seg.cost = COST_ASPHALT_ROAD;
                        }

                        road.push_back(seg);
                        fprintf(fileDebug, "\tRoadSegment ID=%d; Cost=%.1f; x=%f; y=%f; lenght=%f; width=%f\n",
                                seg.ID, seg.cost, seg.x, seg.y, seg.length, seg.width);
                        break;
                    }
                }
  
                // Define path_to_follow
                int numberSolutions = rrt_star(startNode, goalNode, road, obstacle_list, path_to_follow);
                if (numberSolutions == 0)
                {
                    perror("error rrt_star did not found any solution.S");
                    exit(EXIT_FAILURE);
                }
                fprintf(fileDebug, "\trrt_star found %d solution(s)\n", numberSolutions);

                rrt_star_refine(road, obstacle_list, path_to_follow);
                
                //rrt_from_csv("../rrt/path_refined.csv", path_to_follow); // for DEBUG

                // to send the points to PyDrivingSim
                if (nextIdxToReach > path_to_follow.size())
                {
                    nextIdxToReach = path_to_follow.size();
                }

                getClothoid(initialYaw, path_to_follow, path_clothoid);
                path_len = path_clothoid.length();

                fprintf(fileDebug, "firstCycle END\n\n");
            }

            // ----- INFORMATION VEHICLE -----
            double L = in->VehicleLen; // lenght of the vehicle
            double v0 = in->VLgtFild;  // actual longitudinal velocity
            double a0 = in->ALgtFild;  // actual longitudinal acceleration
            position vehicle_position;
            get_vehicle_position(gps_index, in, vehicle_position);

            // ----- LATERAL CONTROL -----
            const double T_look = 0.7;               // preview time [s]
            const double L0 = 1.0;                   // minimum lookahead distance [m]
            double lookahead_lat = L0 + T_look * v0; // end of C1 in s on path_clothoid
            const double K_US = 0.0;                 // understeering gradient
            position closest_on_path;                // point of the path which is the closest to the vehicle
            real_type variable_s, t_coordinate, points_dist;

            path_clothoid.closest_point_ISO(vehicle_position.s, vehicle_position.n,
                                            closest_on_path.s, closest_on_path.n,
                                            variable_s, t_coordinate, points_dist);

            path_clothoid.eval(variable_s + lookahead_lat, closest_on_path.s, closest_on_path.n);
            closest_on_path.xi = path_clothoid.theta(variable_s + lookahead_lat);

            // build C1 connecting from the car position to the path_clothoid
            ClothoidCurve C1("C1");
            C1.build_G1(vehicle_position.s, vehicle_position.n, vehicle_position.xi,
                        closest_on_path.s, closest_on_path.n, closest_on_path.xi);
            double curvature = C1.kappa_begin(); // return curvature at the beginning
            double requested_steer = curvature * (L + K_US * pow(v0, 2));

            // ----- find v_r -----
            double max_abs_kappa_future = 0.0;
            double dist_to_max_kappa = 0.0;
            double SCAN_DIST = fmax(20.0, v0 * 5.0);    // scan at minimum next 20m
            const double step_size = 1.0;
            const double a_n_max = 3.0;                 // maximum lateral acceleration
            const double lat_error_speed_penalty = 0.6; // if distant from path_clothoid, reduce v_r

            // find max curvature in an horizon
            for (double ds = 0; ds < SCAN_DIST; ds += step_size)
            {
                double s_query = variable_s + ds;
                if (s_query > path_len)
                {
                    break;
                }

                double k_future = path_clothoid.kappa(s_query);
                if (fabs(k_future) > max_abs_kappa_future)
                {
                    max_abs_kappa_future = fabs(k_future);
                    dist_to_max_kappa = ds;
                }
            }
            max_abs_kappa_future = fmax(max_abs_kappa_future, 1e-4);
            double v_limit_curve = sqrt(a_n_max / max_abs_kappa_future);
            position point_max_abs; // need for debug
            path_clothoid.eval(variable_s + dist_to_max_kappa, point_max_abs.s, point_max_abs.n);

            double v_limit_stability = v_limit_curve / (1.0 + lat_error_speed_penalty * points_dist);
            double v_r = fmin(in->RequestedCruisingSpeed, v_limit_stability);
            v_r = fmax(v_r, 1.0);

            /// ----- find lookahead_long -----
            const double T_horizon = 3.0;
            const double recovery_lookahead_scale = 0.5;
            double lookahead_long = 0.0;

            // case we are far from the trajectory
            if (points_dist > 0.4)
            {
                lookahead_long = v0 * T_horizon * recovery_lookahead_scale;
                lookahead_long = fmax(lookahead_long, v0 * 1.0); // saturate to avoid too short primitive
            }
            // case there is a curve in the horizon
            else if (v_r < v0 - 1.0)
            {
                lookahead_long = dist_to_max_kappa;
            }
            // case normal driving
            else
            {
                lookahead_long = v_r * T_horizon;
            }

            // --- avoid m=[0] when braking ---
            const double stopping_safety_factor = 2.0;
            const double min_planning_margin = 10.0;
            if (a0 < -0.1)
            {
                double stopping_dist = (v0 * v0) / (2.0 * fabs(a0));
                double max_physical_dist = stopping_dist * stopping_safety_factor + min_planning_margin;
                lookahead_long = max_physical_dist;
            }

            // ----- LONGITUDINAL CONTROL -----
            double m_star[6], m1[6], m2[6];         // primitives
            const double v_min = 3.0, v_max = 15.0; // vel min & max to pass the traffic light
            const double x_s = 5.0;                 // safety space before traffic light
            const double x_in = 10.0;               // length of the intersection
            const double T_s = x_s / v_min;         // time to travel the safety space
            const double T_in = x_in / v_min;       // time to safety space
            static double x_tr = 0;                 // distance to the traffic light
            static double x_stop = 0;               // distance to the stop the vehicle
            double v1, T1, v2, T2;
            double T_green, T_red;
            double final_time, final_space;
            const char *messageDebug;

            // ----- LOGIC FOR TRAFFIC LIGHT -----
            if (in->NrTrfLights != 0) // if there is a traffic light
            {
                x_tr = in->TrfLightDist;
                x_stop = x_tr - (x_s / 2.0); // stop before the TL
                if (x_stop < 0)
                {
                    x_stop = 0;
                }
            }
            if (in->NrTrfLights == 0 || x_tr >= lookahead_long) // if there is no TL or is very far -> FreeFlow
            {
                // pass_primitive(v0, a0, lookahead_long, v_r, v_r, 0.0, 0.0, m_star, &v1, &T1, m_star, &v2, &T2); // FreeFlow
                free_flow(v0, a0, lookahead_long, v_r, m_star, &v1, &final_time);
                messageDebug = "if (in->NrTrfLights==0 || x_tr>=lookahead_long)";
            }
            else if (in->TrfLightDist + x_in < 0) // if car passed the intersection and it turns red do not stop
            {
                free_flow(v0, a0, lookahead_long, v_r, m_star, &v1, &final_time);
                messageDebug = "else if (in->TrfLightDist<0)";
            }
            else // if TL is near
            {
                switch (in->TrfLightCurrState) // set times according to the color of TL
                {
                case GREEN_TL:
                    T_green = 0.0;
                    T_red = in->TrfLightFirstTimeToChange - T_in;
                    break;
                case YELLOW_TL:
                    T_green = in->TrfLightSecondTimeToChange + T_s;
                    T_red = in->TrfLightThirdTimeToChange - T_in;
                    break;
                case RED_TL:
                    T_green = in->TrfLightFirstTimeToChange + T_s;
                    T_red = in->TrfLightSecondTimeToChange - T_in;
                    break;
                }

                if (in->TrfLightCurrState == GREEN_TL && in->TrfLightDist <= x_s) // if TL green and we are very close to TL
                {
                    // pass_primitive(v0, a0, lookahead_long, v_r, v_r, 0.0, 0.0, m_star, &v1, &T1, m_star, &v2, &T2); // FreeFlow
                    free_flow(v0, a0, lookahead_long, v_r, m_star, &v1, &final_time);
                    messageDebug = "if (in->TrfLightCurrState==GREEN_TL && in->TrfLightDist<=x_s)";
                }
                else
                {
                    pass_primitive(v0, a0, x_tr, v_min, v_max, T_green, T_red, m1, &v1, &T1, m2, &v2, &T2);
                    if (isAllZero(m1) && isAllZero(m2))
                    {
                        stop_primitive(v0, a0, x_stop, m_star, &final_space, &final_time);
                        messageDebug = "if (isAllZero(m1) && isAllZero(m2))";
                    }
                    else
                    {
                        if ((m1[3] < 0 && m2[3] > 0) || (m1[3] > 0 && m2[3] < 0))
                        {
                            pass_primitive_j0(v0, a0, x_tr, v_min, v_max, m_star, &final_space, &final_time);
                            messageDebug = "if ((m1[3]<0 && m2[3]>0) || (m1[3]>0 && m2[3]<0))";
                        }
                        else
                        {
                            if (abs(m1[3]) < abs(m2[3]))
                            {
                                copy_m(m_star, m1);
                                final_time = T1;
                                messageDebug = "if (abs(m1[3]) < abs(m2[3]))";
                            }
                            else
                            {
                                copy_m(m_star, m2);
                                final_time = T2;
                                messageDebug = "else";
                            }
                        }
                    }
                }
            }

            // ----- TRAPEZOIDAL JERK -----
            static double a0_bar = 0.0;
            const double a_min = -5.0;
            const double a_max = 5.0;
            double j_req = 0.5 * DT * (j_from_coeffs(0.0, m_star) + j_from_coeffs(DT, m_star));
            double a_req = a0_bar + j_req;
            a_req = fmin(fmax(a_req, a_min), a_max);
            a0_bar = a_req;
            double v_req = v_from_coeffs(DT, m_star);
            static double s_req = 0.0;
            s_req += s_from_coeffs(DT, m_star);

            // ----- PI IMPLEMENTATION -----
            const double k_p = 0.018;//0.022;
            const double k_i = 0.3;//0.19;
            double error = a_req - a0;
            static double error_integral = 0.0;
            error_integral = error_integral + error * DT;
            double requested_pedal = error * k_p + error_integral * k_i;
            if (v0 < 0.15 && a0_bar < 0.0 && j_req > 0.0) // Reset the error_integral
            {
                a0_bar = 0.0;
                error_integral = 0.0;
            }

            // ----- SEND COMMANDS -----
            // send path_to_follow to PyDrivingSim
            static int idxToCheck = 0;
            if (nextIdxToReach != idxNodeToReach)
            {
                if (positionReached(path_to_follow[idxToCheck], vehicle_position.s, vehicle_position.n))
                {
                    // send data only if there are any that haven't been sent
                    fprintf(fileDebug, "Sending from path_to_follow[%d] to path_to_follow[%d]\n", idxNodeToReach, nextIdxToReach);
                    int nmbrOfPoints = nextIdxToReach - idxNodeToReach;
                    manoeuvre_msg.data_struct.NTrajectoryPoints = nmbrOfPoints;
                    for (int i = 0; i < nmbrOfPoints; i++)
                    {
                        manoeuvre_msg.data_struct.TrajectoryPointIX[i] = path_to_follow[i + idxNodeToReach].p.x;
                        manoeuvre_msg.data_struct.TrajectoryPointIY[i] = path_to_follow[i + idxNodeToReach].p.y;
                    }
                    idxToCheck = idxNodeToReach + (nextIdxToReach - idxNodeToReach) * 0.75;
                    idxNodeToReach = nextIdxToReach;
                    nextIdxToReach += MAX_TRAJ_POINTS;
                    if (nextIdxToReach > path_to_follow.size())
                    {
                        nextIdxToReach = path_to_follow.size();
                    }
                }
                else
                {
                    manoeuvre_msg.data_struct.NTrajectoryPoints = 0;
                }
            }

            manoeuvre_msg.data_struct.RequestedAcc = requested_pedal;
            manoeuvre_msg.data_struct.RequestedSteerWhlAg = requested_steer;

            // ----- CSV FILE & PRINT -----
            const char *fileName = "Follow_path";

            // Log_vars for csv
            logger.log_var(fileName, "messageDebug", messageDebug);
            logger.log_var(fileName, "cycle", in->CycleNumber);
            logger.log_var(fileName, "time", in->ECUupTime);
            logger.log_var(fileName, "X0", vehicle_position.s);
            logger.log_var(fileName, "Y0", vehicle_position.n);
            logger.log_var(fileName, "Psi0", vehicle_position.xi);
            logger.log_var(fileName, "X_closest", closest_on_path.s);
            logger.log_var(fileName, "Y_closest", closest_on_path.n);
            logger.log_var(fileName, "Psi_closest", closest_on_path.xi);
            logger.log_var(fileName, "s_req", s_req);
            logger.log_var(fileName, "x_tr", x_tr);
            logger.log_var(fileName, "x_stop", x_stop);
            logger.log_var(fileName, "v0", in->VLgtFild);
            logger.log_var(fileName, "v_r", v_r);
            logger.log_var(fileName, "v_req", v_req);
            logger.log_var(fileName, "a0", a0);
            logger.log_var(fileName, "a_req", a_req);
            logger.log_var(fileName, "k_p", k_p);
            logger.log_var(fileName, "k_i", k_i);
            logger.log_var(fileName, "K_US", K_US);
            logger.log_var(fileName, "curvature", curvature);
            logger.log_var(fileName, "variable_s", variable_s);
            logger.log_var(fileName, "t_coordinate", t_coordinate);
            logger.log_var(fileName, "points_dist", points_dist);
            logger.log_var(fileName, "lookahead_long", lookahead_long);
            logger.log_var(fileName, "lookahead_lat", lookahead_lat);
            logger.log_var(fileName, "error_integral", error_integral);
            logger.log_var(fileName, "TL_state", in->TrfLightCurrState);
            logger.log_var(fileName, "T_green", T_green);
            logger.log_var(fileName, "T_red", T_red);
            logger.log_var(fileName, "m1[3]", m1[3]);
            logger.log_var(fileName, "m2[3]", m2[3]);
            logger.log_var(fileName, "final_time", final_time);
            logger.log_var(fileName, "lookahed_lat", lookahead_lat);
            logger.log_var(fileName, "dist_to_max_kappa", dist_to_max_kappa);
            logger.log_var(fileName, "max_kappa", max_abs_kappa_future);
            logger.log_var(fileName, "X_max_abs", point_max_abs.s);
            logger.log_var(fileName, "Y_max_abs", point_max_abs.n);
            logger.log_var(fileName, "v_limit_curve", v_limit_curve);
            logger.log_var(fileName, "v_limit_stability", v_limit_stability);
            logger.log_var(fileName, "c0", m_star[0]);
            logger.log_var(fileName, "c1", m_star[1]);
            logger.log_var(fileName, "c2", m_star[2]);
            logger.log_var(fileName, "c3", m_star[3]);
            logger.log_var(fileName, "c4", m_star[4]);
            logger.log_var(fileName, "c5", m_star[5]);

            // Write log
            logger.write_line(fileName);

            // Screen print
            printLogVar(message_id, "Time", num_seconds);
            printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);

            // Send manoeuvre message to the environment
            if (server_send_to_client(server_run, message_id, &manoeuvre_msg.data_struct) == -1)
            {
                perror("error send_message()");
                exit(EXIT_FAILURE);
            }
            else
            {
                printLogTitle(message_id, "sent message");
            }
        }
    }

    fprintf(fileDebug, "main FINISHED");
    fclose(fileDebug);

    // Close the server of the agent
    server_agent_close();
    return 0;
}

// ----- OTHER FUNCTIONS -----
void copy_m(double m1[6], double m2[6])
{
    for (int i = 0; i < 6; i++)
    {
        m1[i] = m2[i];
    }
}

bool isAllZero(double m[6])
{
    for (int i = 0; i < 6; i++)
    {
        if (m[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void free_flow(double v0, double a0, double x_f, double v_r, double m_star[6], double *v1, double *T1)
{
    pass_primitive(v0, a0, x_f, v_r, v_r, 0.0, 0.0, m_star, v1, T1, m_star, v1, T1); // FreeFlow
}

bool positionReached(const node &nd, double x_veh, double y_veh)
{
    double dx = x_veh - nd.p.x;
    double dy = y_veh - nd.p.y;
    double d2 = dx * dx + dy * dy; // distance^2
    if (d2 <= TH_NODE_REACHED * TH_NODE_REACHED)
    {
        return true;
    }
    return false;
}

void get_vehicle_position(int gps_index, input_data_str *in, position &vehicle_position)
{
    vehicle_position.s = in->ObjX[gps_index];
    vehicle_position.n = in->ObjY[gps_index];
    vehicle_position.xi = in->LaneHeading;
}