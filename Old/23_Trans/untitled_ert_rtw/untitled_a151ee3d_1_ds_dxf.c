/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'untitled/Solver Configuration'.
 */

#include "ne_ds.h"
#include "untitled_a151ee3d_1_ds_sys_struct.h"
#include "untitled_a151ee3d_1_ds_dxf.h"
#include "untitled_a151ee3d_1_ds.h"
#include "untitled_a151ee3d_1_ds_externals.h"
#include "untitled_a151ee3d_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T untitled_a151ee3d_1_ds_dxf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t38, NeDsMethodOutput *t39)
{
  PmRealVector out;
  real_T Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T intermediate_der17;
  real_T intermediate_der18;
  real_T t11;
  real_T t12;
  real_T t15;
  real_T t16;
  real_T t18;
  real_T t19;
  real_T t34;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_5;
  int32_T M_idx_6;
  int32_T M_idx_7;
  M_idx_0 = t38->mM.mX[0];
  M_idx_1 = t38->mM.mX[1];
  M_idx_2 = t38->mM.mX[2];
  M_idx_3 = t38->mM.mX[3];
  M_idx_4 = t38->mM.mX[4];
  M_idx_5 = t38->mM.mX[5];
  M_idx_6 = t38->mM.mX[6];
  M_idx_7 = t38->mM.mX[7];
  U_idx_0 = t38->mU.mX[0];
  X_idx_0 = t38->mX.mX[0];
  X_idx_2 = t38->mX.mX[2];
  X_idx_3 = t38->mX.mX[3];
  X_idx_4 = t38->mX.mX[4];
  out = t39->mDXF;
  Double_Acting_Hydraulic_Cylinder_Simple_R_v = X_idx_4 * 0.00038750077500155006;
  t16 = U_idx_0 * 0.001;
  t15 = ((X_idx_2 + 55.15805834534688) + 2.0265) / 2.0 * 0.0010000000000000009;
  t11 = ((X_idx_3 + 55.15805834534688) + 2.0265) / 2.0 * 0.0010000000000000009;
  t19 = (X_idx_2 + 2.0265) / 2.0 * 0.0010000000000000009;
  t34 = (X_idx_3 + 2.0265) / 2.0 * 0.0010000000000000009;
  if (M_idx_4 != 0) {
    U_idx_0 = 5.0E-5;
  } else if (M_idx_5 != 0) {
    U_idx_0 = 1.0E-12;
  } else {
    U_idx_0 = -t16 * 5.0E-5;
  }

  t18 = M_idx_3 != 0 ? U_idx_0 : 1.0E-12;
  if (M_idx_7 != 0) {
    U_idx_0 = 5.0E-5;
  } else if (M_idx_2 != 0) {
    U_idx_0 = 1.0E-12;
  } else {
    U_idx_0 = t16 * 5.0E-5;
  }

  t16 = M_idx_6 != 0 ? U_idx_0 : 1.0E-12;
  if (M_idx_0 != 0) {
    intermediate_der17 = (X_idx_0 - 0.30479999999999996) * 3.8750077500155008E+8;
  } else if (M_idx_1 != 0) {
    intermediate_der17 = X_idx_0 * -3.8750077500155008E+8;
  } else {
    intermediate_der17 = 0.0;
  }

  if (M_idx_0 != 0) {
    intermediate_der18 = X_idx_4 * 3.8750077500155008E+8;
  } else if (M_idx_1 != 0) {
    intermediate_der18 = -(X_idx_4 * 0.00038750077500155006) * 1.0E+12;
  } else {
    intermediate_der18 = 0.0;
  }

  X_idx_0 = pmf_sqrt(X_idx_2 * X_idx_2 + t19 * t19) * pmf_sqrt(pmf_sqrt(X_idx_2 *
    X_idx_2 + t19 * t19));
  X_idx_4 = pmf_sqrt(pmf_sqrt(X_idx_2 * X_idx_2 + t19 * t19)) * pmf_sqrt
    (pmf_sqrt(X_idx_2 * X_idx_2 + t19 * t19));
  U_idx_0 = pmf_sqrt(pmf_sqrt(X_idx_2 * X_idx_2 + t19 * t19));
  t12 = -(((X_idx_2 * 2.0 + 0.00050000000000000044 * t19 * 2.0) * (-(X_idx_2 *
             t18 * 0.033954987505086617) / (X_idx_4 == 0.0 ? 1.0E-16 : X_idx_4))
           * (1.0 / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0)) * 0.25 + t18 *
           0.033954987505086617 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0)) *
          3.1622776601683795E+8);
  t19 = pmf_sqrt((-X_idx_2 + 55.15805834534688) * (-X_idx_2 + 55.15805834534688)
                 + t15 * t15) * pmf_sqrt(pmf_sqrt((-X_idx_2 + 55.15805834534688)
    * (-X_idx_2 + 55.15805834534688) + t15 * t15));
  U_idx_0 = pmf_sqrt(pmf_sqrt((-X_idx_2 + 55.15805834534688) * (-X_idx_2 +
    55.15805834534688) + t15 * t15)) * pmf_sqrt(pmf_sqrt((-X_idx_2 +
    55.15805834534688) * (-X_idx_2 + 55.15805834534688) + t15 * t15));
  X_idx_0 = pmf_sqrt(pmf_sqrt((-X_idx_2 + 55.15805834534688) * (-X_idx_2 +
    55.15805834534688) + t15 * t15));
  X_idx_2 = -(((-(-X_idx_2 + 55.15805834534688) * 2.0 + 0.00050000000000000044 *
                t15 * 2.0) * (-((-X_idx_2 + 55.15805834534688) * t16 *
    0.033954987505086617) / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0)) * (1.0 / (t19 ==
    0.0 ? 1.0E-16 : t19)) * 0.25 + -t16 * 0.033954987505086617 / (X_idx_0 == 0.0
    ? 1.0E-16 : X_idx_0)) * 3.1622776601683795E+8);
  t15 = pmf_sqrt(X_idx_3 * X_idx_3 + t34 * t34) * pmf_sqrt(pmf_sqrt(X_idx_3 *
    X_idx_3 + t34 * t34));
  X_idx_0 = pmf_sqrt(pmf_sqrt(X_idx_3 * X_idx_3 + t34 * t34)) * pmf_sqrt
    (pmf_sqrt(X_idx_3 * X_idx_3 + t34 * t34));
  X_idx_4 = pmf_sqrt(pmf_sqrt(X_idx_3 * X_idx_3 + t34 * t34));
  t19 = -(((X_idx_3 * 2.0 + 0.00050000000000000044 * t34 * 2.0) * (-(X_idx_3 *
             t16 * 0.033954987505086617) / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0))
           * (1.0 / (t15 == 0.0 ? 1.0E-16 : t15)) * 0.25 + t16 *
           0.033954987505086617 / (X_idx_4 == 0.0 ? 1.0E-16 : X_idx_4)) *
          3.1622776601683795E+8);
  t16 = pmf_sqrt((-X_idx_3 + 55.15805834534688) * (-X_idx_3 + 55.15805834534688)
                 + t11 * t11) * pmf_sqrt(pmf_sqrt((-X_idx_3 + 55.15805834534688)
    * (-X_idx_3 + 55.15805834534688) + t11 * t11));
  U_idx_0 = pmf_sqrt(pmf_sqrt((-X_idx_3 + 55.15805834534688) * (-X_idx_3 +
    55.15805834534688) + t11 * t11)) * pmf_sqrt(pmf_sqrt((-X_idx_3 +
    55.15805834534688) * (-X_idx_3 + 55.15805834534688) + t11 * t11));
  X_idx_0 = pmf_sqrt(pmf_sqrt((-X_idx_3 + 55.15805834534688) * (-X_idx_3 +
    55.15805834534688) + t11 * t11));
  t15 = -(((-(-X_idx_3 + 55.15805834534688) * 2.0 + 0.00050000000000000044 * t11
            * 2.0) * (-((-X_idx_3 + 55.15805834534688) * t18 *
                        0.033954987505086617) / (U_idx_0 == 0.0 ? 1.0E-16 :
             U_idx_0)) * (1.0 / (t16 == 0.0 ? 1.0E-16 : t16)) * 0.25 + -t18 *
           0.033954987505086617 / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0)) *
          3.1622776601683795E+8);
  t11 = cosh(Double_Acting_Hydraulic_Cylinder_Simple_R_v / 0.01) * cosh
    (Double_Acting_Hydraulic_Cylinder_Simple_R_v / 0.01);
  t18 = -((0.002740044257186386 * pmf_exp
           (-(Double_Acting_Hydraulic_Cylinder_Simple_R_v / 0.14142135623730953 *
              (Double_Acting_Hydraulic_Cylinder_Simple_R_v / 0.14142135623730953)))
           + -(Double_Acting_Hydraulic_Cylinder_Simple_R_v / 0.14142135623730953
               * 0.002740044257186386 * 2.0) *
           (Double_Acting_Hydraulic_Cylinder_Simple_R_v / 0.14142135623730953) *
           pmf_exp(-(Double_Acting_Hydraulic_Cylinder_Simple_R_v /
                     0.14142135623730953 *
                     (Double_Acting_Hydraulic_Cylinder_Simple_R_v /
                      0.14142135623730953)))) * 2285.0111019651818 +
          0.038750077500155009 * (1.0 / (t11 == 0.0 ? 1.0E-16 : t11)) * 20.0);
  out.mX[0] = intermediate_der18 / 258.06399999999996;
  out.mX[1] = t12;
  out.mX[2] = X_idx_2;
  out.mX[3] = t19;
  out.mX[4] = t15;
  out.mX[5] = intermediate_der17 / 258.06399999999996;
  out.mX[6] = t18;
  (void)sys;
  (void)t39;
  return 0;
}
