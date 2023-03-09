/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'untitled/Solver Configuration'.
 */

#include "ne_ds.h"
#include "untitled_a151ee3d_1_ds_sys_struct.h"
#include "untitled_a151ee3d_1_ds_zc.h"
#include "untitled_a151ee3d_1_ds.h"
#include "untitled_a151ee3d_1_ds_externals.h"
#include "untitled_a151ee3d_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T untitled_a151ee3d_1_ds_zc(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t14, NeDsMethodOutput *t15)
{
  PmRealVector out;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_4;
  real_T intrm_sf_mf_11;
  real_T intrm_sf_mf_15;
  real_T t0;
  real_T t10;
  real_T t11;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t8;
  int32_T M_idx_0;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_6;
  int32_T M_idx_7;
  M_idx_0 = t14->mM.mX[0];
  M_idx_3 = t14->mM.mX[3];
  M_idx_4 = t14->mM.mX[4];
  M_idx_6 = t14->mM.mX[6];
  M_idx_7 = t14->mM.mX[7];
  U_idx_0 = t14->mU.mX[0];
  X_idx_0 = t14->mX.mX[0];
  X_idx_4 = t14->mX.mX[4];
  out = t15->mZC;
  t7 = U_idx_0 * 0.001;
  if (t7 > 1.0) {
    intrm_sf_mf_11 = 5.0E-5;
  } else if (t7 < 1.9999999999999997E-8) {
    intrm_sf_mf_11 = 1.0E-12;
  } else {
    intrm_sf_mf_11 = t7 * 5.0E-5;
  }

  U_idx_0 = -t7;
  if (-t7 > 1.0) {
    intrm_sf_mf_15 = 5.0E-5;
  } else if (-t7 < 1.9999999999999997E-8) {
    intrm_sf_mf_15 = 1.0E-12;
  } else {
    intrm_sf_mf_15 = -t7 * 5.0E-5;
  }

  if (M_idx_0 == 0) {
    t11 = -(X_idx_4 * 0.00038750077500155006);
    t0 = -X_idx_0 > t11 ? t11 : -X_idx_0;
  } else {
    t0 = 0.0;
  }

  if (M_idx_3 != 0) {
    t10 = -t7 - 1.0;
  } else {
    t10 = 0.0;
  }

  if ((M_idx_4 == 0) && (M_idx_3 != 0)) {
    t11 = 1.9999999999999997E-8 - (-t7);
  } else {
    t11 = 0.0;
  }

  if (M_idx_6 != 0) {
    t3 = t7 - 1.0;
  } else {
    t3 = 0.0;
  }

  if ((M_idx_7 == 0) && (M_idx_6 != 0)) {
    t4 = 1.9999999999999997E-8 - t7;
  } else {
    t4 = 0.0;
  }

  if (M_idx_6 != 0) {
    t5 = t7 - 1.0;
  } else {
    t5 = 0.0;
  }

  if ((M_idx_7 == 0) && (M_idx_6 != 0)) {
    t6 = 1.9999999999999997E-8 - t7;
  } else {
    t6 = 0.0;
  }

  if (M_idx_3 != 0) {
    t7 = -t7 - 1.0;
  } else {
    t7 = 0.0;
  }

  if ((M_idx_4 == 0) && (M_idx_3 != 0)) {
    t8 = 1.9999999999999997E-8 - U_idx_0;
  } else {
    t8 = 0.0;
  }

  U_idx_0 = X_idx_4 * 0.00038750077500155006;
  out.mX[0] = X_idx_0 - 0.30479999999999996 > U_idx_0 ? U_idx_0 : X_idx_0 -
    0.30479999999999996;
  out.mX[1] = t0;
  out.mX[2] = t10;
  out.mX[3] = t11;
  out.mX[4] = intrm_sf_mf_15 - 1.0E-12;
  out.mX[5] = t3;
  out.mX[6] = t4;
  out.mX[7] = intrm_sf_mf_11 - 1.0E-12;
  out.mX[8] = t5;
  out.mX[9] = t6;
  out.mX[10] = intrm_sf_mf_11 - 1.0E-12;
  out.mX[11] = t7;
  out.mX[12] = t8;
  out.mX[13] = intrm_sf_mf_15 - 1.0E-12;
  (void)sys;
  (void)t15;
  return 0;
}
