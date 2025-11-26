//
// Created by Gastone Pietro Rosati Papini on 10/08/22.
//
// Shortcuts -> compile: f6; run: f7

// ----- #include <> -----
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

// ----- #include "" -----
extern "C"
{
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"
#include "primitives.h"

// --- MATLAB PRIMITIVES INCLUDE ---
#include "primitives.h"
// --- MATLAB PRIMITIVES INCLUDE ---

// ----- #define -----
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

// ----- PROTOTYPES -----
static void create_csv_PI(const char*, const input_data_str* in, double s_req, double dist, double v_req, double a_req,double a_real, double error, double error_integral, double requested_pedal);
static void create_csv_Coeff(const char* fileName, const input_data_str* in, double s_req, double dist, double v_req, double a_req, double a_real, double coeff[6], double final_time);


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

            static double init_dist = in->TrfLightDist;
            double dist = init_dist - in->TrfLightDist;
            double s_req=0, v_req=0, a_req=0;
            double v_real = in->VLgtFild;
            double a_real = in->ALgtFild;
            const double a_max = 5;
            const double a_min = -10;
            a_real = fmin(fmax(a_real, a_min), a_max); // saturate acceleration -> forse questo è sbagliato
            double t = in->ECUupTime;
            static double s_req_cumulative = 0; // to plot s_req
            double coef[6]; // 6 elements because the matlab function returns a vector of 6
            double final_time, final_distance, final_vel;

            /* -- Lezione 14/11 --
            double req_acc = coueffs_a_opt(DT, coef);
            double s = coeffs_s_opt(DT, coef);
            */

            // ADD AGENT CODE HERE
            // TEST 1: Constant acceleration
            /*
            a_req = 1;
            v_req = v_req + a_req * DT;
            s_req = s_req + v_req*DT + 1/2*a_req*DT*DT;
            */

            // TEST 2
            /* In this case we surpass the traffic light because we have a_req<<a_min */
            /*
            a_req = a_opt(DT, v_real, a_real, in->TrfLightDist, 0, 0, 20-t);
            v_req = v_opt(DT, v_real, a_real, in->TrfLightDist, 0, 0, 20-t);
            s_req = s_opt(DT, v_real, a_real, in->TrfLightDist, 0, 0, 20-t);
            s_req_cumulative += s_req;
            */
            

            // TEST 3
            /* Test acc and brake: lecture 8/11 online
            // Poi ha disegnato grafico s[m];vel[m/s] con tracciate vel e Rq vel
            // e anche grafico t[s];vel[m/s] con tracciate vel e Rq vel*/
            /*
            s_req = s_opt(DT, v_real, a_real, in->TrfLightDist, 25, 0, 10-t);
            v_req = v_opt(DT, v_real, a_real, in->TrfLightDist, 25, 0, 10-t);
            a_req = a_opt(DT, v_real, a_real, in->TrfLightDist, 25, 0, 10-t);
            if(t > 5)
            {
                s_req = s_opt(DT, v_real, a_real, in->TrfLightDist, 0, 0, 15-t);
                v_req = v_opt(DT, v_real, a_real, in->TrfLightDist, 0, 0, 15-t);
                a_req = a_opt(DT, v_real, a_real, in->TrfLightDist, 0, 0, 15-t);
            }
            s_req_cumulative += s_req;
            */

            /*
            A req pagina 66 -> mettere a_req quella fittizia che altrimenti è troppo rumorosa.
            */

            //TEST 4
            if (dist > 50)
            {
                //student_stop_primitive(v_real, a_real, dist, coef, &final_distance, &final_time);
                student_stop_primitive(v_real, a_real, in->TrfLightDist, coef, &final_distance, &final_time);
            }
            else
            {
                student_pass_primitive(v_real, a_real, in->TrfLightDist, 15.0, 15.0, 0.0, 0.0, coef, &final_vel, &final_time, coef, &final_vel, &final_time); //check se possibile mettere T_min=T_mas=0
            }
            s_req = s_from_coeffs(DT, coef);
            v_req = v_from_coeffs(DT, coef);
            // a_req = a_from_coeffs(DT, coef);
            static double a_req_old = a_real;
            a_req = a_req_old + 0.5*DT*(j_from_coeffs(0,coef)+j_from_coeffs(DT,coef));
            a_req = fmin(fmax(a_req, a_min), a_max);
            a_req_old = a_req;
            s_req_cumulative += s_req;

            // Lezione 20/11 -> plot the primitives in matlab
            double s = init_dist - dist;
            /* Lui ha un file con time, acc, req_acc, vel, req_vel, e poi i coefficienti. */

            
            // PI implementation
            const double k_p = 0.1;
            const double k_i = 0.01;
            double error = a_req - a_real;
            static double error_integral = 0;
            error_integral = error_integral + error * DT;
            double requested_pedal = error * k_p + error_integral * k_i;
            /* Classe: [k_p=1.0;k_i=0.01;]
            Test 2: [k_p=0.02;k_i=1;] 8/11 online
            */

            // PLOT TEST 2
            /*
            if (t<19.98)
            {
                create_csv_PI("Test_2", in, s_req_cumulative, dist, v_req, a_req, a_real, error, error_integral, requested_pedal);
            }
            */

            // PLOT TEST 3
            /*
            if (t<14.98)
            {
                create_csv_PI("Test_3", in, s_req_cumulative, dist, v_req, a_req, a_real, error, error_integral, requested_pedal);
            }
            */

            // PLOT TEST 4
            create_csv_Coeff("Test_4_Coeff", in, s_req_cumulative, dist, v_req, a_req, a_real, coef, final_time);

            //logger.log_var("acc_test", "coef0", coef[0]);


            /*  -- lezione 14/11 -- Test the primitives
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

// ----- FUNCTIONS -----
static void create_csv_PI(const char* fileName, const input_data_str* in, double s_req, double dist, double v_req, double a_req, double a_real, double error, double error_integral, double requested_pedal)
{
    logger.log_var(fileName, "cycle", in->CycleNumber);
    logger.log_var(fileName, "time",  in->ECUupTime);
    logger.log_var(fileName, "s_req", s_req);
    logger.log_var(fileName, "in->TrfLightDist", in->TrfLightDist);
    logger.log_var(fileName, "dist", dist);
    logger.log_var(fileName, "v_req", v_req);
    logger.log_var(fileName, "v_real", in->VLgtFild);
    logger.log_var(fileName, "a_req", a_req);
    logger.log_var(fileName, "a_real", a_real);
    logger.log_var(fileName, "error", error);
    logger.log_var(fileName, "error_integral",  error_integral);
    logger.log_var(fileName, "requested_pedal", requested_pedal);
    
    // Write log
    logger.write_line(fileName);
}

static void create_csv_Coeff(const char* fileName, const input_data_str* in, double s_req, double dist, double v_req, double a_req, double a_real, double coeff[6], double final_time)
{
    logger.log_var(fileName, "cycle", in->CycleNumber);
    logger.log_var(fileName, "time",  in->ECUupTime);
    logger.log_var(fileName, "s_req", s_req);
    logger.log_var(fileName, "dist", dist);
    logger.log_var(fileName, "in->TrfLightDist", in->TrfLightDist);
    logger.log_var(fileName, "v_req", v_req);
    logger.log_var(fileName, "v_real", in->VLgtFild);
    logger.log_var(fileName, "a_req", a_req);
    logger.log_var(fileName, "a_real", a_real);
    logger.log_var(fileName, "final_time", final_time);
    logger.log_var(fileName, "c0", coeff[0]);
    logger.log_var(fileName, "c1", coeff[1]);
    logger.log_var(fileName, "c2", coeff[2]);
    logger.log_var(fileName, "c3", coeff[3]);
    logger.log_var(fileName, "c4", coeff[4]);
    logger.log_var(fileName, "c5", coeff[5]);

    /*char name_coef[5];
    for(int i=0; i<6; i++)
    {
        snprintf(name_coef, sizeof(name_coef), "c(%d)", i);
        logger.log_var(fileName, name_coef, coeff[i]);
    }*/

    // Write log
    logger.write_line(fileName);
}