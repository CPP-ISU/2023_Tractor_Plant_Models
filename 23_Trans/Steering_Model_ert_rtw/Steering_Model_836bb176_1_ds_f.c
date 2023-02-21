/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Steering_Model/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Steering_Model_836bb176_1_ds_sys_struct.h"
#include "Steering_Model_836bb176_1_ds_f.h"
#include "Steering_Model_836bb176_1_ds.h"
#include "Steering_Model_836bb176_1_ds_externals.h"
#include "Steering_Model_836bb176_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Steering_Model_836bb176_1_ds_f(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t13, NeDsMethodOutput *t14)
{
  PmRealVector out;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T intrm_sf_mf_13;
  real_T intrm_sf_mf_17;
  real_T t0_idx_3;
  real_T t1;
  real_T t12;
  real_T t3;
  real_T t6;
  real_T t8;
  real_T t9;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_5;
  int32_T M_idx_6;
  int32_T M_idx_7;
  M_idx_0 = t13->mM.mX[0];
  M_idx_1 = t13->mM.mX[1];
  M_idx_2 = t13->mM.mX[2];
  M_idx_3 = t13->mM.mX[3];
  M_idx_4 = t13->mM.mX[4];
  M_idx_5 = t13->mM.mX[5];
  M_idx_6 = t13->mM.mX[6];
  M_idx_7 = t13->mM.mX[7];
  U_idx_0 = t13->mU.mX[0];
  X_idx_0 = t13->mX.mX[0];
  X_idx_2 = t13->mX.mX[2];
  X_idx_3 = t13->mX.mX[3];
  X_idx_4 = t13->mX.mX[4];
  out = t14->mF;
  t9 = X_idx_4 * 0.00038750077500155006;
  t12 = U_idx_0 * 0.001;
  intrm_sf_mf_13 = ((X_idx_2 + 55.15805834534688) + 2.0265) / 2.0 *
    0.0010000000000000009;
  intrm_sf_mf_17 = ((X_idx_3 + 55.15805834534688) + 2.0265) / 2.0 *
    0.0010000000000000009;
  t8 = (X_idx_2 + 2.0265) / 2.0 * 0.0010000000000000009;
  t3 = (X_idx_3 + 2.0265) / 2.0 * 0.0010000000000000009;
  if (M_idx_0 != 0) {
    t6 = (X_idx_0 - 0.30479999999999996) * X_idx_4 * 3.8750077500155008E+8;
  } else if (M_idx_1 != 0) {
    t6 = -(X_idx_4 * 0.00038750077500155006) * X_idx_0 * 1.0E+12;
  } else {
    t6 = 0.0;
  }

  if (M_idx_4 != 0) {
    U_idx_0 = 5.0E-5;
  } else if (M_idx_5 != 0) {
    U_idx_0 = 1.0E-12;
  } else {
    U_idx_0 = -t12 * 5.0E-5;
  }

  t1 = M_idx_3 != 0 ? U_idx_0 : 1.0E-12;
  if (M_idx_7 != 0) {
    U_idx_0 = 5.0E-5;
  } else if (M_idx_2 != 0) {
    U_idx_0 = 1.0E-12;
  } else {
    U_idx_0 = t12 * 5.0E-5;
  }

  t12 = M_idx_6 != 0 ? U_idx_0 : 1.0E-12;
  X_idx_4 = t6 / 258.06399999999996;
  t0_idx_3 = -(t9 / 0.14142135623730953 * pmf_exp(-(t9 / 0.14142135623730953 *
    (t9 / 0.14142135623730953))) * 2285.0111019651818 + tanh(t9 / 0.01) * 20.0);
  t6 = pmf_sqrt(pmf_sqrt(X_idx_2 * X_idx_2 + t8 * t8));
  t8 = pmf_sqrt(pmf_sqrt(X_idx_3 * X_idx_3 + t3 * t3));
  X_idx_0 = -(X_idx_3 * t12 * 0.033954987505086617 / (t8 == 0.0 ? 1.0E-16 : t8) *
              3.1622776601683795E+8);
  t9 = (-X_idx_2 + 55.15805834534688) * t12 * 0.033954987505086617;
  t12 = pmf_sqrt(pmf_sqrt((-X_idx_2 + 55.15805834534688) * (-X_idx_2 +
    55.15805834534688) + intrm_sf_mf_13 * intrm_sf_mf_13));
  U_idx_0 = -(t9 / (t12 == 0.0 ? 1.0E-16 : t12) * 3.1622776601683795E+8);
  t12 = pmf_sqrt(pmf_sqrt((-X_idx_3 + 55.15805834534688) * (-X_idx_3 +
    55.15805834534688) + intrm_sf_mf_17 * intrm_sf_mf_17));
  out.mX[0] = -0.0;
  out.mX[1] = -0.0;
  out.mX[2] = X_idx_4;
  out.mX[3] = t0_idx_3;
  out.mX[4] = -(X_idx_2 * t1 * 0.033954987505086617 / (t6 == 0.0 ? 1.0E-16 : t6)
                * 3.1622776601683795E+8);
  out.mX[5] = X_idx_0;
  out.mX[6] = U_idx_0;
  out.mX[7] = -((-X_idx_3 + 55.15805834534688) * t1 * 0.033954987505086617 /
                (t12 == 0.0 ? 1.0E-16 : t12) * 3.1622776601683795E+8);
  (void)sys;
  (void)t14;
  return 0;
}
