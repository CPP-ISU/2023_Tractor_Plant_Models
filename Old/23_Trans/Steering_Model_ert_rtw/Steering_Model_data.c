/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Steering_Model_data.c
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

#include "Steering_Model.h"

/* Block parameters (default storage) */
P_Steering_Model_T Steering_Model_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S30>/Derivative Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S33>/Integral Gain'
   */
  5.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  20.0,

  /* Expression: 6
   * Referenced by: '<Root>/Constant2'
   */
  6.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Constant1'
   */
  10000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 6
   * Referenced by: '<Root>/Gain'
   */
  6.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
