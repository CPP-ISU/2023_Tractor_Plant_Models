/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test_Stand_Trans_Controller.h
 *
 * Code generated for Simulink model 'Test_Stand_Trans_Controller'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar  6 21:37:24 2023
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
#include "rtsplntypes.h"
#include <string.h>
#include "rtGetInf.h"
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
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Product;                      /* '<Root>/Product' */
  real_T IC3;                          /* '<S1>/IC3' */
  real_T Saturation14;                 /* '<S1>/Saturation14' */
  real_T Gain11;                       /* '<S1>/Gain11' */
  real_T MaxTorque;                    /* '<S1>/MaxTorqueatSpeed' */
  real_T IC;                           /* '<S1>/IC' */
  real_T MP2;                          /* '<S1>/Gain10' */
  real_T Product6;                     /* '<S1>/Product6' */
  real_T Min1;                         /* '<S1>/Min1' */
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
  codertarget_raspi_internal__l_T obj_p;/* '<Root>/CAN Transmit' */
  codertarget_raspi_internal__l_T obj_pl;/* '<Root>/CAN Transmit1' */
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S1>/Unit Delay3' */
  real_T PrevY;                        /* '<Root>/Rate Limiter1' */
  real_T m_bpLambda[3];                /* '<S1>/3-D Lookup Table1' */
  real_T m_yyA[9];                     /* '<S1>/3-D Lookup Table1' */
  real_T m_yyB[9];                     /* '<S1>/3-D Lookup Table1' */
  real_T m_yy2[9];                     /* '<S1>/3-D Lookup Table1' */
  real_T m_up[3];                      /* '<S1>/3-D Lookup Table1' */
  real_T m_y2[27];                     /* '<S1>/3-D Lookup Table1' */
  real_T prevBp0AndTableData[30];      /* '<S1>/3-D Lookup Table1' */
  real_T PrevY_b;                      /* '<Root>/Rate Limiter' */
  real_T m_bpLambda_m[3];              /* '<S1>/3-D Lookup Table3' */
  real_T m_yyA_h[9];                   /* '<S1>/3-D Lookup Table3' */
  real_T m_yyB_n[9];                   /* '<S1>/3-D Lookup Table3' */
  real_T m_yy2_a[9];                   /* '<S1>/3-D Lookup Table3' */
  real_T m_up_g[3];                    /* '<S1>/3-D Lookup Table3' */
  real_T m_y2_o[27];                   /* '<S1>/3-D Lookup Table3' */
  real_T prevBp0AndTableData_k[30];    /* '<S1>/3-D Lookup Table3' */
  real_T PrevY_g;                      /* '<S1>/Rate Limiter' */
  void* m_bpDataSet[3];                /* '<S1>/3-D Lookup Table1' */
  void* TWork[6];                      /* '<S1>/3-D Lookup Table1' */
  void* SWork[9];                      /* '<S1>/3-D Lookup Table1' */
  void* m_bpDataSet_l[3];              /* '<S1>/3-D Lookup Table3' */
  void* TWork_i[6];                    /* '<S1>/3-D Lookup Table3' */
  void* SWork_l[9];                    /* '<S1>/3-D Lookup Table3' */
  uint32_T m_bpIndex[3];               /* '<S1>/3-D Lookup Table1' */
  uint32_T m_bpIndex_h[3];             /* '<S1>/3-D Lookup Table3' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
  uint8_T reCalcSecDerivFirstDimCoeffs;/* '<S1>/3-D Lookup Table1' */
  uint8_T reCalcSecDerivFirstDimCoeffs_j;/* '<S1>/3-D Lookup Table3' */
  boolean_T IC2_FirstOutputTime;       /* '<S1>/IC2' */
  boolean_T IC_FirstOutputTime;        /* '<S1>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<S1>/IC1' */
  boolean_T IC3_FirstOutputTime;       /* '<S1>/IC3' */
  FILE* eml_openfiles[20];             /* '<Root>/CAN Transmit' */
} DW_Test_Stand_Trans_Controlle_T;

/* Parameters (default storage) */
struct P_Test_Stand_Trans_Controller_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S2>/Constant'
                                       */
  real_T CANReceive_SampleTime;        /* Expression: -1
                                        * Referenced by: '<Root>/CAN Receive'
                                        */
  real_T Constant35_Value;             /* Expression: -1
                                        * Referenced by: '<S1>/Constant35'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant36_Value;             /* Expression: -1
                                        * Referenced by: '<S1>/Constant36'
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
  real_T Saturation8_UpperSat;         /* Expression: 4000
                                        * Referenced by: '<S1>/Saturation8'
                                        */
  real_T Saturation8_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S1>/Saturation8'
                                        */
  real_T Gain25_Gain;                  /* Expression: 0.0689476
                                        * Referenced by: '<S1>/Gain25'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T RateLimiter1_RisingLim;       /* Expression: .1
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim;      /* Expression: -.1
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T RateLimiter1_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T Gain24_Gain;                  /* Expression: 24
                                        * Referenced by: '<S1>/Gain24'
                                        */
  real_T uDLookupTable1_tableData[27];
  /* Expression: cat(3,[.46,.62,.54;.27,.74,.83;.21,.73,.89],[.65,.86,.83;.46,.86,.94;.35,.86,.95],[.66,.83,.85;.53,.88,.91;.39,.87,.94])
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[3];   /* Expression: [10,135,278]
                                        * Referenced by: '<S1>/3-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp02Data[3];   /* Expression: [500,1974,4000]
                                        * Referenced by: '<S1>/3-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp03Data[3];   /* Expression: [4.8,12,24]
                                        * Referenced by: '<S1>/3-D Lookup Table1'
                                        */
  real_T Saturation14_UpperSat;        /* Expression: 1
                                        * Referenced by: '<S1>/Saturation14'
                                        */
  real_T Saturation14_LowerSat;        /* Expression: 1
                                        * Referenced by: '<S1>/Saturation14'
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
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T RateLimiter_RisingLim;        /* Expression: .1
                                        * Referenced by: '<Root>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Expression: -.1
                                        * Referenced by: '<Root>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1.46
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T Constant17_Value;             /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant17'
                                        */
  real_T Saturation10_UpperSat;        /* Expression: 4000
                                        * Referenced by: '<S1>/Saturation10'
                                        */
  real_T Saturation10_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S1>/Saturation10'
                                        */
  real_T Gain29_Gain;                  /* Expression: 0.0689476
                                        * Referenced by: '<S1>/Gain29'
                                        */
  real_T Gain28_Gain;                  /* Expression: 24
                                        * Referenced by: '<S1>/Gain28'
                                        */
  real_T uDLookupTable3_tableData[27];
  /* Expression: cat(3,[.46,.62,.54;.27,.74,.83;.21,.73,.89],[.65,.86,.83;.46,.86,.94;.35,.86,.95],[.66,.83,.85;.53,.88,.91;.39,.87,.94])
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  real_T uDLookupTable3_bp01Data[3];   /* Expression: [10,135,278]
                                        * Referenced by: '<S1>/3-D Lookup Table3'
                                        */
  real_T uDLookupTable3_bp02Data[3];   /* Expression: [500,1974,4000]
                                        * Referenced by: '<S1>/3-D Lookup Table3'
                                        */
  real_T uDLookupTable3_bp03Data[3];   /* Expression: [4.8,12,24]
                                        * Referenced by: '<S1>/3-D Lookup Table3'
                                        */
  real_T Saturation12_UpperSat;        /* Expression: 1
                                        * Referenced by: '<S1>/Saturation12'
                                        */
  real_T Saturation12_LowerSat;        /* Expression: 1
                                        * Referenced by: '<S1>/Saturation12'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1/12
                                        * Referenced by: '<S1>/Gain9'
                                        */
  real_T RateLimiter_RisingLim_e;      /* Expression: inf
                                        * Referenced by: '<S1>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_d;     /* Expression: -inf
                                        * Referenced by: '<S1>/Rate Limiter'
                                        */
  real_T RateLimiter_IC_f;             /* Expression: 0
                                        * Referenced by: '<S1>/Rate Limiter'
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
  real_T UnitDelay3_InitialCondition;  /* Expression: 1
                                        * Referenced by: '<S1>/Unit Delay3'
                                        */
  real_T Gain18_Gain;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain18'
                                        */
  real_T Constant37_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant37'
                                        */
  real_T Gain30_Gain;                  /* Expression: 1
                                        * Referenced by: '<S1>/Gain30'
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
  real_T Saturation_LowerSat;          /* Expression: -1
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
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T IC3_Value;                    /* Expression: -1
                                        * Referenced by: '<S1>/IC3'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: -10000
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
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 12
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: (1/10000)*4.77
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint32_T uDLookupTable1_maxIndex[3];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S1>/3-D Lookup Table1'
                                   */
  uint32_T uDLookupTable1_dimSizes[3];
                                  /* Computed Parameter: uDLookupTable1_dimSizes
                                   * Referenced by: '<S1>/3-D Lookup Table1'
                                   */
  uint32_T uDLookupTable1_numYWorkElts[4];
                              /* Computed Parameter: uDLookupTable1_numYWorkElts
                               * Referenced by: '<S1>/3-D Lookup Table1'
                               */
  uint32_T uDLookupTable3_maxIndex[3];
                                  /* Computed Parameter: uDLookupTable3_maxIndex
                                   * Referenced by: '<S1>/3-D Lookup Table3'
                                   */
  uint32_T uDLookupTable3_dimSizes[3];
                                  /* Computed Parameter: uDLookupTable3_dimSizes
                                   * Referenced by: '<S1>/3-D Lookup Table3'
                                   */
  uint32_T uDLookupTable3_numYWorkElts[4];
                              /* Computed Parameter: uDLookupTable3_numYWorkElts
                               * Referenced by: '<S1>/3-D Lookup Table3'
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
 * Block '<Root>/CAN Unpack1' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<Root>/Display5' : Unused code path elimination
 * Block '<S1>/3-D Lookup Table' : Unused code path elimination
 * Block '<S1>/3-D Lookup Table2' : Unused code path elimination
 * Block '<S1>/Abs16' : Unused code path elimination
 * Block '<S1>/Abs17' : Unused code path elimination
 * Block '<S1>/Abs18' : Unused code path elimination
 * Block '<S1>/Abs4' : Unused code path elimination
 * Block '<S1>/Abs5' : Unused code path elimination
 * Block '<S1>/Abs6' : Unused code path elimination
 * Block '<S1>/Abs7' : Unused code path elimination
 * Block '<S1>/Abs8' : Unused code path elimination
 * Block '<S1>/Abs9' : Unused code path elimination
 * Block '<S1>/Add4' : Unused code path elimination
 * Block '<S1>/Add5' : Unused code path elimination
 * Block '<S1>/Add6' : Unused code path elimination
 * Block '<S1>/Add7' : Unused code path elimination
 * Block '<S1>/Add8' : Unused code path elimination
 * Block '<S1>/Constant10' : Unused code path elimination
 * Block '<S1>/Constant11' : Unused code path elimination
 * Block '<S1>/Constant12' : Unused code path elimination
 * Block '<S1>/Constant13' : Unused code path elimination
 * Block '<S1>/Constant14' : Unused code path elimination
 * Block '<S1>/Constant15' : Unused code path elimination
 * Block '<S1>/Constant16' : Unused code path elimination
 * Block '<S1>/Constant2' : Unused code path elimination
 * Block '<S1>/Constant23' : Unused code path elimination
 * Block '<S1>/Constant24' : Unused code path elimination
 * Block '<S1>/Constant25' : Unused code path elimination
 * Block '<S1>/Constant26' : Unused code path elimination
 * Block '<S1>/Constant27' : Unused code path elimination
 * Block '<S1>/Constant28' : Unused code path elimination
 * Block '<S1>/Constant29' : Unused code path elimination
 * Block '<S1>/Constant30' : Unused code path elimination
 * Block '<S1>/Constant31' : Unused code path elimination
 * Block '<S1>/Constant32' : Unused code path elimination
 * Block '<S1>/Constant33' : Unused code path elimination
 * Block '<S1>/Constant34' : Unused code path elimination
 * Block '<S1>/Constant9' : Unused code path elimination
 * Block '<S1>/Divide10' : Unused code path elimination
 * Block '<S1>/Divide19' : Unused code path elimination
 * Block '<S1>/Divide23' : Unused code path elimination
 * Block '<S1>/Divide24' : Unused code path elimination
 * Block '<S1>/Divide25' : Unused code path elimination
 * Block '<S1>/Divide26' : Unused code path elimination
 * Block '<S1>/Divide27' : Unused code path elimination
 * Block '<S1>/Divide28' : Unused code path elimination
 * Block '<S1>/Divide29' : Unused code path elimination
 * Block '<S1>/Divide3' : Unused code path elimination
 * Block '<S1>/Divide30' : Unused code path elimination
 * Block '<S1>/Divide31' : Unused code path elimination
 * Block '<S1>/Divide32' : Unused code path elimination
 * Block '<S1>/Divide33' : Unused code path elimination
 * Block '<S1>/Divide34' : Unused code path elimination
 * Block '<S1>/Divide35' : Unused code path elimination
 * Block '<S1>/Divide36' : Unused code path elimination
 * Block '<S1>/Divide37' : Unused code path elimination
 * Block '<S1>/Divide38' : Unused code path elimination
 * Block '<S1>/Divide4' : Unused code path elimination
 * Block '<S1>/Divide5' : Unused code path elimination
 * Block '<S1>/Divide6' : Unused code path elimination
 * Block '<S1>/Divide7' : Unused code path elimination
 * Block '<S1>/Gain12' : Unused code path elimination
 * Block '<S1>/Gain14' : Unused code path elimination
 * Block '<S1>/Gain19' : Unused code path elimination
 * Block '<S1>/Gain2' : Unused code path elimination
 * Block '<S1>/Gain20' : Unused code path elimination
 * Block '<S1>/Gain21' : Unused code path elimination
 * Block '<S1>/Gain22' : Unused code path elimination
 * Block '<S1>/Gain23' : Unused code path elimination
 * Block '<S1>/Gain26' : Unused code path elimination
 * Block '<S1>/Gain27' : Unused code path elimination
 * Block '<S1>/Gain7' : Unused code path elimination
 * Block '<S1>/Gain8' : Unused code path elimination
 * Block '<S1>/MP1_Eff' : Unused code path elimination
 * Block '<S1>/MP1_Torque' : Unused code path elimination
 * Block '<S1>/MP2_Eff' : Unused code path elimination
 * Block '<S1>/MP2_torque' : Unused code path elimination
 * Block '<S1>/Mod' : Unused code path elimination
 * Block '<S1>/Product15' : Unused code path elimination
 * Block '<S1>/Product19' : Unused code path elimination
 * Block '<S1>/Product20' : Unused code path elimination
 * Block '<S1>/Product21' : Unused code path elimination
 * Block '<S1>/Saturation11' : Unused code path elimination
 * Block '<S1>/Saturation13' : Unused code path elimination
 * Block '<S1>/Saturation2' : Unused code path elimination
 * Block '<S1>/Saturation4' : Unused code path elimination
 * Block '<S1>/Saturation7' : Unused code path elimination
 * Block '<S1>/Saturation9' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope10' : Unused code path elimination
 * Block '<S1>/Scope11' : Unused code path elimination
 * Block '<S1>/Scope12' : Unused code path elimination
 * Block '<S1>/Scope13' : Unused code path elimination
 * Block '<S1>/Scope14' : Unused code path elimination
 * Block '<S1>/Scope16' : Unused code path elimination
 * Block '<S1>/Scope19' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope20' : Unused code path elimination
 * Block '<S1>/Scope21' : Unused code path elimination
 * Block '<S1>/Scope22' : Unused code path elimination
 * Block '<S1>/Scope24' : Unused code path elimination
 * Block '<S1>/Scope25' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S1>/Scope5' : Unused code path elimination
 * Block '<S1>/Scope6' : Unused code path elimination
 * Block '<S1>/Scope7' : Unused code path elimination
 * Block '<S1>/Scope8' : Unused code path elimination
 * Block '<S1>/Scope9' : Unused code path elimination
 * Block '<S1>/Square' : Unused code path elimination
 * Block '<S1>/Square Root' : Unused code path elimination
 * Block '<S1>/Square1' : Unused code path elimination
 * Block '<S1>/Subtract1' : Unused code path elimination
 * Block '<S1>/Subtract5' : Unused code path elimination
 * Block '<S1>/Subtract6' : Unused code path elimination
 * Block '<S1>/Subtract7' : Unused code path elimination
 * Block '<S1>/Subtract9' : Unused code path elimination
 * Block '<S1>/Switch' : Unused code path elimination
 * Block '<S1>/Switch1' : Unused code path elimination
 * Block '<S1>/Unit Delay' : Unused code path elimination
 * Block '<S1>/Unit Delay1' : Unused code path elimination
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
 * '<S2>'   : 'Test_Stand_Trans_Controller/Subsystem Reference/Compare To Constant'
 */
#endif                           /* RTW_HEADER_Test_Stand_Trans_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
