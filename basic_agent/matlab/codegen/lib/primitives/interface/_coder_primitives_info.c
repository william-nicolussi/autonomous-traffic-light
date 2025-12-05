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
  const char_T *data[11] = {
      "789ced9bbf73e24614c7e5cce5577117924cee8a94299378c0870f2e9d11602036061b0e"
      "4c941102ad8e455a49a71f605ca448755dfe814cf20f64266dbad064"
      "26336952a6489b9914e992363301840029de018f4020795fb35e1eabef7b4fe6e3d55b4c"
      "ede54ff7288a7a404dad640df7a7d3c8747c85729adbbf371d1fb8e6",
      "b6bd4add73acb3fd5f4dc7b6221be0cab0263287c06c25af202873b25119a880d280ae48"
      "3dc04f3c029440052270b138298e6728bbe09a4dc6aef1cf7407b4c5"
      "0b13515a479f47282d4e6679fc80c9f7de8af5a861ea1171f93fcb7c4e7fc25475a0e94c"
      "aec4a4812e1a8aca5465589199fcb3a334c39986222b483175d6d038",
      "41806d5682cf3bc6c7888332833843e25a8ccae93aab6a104103f6c03e9ae571e5318f77"
      "97e461fb85d1bd9258453558635471761ccfe4753b8ea6c7385ec3c6"
      "617978c56c4960aef7ab473d05abe7f4afe9fe09a6dc36a022eb2cb85215cd003c734345"
      "17ee6b1313ff5b2be6e71ee7ef7f6332fed1fa7de2f24baf51bc9ff1",
      "53cfb66de979fd5c3ec4e8455c7e3a533a6ea16c1c3c16eb973d78289d697a2a338fa3b4"
      "4467591c1466eed7f509a72d7b7b491eb67fc292d11f56b607a439a5"
      "83cb6984d573fa37c7e9ff55747fac19564e7ff7f74784d3d4fa39cd27a4b37a3d536a1c"
      "c9b1d3f8612b6bca623c4d38bd6b9c6e7acce3756c1e96670a92adf1",
      "f8678f7a6dac9ed3bf391e4f2bb86f913fac1c4ebdff9470985a3f872bc7f99e201a65a1"
      "74ae6ad7ad4c3f23461b34e1f0ae71d8ebefc33b4bf2b0fdf3a770e7"
      "8639a8fb6519abe7f4fbd1d758dc308795d37f7ef057da4f3ddbc2ce69a577f26935971d"
      "3cad3dbbe469eee44446864e38bd739c563de6f1e6923c6c7f5b01c2",
      "282e7d7a9210d8fd3370cd29d7fb6cffe6f83cab64a8fb18f09b9f9ef8a9675b50b9fc1e"
      "462fe2f2974d58a62b877477f0e24501c50eea62b26652e1e1f210b3"
      "7ed53a3630d78fb8fc1be132db8d4e1f8bb77d3ed88db231471c4d8f71dcf9f3c1714543"
      "7c3ef8adf163c14f3ddb82caeb55f7d14faecfd26728d18785ca09cc",
      "c6aa62b1185743743e38c4ac0f2aafbdeea771f58bb846e7537a371a544e4b583da7dfaf"
      "7e877d47c3cae9fccbaff37eead916764e77cd8e28d6f5d3925840d0"
      "04d1d4b941d742743e38c4acbfab9c267d0fe7fb48df633d7aa4ef6119e97bdceefa43cc"
      "faa0f2797b7d8f03471c4d8f7190bec7a8a221ee7b7c28fe42fa1ed4",
      "faf7d3a8719da6e59c7a9d8d27f39d64aa30908110a2fd74c0ce0ff5d1a25dfaff95713c"
      "93d709a7d7c4e9714543cce9efcd97453ff56c0b2aa757dd573f8f49"
      "fd785ccf95db895c2279c5cb666650a408a7778dd3a4df713b3dd2eff0478ff43b2c23fd"
      "8edb5d7f8859bfa3fd0e279737d0ef58f5b9ea865ddf289aed71fa37",
      "8f7a1a56cfe9f7751f7dc3fd6d62f2082ab7bffce2d1859f7ab60595dbab7e3e07e53e7f"
      "c8f7b8c2e56982178f92a54bbd2c1c136eef2ab7bdeeab71f58bb8c6"
      "3965544527dff7580bafad4a86fbfb1effe4ff3df753cfb6b073ba5a2fd652c5d8e32374"
      "3c88f51322940edaf910f5a78798f57795d3a4ffe17c1fe97fac478f",
      "f43f2c23fd8fd5aeff1f2a12ffb9",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 20504U, &nameCaptureInfo);
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
      emlrtCreateStructMatrix(1, 25, 8, (const char_T **)&epFieldName[0]);
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
                emlrtMxCreateDoubleScalar(739952.7563773148));
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
                emlrtMxCreateDoubleScalar(739952.7563773148));
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
                emlrtMxCreateDoubleScalar(739952.75638888893));
  emlrtSetField(xEntryPoints, 2, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 2, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 3, "Name",
                emlrtMxCreateString("final_opt_pos_j0"));
  emlrtSetField(xEntryPoints, 3, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 3, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 3, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 3, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_pos_j0.m"));
  emlrtSetField(xEntryPoints, 3, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75693287037));
  emlrtSetField(xEntryPoints, 3, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 3, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 4, "Name",
                emlrtMxCreateString("final_opt_time_j0"));
  emlrtSetField(xEntryPoints, 4, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 4, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 4, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 4, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_j0.m"));
  emlrtSetField(xEntryPoints, 4, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75677083328));
  emlrtSetField(xEntryPoints, 4, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 4, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 5, "Name",
                emlrtMxCreateString("final_opt_time_j0_1"));
  emlrtSetField(xEntryPoints, 5, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 5, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 5, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 5, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_j0_1.m"));
  emlrtSetField(xEntryPoints, 5, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75677083328));
  emlrtSetField(xEntryPoints, 5, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 5, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 6, "Name",
                emlrtMxCreateString("final_opt_time_j0_2"));
  emlrtSetField(xEntryPoints, 6, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 6, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 6, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 6, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_j0_2.m"));
  emlrtSetField(xEntryPoints, 6, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75677083328));
  emlrtSetField(xEntryPoints, 6, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 6, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 7, "Name",
                emlrtMxCreateString("final_opt_time_pass"));
  emlrtSetField(xEntryPoints, 7, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 7, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 7, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 7, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_pass.m"));
  emlrtSetField(xEntryPoints, 7, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75665509258));
  emlrtSetField(xEntryPoints, 7, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 7, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 8, "Name",
                emlrtMxCreateString("final_opt_time_stop"));
  emlrtSetField(xEntryPoints, 8, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 8, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 8, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 8, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_stop.m"));
  emlrtSetField(xEntryPoints, 8, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75684027781));
  emlrtSetField(xEntryPoints, 8, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 8, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 9, "Name",
                emlrtMxCreateString("final_opt_time_stop_j0"));
  emlrtSetField(xEntryPoints, 9, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 9, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 9, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 9, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_time_stop_j0.m"));
  emlrtSetField(xEntryPoints, 9, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75693287037));
  emlrtSetField(xEntryPoints, 9, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 9, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 10, "Name",
                emlrtMxCreateString("final_opt_vel_j0"));
  emlrtSetField(xEntryPoints, 10, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 10, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 10, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 10, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_vel_j0.m"));
  emlrtSetField(xEntryPoints, 10, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75674768514));
  emlrtSetField(xEntryPoints, 10, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 10, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 11, "Name",
                emlrtMxCreateString("final_opt_vel_pass"));
  emlrtSetField(xEntryPoints, 11, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 11, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 11, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 11, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\final_opt_vel_pass.m"));
  emlrtSetField(xEntryPoints, 11, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75665509258));
  emlrtSetField(xEntryPoints, 11, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 11, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 12, "Name", emlrtMxCreateString("j_from_coeffs"));
  emlrtSetField(xEntryPoints, 12, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 12, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 12, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 12, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\j_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 12, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.7563773148));
  emlrtSetField(xEntryPoints, 12, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 12, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 13, "Name", emlrtMxCreateString("j_opt"));
  emlrtSetField(xEntryPoints, 13, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 13, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 13, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 13, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\j_opt.m"));
  emlrtSetField(xEntryPoints, 13, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.7563773148));
  emlrtSetField(xEntryPoints, 13, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 13, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 14, "Name", emlrtMxCreateString("min_vel"));
  emlrtSetField(xEntryPoints, 14, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 14, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 14, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 14, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\min_vel.m"));
  emlrtSetField(xEntryPoints, 14, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75666666671));
  emlrtSetField(xEntryPoints, 14, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 14, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 15, "Name",
                emlrtMxCreateString("pass_primitive"));
  emlrtSetField(xEntryPoints, 15, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 15, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 15, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 15, "FullPath",
      emlrtMxCreateString("C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_"
                          "traffic_light-main\\matlab\\pass_primitive.m"));
  emlrtSetField(xEntryPoints, 15, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.73694444448));
  emlrtSetField(xEntryPoints, 15, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 15, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 16, "Name",
                emlrtMxCreateString("pass_primitive_j0"));
  emlrtSetField(xEntryPoints, 16, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 16, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 16, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 16, "FullPath",
      emlrtMxCreateString("C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_"
                          "traffic_light-main\\matlab\\pass_primitive_j0.m"));
  emlrtSetField(xEntryPoints, 16, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75322916661));
  emlrtSetField(xEntryPoints, 16, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 16, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 17, "Name", emlrtMxCreateString("s_from_coeffs"));
  emlrtSetField(xEntryPoints, 17, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 17, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 17, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 17, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\s_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 17, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.7563773148));
  emlrtSetField(xEntryPoints, 17, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 17, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 18, "Name", emlrtMxCreateString("s_opt"));
  emlrtSetField(xEntryPoints, 18, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 18, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 18, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 18, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\s_opt.m"));
  emlrtSetField(xEntryPoints, 18, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75636574079));
  emlrtSetField(xEntryPoints, 18, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 18, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 19, "Name",
                emlrtMxCreateString("stop_primitive"));
  emlrtSetField(xEntryPoints, 19, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 19, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 19, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 19, "FullPath",
      emlrtMxCreateString("C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_"
                          "traffic_light-main\\matlab\\stop_primitive.m"));
  emlrtSetField(xEntryPoints, 19, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.72556712967));
  emlrtSetField(xEntryPoints, 19, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 19, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 20, "Name",
                emlrtMxCreateString("stop_primitive_j0"));
  emlrtSetField(xEntryPoints, 20, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 20, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 20, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 20, "FullPath",
      emlrtMxCreateString("C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_"
                          "traffic_light-main\\matlab\\stop_primitive_j0.m"));
  emlrtSetField(xEntryPoints, 20, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.76396990742));
  emlrtSetField(xEntryPoints, 20, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 20, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 21, "Name",
                emlrtMxCreateString("time_min_vel_pass"));
  emlrtSetField(xEntryPoints, 21, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 21, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 21, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 21, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\matlab\\functions_exported\\time_min_vel_pass.m"));
  emlrtSetField(xEntryPoints, 21, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75666666671));
  emlrtSetField(xEntryPoints, 21, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 21, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 22, "Name", emlrtMxCreateString("total_cost"));
  emlrtSetField(xEntryPoints, 22, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 22, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 22, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 22, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\total_cost.m"));
  emlrtSetField(xEntryPoints, 22, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75638888893));
  emlrtSetField(xEntryPoints, 22, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 22, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 23, "Name", emlrtMxCreateString("v_from_coeffs"));
  emlrtSetField(xEntryPoints, 23, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 23, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 23, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 23, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\v_from_coeffs.m"));
  emlrtSetField(xEntryPoints, 23, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.7563773148));
  emlrtSetField(xEntryPoints, 23, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 23, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 24, "Name", emlrtMxCreateString("v_opt"));
  emlrtSetField(xEntryPoints, 24, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 24, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 24, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 24, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\matlab\\functions_exported\\v_opt.m"));
  emlrtSetField(xEntryPoints, 24, "TimeStamp",
                emlrtMxCreateDoubleScalar(739952.75636574079));
  emlrtSetField(xEntryPoints, 24, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 24, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.1.0.2603908 (R2024a) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("WBcPt17zaolVz06ffvIYBH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_primitives_info.c) */
