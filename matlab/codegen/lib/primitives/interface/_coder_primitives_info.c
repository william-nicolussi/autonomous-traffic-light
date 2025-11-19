/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_primitives_info.c
 *
 * Code generation for function 'a_from_coeffs'
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
  const char_T *data[8] = {
      "789ced59cd6ed34010dea0f2d3032580ca8d2be24215d31f52240ea549da404243e39614"
      "8c5cd75927abdabbae7763b539227103c11509de0089032fd0231217"
      "1e8007e031481c3b890dab04b97593e0b96cc69fd7dfccd8f93cde05897c31010098011d"
      "7b7fbb335e76fda43b9e037e0be20977bc18f03d3b0fa67cf33cfc9d",
      "3baa043378c83a0e560cd89d592506c20a66e29109810529d16d5875100de95044062cf7"
      "3b4fda9e91eb83ba4e1b6aff5ead4375bfdc308055a7bd08f57ea75b"
      "8f634ebe5343d643e6d42319c05f645faede97b628b4a8b45e923290ee33624a5b188958"
      "ca6faf6424a5c1082606695099598aa62155d651adceee180ac292a1",
      "305dd993286b542166b2a9502a9b16321043369c33baf91c86cce7fa807c3c5c6bdd335d"
      "26269359abf24e3cce712f8edd90715ce0c6d141aaa4b1a7c31edf8f"
      "907c84cbe7c74fe83e6a0dac32443095e1a1492c06abd25f2ada775f7739f15f1932bfe0"
      "d83bff9233a29d9f0e1415df87d9994f51f27976567c61ff9737387c",
      "c9005ed1d2505bca29472bd6c186b891ae2d14f60a6bbd384a037806c501387e54d73fe6"
      "ccff5ff5faea807c3cdcd194d68b56b6a1de53ebf1d56b83cbe7c74f"
      "4fafffa8e85c9b7352f53af1ea41acd760f8e77396c3970ce0aab9609b76b5b6be56110e"
      "f26aa9b9a9a32688f57a54f57a37643ebcefa7a48bb8827266bafc2d",
      "249fcae5f3e3a7a7cb6e05e73a6f8049d5e3c29742acc7e0e4fb67bbb6bf2d6cab2b8b58"
      "78582b16cbc6d3626a271bebf1a8ea71d8e7e2da807c3cbcf775ee6f"
      "a0c7b57fc65c3e3f1ec57a477f033da97afdfae6af8f51f27936ae7a3d6cff6cd94b76a5"
      "744fb132daa3a3542eff7c51582b8158af4755afcd90f94c0fc8c7c3",
      "5502b5567cd4dd7118db7e1a067c1038cfc34f4fa7bb958c747de3b318ad3ebf9585e928"
      "f93c1b577d1e7a3d7a79395d6f0a295bb415156d662bf98cf06c35d6"
      "e733d667da9a3c4afb87ed789ce3e3da4f8fdcfe61bba211ee1f4a11f7d35fbfbfb91525"
      "9f6793aed7f471b9b47c379bcda4b672e97571715e5b986f6662bd1e",
      "55bd8efbe97fe38bfbe968f8e27eba63713f3ddcf57f0375b11d41",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 10408U, &nameCaptureInfo);
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
      emlrtCreateStructMatrix(1, 17, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("a_from_coeffs"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\a_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 1, "Name", emlrtMxCreateString("a_opt"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 1, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\a_opt.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 2, "Name", emlrtMxCreateString("coef_list"));
  emlrtSetField(xEntryPoints, 2, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 2, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 2, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 2, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\coef_list.m"));
  emlrtSetField(xEntryPoints, 2, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 2, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 2, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 3, "Name",
                emlrtMxCreateString("final_opt_time_pass"));
  emlrtSetField(xEntryPoints, 3, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 3, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 3, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 3, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_pass.m"));
  emlrtSetField(xEntryPoints, 3, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.68871527782));
  emlrtSetField(xEntryPoints, 3, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 3, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 4, "Name",
                emlrtMxCreateString("final_opt_time_stop"));
  emlrtSetField(xEntryPoints, 4, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 4, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 4, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 4, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_stop.m"));
  emlrtSetField(xEntryPoints, 4, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.62179398153));
  emlrtSetField(xEntryPoints, 4, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 4, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 5, "Name",
                emlrtMxCreateString("final_opt_vel_pass"));
  emlrtSetField(xEntryPoints, 5, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 5, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 5, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 5, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_vel_pass.m"));
  emlrtSetField(xEntryPoints, 5, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.68871527782));
  emlrtSetField(xEntryPoints, 5, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 5, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 6, "Name", emlrtMxCreateString("j_from_coeffs"));
  emlrtSetField(xEntryPoints, 6, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 6, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 6, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 6, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\j_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 6, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 6, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 6, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 7, "Name", emlrtMxCreateString("j_opt"));
  emlrtSetField(xEntryPoints, 7, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 7, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 7, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 7, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\j_opt.m"));
  emlrtSetField(xEntryPoints, 7, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 7, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 7, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 8, "Name", emlrtMxCreateString("min_vel"));
  emlrtSetField(xEntryPoints, 8, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 8, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 8, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 8, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\min_vel.m"));
  emlrtSetField(xEntryPoints, 8, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.68871527782));
  emlrtSetField(xEntryPoints, 8, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 8, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 9, "Name", emlrtMxCreateString("s_from_coeffs"));
  emlrtSetField(xEntryPoints, 9, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 9, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 9, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 9, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\s_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 9, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 9, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 9, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 10, "Name", emlrtMxCreateString("s_opt"));
  emlrtSetField(xEntryPoints, 10, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 10, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 10, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 10, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\s_opt.m"));
  emlrtSetField(xEntryPoints, 10, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 10, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 10, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 11, "Name",
                emlrtMxCreateString("student_pass_primitive"));
  emlrtSetField(xEntryPoints, 11, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 11, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 11, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 11, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\student_pass_primitive.m"));
  emlrtSetField(xEntryPoints, 11, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.68806712958));
  emlrtSetField(xEntryPoints, 11, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 11, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 12, "Name",
                emlrtMxCreateString("student_stop_primitive"));
  emlrtSetField(xEntryPoints, 12, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 12, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 12, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 12, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\student_stop_primitive.m"));
  emlrtSetField(xEntryPoints, 12, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.63107638888));
  emlrtSetField(xEntryPoints, 12, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 12, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 13, "Name",
                emlrtMxCreateString("time_min_vel_pass"));
  emlrtSetField(xEntryPoints, 13, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 13, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 13, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 13, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\time_min_vel_pass.m"));
  emlrtSetField(xEntryPoints, 13, "TimeStamp",
                emlrtMxCreateDoubleScalar(739940.68871527782));
  emlrtSetField(xEntryPoints, 13, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 13, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 14, "Name",
                emlrtMxCreateString("total_cost_var"));
  emlrtSetField(xEntryPoints, 14, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 14, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 14, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 14, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\total_cost_var.m"));
  emlrtSetField(xEntryPoints, 14, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65599537035));
  emlrtSetField(xEntryPoints, 14, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 14, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 15, "Name", emlrtMxCreateString("v_from_coeffs"));
  emlrtSetField(xEntryPoints, 15, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 15, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 15, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 15, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\v_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 15, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 15, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 15, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 16, "Name", emlrtMxCreateString("v_opt"));
  emlrtSetField(xEntryPoints, 16, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 16, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 16, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 16, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\v_opt.m"));
  emlrtSetField(xEntryPoints, 16, "TimeStamp",
                emlrtMxCreateDoubleScalar(739934.65598379634));
  emlrtSetField(xEntryPoints, 16, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 16, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.1.0.2603908 (R2024a) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("Ks3DJaSmaee0qV6BzZvYTF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_primitives_info.c) */
