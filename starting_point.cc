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
#include "screen_print.h"
#include "server_lib.h"

// ----- #define -----
#define DEFAULT_SERVER_IP "127.0.0.1" // IP Address
#define SERVER_PORT 30000             // Server port
#define DT 0.05                       // Time step
#define GREEN_TL 1                    // State corresponding to green  traffic light
#define YELLOW_TL 2                   // State corresponding to yellow  traffic light
#define RED_TL 3                      // State corresponding to red  traffic light

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) { server_run = 0; }

// ----- PROTOTYPES -----
void copy_m(double m1[6], double m2[6]);

// ----- MAIN -----
int main(int argc, const char *argv[])
{
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

            // ----- LONGITUDINAL CONTROL -----
            double v0 = in->VLgtFild;       // actual longitudinal velocity
            double a0 = in->ALgtFild;       // actual longitudinal acceleration
            double m_star[6], m1[6], m2[6]; // primitives

            // others to add in longitudinal control

            // ----- TEST LOGIC (only to check if primitives work) -----
            static double init_dist = in->TrfLightDist;
            double sf = in->TrfLightDist;
            double vr = in->RequestedCruisingSpeed;
            double dist = init_dist - sf;
            double minTime, maxTime;
            double final_time, final_distance, final_vel;
            double v1, T1, v2, T2;
            if (dist > 50)
            {
                stop_primitive(v0, a0, sf, m1, &v1, &T1); // v1=maxsf lecture 29/11 online
            }
            else
            {
                pass_primitive(v0, a0, sf, 15.0, 15.0, 0.0, 0.0, m1, &v1, &T1, m2, &v2, &T2);
            }

            copy_m(m_star, m1); // m_star=m1
            double bestv = v1;
            double bests = sf;
            double bestT = T1;

            final_time = bestT;
            final_distance = bests;
            final_vel = bestv;

            static double ECUtimeOLD = 0.0;
            ECUtimeOLD = in->ECUupTime;
            double longGain = 20.0;
            double j0 = m_star[3];
            double s0 = m_star[4];
            double cr0 = m_star[5];
            double t0ffs = 0.0;
            double jT0 = j0 + t0ffs * s0 + 0.5 * t0ffs * t0ffs * cr0;
            double jT1 = j0 + (DT + t0ffs) * s0 + 0.5 * (DT + t0ffs) * (DT + t0ffs) * cr0;

            // ----- LOGIC FOR TRAFFIC LIGHT -----

            // ----- TRAPEZOIDAL JERK -----
            static double a0_bar = 0.0; //=a0 or 0.0; (?)
            const double a_min = -5.0;
            const double a_max = 5.0;
            double j_req = 0.5 * DT * (j_from_coeffs(0.0, m_star) + j_from_coeffs(DT, m_star));
            double a_req = a0_bar + j_req;
            a_req = fmin(fmax(a_req, a_min), a_max);
            // a_req = fmin(fmax(a0_bar+longGain*(DT*(jT1+jT0)*0.5),a_min), a_max);
            a0_bar = a_req;
            //double v_req = v_opt(DT, v0, a0, bests, bestv, 0.0, bestT);
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
            manoeuvre_msg.data_struct.RequestedAcc = requested_pedal;
            manoeuvre_msg.data_struct.RequestedSteerWhlAg = 0.0;

            // ----- CSV FILE & PRINT -----
            const char *fileName = "Test";

            // Log_vars for csv
            logger.log_var(fileName, "cycle", in->CycleNumber);
            logger.log_var(fileName, "time", in->ECUupTime);
            logger.log_var(fileName, "s_req", s_req);
            logger.log_var(fileName, "dist", dist);
            logger.log_var(fileName, "in->TrfLightDist", in->TrfLightDist);
            logger.log_var(fileName, "v_req", v_req);
            logger.log_var(fileName, "v0", in->VLgtFild);
            logger.log_var(fileName, "a_req", a_req);
            logger.log_var(fileName, "a0", a0);
            logger.log_var(fileName, "final_time", final_time);
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