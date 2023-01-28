/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_types.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jan 27 14:21:57 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_types_h_
#define RTW_HEADER_untitled_types_h_
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

#ifndef typedef_codertarget_raspi_internal_CA_T
#define typedef_codertarget_raspi_internal_CA_T

typedef struct tag_VWsHpLnzr3Sj7pOoaPHLtE codertarget_raspi_internal_CA_T;

#endif                             /* typedef_codertarget_raspi_internal_CA_T */

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

#ifndef typedef_emxArray_char_T_untitled_T
#define typedef_emxArray_char_T_untitled_T

typedef struct emxArray_char_T emxArray_char_T_untitled_T;

#endif                                 /* typedef_emxArray_char_T_untitled_T */

/* Parameters (default storage) */
typedef struct P_untitled_T_ P_untitled_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_untitled_T RT_MODEL_untitled_T;

#endif                                 /* RTW_HEADER_untitled_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */