/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  7 18:12:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "MW_SocketCAN.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  char_T errString1[63];
  char_T errString1_m[63];
  char_T errString2[52];
  char_T errString2_c[52];
  linuxCANMsg CANReceive_o1;           /* '<Root>/CAN Receive' */
  CAN_MESSAGE_BUS CANPack;             /* '<Root>/CAN Pack' */
  real_T CANUnpack_o1;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o4;                 /* '<Root>/CAN Unpack' */
  real_T Divide2;                      /* '<Root>/Divide2' */
  real_T Load;                         /* '<Root>/Chart' */
  real_T Throttle;                     /* '<Root>/Chart' */
  boolean_T Load_Enable;               /* '<Root>/Chart' */
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_CA_T obj; /* '<Root>/CAN Receive' */
  codertarget_raspi_internal__b_T obj_g;/* '<Root>/CAN Transmit' */
  real_T Count;                        /* '<Root>/Chart' */
  real_T Enable_start;                 /* '<Root>/Chart' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_c3_untitled;              /* '<Root>/Chart' */
  uint8_T is_Enabled;                  /* '<Root>/Chart' */
  uint8_T is_Throttle_Setting;         /* '<Root>/Chart' */
  uint8_T is_active_c3_untitled;       /* '<Root>/Chart' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T CANReceive_SampleTime;        /* Expression: -1
                                        * Referenced by: '<Root>/CAN Receive'
                                        */
  real_T Constant4_Value;              /* Expression: 12
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 1600
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 500
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 26000
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 2500
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant9_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant_Value;               /* Expression: 234
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant8' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<Root>/Display5' : Unused code path elimination
 * Block '<Root>/Divide' : Unused code path elimination
 * Block '<Root>/Divide1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Chart'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
