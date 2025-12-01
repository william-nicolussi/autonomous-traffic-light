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
               real_T m[6]);

void coef_list_api(const mxArray *const prhs[6], const mxArray **plhs);

real_T final_opt_pos_j0(real_T v0, real_T a0, real_T tf);

void final_opt_pos_j0_api(const mxArray *const prhs[3], const mxArray **plhs);

void final_opt_time_j0(real_T v0, real_T a0, real_T sf,
                       real_T tf_j0_opt_all[2]);

real_T final_opt_time_j0_1(real_T v0, real_T a0, real_T sf);

void final_opt_time_j0_1_api(const mxArray *const prhs[3],
                             const mxArray **plhs);

real_T final_opt_time_j0_2(real_T v0, real_T a0, real_T sf);

void final_opt_time_j0_2_api(const mxArray *const prhs[3],
                             const mxArray **plhs);

void final_opt_time_j0_api(const mxArray *const prhs[3], const mxArray **plhs);

real_T final_opt_time_pass(real_T v0, real_T a0, real_T sf, real_T vf);

void final_opt_time_pass_api(const mxArray *const prhs[4],
                             const mxArray **plhs);

real_T final_opt_time_stop(real_T v0, real_T a0, real_T sf);

void final_opt_time_stop_api(const mxArray *const prhs[3],
                             const mxArray **plhs);

real_T final_opt_time_stop_j0(real_T v0, real_T a0);

void final_opt_time_stop_j0_api(const mxArray *const prhs[2],
                                const mxArray **plhs);

real_T final_opt_vel_j0(real_T v0, real_T a0, real_T sf, real_T tf);

void final_opt_vel_j0_api(const mxArray *const prhs[4], const mxArray **plhs);

real_T final_opt_vel_pass(real_T v0, real_T a0, real_T sf, real_T tf);

void final_opt_vel_pass_api(const mxArray *const prhs[4], const mxArray **plhs);

real_T j_from_coeffs(real_T t, real_T in2[6]);

void j_from_coeffs_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T j_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T T);

void j_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

real_T min_vel(real_T v0, real_T a0, real_T sf);

void min_vel_api(const mxArray *const prhs[3], const mxArray **plhs);

void pass_primitive(real_T v0, real_T a0, real_T sf, real_T v_min, real_T v_max,
                    real_T T_min, real_T T_max, real_T m1[6], real_T *v1,
                    real_T *T1, real_T m2[6], real_T *v2, real_T *T2);

void pass_primitive_api(const mxArray *const prhs[7], int32_T nlhs,
                        const mxArray *plhs[6]);

void pass_primitive_j0(real_T v0, real_T a0, real_T sf, real_T v_min,
                       real_T v_max, real_T m[6], real_T *sf_j0, real_T *tf_j0);

void pass_primitive_j0_api(const mxArray *const prhs[5], int32_T nlhs,
                           const mxArray *plhs[3]);

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

void stop_primitive(real_T v0, real_T a0, real_T sf, real_T m[6], real_T *s_max,
                    real_T *tf);

void stop_primitive_api(const mxArray *const prhs[3], int32_T nlhs,
                        const mxArray *plhs[3]);

void stop_primitive_j0(real_T v0, real_T a0, real_T m[6], real_T *sf_j0,
                       real_T *tf_j0);

void stop_primitive_j0_api(const mxArray *const prhs[2], int32_T nlhs,
                           const mxArray *plhs[3]);

real_T time_min_vel_pass(real_T a0, real_T sf);

void time_min_vel_pass_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T total_cost(real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
                  real_T T);

void total_cost_api(const mxArray *const prhs[6], const mxArray **plhs);

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
