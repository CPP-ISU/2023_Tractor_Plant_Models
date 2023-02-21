/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Steering_Model.h
 *
 * Code generated for Simulink model 'Steering_Model'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb  8 15:48:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Steering_Model_h_
#define RTW_HEADER_Steering_Model_h_
#ifndef Steering_Model_COMMON_INCLUDES_
#define Steering_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw.h"
#include "Steering_Model_836bb176_1_gateway.h"
#endif                                 /* Steering_Model_COMMON_INCLUDES_ */

#include "Steering_Model_types.h"
#include <string.h>
#include "math.h"
#include <math.h>
#include "rt_matrixlib.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMassMatrixIr
#define rtmGetMassMatrixIr(rtm)        ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
#define rtmSetMassMatrixIr(rtm, val)   ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
#define rtmGetMassMatrixJc(rtm)        ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
#define rtmSetMassMatrixJc(rtm, val)   ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
#define rtmGetMassMatrixNzMax(rtm)     ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
#define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
#define rtmGetMassMatrixPr(rtm)        ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
#define rtmSetMassMatrixPr(rtm, val)   ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
#define rtmGetMassMatrixType(rtm)      ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
#define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
#define rtmGetOdeDELTA(rtm)            ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
#define rtmSetOdeDELTA(rtm, val)       ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
#define rtmGetOdeDFDX(rtm)             ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
#define rtmSetOdeDFDX(rtm, val)        ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
#define rtmGetOdeE(rtm)                ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
#define rtmSetOdeE(rtm, val)           ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeF0
#define rtmGetOdeF0(rtm)               ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
#define rtmSetOdeF0(rtm, val)          ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
#define rtmGetOdeF1(rtm)               ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
#define rtmSetOdeF1(rtm, val)          ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
#define rtmGetOdeFAC(rtm)              ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
#define rtmSetOdeFAC(rtm, val)         ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
#define rtmGetOdeMASSMATRIX_M(rtm)     ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
#define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdePIVOTS
#define rtmGetOdePIVOTS(rtm)           ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
#define rtmSetOdePIVOTS(rtm, val)      ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
#define rtmGetOdeW(rtm)                ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
#define rtmSetOdeW(rtm, val)           ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
#define rtmGetOdeX1START(rtm)          ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
#define rtmSetOdeX1START(rtm, val)     ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
#define rtmGetOdeXTMP(rtm)             ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
#define rtmSetOdeXTMP(rtm, val)        ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
#define rtmGetOdeZTMP(rtm)             ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
#define rtmSetOdeZTMP(rtm, val)        ((rtm)->odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T dv[20];
  NeModelParameters modelParameters;
  NeModelParameters modelParameters_m;
  real_T dv1[4];
  real_T dv2[4];
  real_T dv3[4];
  real_T dv4[4];
  real_T dv5[4];
  int_T iv[3];
  int_T iv1[2];
  real_T DerivativeGain;               /* '<S30>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S39>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S41>/Proportional Gain' */
  real_T INPUT_1_1_1[4];               /* '<S55>/INPUT_1_1_1' */
  real_T STATE_1[16];                  /* '<S55>/STATE_1' */
  real_T OUTPUT_1_0;                   /* '<S55>/OUTPUT_1_0' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T time;
  real_T time_c;
  real_T time_k;
  real_T time_cx;
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T time_tmp;
  real_T d;
  real_T time_b;
  int32_T i;
  int_T i1;
  int_T i2;
  int_T i3;
  int_T i4;
} B_Steering_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S55>/INPUT_1_1_1' */
  real_T STATE_1_Discrete;             /* '<S55>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S55>/OUTPUT_1_0' */
  void* STATE_1_Simulator;             /* '<S55>/STATE_1' */
  void* STATE_1_SimData;               /* '<S55>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S55>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S55>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S55>/STATE_1' */
  void* SINK_1_RtwLogger;              /* '<S55>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S55>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S55>/SINK_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S55>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S55>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S55>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S55>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S55>/OUTPUT_1_0' */
  int_T STATE_1_Modes[8];              /* '<S55>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S55>/OUTPUT_1_0' */
  int32_T STATE_1_MASS_MATRIX_PR;      /* '<S55>/STATE_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S55>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S55>/OUTPUT_1_0' */
} DW_Steering_Model_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos[8];/* '<S55>/STATE_1' */
} X_Steering_Model_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos[8];/* '<S55>/STATE_1' */
} XDot_Steering_Model_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos[8];/* '<S55>/STATE_1' */
} XDis_Steering_Model_T;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[4];
  int_T jc[11];
  real_T pr[4];
} MassMatrix_Steering_Model_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Parameters (default storage) */
struct P_Steering_Model_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S30>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionForFilter;
                      /* Mask Parameter: PIDController_InitialConditionForFilter
                       * Referenced by: '<S31>/Filter'
                       */
  real_T PIDController_InitialConditionForIntegrator;
                  /* Mask Parameter: PIDController_InitialConditionForIntegrator
                   * Referenced by: '<S36>/Integrator'
                   */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S39>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 6
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 10000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 6
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Steering_Model_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Steering_Model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Steering_Model_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[10];
  real_T odeF0[10];
  real_T odeX1START[10];
  real_T odeF1[10];
  real_T odeDELTA[10];
  real_T odeE[4*10];
  real_T odeFAC[10];
  real_T odeDFDX[10*10];
  real_T odeW[10*10];
  int_T odePIVOTS[10];
  real_T odeXTMP[10];
  real_T odeZTMP[10];
  real_T odeMASSMATRIX_M[4];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint8_T clockTick0;
    time_T stepSize0;
    uint8_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Steering_Model_T Steering_Model_P;

/* Block signals (default storage) */
extern B_Steering_Model_T Steering_Model_B;

/* Continuous states (default storage) */
extern X_Steering_Model_T Steering_Model_X;

/* Block states (default storage) */
extern DW_Steering_Model_T Steering_Model_DW;

/* global MassMatrix */
extern MassMatrix_Steering_Model_T Steering_Model_MassMatrix;

/* Model entry point functions */
extern void Steering_Model_initialize(void);
extern void Steering_Model_step(void);
extern void Steering_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Steering_Model_T *const Steering_Model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Divide' : Unused code path elimination
 * Block '<Root>/Multiply' : Unused code path elimination
 * Block '<Root>/Saturation1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S53>/RESHAPE' : Reshape block reduction
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
 * '<Root>' : 'Steering_Model'
 * '<S1>'   : 'Steering_Model/PID Controller'
 * '<S2>'   : 'Steering_Model/PS-Simulink Converter'
 * '<S3>'   : 'Steering_Model/Simulink-PS Converter1'
 * '<S4>'   : 'Steering_Model/Solver Configuration'
 * '<S5>'   : 'Steering_Model/PID Controller/Anti-windup'
 * '<S6>'   : 'Steering_Model/PID Controller/D Gain'
 * '<S7>'   : 'Steering_Model/PID Controller/Filter'
 * '<S8>'   : 'Steering_Model/PID Controller/Filter ICs'
 * '<S9>'   : 'Steering_Model/PID Controller/I Gain'
 * '<S10>'  : 'Steering_Model/PID Controller/Ideal P Gain'
 * '<S11>'  : 'Steering_Model/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'Steering_Model/PID Controller/Integrator'
 * '<S13>'  : 'Steering_Model/PID Controller/Integrator ICs'
 * '<S14>'  : 'Steering_Model/PID Controller/N Copy'
 * '<S15>'  : 'Steering_Model/PID Controller/N Gain'
 * '<S16>'  : 'Steering_Model/PID Controller/P Copy'
 * '<S17>'  : 'Steering_Model/PID Controller/Parallel P Gain'
 * '<S18>'  : 'Steering_Model/PID Controller/Reset Signal'
 * '<S19>'  : 'Steering_Model/PID Controller/Saturation'
 * '<S20>'  : 'Steering_Model/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'Steering_Model/PID Controller/Sum'
 * '<S22>'  : 'Steering_Model/PID Controller/Sum Fdbk'
 * '<S23>'  : 'Steering_Model/PID Controller/Tracking Mode'
 * '<S24>'  : 'Steering_Model/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'Steering_Model/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'Steering_Model/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'Steering_Model/PID Controller/postSat Signal'
 * '<S28>'  : 'Steering_Model/PID Controller/preSat Signal'
 * '<S29>'  : 'Steering_Model/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'Steering_Model/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'Steering_Model/PID Controller/Filter/Cont. Filter'
 * '<S32>'  : 'Steering_Model/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'Steering_Model/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'Steering_Model/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'Steering_Model/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'Steering_Model/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'Steering_Model/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'Steering_Model/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'Steering_Model/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'Steering_Model/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'Steering_Model/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'Steering_Model/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'Steering_Model/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'Steering_Model/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'Steering_Model/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'Steering_Model/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'Steering_Model/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'Steering_Model/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'Steering_Model/PID Controller/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'Steering_Model/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'Steering_Model/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'Steering_Model/PID Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'Steering_Model/PS-Simulink Converter/EVAL_KEY'
 * '<S54>'  : 'Steering_Model/Simulink-PS Converter1/EVAL_KEY'
 * '<S55>'  : 'Steering_Model/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_Steering_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
