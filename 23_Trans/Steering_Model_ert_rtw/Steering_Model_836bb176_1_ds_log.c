/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Steering_Model/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Steering_Model_836bb176_1_ds_sys_struct.h"
#include "Steering_Model_836bb176_1_ds_log.h"
#include "Steering_Model_836bb176_1_ds.h"
#include "Steering_Model_836bb176_1_ds_externals.h"
#include "Steering_Model_836bb176_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Steering_Model_836bb176_1_ds_log(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  real_T Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  real_T Hydraulic_Constant_Pressure_Source_flow_rate;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T x4_Way_Directional_Valve_orifice_P_A_S;
  U_idx_0 = t1->mU.mX[0];
  X_idx_0 = t1->mX.mX[0];
  X_idx_1 = t1->mX.mX[1];
  X_idx_2 = t1->mX.mX[2];
  X_idx_3 = t1->mX.mX[3];
  X_idx_4 = t1->mX.mX[4];
  X_idx_5 = t1->mX.mX[5];
  X_idx_6 = t1->mX.mX[6];
  X_idx_7 = t1->mX.mX[7];
  out = t2->mLOG;
  Double_Acting_Hydraulic_Cylinder_Simple_R_v = X_idx_4 * 0.00038750077500155006;
  Hydraulic_Constant_Pressure_Source_flow_rate = -X_idx_6 - X_idx_7;
  x4_Way_Directional_Valve_orifice_P_A_S = U_idx_0 * 0.001;
  out.mX[0] = X_idx_2 * 99999.999999999985;
  out.mX[1] = X_idx_3 * 99999.999999999985;
  out.mX[2] = Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  out.mX[3] = X_idx_4 * 1.0E-6;
  out.mX[4] = X_idx_4 * 9.9999999999999974E-7;
  out.mX[5] = X_idx_5;
  out.mX[6] = X_idx_0;
  out.mX[7] = X_idx_2 * 99999.999999999985;
  out.mX[8] = X_idx_3 * 99999.999999999985;
  out.mX[9] = X_idx_4 * 0.00038750077500155006;
  out.mX[10] = Hydraulic_Constant_Pressure_Source_flow_rate * 1.0E-6;
  out.mX[11] = Hydraulic_Constant_Pressure_Source_flow_rate * 5.5158058345346879;
  out.mX[12] = X_idx_1;
  out.mX[13] = Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  out.mX[14] = Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  out.mX[15] = X_idx_1;
  out.mX[16] = X_idx_1 * 39.370078740157481;
  out.mX[17] = U_idx_0;
  out.mX[18] = Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  out.mX[19] = X_idx_5;
  out.mX[20] = Double_Acting_Hydraulic_Cylinder_Simple_R_v;
  out.mX[21] = Double_Acting_Hydraulic_Cylinder_Simple_R_v * X_idx_5;
  out.mX[22] = X_idx_2 * 99999.999999999985;
  out.mX[23] = X_idx_3 * 99999.999999999985;
  out.mX[24] = x4_Way_Directional_Valve_orifice_P_A_S;
  out.mX[25] = X_idx_2 * 99999.999999999985;
  out.mX[26] = x4_Way_Directional_Valve_orifice_P_A_S;
  out.mX[27] = (-X_idx_4 + X_idx_6) * 1.0E-6;
  out.mX[28] = X_idx_2 * 99999.999999999985;
  out.mX[29] = X_idx_3 * 99999.999999999985;
  out.mX[30] = x4_Way_Directional_Valve_orifice_P_A_S;
  out.mX[31] = (X_idx_4 * 0.99999999999999989 + X_idx_7) * 1.0E-6;
  out.mX[32] = X_idx_3 * 99999.999999999985;
  out.mX[33] = X_idx_2 * 99999.999999999985;
  out.mX[34] = x4_Way_Directional_Valve_orifice_P_A_S;
  out.mX[35] = X_idx_6 * 1.0E-6;
  out.mX[36] = (-X_idx_2 + 55.15805834534688) * 99999.999999999985;
  out.mX[37] = X_idx_3 * 99999.999999999985;
  out.mX[38] = x4_Way_Directional_Valve_orifice_P_A_S;
  out.mX[39] = X_idx_7 * 1.0E-6;
  out.mX[40] = (-X_idx_3 + 55.15805834534688) * 99999.999999999985;
  (void)sys;
  (void)t2;
  return 0;
}
