/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle_dyno_types.h
 *
 * Code generated for Simulink model 'Throttle_dyno'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar  6 22:40:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Throttle_dyno_types_h_
#define RTW_HEADER_Throttle_dyno_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_linuxCANMsg_
#define DEFINED_TYPEDEF_FOR_linuxCANMsg_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} linuxCANMsg;

#endif

#ifndef struct_tag_MRn9RnGM9y9H1ik1iAfDlE
#define struct_tag_MRn9RnGM9y9H1ik1iAfDlE

struct tag_MRn9RnGM9y9H1ik1iAfDlE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  int32_T sockHandleDataFrames;
  int32_T sockHandleErrorFrames;
  boolean_T Initialized;
};

#endif                                 /* struct_tag_MRn9RnGM9y9H1ik1iAfDlE */

#ifndef typedef_codertarget_raspi_internal_CA_T
#define typedef_codertarget_raspi_internal_CA_T

typedef struct tag_MRn9RnGM9y9H1ik1iAfDlE codertarget_raspi_internal_CA_T;

#endif                             /* typedef_codertarget_raspi_internal_CA_T */

/* Custom Type definition for MATLABSystem: '<Root>/CAN Transmit' */
#include <stdio.h>
#include <stdio.h>
#ifndef struct_tag_VWsHpLnzr3Sj7pOoaPHLtE
#define struct_tag_VWsHpLnzr3Sj7pOoaPHLtE

struct tag_VWsHpLnzr3Sj7pOoaPHLtE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int32_T sockHandleDataFrames;
  int32_T sockHandleErrorFrames;
  boolean_T notFirstStep;
  boolean_T Initialized;
};

#endif                                 /* struct_tag_VWsHpLnzr3Sj7pOoaPHLtE */

#ifndef typedef_codertarget_raspi_internal__k_T
#define typedef_codertarget_raspi_internal__k_T

typedef struct tag_VWsHpLnzr3Sj7pOoaPHLtE codertarget_raspi_internal__k_T;

#endif                             /* typedef_codertarget_raspi_internal__k_T */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_Throttle_dyno_T
#define typedef_emxArray_char_T_Throttle_dyno_T

typedef struct emxArray_char_T emxArray_char_T_Throttle_dyno_T;

#endif                             /* typedef_emxArray_char_T_Throttle_dyno_T */

/* Parameters (default storage) */
typedef struct P_Throttle_dyno_T_ P_Throttle_dyno_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Throttle_dyno_T RT_MODEL_Throttle_dyno_T;

#endif                                 /* RTW_HEADER_Throttle_dyno_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
