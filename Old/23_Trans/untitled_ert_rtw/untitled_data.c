/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb  8 16:11:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S1>/Constant'
   *   '<S1>/Step'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/CAN Receive'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 14
   * Referenced by: '<Root>/Constant3'
   */
  14.0,

  /* Expression: [0,6,12,0,6,6,6,12]
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.0, 6.0, 12.0, 0.0, 6.0, 6.0, 6.0, 12.0 },

  /* Expression: [0,2,4,6,8,10,12,14]
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Constant'
   */
  12.0,

  /* Expression: 20000
   * Referenced by: '<Root>/Multiply'
   */
  20000.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Saturation1'
   */
  10000.0,

  /* Expression: -10000
   * Referenced by: '<Root>/Saturation1'
   */
  -10000.0,

  /* Expression: 2
   * Referenced by: '<Root>/Gain2'
   */
  2.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S2>/sample time'
   */
  1.12,

  /* Expression: 0
   * Referenced by: '<S2>/Delay Input2'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
