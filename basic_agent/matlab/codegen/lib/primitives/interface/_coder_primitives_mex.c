/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_mex.c
 *
 * Code generation for function 'a_from_coeffs'
 *
 */

/* Include files */
#include "_coder_primitives_mex.h"
#include "_coder_primitives_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[25] = {"a_from_coeffs",
                                               "a_opt",
                                               "coef_list",
                                               "final_opt_pos_j0",
                                               "final_opt_time_j0",
                                               "final_opt_time_j0_1",
                                               "final_opt_time_j0_2",
                                               "final_opt_time_pass",
                                               "final_opt_time_stop",
                                               "final_opt_time_stop_j0",
                                               "final_opt_vel_j0",
                                               "final_opt_vel_pass",
                                               "j_from_coeffs",
                                               "j_opt",
                                               "min_vel",
                                               "pass_primitive",
                                               "pass_primitive_j0",
                                               "s_from_coeffs",
                                               "s_opt",
                                               "stop_primitive",
                                               "stop_primitive_j0",
                                               "time_min_vel_pass",
                                               "total_cost",
                                               "v_from_coeffs",
                                               "v_opt"};
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *ab_prhs[7];
  const mxArray *s_prhs[7];
  const mxArray *u_prhs[7];
  const mxArray *v_prhs[7];
  const mxArray *x_prhs[7];
  const mxArray *t_prhs[6];
  const mxArray *y_prhs[6];
  const mxArray *w_prhs[5];
  const mxArray *g_prhs[4];
  const mxArray *j_prhs[4];
  const mxArray *k_prhs[4];
  const mxArray *c_prhs[3];
  const mxArray *d_prhs[3];
  const mxArray *e_prhs[3];
  const mxArray *f_prhs[3];
  const mxArray *h_prhs[3];
  const mxArray *m_prhs[3];
  const mxArray *o_prhs[3];
  const mxArray *b_prhs[2];
  const mxArray *i_prhs[2];
  const mxArray *l_prhs[2];
  const mxArray *n_prhs[2];
  const mxArray *p_prhs[2];
  const mxArray *q_prhs[2];
  const mxArray *r_prhs[2];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  mexAtExit(&primitives_atexit);
  /* Module initialization. */
  primitives_initialize();
  st.tls = emlrtRootTLSGlobal;
  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 25)) {
  case 0:
    b_prhs[0] = prhs[1];
    b_prhs[1] = prhs[2];
    unsafe_a_from_coeffs_mexFunction(nlhs, plhs, nrhs - 1, b_prhs);
    break;
  case 1:
    for (i = 0; i < 7; i++) {
      s_prhs[i] = prhs[i + 1];
    }
    unsafe_a_opt_mexFunction(nlhs, plhs, nrhs - 1, s_prhs);
    break;
  case 2:
    for (i1 = 0; i1 < 6; i1++) {
      t_prhs[i1] = prhs[i1 + 1];
    }
    unsafe_coef_list_mexFunction(nlhs, plhs, nrhs - 1, t_prhs);
    break;
  case 3:
    c_prhs[0] = prhs[1];
    c_prhs[1] = prhs[2];
    c_prhs[2] = prhs[3];
    unsafe_final_opt_pos_j0_mexFunction(nlhs, plhs, nrhs - 1, c_prhs);
    break;
  case 4:
    d_prhs[0] = prhs[1];
    d_prhs[1] = prhs[2];
    d_prhs[2] = prhs[3];
    unsafe_final_opt_time_j0_mexFunction(nlhs, plhs, nrhs - 1, d_prhs);
    break;
  case 5:
    e_prhs[0] = prhs[1];
    e_prhs[1] = prhs[2];
    e_prhs[2] = prhs[3];
    unsafe_final_opt_time_j0_1_mexFunction(nlhs, plhs, nrhs - 1, e_prhs);
    break;
  case 6:
    f_prhs[0] = prhs[1];
    f_prhs[1] = prhs[2];
    f_prhs[2] = prhs[3];
    unsafe_final_opt_time_j0_2_mexFunction(nlhs, plhs, nrhs - 1, f_prhs);
    break;
  case 7:
    g_prhs[0] = prhs[1];
    g_prhs[1] = prhs[2];
    g_prhs[2] = prhs[3];
    g_prhs[3] = prhs[4];
    unsafe_final_opt_time_pass_mexFunction(nlhs, plhs, nrhs - 1, g_prhs);
    break;
  case 8:
    h_prhs[0] = prhs[1];
    h_prhs[1] = prhs[2];
    h_prhs[2] = prhs[3];
    unsafe_final_opt_time_stop_mexFunction(nlhs, plhs, nrhs - 1, h_prhs);
    break;
  case 9:
    i_prhs[0] = prhs[1];
    i_prhs[1] = prhs[2];
    unsafe_final_opt_time_stop_j0_mexFunction(nlhs, plhs, nrhs - 1, i_prhs);
    break;
  case 10:
    j_prhs[0] = prhs[1];
    j_prhs[1] = prhs[2];
    j_prhs[2] = prhs[3];
    j_prhs[3] = prhs[4];
    unsafe_final_opt_vel_j0_mexFunction(nlhs, plhs, nrhs - 1, j_prhs);
    break;
  case 11:
    k_prhs[0] = prhs[1];
    k_prhs[1] = prhs[2];
    k_prhs[2] = prhs[3];
    k_prhs[3] = prhs[4];
    unsafe_final_opt_vel_pass_mexFunction(nlhs, plhs, nrhs - 1, k_prhs);
    break;
  case 12:
    l_prhs[0] = prhs[1];
    l_prhs[1] = prhs[2];
    unsafe_j_from_coeffs_mexFunction(nlhs, plhs, nrhs - 1, l_prhs);
    break;
  case 13:
    for (i2 = 0; i2 < 7; i2++) {
      u_prhs[i2] = prhs[i2 + 1];
    }
    unsafe_j_opt_mexFunction(nlhs, plhs, nrhs - 1, u_prhs);
    break;
  case 14:
    m_prhs[0] = prhs[1];
    m_prhs[1] = prhs[2];
    m_prhs[2] = prhs[3];
    unsafe_min_vel_mexFunction(nlhs, plhs, nrhs - 1, m_prhs);
    break;
  case 15:
    for (i3 = 0; i3 < 7; i3++) {
      v_prhs[i3] = prhs[i3 + 1];
    }
    unsafe_pass_primitive_mexFunction(nlhs, plhs, nrhs - 1, v_prhs);
    break;
  case 16:
    for (i4 = 0; i4 < 5; i4++) {
      w_prhs[i4] = prhs[i4 + 1];
    }
    unsafe_pass_primitive_j0_mexFunction(nlhs, plhs, nrhs - 1, w_prhs);
    break;
  case 17:
    n_prhs[0] = prhs[1];
    n_prhs[1] = prhs[2];
    unsafe_s_from_coeffs_mexFunction(nlhs, plhs, nrhs - 1, n_prhs);
    break;
  case 18:
    for (i5 = 0; i5 < 7; i5++) {
      x_prhs[i5] = prhs[i5 + 1];
    }
    unsafe_s_opt_mexFunction(nlhs, plhs, nrhs - 1, x_prhs);
    break;
  case 19:
    o_prhs[0] = prhs[1];
    o_prhs[1] = prhs[2];
    o_prhs[2] = prhs[3];
    unsafe_stop_primitive_mexFunction(nlhs, plhs, nrhs - 1, o_prhs);
    break;
  case 20:
    p_prhs[0] = prhs[1];
    p_prhs[1] = prhs[2];
    unsafe_stop_primitive_j0_mexFunction(nlhs, plhs, nrhs - 1, p_prhs);
    break;
  case 21:
    q_prhs[0] = prhs[1];
    q_prhs[1] = prhs[2];
    unsafe_time_min_vel_pass_mexFunction(nlhs, plhs, nrhs - 1, q_prhs);
    break;
  case 22:
    for (i6 = 0; i6 < 6; i6++) {
      y_prhs[i6] = prhs[i6 + 1];
    }
    unsafe_total_cost_mexFunction(nlhs, plhs, nrhs - 1, y_prhs);
    break;
  case 23:
    r_prhs[0] = prhs[1];
    r_prhs[1] = prhs[2];
    unsafe_v_from_coeffs_mexFunction(nlhs, plhs, nrhs - 1, r_prhs);
    break;
  case 24:
    for (i7 = 0; i7 < 7; i7++) {
      ab_prhs[i7] = prhs[i7 + 1];
    }
    unsafe_v_opt_mexFunction(nlhs, plhs, nrhs - 1, ab_prhs);
    break;
  }
  /* Module termination. */
  primitives_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_a_from_coeffs_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                      int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "a_from_coeffs");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "a_from_coeffs");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  a_from_coeffs_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_a_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs;
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        5, "a_opt");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "a_opt");
  }
  /* Call the function. */
  for (i = 0; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  a_opt_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_coef_list_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[6];
  const mxArray *outputs;
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        9, "coef_list");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "coef_list");
  }
  /* Call the function. */
  for (i = 0; i < 6; i++) {
    b_prhs[i] = prhs[i];
  }
  coef_list_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_pos_j0_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                         int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        16, "final_opt_pos_j0");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "final_opt_pos_j0");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  final_opt_pos_j0_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_time_j0_1_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        19, "final_opt_time_j0_1");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "final_opt_time_j0_1");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  final_opt_time_j0_1_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_time_j0_2_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        19, "final_opt_time_j0_2");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "final_opt_time_j0_2");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  final_opt_time_j0_2_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_time_j0_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        17, "final_opt_time_j0");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "final_opt_time_j0");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  final_opt_time_j0_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_time_pass_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[4];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        19, "final_opt_time_pass");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "final_opt_time_pass");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  b_prhs[3] = prhs[3];
  final_opt_time_pass_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_time_stop_j0_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                               int32_T nrhs,
                                               const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        22, "final_opt_time_stop_j0");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "final_opt_time_stop_j0");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  final_opt_time_stop_j0_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_time_stop_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        19, "final_opt_time_stop");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "final_opt_time_stop");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  final_opt_time_stop_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_vel_j0_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                         int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[4];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        16, "final_opt_vel_j0");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "final_opt_vel_j0");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  b_prhs[3] = prhs[3];
  final_opt_vel_j0_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_final_opt_vel_pass_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[4];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        18, "final_opt_vel_pass");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "final_opt_vel_pass");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  b_prhs[3] = prhs[3];
  final_opt_vel_pass_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_j_from_coeffs_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                      int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "j_from_coeffs");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "j_from_coeffs");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  j_from_coeffs_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_j_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs;
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        5, "j_opt");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "j_opt");
  }
  /* Call the function. */
  for (i = 0; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  j_opt_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_min_vel_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        7, "min_vel");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "min_vel");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  min_vel_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_pass_primitive_j0_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                          int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[5];
  const mxArray *outputs[3];
  int32_T i;
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        17, "pass_primitive_j0");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "pass_primitive_j0");
  }
  /* Call the function. */
  for (i = 0; i < 5; i++) {
    b_prhs[i] = prhs[i];
  }
  pass_primitive_j0_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

void unsafe_pass_primitive_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                       int32_T nrhs, const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs[6];
  int32_T i;
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        14, "pass_primitive");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "pass_primitive");
  }
  /* Call the function. */
  for (i = 0; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  pass_primitive_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

void unsafe_s_from_coeffs_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                      int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "s_from_coeffs");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "s_from_coeffs");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  s_from_coeffs_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_s_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs;
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        5, "s_opt");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "s_opt");
  }
  /* Call the function. */
  for (i = 0; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  s_opt_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_stop_primitive_j0_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                          int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  const mxArray *b_prhs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        17, "stop_primitive_j0");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "stop_primitive_j0");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  stop_primitive_j0_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void unsafe_stop_primitive_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                       int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[3];
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        14, "stop_primitive");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "stop_primitive");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  stop_primitive_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void unsafe_time_min_vel_pass_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        17, "time_min_vel_pass");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "time_min_vel_pass");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  time_min_vel_pass_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_total_cost_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[6];
  const mxArray *outputs;
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        10, "total_cost");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "total_cost");
  }
  /* Call the function. */
  for (i = 0; i < 6; i++) {
    b_prhs[i] = prhs[i];
  }
  total_cost_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_v_from_coeffs_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                      int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "v_from_coeffs");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "v_from_coeffs");
  }
  /* Call the function. */
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  v_from_coeffs_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_v_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs;
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        5, "v_opt");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "v_opt");
  }
  /* Call the function. */
  for (i = 0; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  v_opt_api(b_prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_primitives_mex.c) */
