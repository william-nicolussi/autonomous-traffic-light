/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * primitives.h
 *
 * Code generation for function 'primitives'
 *
 */

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern double a_from_coeffs(double t, const double in2[6]);

extern double a_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

extern void coef_list(double v0, double a0, double sf, double vf, double af,
                      double T, double m[6]);

extern double final_opt_pos_j0(double v0, double a0, double tf);

extern void final_opt_time_j0(double v0, double a0, double sf,
                              double tf_j0_opt_all[2]);

extern double final_opt_time_j0_1(double v0, double a0, double sf);

extern double final_opt_time_j0_2(double v0, double a0, double sf);

extern double final_opt_time_pass(double v0, double a0, double sf, double vf);

extern double final_opt_time_stop(double v0, double a0, double sf);

extern double final_opt_time_stop_j0(double v0, double a0);

extern double final_opt_vel_j0(double v0, double a0, double sf, double tf);

extern double final_opt_vel_pass(double v0, double a0, double sf, double tf);

extern double j_from_coeffs(double t, const double in2[6]);

extern double j_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

extern double min_vel(double v0, double a0, double sf);

extern void pass_primitive(double v0, double a0, double sf, double v_min,
                           double v_max, double T_min, double T_max,
                           double m1[6], double *v1, double *T1, double m2[6],
                           double *v2, double *T2);

extern void pass_primitive_j0(double v0, double a0, double sf, double v_min,
                              double v_max, double m[6], double *sf_j0,
                              double *tf_j0);

extern void primitives_initialize(void);

extern void primitives_terminate(void);

extern double s_from_coeffs(double t, const double in2[6]);

extern double s_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

extern void stop_primitive(double v0, double a0, double sf, double m[6],
                           double *s_max, double *tf);

extern void stop_primitive_j0(double v0, double a0, double m[6], double *sf_j0,
                              double *tf_j0);

extern double time_min_vel_pass(double a0, double sf);

extern double total_cost(double v0, double a0, double sf, double vf, double af,
                         double T);

extern double v_from_coeffs(double t, const double in2[6]);

extern double v_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (primitives.h) */
