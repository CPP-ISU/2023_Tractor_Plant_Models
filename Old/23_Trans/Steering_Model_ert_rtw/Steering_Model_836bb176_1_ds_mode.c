/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Steering_Model/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Steering_Model_836bb176_1_ds_sys_struct.h"
#include "Steering_Model_836bb176_1_ds_mode.h"
#include "Steering_Model_836bb176_1_ds.h"
#include "Steering_Model_836bb176_1_ds_externals.h"
#include "Steering_Model_836bb176_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Steering_Model_836bb176_1_ds_mode(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_4;
  real_T intrm_sf_mf_11;
  real_T intrm_sf_mf_15;
  U_idx_0 = t1->mU.mX[0];
  X_idx_0 = t1->mX.mX[0];
  X_idx_4 = t1->mX.mX[4];
  out = t2->mMODE;
  U_idx_0 *= 0.001;
  if (U_idx_0 > 1.0) {
    intrm_sf_mf_11 = 5.0E-5;
  } else if (U_idx_0 < 1.9999999999999997E-8) {
    intrm_sf_mf_11 = 1.0E-12;
  } else {
    intrm_sf_mf_11 = U_idx_0 * 5.0E-5;
  }

  if (-U_idx_0 > 1.0) {
    intrm_sf_mf_15 = 5.0E-5;
  } else if (-U_idx_0 < 1.9999999999999997E-8) {
    intrm_sf_mf_15 = 1.0E-12;
  } else {
    intrm_sf_mf_15 = -U_idx_0 * 5.0E-5;
  }

  out.mX[0] = (int32_T)((X_idx_0 > 0.30479999999999996) && (X_idx_4 *
    0.00038750077500155006 > 0.0));
  out.mX[1] = (int32_T)((X_idx_0 < 0.0) && (X_idx_4 * 0.00038750077500155006 <
    0.0));
  out.mX[2] = (int32_T)(U_idx_0 < 1.9999999999999997E-8);
  out.mX[3] = (int32_T)(intrm_sf_mf_15 > 1.0E-12);
  out.mX[4] = (int32_T)(-U_idx_0 > 1.0);
  out.mX[5] = (int32_T)(-U_idx_0 < 1.9999999999999997E-8);
  out.mX[6] = (int32_T)(intrm_sf_mf_11 > 1.0E-12);
  out.mX[7] = (int32_T)(U_idx_0 > 1.0);
  (void)sys;
  (void)t2;
  return 0;
}
