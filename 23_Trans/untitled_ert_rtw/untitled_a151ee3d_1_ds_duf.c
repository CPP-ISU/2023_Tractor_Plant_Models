/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'untitled/Solver Configuration'.
 */

#include "ne_ds.h"
#include "untitled_a151ee3d_1_ds_sys_struct.h"
#include "untitled_a151ee3d_1_ds_duf.h"
#include "untitled_a151ee3d_1_ds.h"
#include "untitled_a151ee3d_1_ds_externals.h"
#include "untitled_a151ee3d_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T untitled_a151ee3d_1_ds_duf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t12, NeDsMethodOutput *t13)
{
  PmRealVector out;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T intermediate_der20;
  real_T intermediate_der21;
  real_T intrm_sf_mf_17;
  real_T t10;
  real_T t11;
  real_T t6;
  real_T t7;
  real_T t8;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_5;
  int32_T M_idx_6;
  int32_T M_idx_7;
  M_idx_2 = t12->mM.mX[2];
  M_idx_3 = t12->mM.mX[3];
  M_idx_4 = t12->mM.mX[4];
  M_idx_5 = t12->mM.mX[5];
  M_idx_6 = t12->mM.mX[6];
  M_idx_7 = t12->mM.mX[7];
  X_idx_2 = t12->mX.mX[2];
  X_idx_3 = t12->mX.mX[3];
  out = t13->mDUF;
  t11 = ((X_idx_2 + 55.15805834534688) + 2.0265) / 2.0 * 0.0010000000000000009;
  intrm_sf_mf_17 = ((X_idx_3 + 55.15805834534688) + 2.0265) / 2.0 *
    0.0010000000000000009;
  t7 = (X_idx_2 + 2.0265) / 2.0 * 0.0010000000000000009;
  t10 = (X_idx_3 + 2.0265) / 2.0 * 0.0010000000000000009;
  if (M_idx_4 != 0) {
    intermediate_der21 = 0.0;
  } else if (M_idx_5 != 0) {
    intermediate_der21 = 0.0;
  } else {
    intermediate_der21 = -5.0000000000000004E-8;
  }

  intermediate_der20 = M_idx_3 != 0 ? intermediate_der21 : 0.0;
  if (M_idx_7 != 0) {
    intermediate_der21 = 0.0;
  } else if (M_idx_2 != 0) {
    intermediate_der21 = 0.0;
  } else {
    intermediate_der21 = 5.0000000000000004E-8;
  }

  intermediate_der21 = M_idx_6 != 0 ? intermediate_der21 : 0.0;
  t6 = pmf_sqrt(pmf_sqrt(X_idx_2 * X_idx_2 + t7 * t7));
  t8 = pmf_sqrt(pmf_sqrt(X_idx_3 * X_idx_3 + t10 * t10));
  t10 = pmf_sqrt(pmf_sqrt((-X_idx_2 + 55.15805834534688) * (-X_idx_2 +
    55.15805834534688) + t11 * t11));
  t7 = pmf_sqrt(pmf_sqrt((-X_idx_3 + 55.15805834534688) * (-X_idx_3 +
    55.15805834534688) + intrm_sf_mf_17 * intrm_sf_mf_17));
  out.mX[0] = -(intermediate_der20 * X_idx_2 * 0.033954987505086617 / (t6 == 0.0
    ? 1.0E-16 : t6) * 3.1622776601683795E+8);
  out.mX[1] = -(intermediate_der21 * X_idx_3 * 0.033954987505086617 / (t8 == 0.0
    ? 1.0E-16 : t8) * 3.1622776601683795E+8);
  out.mX[2] = -(intermediate_der21 * (-X_idx_2 + 55.15805834534688) *
                0.033954987505086617 / (t10 == 0.0 ? 1.0E-16 : t10) *
                3.1622776601683795E+8);
  out.mX[3] = -(intermediate_der20 * (-X_idx_3 + 55.15805834534688) *
                0.033954987505086617 / (t7 == 0.0 ? 1.0E-16 : t7) *
                3.1622776601683795E+8);
  (void)sys;
  (void)t13;
  return 0;
}
