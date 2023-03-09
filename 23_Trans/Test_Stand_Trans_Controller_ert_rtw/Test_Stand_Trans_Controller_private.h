/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test_Stand_Trans_Controller_private.h
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

#ifndef RTW_HEADER_Test_Stand_Trans_Controller_private_h_
#define RTW_HEADER_Test_Stand_Trans_Controller_private_h_
#include "rtwtypes.h"
#include "Test_Stand_Trans_Controller_types.h"
#include "Test_Stand_Trans_Controller.h"
#include "can_message.h"

extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern real_T rt_powd_snf(real_T u0, real_T u1);
real_T look_SplNBinCZcd(uint32_T numDims, const real_T* u, const
  rt_LUTSplineWork * const SWork);
void rt_Spline2Derivd(const real_T *x, const real_T *y, uint32_T n, real_T *u,
                      real_T *y2);
real_T intrp_NSplcd(uint32_T numDims, const rt_LUTSplineWork * const splWork,
                    uint32_T extrapMethod);
extern uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
extern uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);

#endif                   /* RTW_HEADER_Test_Stand_Trans_Controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
