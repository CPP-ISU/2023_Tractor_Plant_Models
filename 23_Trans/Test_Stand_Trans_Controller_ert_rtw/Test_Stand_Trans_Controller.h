/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test_Stand_Trans_Controller.h
 *
 * Code generated for Simulink model 'Test_Stand_Trans_Controller'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jan 27 17:11:46 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Test_Stand_Trans_Controller_h_
#define RTW_HEADER_Test_Stand_Trans_Controller_h_
#ifndef Test_Stand_Trans_Controller_COMMON_INCLUDES_
#define Test_Stand_Trans_Controller_COMMON_INCLUDES_
#include <math.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "MW_SocketCAN.h"
#endif                        /* Test_Stand_Trans_Controller_COMMON_INCLUDES_ */

#include "Test_Stand_Trans_Controller_types.h"
#include "rt_nonfinite.h"
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
  char_T errString1_m[63];
  char_T errString2[52];
  char_T errString2_c[52];
  char_T patVal[42];
  char_T patVal_k[25];
  linuxCANMsg CANReceive_o1;           /* '<Root>/CAN Receive' */
  CAN_MESSAGE_BUS CANPack;             /* '<Root>/CAN Pack' */
  CAN_MESSAGE_BUS CANPack1;            /* '<Root>/CAN Pack1' */
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
  real_T Pressure_A;                   /* '<Root>/CAN Unpack' */
  real_T Pressure_B;                   /* '<Root>/CAN Unpack' */
  real_T MP1_Speed;                    /* '<Root>/CAN Unpack' */
  real_T MP2_Speed;                    /* '<Root>/CAN Unpack' */
  real_T MP1_Swash;                    /* '<Root>/CAN Unpack1' */
  real_T MP2_Swash;                    /* '<Root>/CAN Unpack1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Mp1;                          /* '<S1>/Chart' */
  real_T Gain11;                       /* '<S1>/Gain11' */
  real_T Minimumswashcommand;          /* '<S1>/Gain16' */
  real_T Gain17;                       /* '<S1>/Gain17' */
  uint8_T rxData[8];
  char_T canInterface[5];
  int32_T i;
  int32_T stat1;
  int32_T stat2;
  int32_T len;
  int32_T j;
  int32_T reachedEndOfFile;
  int32_T idx;
  int32_T carriageReturnAt;
} B_Test_Stand_Trans_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_CA_T obj; /* '<Root>/CAN Receive' */
  codertarget_raspi_internal__l_T obj_p;/* '<Root>/CAN Transmit1' */
  codertarget_raspi_internal__l_T obj_pe;/* '<Root>/CAN Transmit' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S1>/Unit Delay3' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<Root>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<Root>/CAN Unpack1' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
  uint8_T is_c3_Test_Stand_Trans_Controll;/* '<S1>/Chart' */
  uint8_T is_active_c3_Test_Stand_Trans_C;/* '<S1>/Chart' */
  boolean_T IC2_FirstOutputTime;       /* '<S1>/IC2' */
  boolean_T IC_FirstOutputTime;        /* '<S1>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<S1>/IC1' */
  FILE* eml_openfiles[20];             /* '<Root>/CAN Transmit' */
} DW_Test_Stand_Trans_Controlle_T;

/* Parameters (default storage) */
struct P_Test_Stand_Trans_Controller_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S3>/Constant'
                                       */
  real_T CANReceive_SampleTime;        /* Expression: -1
                                        * Referenced by: '<Root>/CAN Receive'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 22
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 58
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant7_Value;              /* Expression: 14
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: 38
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 25
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 54
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Gain11_Gain;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain11'
                                        */
  real_T Constant19_Value;             /* Expression: .8
                                        * Referenced by: '<S1>/Constant19'
                                        */
  real_T Gain13_Gain;                  /* Expression: 3/4
                                        * Referenced by: '<S1>/Gain13'
                                        */
  real_T Gain17_Gain;                  /* Expression: 3/4
                                        * Referenced by: '<S1>/Gain17'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1.46
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T Constant18_Value;             /* Expression: 6.28
                                        * Referenced by: '<S1>/Constant18'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1/12
                                        * Referenced by: '<S1>/Gain10'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1.46
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T Constant17_Value;             /* Expression: 6.28
                                        * Referenced by: '<S1>/Constant17'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1/12
                                        * Referenced by: '<S1>/Gain9'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 2000
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 1
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T UnitDelay3_InitialCondition;  /* Expression: 1
                                        * Referenced by: '<S1>/Unit Delay3'
                                        */
  real_T Gain18_Gain;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain18'
                                        */
  real_T Gain15_Gain;                  /* Expression: 1
                                        * Referenced by: '<S1>/Gain15'
                                        */
  real_T Constant20_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant20'
                                        */
  real_T Constant22_Value;             /* Expression: 3.14
                                        * Referenced by: '<S1>/Constant22'
                                        */
  real_T Constant21_Value;             /* Expression: 3800
                                        * Referenced by: '<S1>/Constant21'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1/1.46
                                        * Referenced by: '<S1>/Gain16'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T IC_Value;                     /* Expression: 0
                                        * Referenced by: '<S1>/IC'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation6'
                                        */
  real_T Gain_Gain;                    /* Expression: 10000
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T IC1_Value;                    /* Expression: -1000
                                        * Referenced by: '<S1>/IC1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 10000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 10000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant4_Value_d;            /* Expression: 3.14
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant3_Value_o;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 189
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 12
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: (1/10000)*4.77
                                        * Referenced by: '<Root>/Gain2'
                                        */
  boolean_T IC2_Value;                 /* Expression: false
                                        * Referenced by: '<S1>/IC2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test_Stand_Trans_Cont_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Test_Stand_Trans_Controller_T Test_Stand_Trans_Controller_P;

/* Block signals (default storage) */
extern B_Test_Stand_Trans_Controller_T Test_Stand_Trans_Controller_B;

/* Block states (default storage) */
extern DW_Test_Stand_Trans_Controlle_T Test_Stand_Trans_Controller_DW;

/* Model entry point functions */
extern void Test_Stand_Trans_Controller_initialize(void);
extern void Test_Stand_Trans_Controller_step(void);
extern void Test_Stand_Trans_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Test_Stand_Trans_Con_T *const Test_Stand_Trans_Controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<Root>/Display5' : Unused code path elimination
 * Block '<S1>/Add4' : Unused code path elimination
 * Block '<S1>/Constant10' : Unused code path elimination
 * Block '<S1>/Constant11' : Unused code path elimination
 * Block '<S1>/Constant12' : Unused code path elimination
 * Block '<S1>/Constant13' : Unused code path elimination
 * Block '<S1>/Constant14' : Unused code path elimination
 * Block '<S1>/Constant15' : Unused code path elimination
 * Block '<S1>/Constant2' : Unused code path elimination
 * Block '<S1>/Constant9' : Unused code path elimination
 * Block '<S1>/Divide19' : Unused code path elimination
 * Block '<S1>/Divide3' : Unused code path elimination
 * Block '<S1>/Divide4' : Unused code path elimination
 * Block '<S1>/Divide5' : Unused code path elimination
 * Block '<S1>/Divide6' : Unused code path elimination
 * Block '<S1>/Divide7' : Unused code path elimination
 * Block '<S1>/Gain12' : Unused code path elimination
 * Block '<S1>/Gain14' : Unused code path elimination
 * Block '<S1>/Gain2' : Unused code path elimination
 * Block '<S1>/Gain7' : Unused code path elimination
 * Block '<S1>/Gain8' : Unused code path elimination
 * Block '<S1>/Mod' : Unused code path elimination
 * Block '<S1>/Product15' : Unused code path elimination
 * Block '<S1>/Saturation2' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope10' : Unused code path elimination
 * Block '<S1>/Scope11' : Unused code path elimination
 * Block '<S1>/Scope12' : Unused code path elimination
 * Block '<S1>/Scope13' : Unused code path elimination
 * Block '<S1>/Scope14' : Unused code path elimination
 * Block '<S1>/Scope15' : Unused code path elimination
 * Block '<S1>/Scope16' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope5' : Unused code path elimination
 * Block '<S1>/Scope6' : Unused code path elimination
 * Block '<S1>/Scope7' : Unused code path elimination
 * Block '<S1>/Scope8' : Unused code path elimination
 * Block '<S1>/Scope9' : Unused code path elimination
 * Block '<S1>/Subtract1' : Unused code path elimination
 * Block '<S1>/Switch' : Unused code path elimination
 * Block '<S1>/Switch1' : Unused code path elimination
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
 * '<Root>' : 'Test_Stand_Trans_Controller'
 * '<S1>'   : 'Test_Stand_Trans_Controller/Subsystem Reference'
 * '<S2>'   : 'Test_Stand_Trans_Controller/Subsystem Reference/Chart'
 * '<S3>'   : 'Test_Stand_Trans_Controller/Subsystem Reference/Compare To Constant'
 */
#endif                           /* RTW_HEADER_Test_Stand_Trans_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
