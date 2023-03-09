/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle_dyno.h
 *
 * Code generated for Simulink model 'Throttle_dyno'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  7 17:16:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Throttle_dyno_h_
#define RTW_HEADER_Throttle_dyno_h_
#ifndef Throttle_dyno_COMMON_INCLUDES_
#define Throttle_dyno_COMMON_INCLUDES_
#include <math.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "MW_SocketCAN.h"
#endif                                 /* Throttle_dyno_COMMON_INCLUDES_ */

#include "Throttle_dyno_types.h"
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
  char_T ReadBuff[1024];
  char_T cmd[226];
  char_T cmd_data[224];
  char_T errString1[63];
  char_T errString2[52];
  char_T patVal[42];
  char_T patVal_m[25];
  linuxCANMsg CANReceive_o1;           /* '<Root>/CAN Receive' */
  CAN_MESSAGE_BUS CANPack;             /* '<Root>/CAN Pack' */
  char_T errString3[20];
  char_T errString0[17];
  FILE* a;
  char_T bitRate[8];
  FILE* filestar;
  char* cOut;
  FILE* b_NULL;
  FILE* filestar_c;
  int b_st;
  int wherefrom;
  real_T CANUnpack_o1;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o4;                 /* '<Root>/CAN Unpack' */
  real_T Divide2;                      /* '<Root>/Divide2' */
  real_T Load;                         /* '<Root>/Chart' */
  real_T Throttle;                     /* '<Root>/Chart' */
  char_T canInterface[5];
  int32_T i;
  int32_T stat1;
  int32_T stat2;
  int32_T len;
  int32_T j;
  int32_T reachedEndOfFile;
  int32_T idx;
  int32_T carriageReturnAt;
  boolean_T Load_Enable;               /* '<Root>/Chart' */
} B_Throttle_dyno_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_CA_T obj; /* '<Root>/CAN Receive' */
  codertarget_raspi_internal__k_T obj_j;/* '<Root>/CAN Transmit' */
  real_T Count;                        /* '<Root>/Chart' */
  real_T Enable_start;                 /* '<Root>/Chart' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_c3_Throttle_dyno;         /* '<Root>/Chart' */
  uint8_T is_Enabled;                  /* '<Root>/Chart' */
  uint8_T is_Throttle_Setting;         /* '<Root>/Chart' */
  uint8_T is_active_c3_Throttle_dyno;  /* '<Root>/Chart' */
  FILE* eml_openfiles[20];             /* '<Root>/CAN Transmit' */
} DW_Throttle_dyno_T;

/* Parameters (default storage) */
struct P_Throttle_dyno_T_ {
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
  real_T Constant_Value;               /* Expression: 2000
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Throttle_dyno_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Throttle_dyno_T Throttle_dyno_P;

/* Block signals (default storage) */
extern B_Throttle_dyno_T Throttle_dyno_B;

/* Block states (default storage) */
extern DW_Throttle_dyno_T Throttle_dyno_DW;

/* Model entry point functions */
extern void Throttle_dyno_initialize(void);
extern void Throttle_dyno_step(void);
extern void Throttle_dyno_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Throttle_dyno_T *const Throttle_dyno_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant8' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
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
 * '<Root>' : 'Throttle_dyno'
 * '<S1>'   : 'Throttle_dyno/Chart'
 */
#endif                                 /* RTW_HEADER_Throttle_dyno_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
