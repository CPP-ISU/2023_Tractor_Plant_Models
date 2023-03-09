/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'untitled/Solver Configuration'.
 */

#include "ne_ds.h"
#include "untitled_a151ee3d_1_ds_sys_struct.h"
#include "untitled_a151ee3d_1_ds_assert.h"
#include "untitled_a151ee3d_1_ds.h"
#include "untitled_a151ee3d_1_ds_externals.h"
#include "untitled_a151ee3d_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T untitled_a151ee3d_1_ds_assert(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t5, NeDsMethodOutput *t6)
{
  PmIntVector out;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T intrm_sf_mf_13;
  real_T intrm_sf_mf_17;
  real_T t1;
  real_T t2;
  int32_T t0_idx_17;
  int32_T t0_idx_24;
  int32_T t0_idx_31;
  int32_T t0_idx_38;
  X_idx_2 = t5->mX.mX[2];
  X_idx_3 = t5->mX.mX[3];
  X_idx_4 = t5->mX.mX[4];
  out = t6->mASSERT;
  X_idx_4 *= 0.00038750077500155006;
  intrm_sf_mf_13 = ((X_idx_2 + 55.15805834534688) + 2.0265) / 2.0 *
    0.0010000000000000009;
  intrm_sf_mf_17 = ((X_idx_3 + 55.15805834534688) + 2.0265) / 2.0 *
    0.0010000000000000009;
  t1 = (X_idx_2 + 2.0265) / 2.0 * 0.0010000000000000009;
  t2 = (X_idx_3 + 2.0265) / 2.0 * 0.0010000000000000009;
  t0_idx_17 = (int32_T)((!(X_idx_2 * X_idx_2 + t1 * t1 >= 0.0)) || (pmf_sqrt
    (pmf_sqrt(X_idx_2 * X_idx_2 + t1 * t1)) != 0.0));
  t0_idx_24 = (int32_T)((!(X_idx_3 * X_idx_3 + t2 * t2 >= 0.0)) || (pmf_sqrt
    (pmf_sqrt(X_idx_3 * X_idx_3 + t2 * t2)) != 0.0));
  t0_idx_31 = (int32_T)((!((-X_idx_2 + 55.15805834534688) * (-X_idx_2 +
    55.15805834534688) + intrm_sf_mf_13 * intrm_sf_mf_13 >= 0.0)) || (pmf_sqrt
    (pmf_sqrt((-X_idx_2 + 55.15805834534688) * (-X_idx_2 + 55.15805834534688) +
              intrm_sf_mf_13 * intrm_sf_mf_13)) != 0.0));
  t0_idx_38 = (int32_T)((!((-X_idx_3 + 55.15805834534688) * (-X_idx_3 +
    55.15805834534688) + intrm_sf_mf_17 * intrm_sf_mf_17 >= 0.0)) || (pmf_sqrt
    (pmf_sqrt((-X_idx_3 + 55.15805834534688) * (-X_idx_3 + 55.15805834534688) +
              intrm_sf_mf_17 * intrm_sf_mf_17)) != 0.0));
  out.mX[0] = 1;
  out.mX[1] = 1;
  out.mX[2] = 1;
  out.mX[3] = 1;
  out.mX[4] = 1;
  out.mX[5] = 1;
  out.mX[6] = 1;
  out.mX[7] = 1;
  out.mX[8] = 1;
  out.mX[9] = 1;
  out.mX[10] = (int32_T)(-(X_idx_4 / 0.14142135623730953 * (X_idx_4 /
    0.14142135623730953)) < 663.67513503334737);
  out.mX[11] = 1;
  out.mX[12] = 1;
  out.mX[13] = 1;
  out.mX[14] = 1;
  out.mX[15] = 1;
  out.mX[16] = (int32_T)(X_idx_2 * X_idx_2 + t1 * t1 >= 0.0);
  out.mX[17] = t0_idx_17;
  out.mX[18] = 1;
  out.mX[19] = 1;
  out.mX[20] = 1;
  out.mX[21] = 1;
  out.mX[22] = 1;
  out.mX[23] = (int32_T)(X_idx_3 * X_idx_3 + t2 * t2 >= 0.0);
  out.mX[24] = t0_idx_24;
  out.mX[25] = 1;
  out.mX[26] = 1;
  out.mX[27] = 1;
  out.mX[28] = 1;
  out.mX[29] = 1;
  out.mX[30] = (int32_T)((-X_idx_2 + 55.15805834534688) * (-X_idx_2 +
    55.15805834534688) + intrm_sf_mf_13 * intrm_sf_mf_13 >= 0.0);
  out.mX[31] = t0_idx_31;
  out.mX[32] = 1;
  out.mX[33] = 1;
  out.mX[34] = 1;
  out.mX[35] = 1;
  out.mX[36] = 1;
  out.mX[37] = (int32_T)((-X_idx_3 + 55.15805834534688) * (-X_idx_3 +
    55.15805834534688) + intrm_sf_mf_17 * intrm_sf_mf_17 >= 0.0);
  out.mX[38] = t0_idx_38;
  (void)sys;
  (void)t6;
  return 0;
}
