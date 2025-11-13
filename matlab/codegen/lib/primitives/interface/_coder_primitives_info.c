/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_info.c
 *
 * Code generation for function 'coef_list'
 *
 */

/* Include files */
#include "_coder_primitives_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ced58cd6ed34010dea082e0008d40e2d6470009a9aa801b6a7e9c282d45b5130246ae"
      "63af9b25f6aeeb5da72e120724ae880be25a891b37c413549c38f200"
      "bc040f8044ec649dc4c24a90619306cf6532fb79fdcdcc2a9fc60b0ab59d0200e01a18da"
      "dec6d05f1dc5c591bf00a62d891746fe622206f1fadad43e8ebf1d79",
      "83600603360cb0eec078a7491c8475cce41317020f5262f7a1192116b2a18c1cb83f19ec"
      "8691539980e22084c2dfdb5d68f4f67d07785d3aced09e0ce27e9ca5"
      "d4bb36673fb4947e1413f8d3f2b3edfbaa42a14755694f2d41da63c455158c64acd69a0f"
      "4aaaee338289437caa314fb72c6468363aecb25b8e8eb0eae8ccd63b",
      "2a65be0931d35c9d52cdf5908318eac3db4e5c4f90b19e1b33eae1b83538335b232ed3d8"
      "a0f3513ed13acfe320631e9752f3182226f13b361cf37dcbc84752f9"
      "a6f1bf748e968f0d8608a61a0c5ce23168aabfe9e8c4b91ea4e4bf3e677d493f7efe72e4"
      "dfc9df234814dfe997f71f44f2715b145fd6ffe5cd14be6202373d45",
      "a93edad29b4dbf51a9378e1edea977e4ea84fecfe0999507488945bdff2c65ffffaad7d7"
      "67d4c3f1b1baf4a13d96eb73abd738956f1a17a1d7bca383635d59bd"
      "66f8f5a9483e6eabaed7bbdeb17b97dc335b3549ea059be5f6a1bfb923e57abdac7aed66"
      "ace7ca8c7a386e10680df2a3a32fa685e9f4d78c7c301183c4731cff",
      "773a1d77329467617af2b324569f3fbff9f14a241fb755d7e76a503ef63cd34552fbe845"
      "4b69187d7cf2bc9cebf382f5990e362fd3fd47984fb47e5ee7e9a5bb"
      "ff083b2af0fe63bd2c56af5f7e523e8ae4e3b6ea7a2db71fd7d856c7eab7d8939e6fd625"
      "bb6505955caf9755aff379facff8f2795a0c5f3e4f0f2d9fa7e77bff",
      "2f032f50f2",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 7528U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 3, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("coef_list"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\coef_list.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739914.74133101851));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 1, "Name",
                emlrtMxCreateString("student_pass_primitive"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 1, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\student_pass_primitive.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.54725694447));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 2, "Name",
                emlrtMxCreateString("student_stop_primitive"));
  emlrtSetField(xEntryPoints, 2, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 2, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 2, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 2, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\student_stop_primitive.m"));
  emlrtSetField(xEntryPoints, 2, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.53146990738));
  emlrtSetField(xEntryPoints, 2, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 2, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.1.0.2603908 (R2024a) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("HRAalHqYO0FgbfIi6d2BPG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_primitives_info.c) */
