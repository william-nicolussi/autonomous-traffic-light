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
  const char_T *data[10] = {
      "789ced9b4d6fe34418c75db4bc1d760920e0c091232f4abae926cbad719226a14d9336d9"
      "a6c5c871e27133b1c77633e3bc21ed81d3def80208be00121f811312"
      "12178e1c387041e2c00dae48e4cd49eded28593971626b9ecb74fc38f39f67a6fef5f133"
      "29b7973fd9e338ee0137b55679dade9ff523b3f625ce696effdeac7d",
      "e0eadbf63277cff139dbfff5ac6d1a3a017d32ede81202f34fca0682baa493cac0045c07"
      "6043eb0279e251a0062a1081f3db9de2b887b2b75cf3ced835fe996f"
      "81a67a6e21aed3c28b196ab73bf3387ea6c47b6fc5f56852d623e2f27f9ef982ff54a862"
      "d0c142ae24a4015689610a551d567421ffe4302d4816317403191616",
      "49475214d8143578dd221f2309ea4243c2a30bd235d0898024a2490dc1943016cd0e4490"
      "c02ef80439e2ea7b8cebed2571d97e65b4779a68984424a31d10c773"
      "72cca3ee711eaf50e731f5c886d5d0c042ef0f8f7a5f52f59cfe0deca762e94d020d1d8b"
      "a06f1a1d0264e18ed575ed739d12cf1b2bc6eb6e17f7bf3669ff6cfc",
      "bee7a7de55f17ec64f3ddbb6a5e7f5397d97a21771f9f94ce9a881b271f050ad5d76e181"
      "76dac1a9cc621ea5253acbe6c151fa7e8dcf387e775c6f2e89cbf64f"
      "f832fa432c7681b6a07870393ea0ea39fdfe70fcb9d59ded727839fefd3f1f318e73ebe7"
      "b89cd04e6bb54ce9ea508f9dc40f1a594b57e369c6f15de778dd635c",
      "af52e39a7a6670d91aaf7ff5a86750f59c7e7f783d5bcdd11e8695cfa9f71f333e73ebe7"
      "73e528df555452564a676667d8c8f4326af48a677cde753e7bfdfd78"
      "6b495cb67ff146ef4cb4839a670fa97a4ebfdff51277a21d568efff5c1df693ff56c0b3b"
      "c78deef167d55c76f0f8e2c9a5cc4bc7c73a2298717ce7396e7a8ceb",
      "f52571d9fea60194d13cf1ec44636bfcfecda3de0d55cfe9f787dff3550d7d7d047efbd3"
      "233ff56c0b2ab7dfa1e8455cfeb205cb7ce5806f0f6e6e0a28b65f53"
      "931716c7b86d8fa750c68fb8fc1be7b6d88e8e1ff22d9f57b6a3626c723da8f9f74e9f57"
      "8e5737e4e795df911f0b7eead916548eaf9a7f3f1a9ea64f51a2070b",
      "9563988d55d562316eb2f3ca9de7b8d7fc9bb68e1157eb7cd36f47839a7ff75d7dce759f"
      "eddf46fd64bcb361e576fed937793ff56c0b3bb7db564b556bf8a4a4"
      "1610b440347546f80b763e197a6eb3ba89f33e5637d98c1eab9b4c8dd54d5e6cfcb0727b"
      "7b7593fdc9755637d94cdd643fe475930fd55f58dd845b7ffe8dae86",
      "695ecf99c36c3c996f255385810e14967fcfc7dbe2b9251e0db06bffaf339e93631e758f"
      "f3601c77ad6ec839fe83f5ace8a79e6d41e5f8aaf9f8754cebc5e338"
      "576e267289645fd6adcca0c8318eef3ac7591de5c5f4581d85d551fcd0637594f58c1fe0"
      "3a8a93db6baea3acfa7e764786389a4970f3efa7543da77f6bf9b76b",
      "9feb947882caf1af9ebe77eea79e6d41e5f8aacfe9a0dc930fe4ae54b83c49c8ea61b274"
      "89cbca11e3f8ae73dc6bfe4d5bc788ab5d90c63430fbfec9daf93d5d"
      "d5f07effe4dffc7f677eead916766e576bc58b5431f6f0101d0d62bd840ab5fd669ed5bf"
      "43cf6d563771dec7ea269bd1637593a9b1bac96ae3ff0ffa5e8a89",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 20864U, &nameCaptureInfo);
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
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\a_from_coeffs.m"));
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
  emlrtSetField(
      xEntryPoints, 1, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\a_opt.m"));
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
  emlrtSetField(
      xEntryPoints, 2, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\coef_list.m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_pos_j0.m"));
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
      emlrtMxCreateString("C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_"
                          "traffic_light-main\\basic_agent\\matlab\\functions_"
                          "exported\\final_opt_time_j0.m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_time_j0_1"
          ".m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_time_j0_2"
          ".m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_time_pass"
          ".m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_time_stop"
          ".m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_time_stop"
          "_j0.m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_vel_j0.m"));
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
          "main\\basic_agent\\matlab\\functions_exported\\final_opt_vel_pass."
          "m"));
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
  emlrtSetField(
      xEntryPoints, 12, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\j_from_coeffs.m"));
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
  emlrtSetField(
      xEntryPoints, 13, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\j_opt.m"));
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
  emlrtSetField(
      xEntryPoints, 14, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\min_vel.m"));
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
  emlrtSetField(xEntryPoints, 15, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\basic_agent\\matlab\\pass_primitive.m"));
  emlrtSetField(xEntryPoints, 15, "TimeStamp",
                emlrtMxCreateDoubleScalar(739957.49321759259));
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
  emlrtSetField(xEntryPoints, 16, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\basic_agent\\matlab\\pass_primitive_j0.m"));
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
  emlrtSetField(
      xEntryPoints, 17, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\s_from_coeffs.m"));
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
  emlrtSetField(
      xEntryPoints, 18, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\s_opt.m"));
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
  emlrtSetField(xEntryPoints, 19, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\basic_agent\\matlab\\stop_primitive.m"));
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
  emlrtSetField(xEntryPoints, 20, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_"
                    "light-main\\basic_agent\\matlab\\stop_primitive_j0.m"));
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
      emlrtMxCreateString("C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_"
                          "traffic_light-main\\basic_agent\\matlab\\functions_"
                          "exported\\time_min_vel_pass.m"));
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
  emlrtSetField(
      xEntryPoints, 22, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\total_cost.m"));
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
  emlrtSetField(
      xEntryPoints, 23, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\v_from_coeffs.m"));
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
  emlrtSetField(
      xEntryPoints, 24, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\HP\\Desktop\\UniTn\\IVAD\\autonomous_traffic_light-"
          "main\\basic_agent\\matlab\\functions_exported\\v_opt.m"));
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
