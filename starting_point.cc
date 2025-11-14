//
// Created by Gastone Pietro Rosati Papini on 10/08/22.
//
// Shortcuts -> compile: f6; run: f7


/*
File tmwtypes.h da / matlab copiato in /matlab
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

extern "C"
{
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"

// --- MATLAB PRIMITIVES INCLUDE ---
// #include "primitives.h"
// --- MATLAB PRIMITIVES INCLUDE ---

#define DEFAULT_SERVER_IP "127.0.0.1"
#define SERVER_PORT 30000 // Server port
#define DT 0.05

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal)
{
    server_run = 0;
}

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

            static double init_dist = in->TrfLightDist;
            double dist = init_dist - in->TrfLightDist;
            double v_real = in->VLgtFild;
            double a_real = in->ALgtFild;
            const double a_max = 5;
            const double a_min = -5;
            a_real = fmin(fmax(a_real, a_min), a_max); // saturate acceleration

            // ADD AGENT CODE HERE
            const double a_req = 1;
            static double v_req = 0;
            v_req = v_req + a_req * DT;

            // PI implementation
            const double k_p = 0.04;
            const double k_i = 0.01;
            double error = a_req - a_real;
            static double error_integral = 0;
            error_integral = error_integral + error * DT;
            double requested_pedal = error * k_p + error_integral * k_i;

            // Send information to logger
            logger.log_var("Example", "cycle", in->CycleNumber);
            logger.log_var("Example", "time", in->ECUupTime);
            logger.log_var("Example", "dist", dist);
            logger.log_var("Example", "v_real", v_real);
            logger.log_var("Example", "v_req", v_req);
            logger.log_var("Example", "a_real", a_real);
            logger.log_var("Example", "a_req", a_req);
            logger.log_var("Example", "error", error);
            logger.log_var("Example", "error_integral", error_integral);
            logger.log_var("Example", "requested_pedal", requested_pedal);


            /*  -- lezione 14/11 --
            double coef[6];
            double final_time, finale_distance final_vel;
            if (dist < 50)
            {
                student_stop_primitive(v_real, a_real, dist, coef, &finale_distance, &final_time);
            }
            else
            {
                student_pass_primitive(v_real, a_real, dist, 15, 15, 0, 0, coef, &final_vel, &final_time, coef, &final_vel, &final_time) //check se possibile mettere T_min=T_mas=0
            }
            //double req_acc = a_opt(DT, vel, acc, dist, 20.0, &finale_distance, &final_time-ECUtime);
            //double req_vel = v_opt(DT, vel, acc, dist, 20.0, &final_time-ECUtime);
            double req_acc = coeffs_a_opt(DT, coef);
            */

            // ADD LOW LEVEL CONTROL CODE HERE
            manoeuvre_msg.data_struct.RequestedAcc = requested_pedal;
            manoeuvre_msg.data_struct.RequestedSteerWhlAg = 0.0;

            // Write log
            logger.write_line("Example");

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