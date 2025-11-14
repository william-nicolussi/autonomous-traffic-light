/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_api.h
 *
 * Code generation for function 'a_from_coeffs'
 *
 */

#ifndef _CODER_PRIMITIVES_API_H
#define _CODER_PRIMITIVES_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T a_from_coeffs(real_T t, real_T in2[6]);

void a_from_coeffs_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T a_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T T);

void a_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

void coef_list(real_T v0, real_T a0, real_T sf, real_T vf, real_T af, real_T T,
               real_T coef_list_var[6]);

void coef_list_api(const mxArray *const prhs[6], const mxArray **plhs);

real_T final_opt_time_pass(real_T v0, real_T a0, real_T sf, real_T vf);

void final_opt_time_pass_api(const mxArray *const prhs[4],
                             const mxArray **plhs);

real_T final_opt_time_stop(real_T v0, real_T a0, real_T sf);

void final_opt_time_stop_api(const mxArray *const prhs[3],
                             const mxArray **plhs);

real_T final_opt_vel_pass(real_T v0, real_T a0, real_T sf, real_T tf);

void final_opt_vel_pass_api(const mxArray *const prhs[4], const mxArray **plhs);

real_T j_from_coeffs(real_T t, real_T in2[6]);

void j_from_coeffs_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T j_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T T);

void j_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

void primitives_atexit(void);

void primitives_initialize(void);

void primitives_terminate(void);

void primitives_xil_shutdown(void);

void primitives_xil_terminate(void);

real_T s_from_coeffs(real_T t, real_T in2[6]);

void s_from_coeffs_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T s_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T T);

void s_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

void student_pass_primitive(real_T v0, real_T a0, real_T sf, real_T vf_min,
                            real_T vf_max, real_T T_min, real_T T_max,
                            real_T coeffsT2[6], real_T *v2, real_T *T2,
                            real_T coeffsT1[6], real_T *v1, real_T *T1);

void student_pass_primitive_api(const mxArray *const prhs[7], int32_T nlhs,
                                const mxArray *plhs[6]);

void student_stop_primitive(real_T v0, real_T a0, real_T sf, real_T coefs[6],
                            real_T *maxsf, real_T *tf);

void student_stop_primitive_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[3]);

real_T time_min_vel_pass(real_T v0, real_T a0, real_T sf, real_T v_min);

void time_min_vel_pass_api(const mxArray *const prhs[4], const mxArray **plhs);

real_T total_cost_var(real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
                      real_T T);

void total_cost_var_api(const mxArray *const prhs[6], const mxArray **plhs);

real_T v_from_coeffs(real_T t, real_T in2[6]);

void v_from_coeffs_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T v_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T T);

void v_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_primitives_api.h) */
