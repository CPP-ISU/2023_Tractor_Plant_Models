/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.h
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  7 22:28:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled1_h_
#define RTW_HEADER_untitled1_h_
#ifndef untitled1_COMMON_INCLUDES_
#define untitled1_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "can_message.h"
#include "MW_SocketCAN.h"
#endif                                 /* untitled1_COMMON_INCLUDES_ */

#include "untitled1_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  char_T errString1[63];
  char_T errString1_m[63];
  char_T errString2[52];
  char_T errString2_c[52];
  linuxCANMsg CANReceive_o1;           /* '<Root>/CAN Receive' */
  CAN_MESSAGE_BUS CANPack;             /* '<Root>/CAN Pack' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T Constant7;                    /* '<Root>/Constant7' */
  real_T CANUnpack_o1;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o4;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o5;                 /* '<Root>/CAN Unpack' */
  real_T Constant10;                   /* '<Root>/Constant10' */
  real_T Divide2;                      /* '<Root>/Divide2' */
  real_T Divide3;                      /* '<Root>/Divide3' */
  real_T Load;                         /* '<Root>/Chart' */
  real_T Throttle;                     /* '<Root>/Chart' */
  real_T Speed_Target;                 /* '<Root>/Chart' */
  uint8_T CANUnpack_o6;                /* '<Root>/CAN Unpack' */
  uint8_T CANUnpack_o7;                /* '<Root>/CAN Unpack' */
  uint8_T CANReceive_o2;               /* '<Root>/CAN Receive' */
  boolean_T Load_Enable;               /* '<Root>/Chart' */
} B_untitled1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_CA_T obj; /* '<Root>/CAN Receive' */
  codertarget_raspi_internal__l_T obj_h;/* '<Root>/CAN Transmit' */
  real_T Count;                        /* '<Root>/Chart' */
  real_T Enable_start;                 /* '<Root>/Chart' */
  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  uint32_T is_c3_untitled1;            /* '<Root>/Chart' */
  uint32_T is_Enabled;                 /* '<Root>/Chart' */
  uint32_T is_Throttle_Setting;        /* '<Root>/Chart' */
  uint32_T is_Load_Increase;           /* '<Root>/Chart' */
  uint32_T is_Speed;                   /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint32_T durationCounter_1;          /* '<Root>/Chart' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  uint8_T is_active_c3_untitled1;      /* '<Root>/Chart' */
} DW_untitled1_T;

/* Parameters (default storage) */
struct P_untitled1_T_ {
  real_T CANReceive_SampleTime;        /* Expression: .01
                                        * Referenced by: '<Root>/CAN Receive'
                                        */
  real_T Constant4_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 1700
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: -500
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 26000
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 10000
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: 500
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 2000
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant9_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant11_Value;             /* Expression: 10.862226
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 10000
                                        * Referenced by: '<Root>/Constant12'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_untitled1_T untitled1_P;

/* Block signals (default storage) */
extern B_untitled1_T untitled1_B;

/* Block states (default storage) */
extern DW_untitled1_T untitled1_DW;

/* Model entry point functions */
extern void untitled1_initialize(void);
extern void untitled1_step(void);
extern void untitled1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled1_T *const untitled1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant8' : Unused code path elimination
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
 * '<Root>' : 'untitled1'
 * '<S1>'   : 'untitled1/Chart'
 */
#endif                                 /* RTW_HEADER_untitled1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
