/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Steering_Plant_Model_Pi.h
 *
 * Code generated for Simulink model 'Steering_Plant_Model_Pi'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb  8 16:23:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Steering_Plant_Model_Pi_h_
#define RTW_HEADER_Steering_Plant_Model_Pi_h_
#ifndef Steering_Plant_Model_Pi_COMMON_INCLUDES_
#define Steering_Plant_Model_Pi_COMMON_INCLUDES_
#include <math.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SocketCAN.h"
#endif                            /* Steering_Plant_Model_Pi_COMMON_INCLUDES_ */

#include "Steering_Plant_Model_Pi_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
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
  char_T canInterface[5];
  int32_T i;
  int32_T stat1;
  int32_T stat2;
  int32_T len;
  int32_T j;
  int32_T reachedEndOfFile;
  int32_T idx;
  int32_T carriageReturnAt;
} B_Steering_Plant_Model_Pi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_CA_T obj; /* '<Root>/CAN Receive' */
  codertarget_raspi_internal__g_T obj_h;/* '<Root>/CAN Transmit' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  FILE* eml_openfiles[20];             /* '<Root>/CAN Transmit' */
} DW_Steering_Plant_Model_Pi_T;

/* Parameters (default storage) */
struct P_Steering_Plant_Model_Pi_T_ {
  real_T CANReceive_SampleTime;        /* Expression: -1
                                        * Referenced by: '<Root>/CAN Receive'
                                        */
  real_T Constant4_Value;              /* Expression: 5000
                                        * Referenced by: '<Root>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Steering_Plant_Model__T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Steering_Plant_Model_Pi_T Steering_Plant_Model_Pi_P;

/* Block signals (default storage) */
extern B_Steering_Plant_Model_Pi_T Steering_Plant_Model_Pi_B;

/* Block states (default storage) */
extern DW_Steering_Plant_Model_Pi_T Steering_Plant_Model_Pi_DW;

/* Model entry point functions */
extern void Steering_Plant_Model_Pi_initialize(void);
extern void Steering_Plant_Model_Pi_step(void);
extern void Steering_Plant_Model_Pi_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Steering_Plant_Model_T *const Steering_Plant_Model_Pi_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/1-D Lookup Table' : Unused code path elimination
 * Block '<Root>/Abs' : Unused code path elimination
 * Block '<Root>/CAN Unpack' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Divide' : Unused code path elimination
 * Block '<Root>/Divide1' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/Mod' : Unused code path elimination
 * Block '<Root>/Multiply' : Unused code path elimination
 * Block '<S1>/Clock' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S1>/Output' : Unused code path elimination
 * Block '<S1>/Product' : Unused code path elimination
 * Block '<S1>/Step' : Unused code path elimination
 * Block '<S1>/Sum' : Unused code path elimination
 * Block '<S2>/Delay Input2' : Unused code path elimination
 * Block '<S2>/Difference Inputs1' : Unused code path elimination
 * Block '<S2>/Difference Inputs2' : Unused code path elimination
 * Block '<S2>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/LowerRelop1' : Unused code path elimination
 * Block '<S3>/Switch' : Unused code path elimination
 * Block '<S3>/Switch2' : Unused code path elimination
 * Block '<S3>/UpperRelop' : Unused code path elimination
 * Block '<S2>/delta fall limit' : Unused code path elimination
 * Block '<S2>/delta rise limit' : Unused code path elimination
 * Block '<S2>/sample time' : Unused code path elimination
 * Block '<Root>/Saturation1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Subtract' : Unused code path elimination
 * Block '<Root>/Subtract1' : Unused code path elimination
 * Block '<Root>/Unit Delay' : Unused code path elimination
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
 * '<Root>' : 'Steering_Plant_Model_Pi'
 * '<S1>'   : 'Steering_Plant_Model_Pi/Ramp'
 * '<S2>'   : 'Steering_Plant_Model_Pi/Rate Limiter Dynamic'
 * '<S3>'   : 'Steering_Plant_Model_Pi/Rate Limiter Dynamic/Saturation Dynamic'
 */
#endif                               /* RTW_HEADER_Steering_Plant_Model_Pi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
