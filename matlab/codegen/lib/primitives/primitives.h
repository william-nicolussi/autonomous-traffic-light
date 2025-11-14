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
                      double T, double coef_list_var[6]);

extern double final_opt_time_pass(double v0, double a0, double sf, double vf);

extern double final_opt_time_stop(double v0, double a0, double sf);

extern double final_opt_vel_pass(double v0, double a0, double sf, double tf);

extern double j_from_coeffs(double t, const double in2[6]);

extern double j_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

extern void primitives_initialize(void);

extern void primitives_terminate(void);

extern double s_from_coeffs(double t, const double in2[6]);

extern double s_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

extern void student_pass_primitive(double v0, double a0, double sf,
                                   double vf_min, double vf_max, double T_min,
                                   double T_max, double coeffsT2[6], double *v2,
                                   double *T2, double coeffsT1[6], double *v1,
                                   double *T1);

extern void student_stop_primitive(double v0, double a0, double sf,
                                   double coefs[6], double *maxsf, double *tf);

extern double time_min_vel_pass(double v0, double a0, double sf, double v_min);

extern double total_cost_var(double v0, double a0, double sf, double vf,
                             double af, double T);

extern double v_from_coeffs(double t, const double in2[6]);

extern double v_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double T);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (primitives.h) */
