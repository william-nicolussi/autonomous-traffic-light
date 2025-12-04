//
// Created by Gastone Pietro Rosati Papini on 10/08/22.
//
// Shortcuts -> compile: f6; run: f7
// Indentation -> alt+shift+f;

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
#include "logvars.h"
#include "primitives.h"
#include "rrt_star.h"
#include "screen_print.h"
#include "server_lib.h"

// ----- #define -----
#define DEFAULT_SERVER_IP "127.0.0.1" // IP Address
#define SERVER_PORT 30000             // Server port
#define DT 0.05                       // Time step
#define GREEN_TL 1                    // State corresponding to green  traffic light
#define YELLOW_TL 2                   // State corresponding to yellow  traffic light
#define RED_TL 3                      // State corresponding to red  traffic light
#define ID_OBJ_TRAFFIC_CONE 1
#define ID_OBJ_TARGET 5

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) { server_run = 0; }

// ----- PROTOTYPES -----
void copy_m(double m1[6], double m2[6]);
bool isAllZero(double m[6]);
void free_flow(double v0, double a0, double x_f, double v_r, double m_star[6], double *v1, double *T1);

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

    while (server_run == 1)
    {

        // Clean the buffer
        memset(scenario_msg.data_buffer, '\0', scenario_msg_size);

        // Receive scenario message from the environment
        if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0)
        {
            // Init time
            static auto start = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::now() - start;
            double num_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(time).count() / 1000.0;
            printLogTitle(message_id, "received message");

            // Data struct
            input_data_str *in = &scenario_msg.data_struct;
            manoeuvre_msg.data_struct.CycleNumber = in->CycleNumber;
            manoeuvre_msg.data_struct.Status = in->Status;

            // ----- TRAJECTORY -----
            // Trajectory is otside the while because is calculated just once
            // Starting and goal points definition

            if (firstCycle)
            {
                fprintf(fileDebug, "\nfirstCycle START\n");
                firstCycle = false;

                /* Def of start and end nodes ->
                    -> all positions are given w.r.t. the car, so its starting position is (0, 0) ->
                    -> note in the simulator starting position of the car is (0, -1) ->
                    -> if you put Y0=-1., then the coordinates of obj are wrong (bc simulator returns coordinates wrt the car).
                */ 
                const double X0 = 0., Y0 = 0.; //in->LatOffsLineL;
                node start, goal;
                start.p.x = X0;
                start.p.y = Y0;

                // Def obstacles -> the cones
                std::vector<obstacle> obstacle_list;
                for (int i = 0; i < in->NrObjs; i++)
                {
                    switch (in->ObjID[i])
                    {
                    case ID_OBJ_TRAFFIC_CONE:
                        obstacle obs;
                        obs.ID = in->ObjID[i];
                        obs.x = in->ObjX[i];
                        obs.y = in->ObjY[i];
                        obs.lenght = in->ObjLen[i];
                        obs.width = in->ObjWidth[i];
                        obstacle_list.push_back(obs);
                        fprintf(fileDebug, "obs.ID=%d; obs.x=%f; obs.y=%f; obs.lenght=%f; obs.width=%f\n", obs.ID, obs.x, obs.y, obs.lenght, obs.lenght);
                        break;
                    case ID_OBJ_TARGET:
                        goal.p.x = in->ObjX[i];
                        goal.p.y = in->ObjY[i];
                        fprintf(fileDebug, "goal.x=%f; goal.y=%f\n",goal.p.x, goal.p.y);
                        break;
                    }
                }

                // Definisco il vettore dei punti che definiscono il path da seguire
                std::vector<node> path_to_follow;
                int numberSolutions = rrt_star(start, goal, obstacle_list, path_to_follow);
                fprintf(fileDebug, "rrt_star found %d solution(s)\n", numberSolutions);

                // ----- LATERAL CONTROL -----
                double LatPosL = in->LatOffsLineL; // lateral offset from left line
                logger.log_var("Lateral", "YawRateFild", in->YawRateFild);
                logger.log_var("Lateral", "SteerWhlAg", in->SteerWhlAg);
                logger.log_var("Lateral", "VehicleLen", in->VehicleLen);
                logger.log_var("Lateral", "VehicleWidth", in->VehicleWidth);
                logger.log_var("Lateral", "AutomationLevel", in->AutomationLevel);
                logger.log_var("Lateral", "CurrentLane", in->CurrentLane);
                logger.log_var("Lateral", "NrObjs", in->NrObjs);
                logger.log_var("Lateral", "LaneWidth", in->LaneWidth);
                logger.log_var("Lateral", "LatOffsLineR", in->LatOffsLineR);
                logger.log_var("Lateral", "LatOffsLineL", in->LatOffsLineL);
                logger.log_var("Lateral", "LaneHeading", in->LaneHeading);
                logger.log_var("Lateral", "LaneCrvt", in->LaneCrvt);
                for (int i = 0; i < obstacle_list.size(); ++i)
                {
                    logger.log_var("Lateral", ("objX[" + std::to_string(i) + "]").c_str(), obstacle_list[i].x);
                    logger.log_var("Lateral", ("objY[" + std::to_string(i) + "]").c_str(), obstacle_list[i].y);
                }
                logger.write_line("Lateral");

                fprintf(fileDebug, "firstCycle END\n\n");
            }

            // ----- LONGITUDINAL CONTROL -----
            static double init_dist = in->TrfLightDist; // initial distance to the traffic light
            double sf = in->TrfLightDist;               // distance to the traffic light
            double dist = init_dist - sf;               // distance traveled
            double v0 = in->VLgtFild;                   // actual longitudinal velocity
            double a0 = in->ALgtFild;                   // actual longitudinal acceleration
            double m_star[6], m1[6], m2[6];             // primitives
            double lookahead = fmax(50.0, v0 * 5.0);    // lookahead distance
            const double v_min = 3.0, v_max = 15.0;     // vel min & max to pass the traffic light
            const double x_s = 5.0;                     // safety space before traffic light
            const double x_in = 10.0;                   // length of the intersection
            double v_r = in->RequestedCruisingSpeed;    // req cruising speed of the vehicle
            const double T_s = x_s / v_min;             // time to travel the safety space
            const double T_in = x_in / v_min;           // time to safety space
            static double x_tr = 0;                     // distance to the traffic light
            static double x_stop = 0;                   // distance to the stop the vehicle
            double v1, T1, v2, T2;
            double T_green, T_red;
            double x_stop_max, T_stop;
            double sf_j0, tf_stop_j0;
            const char *messageDebug;
            // others to add in longitudinal control

            // ----- LOGIC FOR TRAFFIC LIGHT -----
            if (in->NrTrfLights != 0) // if there is a traffic light
            {
                x_tr = sf;
                x_stop = sf - (x_s / 2.0); // stop before the TL
                if (x_stop < 0)
                {
                    x_stop = 0;
                }
            }
            if (in->NrTrfLights == 0 || x_tr >= lookahead) // if there is no TL or is very far -> FreeFlow
            {
                // pass_primitive(v0, a0, lookahead, v_r, v_r, 0.0, 0.0, m_star, &v1, &T1, m_star, &v2, &T2); // FreeFlow
                free_flow(v0, a0, lookahead, v_r, m_star, &v1, &T1);
                messageDebug = "if (in->NrTrfLights==0 || x_tr>=lookahead)";
            }
            else if (sf < 0) // ADDED -> if we passed the TL and it turns red do not stop
            {
                free_flow(v0, a0, lookahead, v_r, m_star, &v1, &T1);
                messageDebug = "else if (sf<0)";
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

                if (in->TrfLightCurrState == GREEN_TL && sf <= x_s) // if TL green and we are very closed to TL
                {
                    // pass_primitive(v0, a0, lookahead, v_r, v_r, 0.0, 0.0, m_star, &v1, &T1, m_star, &v2, &T2); // FreeFlow
                    free_flow(v0, a0, lookahead, v_r, m_star, &v1, &T1);
                    messageDebug = "if (in->TrfLightCurrState==GREEN_TL && in->TrfLightDist<=x_s)";
                }
                else
                {
                    pass_primitive(v0, a0, x_tr, v_min, v_max, T_green, T_red, m1, &v1, &T1, m2, &v2, &T2);
                    if (isAllZero(m1) && isAllZero(m2))
                    {
                        stop_primitive(v0, a0, x_stop, m_star, &x_stop_max, &T_stop);
                        messageDebug = "if (isAllZero(m1) && isAllZero(m2))";
                    }
                    else
                    {
                        if ((m1[3] < 0 && m2[3] > 0) || (m1[3] > 0 && m2[3] < 0))
                        {
                            pass_primitive_j0(v0, a0, x_tr, v_min, v_max, m_star, &sf_j0, &tf_stop_j0);
                            messageDebug = "if ((m1[3]<0 && m2[3]>0) || (m1[3]>0 && m2[3]<0))";
                        }
                        else
                        {
                            if (abs(m1[3]) < abs(m2[3]))
                            {
                                copy_m(m_star, m1);
                                messageDebug = "if (abs(m1[3]) < abs(m2[3]))";
                            }
                            else
                            {
                                copy_m(m_star, m2);
                                messageDebug = "else";
                            }
                        }
                    }
                }
            }

            // double vr = in->RequestedCruisingSpeed;
            // double minTime, maxTime;
            double final_time, final_distance, final_vel;

            // ----- TRAPEZOIDAL JERK -----
            static double a0_bar = 0.0; //=a0 or 0.0; (?)
            const double a_min = -5.0;
            const double a_max = 5.0;
            double j_req = 0.5 * DT * (j_from_coeffs(0.0, m_star) + j_from_coeffs(DT, m_star));
            double a_req = a0_bar + j_req;
            a_req = fmin(fmax(a_req, a_min), a_max);
            // a_req = fmin(fmax(a0_bar+longGain*(DT*(jT1+jT0)*0.5),a_min), a_max);
            a0_bar = a_req;
            // double v_req = v_opt(DT, v0, a0, bests, bestv, 0.0, bestT);
            double v_req = v_from_coeffs(DT, m_star);
            static double s_req = 0.0;
            s_req += s_from_coeffs(DT, m_star);

            // Lezione 20/11 -> plot the primitives in matlab
            double s = init_dist - dist;

            // ----- PI IMPLEMENTATION -----
            const double k_p = 0.02;
            const double k_i = 0.15; // 1.0;
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
            manoeuvre_msg.data_struct.RequestedAcc = requested_pedal;
            manoeuvre_msg.data_struct.RequestedSteerWhlAg = 0.0;

            // ----- CSV FILE & PRINT -----
            const char *fileName = "Longitudinal_control";

            // Log_vars for csv
            logger.log_var(fileName, "messageDebug", messageDebug);
            logger.log_var(fileName, "cycle", in->CycleNumber);
            logger.log_var(fileName, "time", in->ECUupTime);
            logger.log_var(fileName, "dist", dist);
            logger.log_var(fileName, "x_tr", x_tr);
            logger.log_var(fileName, "x_stop", x_stop);
            logger.log_var(fileName, "v0", in->VLgtFild);
            logger.log_var(fileName, "a0", a0);
            logger.log_var(fileName, "a_req", a_req);
            logger.log_var(fileName, "lookahead", lookahead);
            logger.log_var(fileName, "error_integral", error_integral);
            logger.log_var(fileName, "v_r", v_r);
            logger.log_var(fileName, "in->TrfLightCurrState", in->TrfLightCurrState);
            logger.log_var(fileName, "T_green", T_green);
            logger.log_var(fileName, "T_red", T_red);
            logger.log_var(fileName, "isAllZero(m1)", isAllZero(m1));
            logger.log_var(fileName, "isAllZero(m2)", isAllZero(m2));
            logger.log_var(fileName, "m1[3]", m1[3]);
            logger.log_var(fileName, "m2[3]", m2[3]);
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