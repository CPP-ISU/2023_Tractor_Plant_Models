/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test_Stand_Trans_Controller_data.c
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

#include "Test_Stand_Trans_Controller.h"

/* Block parameters (default storage) */
P_Test_Stand_Trans_Controller_T Test_Stand_Trans_Controller_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S2>/Constant'
   */
  0.14389,

  /* Expression: -1
   * Referenced by: '<Root>/CAN Receive'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Constant35'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant8'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Constant36'
   */
  -1.0,

  /* Expression: 22
   * Referenced by: '<S1>/Constant1'
   */
  22.0,

  /* Expression: 58
   * Referenced by: '<S1>/Constant3'
   */
  58.0,

  /* Expression: 14
   * Referenced by: '<S1>/Constant7'
   */
  14.0,

  /* Expression: 38
   * Referenced by: '<S1>/Constant6'
   */
  38.0,

  /* Expression: 25
   * Referenced by: '<S1>/Constant5'
   */
  25.0,

  /* Expression: 54
   * Referenced by: '<S1>/Constant4'
   */
  54.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain11'
   */
  -1.0,

  /* Expression: .8
   * Referenced by: '<S1>/Constant19'
   */
  0.8,

  /* Expression: 3/4
   * Referenced by: '<S1>/Gain13'
   */
  0.75,

  /* Expression: 3/4
   * Referenced by: '<S1>/Gain17'
   */
  0.75,

  /* Expression: 4000
   * Referenced by: '<S1>/Saturation8'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation8'
   */
  0.0,

  /* Expression: 0.0689476
   * Referenced by: '<S1>/Gain25'
   */
  0.0689476,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

  /* Expression: .1
   * Referenced by: '<Root>/Rate Limiter1'
   */
  0.1,

  /* Expression: -.1
   * Referenced by: '<Root>/Rate Limiter1'
   */
  -0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Limiter1'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<S1>/Gain24'
   */
  24.0,

  /* Expression: cat(3,[.46,.62,.54;.27,.74,.83;.21,.73,.89],[.65,.86,.83;.46,.86,.94;.35,.86,.95],[.66,.83,.85;.53,.88,.91;.39,.87,.94])
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 0.46, 0.27, 0.21, 0.62, 0.74, 0.73, 0.54, 0.83, 0.89, 0.65, 0.46, 0.35, 0.86,
    0.86, 0.86, 0.83, 0.94, 0.95, 0.66, 0.53, 0.39, 0.83, 0.88, 0.87, 0.85, 0.91,
    0.94 },

  /* Expression: [10,135,278]
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 10.0, 135.0, 278.0 },

  /* Expression: [500,1974,4000]
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 500.0, 1974.0, 4000.0 },

  /* Expression: [4.8,12,24]
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 4.8, 12.0, 24.0 },

  /* Expression: 1
   * Referenced by: '<S1>/Saturation14'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation14'
   */
  1.0,

  /* Expression: 1.46
   * Referenced by: '<S1>/Gain6'
   */
  1.46,

  /* Expression: 6.28
   * Referenced by: '<S1>/Constant18'
   */
  6.28,

  /* Expression: 1/12
   * Referenced by: '<S1>/Gain10'
   */
  0.083333333333333329,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: .1
   * Referenced by: '<Root>/Rate Limiter'
   */
  0.1,

  /* Expression: -.1
   * Referenced by: '<Root>/Rate Limiter'
   */
  -0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Limiter'
   */
  0.0,

  /* Expression: 1.46
   * Referenced by: '<S1>/Gain5'
   */
  1.46,

  /* Expression: 2*pi
   * Referenced by: '<S1>/Constant17'
   */
  6.2831853071795862,

  /* Expression: 4000
   * Referenced by: '<S1>/Saturation10'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation10'
   */
  0.0,

  /* Expression: 0.0689476
   * Referenced by: '<S1>/Gain29'
   */
  0.0689476,

  /* Expression: 24
   * Referenced by: '<S1>/Gain28'
   */
  24.0,

  /* Expression: cat(3,[.46,.62,.54;.27,.74,.83;.21,.73,.89],[.65,.86,.83;.46,.86,.94;.35,.86,.95],[.66,.83,.85;.53,.88,.91;.39,.87,.94])
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 0.46, 0.27, 0.21, 0.62, 0.74, 0.73, 0.54, 0.83, 0.89, 0.65, 0.46, 0.35, 0.86,
    0.86, 0.86, 0.83, 0.94, 0.95, 0.66, 0.53, 0.39, 0.83, 0.88, 0.87, 0.85, 0.91,
    0.94 },

  /* Expression: [10,135,278]
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 10.0, 135.0, 278.0 },

  /* Expression: [500,1974,4000]
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 500.0, 1974.0, 4000.0 },

  /* Expression: [4.8,12,24]
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 4.8, 12.0, 24.0 },

  /* Expression: 1
   * Referenced by: '<S1>/Saturation12'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation12'
   */
  1.0,

  /* Expression: 1/12
   * Referenced by: '<S1>/Gain9'
   */
  0.083333333333333329,

  /* Expression: inf
   * Referenced by: '<S1>/Rate Limiter'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S1>/Rate Limiter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Limiter'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1>/Saturation3'
   */
  2000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Unit Delay3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain18'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant37'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S1>/Gain30'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Gain15'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant20'
   */
  2.0,

  /* Expression: 3.14
   * Referenced by: '<S1>/Constant22'
   */
  3.14,

  /* Expression: 3800
   * Referenced by: '<S1>/Constant21'
   */
  3800.0,

  /* Expression: 1/1.46
   * Referenced by: '<S1>/Gain16'
   */
  0.684931506849315,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain3'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/IC'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation6'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation6'
   */
  -1.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Gain'
   */
  10000.0,

  /* Expression: -1000
   * Referenced by: '<S1>/IC1'
   */
  -1000.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain4'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/IC3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation5'
   */
  -1.0,

  /* Expression: -10000
   * Referenced by: '<Root>/Gain1'
   */
  -10000.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Constant1'
   */
  10000.0,

  /* Expression: 3.14
   * Referenced by: '<Root>/Constant4'
   */
  3.14,

  /* Expression: 2
   * Referenced by: '<Root>/Constant3'
   */
  2.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant2'
   */
  10.0,

  /* Expression: 12
   * Referenced by: '<Root>/Gain3'
   */
  12.0,

  /* Expression: (1/10000)*4.77
   * Referenced by: '<Root>/Gain2'
   */
  0.000477,

  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 2U, 2U, 2U },

  /* Computed Parameter: uDLookupTable1_dimSizes
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 1U, 3U, 9U },

  /* Computed Parameter: uDLookupTable1_numYWorkElts
   * Referenced by: '<S1>/3-D Lookup Table1'
   */
  { 9U, 3U, 1U, 0U },

  /* Computed Parameter: uDLookupTable3_maxIndex
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 2U, 2U, 2U },

  /* Computed Parameter: uDLookupTable3_dimSizes
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 1U, 3U, 9U },

  /* Computed Parameter: uDLookupTable3_numYWorkElts
   * Referenced by: '<S1>/3-D Lookup Table3'
   */
  { 9U, 3U, 1U, 0U },

  /* Expression: false
   * Referenced by: '<S1>/IC2'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
