/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Steering_Model.c
 *
 * Code generated for Simulink model 'Steering_Model'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb  8 15:48:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Steering_Model.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "Steering_Model_private.h"

/* Block signals (default storage) */
B_Steering_Model_T Steering_Model_B;

/* Continuous states */
X_Steering_Model_T Steering_Model_X;

/* Block states (default storage) */
DW_Steering_Model_T Steering_Model_DW;

/* Mass Matrices */
MassMatrix_Steering_Model_T Steering_Model_MassMatrix;

/* Real-time model */
static RT_MODEL_Steering_Model_T Steering_Model_M_;
RT_MODEL_Steering_Model_T *const Steering_Model_M = &Steering_Model_M_;

/* ForcingFunction for root system: '<Root>' */
void Steering_Model_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_Steering_Model_T *_rtXdot;
  char *msg;
  real_T time;
  int32_T tmp_1;
  int_T tmp_0[2];
  boolean_T tmp;
  _rtXdot = ((XDot_Steering_Model_T *) Steering_Model_M->derivs);

  /* ForcingFunction for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = Steering_Model_B.IntegralGain;

  /* ForcingFunction for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = Steering_Model_B.FilterCoefficient;

  /* ForcingFunction for SimscapeExecutionBlock: '<S55>/STATE_1' */
  simulationData = (NeslSimulationData *)Steering_Model_DW.STATE_1_SimData;
  time = Steering_Model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 8;
  simulationData->mData->mContStates.mX =
    &Steering_Model_X.Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos
    [0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Steering_Model_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 8;
  simulationData->mData->mModeVector.mX = &Steering_Model_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(Steering_Model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Steering_Model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&Steering_Model_M->solverInfo);
  tmp_0[0] = 0;
  Steering_Model_B.dv3[0] = Steering_Model_B.INPUT_1_1_1[0];
  Steering_Model_B.dv3[1] = Steering_Model_B.INPUT_1_1_1[1];
  Steering_Model_B.dv3[2] = Steering_Model_B.INPUT_1_1_1[2];
  Steering_Model_B.dv3[3] = Steering_Model_B.INPUT_1_1_1[3];
  tmp_0[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &Steering_Model_B.dv3[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mDx.mN = 8;
  simulationData->mData->mDx.mX =
    &_rtXdot->Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos[0];
  diagnosticManager = (NeuDiagnosticManager *)Steering_Model_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)
    Steering_Model_DW.STATE_1_Simulator, NESL_SIM_FORCINGFUNCTION,
    simulationData, diagnosticManager);
  if (tmp_1 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Steering_Model_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S55>/STATE_1' */
}

/* MassMatrix for root system: '<Root>' */
void Steering_Model_massmatrix(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T *tmp_1;
  real_T *tmp_2;
  int32_T tmp_3;
  int_T tmp_0[2];
  boolean_T tmp;

  /* MassMatrix for SimscapeExecutionBlock: '<S55>/STATE_1' */
  simulationData = (NeslSimulationData *)Steering_Model_DW.STATE_1_SimData;
  Steering_Model_B.time_b = Steering_Model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &Steering_Model_B.time_b;
  simulationData->mData->mContStates.mN = 8;
  simulationData->mData->mContStates.mX =
    &Steering_Model_X.Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos
    [0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Steering_Model_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 8;
  simulationData->mData->mModeVector.mX = &Steering_Model_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(Steering_Model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Steering_Model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&Steering_Model_M->solverInfo);
  tmp_0[0] = 0;
  Steering_Model_B.dv2[0] = Steering_Model_B.INPUT_1_1_1[0];
  Steering_Model_B.dv2[1] = Steering_Model_B.INPUT_1_1_1[1];
  Steering_Model_B.dv2[2] = Steering_Model_B.INPUT_1_1_1[2];
  Steering_Model_B.dv2[3] = Steering_Model_B.INPUT_1_1_1[3];
  tmp_0[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &Steering_Model_B.dv2[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  tmp_1 = Steering_Model_M->massMatrixPr;
  tmp_2 = double_pointer_shift(tmp_1, Steering_Model_DW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 2;
  simulationData->mData->mMassMatrixPr.mX = tmp_2;
  diagnosticManager = (NeuDiagnosticManager *)Steering_Model_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    Steering_Model_DW.STATE_1_Simulator, NESL_SIM_MASSMATRIX, simulationData,
    diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Steering_Model_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S55>/STATE_1' */
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  Steering_Model_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 10;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    Steering_Model_step();
    rtsiSetdX(si,p);
    Steering_Model_forcingfunction();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  if (id->isFirstStep) {
    local_evaluateMassMatrix(si,M );
    id->isFirstStep = false;
  }

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Steering_Model_forcingfunction();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
        real_T m_row_col = M[rowidx];
        row = Mpattern_ir[rowidx];
        p[row] += m_row_col;
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      Steering_Model_step();
      Steering_Model_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        Steering_Model_step();
        Steering_Model_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Steering_Model_step(void)
{
  if (rtmIsMajorTimeStep(Steering_Model_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Steering_Model_M->solverInfo,
                          ((Steering_Model_M->Timing.clockTick0+1)*
      Steering_Model_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Steering_Model_M)) {
    Steering_Model_M->Timing.t[0] = rtsiGetT(&Steering_Model_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T time_tmp;
    int32_T tmp_1;
    boolean_T tmp;
    boolean_T tmp_0;
    boolean_T tmp_2;
    if (rtmIsMajorTimeStep(Steering_Model_M)) {
      /* Sum: '<Root>/Subtract' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Constant: '<Root>/Constant2'
       *  Constant: '<Root>/Constant3'
       *  Gain: '<Root>/Gain'
       *  Product: '<Root>/Divide1'
       *  Sum: '<Root>/Subtract1'
       *  UnitDelay: '<Root>/Unit Delay'
       */
      Steering_Model_B.Subtract = (Steering_Model_P.Constant3_Value /
        Steering_Model_P.Constant1_Value * Steering_Model_P.Gain_Gain -
        Steering_Model_P.Constant2_Value) - Steering_Model_DW.UnitDelay_DSTATE;

      /* Gain: '<S30>/Derivative Gain' */
      Steering_Model_B.DerivativeGain = Steering_Model_P.PIDController_D *
        Steering_Model_B.Subtract;

      /* Gain: '<S41>/Proportional Gain' */
      Steering_Model_B.ProportionalGain = Steering_Model_P.PIDController_P *
        Steering_Model_B.Subtract;
    }

    /* Gain: '<S39>/Filter Coefficient' incorporates:
     *  Integrator: '<S31>/Filter'
     *  Sum: '<S31>/SumD'
     */
    Steering_Model_B.FilterCoefficient = (Steering_Model_B.DerivativeGain -
      Steering_Model_X.Filter_CSTATE) * Steering_Model_P.PIDController_N;

    /* SimscapeInputBlock: '<S55>/INPUT_1_1_1' incorporates:
     *  Integrator: '<S36>/Integrator'
     *  Sum: '<S45>/Sum'
     */
    Steering_Model_B.INPUT_1_1_1[0] = (Steering_Model_B.ProportionalGain +
      Steering_Model_X.Integrator_CSTATE) + Steering_Model_B.FilterCoefficient;
    Steering_Model_B.INPUT_1_1_1[1] = 0.0;
    Steering_Model_B.INPUT_1_1_1[2] = 0.0;
    Steering_Model_B.INPUT_1_1_1[3] = 0.0;

    /* SimscapeExecutionBlock: '<S55>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S55>/OUTPUT_1_0'
     */
    simulationData = (NeslSimulationData *)Steering_Model_DW.STATE_1_SimData;
    Steering_Model_B.time_tmp = Steering_Model_M->Timing.t[0];
    Steering_Model_B.time = Steering_Model_B.time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &Steering_Model_B.time;
    simulationData->mData->mContStates.mN = 8;
    simulationData->mData->mContStates.mX =
      &Steering_Model_X.Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos
      [0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Steering_Model_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 8;
    simulationData->mData->mModeVector.mX = &Steering_Model_DW.STATE_1_Modes[0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp = rtmIsMajorTimeStep(Steering_Model_M);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&Steering_Model_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_0 = rtsiIsModeUpdateTimeStep(&Steering_Model_M->solverInfo);
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    Steering_Model_B.iv1[0] = 0;
    Steering_Model_B.dv1[0] = Steering_Model_B.INPUT_1_1_1[0];
    Steering_Model_B.dv1[1] = Steering_Model_B.INPUT_1_1_1[1];
    Steering_Model_B.dv1[2] = Steering_Model_B.INPUT_1_1_1[2];
    Steering_Model_B.dv1[3] = Steering_Model_B.INPUT_1_1_1[3];
    Steering_Model_B.iv1[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &Steering_Model_B.dv1[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &Steering_Model_B.iv1[0];
    simulationData->mData->mOutputs.mN = 16;
    simulationData->mData->mOutputs.mX = &Steering_Model_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_tmp = Steering_Model_M->Timing.t[0];
    Steering_Model_B.time_c = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &Steering_Model_B.time_c;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      Steering_Model_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = ne_simulator_method((NeslSimulator *)
      Steering_Model_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (tmp_1 != 0) {
      tmp_2 = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
      if (tmp_2) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Steering_Model_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S55>/STATE_1' */

    /* SimscapeExecutionBlock: '<S55>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)Steering_Model_DW.OUTPUT_1_0_SimData;
    Steering_Model_B.time_k = Steering_Model_B.time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &Steering_Model_B.time_k;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &Steering_Model_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &Steering_Model_DW.OUTPUT_1_0_Modes;
    tmp_2 = false;
    simulationData->mData->mFoundZcEvents = tmp_2;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    Steering_Model_B.iv[0] = 0;
    Steering_Model_B.dv[0] = Steering_Model_B.INPUT_1_1_1[0];
    Steering_Model_B.dv[1] = Steering_Model_B.INPUT_1_1_1[1];
    Steering_Model_B.dv[2] = Steering_Model_B.INPUT_1_1_1[2];
    Steering_Model_B.dv[3] = Steering_Model_B.INPUT_1_1_1[3];
    Steering_Model_B.iv[1] = 4;
    memcpy(&Steering_Model_B.dv[4], &Steering_Model_B.STATE_1[0], sizeof(real_T)
           << 4U);
    Steering_Model_B.iv[2] = 20;
    simulationData->mData->mInputValues.mN = 20;
    simulationData->mData->mInputValues.mX = &Steering_Model_B.dv[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &Steering_Model_B.iv[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S55>/OUTPUT_1_0' */
    simulationData->mData->mOutputs.mX = &Steering_Model_B.OUTPUT_1_0;

    /* SimscapeExecutionBlock: '<S55>/OUTPUT_1_0' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    Steering_Model_B.time_cx = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &Steering_Model_B.time_cx;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      Steering_Model_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = ne_simulator_method((NeslSimulator *)
      Steering_Model_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (tmp_1 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(Steering_Model_M, msg_0);
      }
    }

    if (rtmIsMajorTimeStep(Steering_Model_M)) {
      /* Gain: '<S33>/Integral Gain' */
      Steering_Model_B.IntegralGain = Steering_Model_P.PIDController_I *
        Steering_Model_B.Subtract;
    }
  }

  if (rtmIsMajorTimeStep(Steering_Model_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T time;
    int32_T tmp_1;
    int_T tmp_0[2];
    boolean_T tmp;
    if (rtmIsMajorTimeStep(Steering_Model_M)) {
      /* Update for UnitDelay: '<Root>/Unit Delay' */
      Steering_Model_DW.UnitDelay_DSTATE = Steering_Model_B.OUTPUT_1_0;
    }

    /* Update for SimscapeExecutionBlock: '<S55>/STATE_1' */
    simulationData = (NeslSimulationData *)Steering_Model_DW.STATE_1_SimData;
    time = Steering_Model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 8;
    simulationData->mData->mContStates.mX =
      &Steering_Model_X.Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos
      [0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Steering_Model_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 8;
    simulationData->mData->mModeVector.mX = &Steering_Model_DW.STATE_1_Modes[0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (Steering_Model_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&Steering_Model_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&Steering_Model_M->solverInfo);
    tmp_0[0] = 0;
    Steering_Model_B.dv5[0] = Steering_Model_B.INPUT_1_1_1[0];
    Steering_Model_B.dv5[1] = Steering_Model_B.INPUT_1_1_1[1];
    Steering_Model_B.dv5[2] = Steering_Model_B.INPUT_1_1_1[2];
    Steering_Model_B.dv5[3] = Steering_Model_B.INPUT_1_1_1[3];
    tmp_0[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &Steering_Model_B.dv5[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &tmp_0[0];
    diagnosticManager = (NeuDiagnosticManager *)
      Steering_Model_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = ne_simulator_method((NeslSimulator *)
      Steering_Model_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_1 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Steering_Model_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S55>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Steering_Model_M)) {
    rt_ertODEUpdateContinuousStates(&Steering_Model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Steering_Model_M->Timing.clockTick0;
    Steering_Model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Steering_Model_M->solverInfo);

    {
      /* Update absolute timer for sample time: [2000.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2000.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Steering_Model_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Steering_Model_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_Steering_Model_T *_rtXdot;
  char *msg;
  real_T time;
  int32_T tmp_1;
  int_T tmp_0[2];
  boolean_T tmp;
  _rtXdot = ((XDot_Steering_Model_T *) Steering_Model_M->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = Steering_Model_B.IntegralGain;

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = Steering_Model_B.FilterCoefficient;

  /* Derivatives for SimscapeExecutionBlock: '<S55>/STATE_1' */
  simulationData = (NeslSimulationData *)Steering_Model_DW.STATE_1_SimData;
  time = Steering_Model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 8;
  simulationData->mData->mContStates.mX =
    &Steering_Model_X.Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos
    [0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Steering_Model_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 8;
  simulationData->mData->mModeVector.mX = &Steering_Model_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(Steering_Model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Steering_Model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&Steering_Model_M->solverInfo);
  tmp_0[0] = 0;
  Steering_Model_B.dv4[0] = Steering_Model_B.INPUT_1_1_1[0];
  Steering_Model_B.dv4[1] = Steering_Model_B.INPUT_1_1_1[1];
  Steering_Model_B.dv4[2] = Steering_Model_B.INPUT_1_1_1[2];
  Steering_Model_B.dv4[3] = Steering_Model_B.INPUT_1_1_1[3];
  tmp_0[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &Steering_Model_B.dv4[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mDx.mN = 8;
  simulationData->mData->mDx.mX =
    &_rtXdot->Steering_ModelDouble_Acting_Hydraulic_Cylinder_Simplepiston_pos[0];
  diagnosticManager = (NeuDiagnosticManager *)Steering_Model_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)
    Steering_Model_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_1 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Steering_Model_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S55>/STATE_1' */
}

/* Model initialize function */
void Steering_Model_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Steering_Model_M->solverInfo,
                          &Steering_Model_M->Timing.simTimeStep);
    rtsiSetTPtr(&Steering_Model_M->solverInfo, &rtmGetTPtr(Steering_Model_M));
    rtsiSetStepSizePtr(&Steering_Model_M->solverInfo,
                       &Steering_Model_M->Timing.stepSize0);
    rtsiSetdXPtr(&Steering_Model_M->solverInfo, &Steering_Model_M->derivs);
    rtsiSetContStatesPtr(&Steering_Model_M->solverInfo, (real_T **)
                         &Steering_Model_M->contStates);
    rtsiSetNumContStatesPtr(&Steering_Model_M->solverInfo,
      &Steering_Model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Steering_Model_M->solverInfo,
      &Steering_Model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Steering_Model_M->solverInfo,
      &Steering_Model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Steering_Model_M->solverInfo,
      &Steering_Model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Steering_Model_M->solverInfo, (&rtmGetErrorStatus
      (Steering_Model_M)));
    rtsiSetSolverMassMatrixIr(&Steering_Model_M->solverInfo,
      Steering_Model_MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&Steering_Model_M->solverInfo,
      Steering_Model_MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&Steering_Model_M->solverInfo,
      Steering_Model_MassMatrix.pr);
    rtsiSetRTModelPtr(&Steering_Model_M->solverInfo, Steering_Model_M);
  }

  rtsiSetSimTimeStep(&Steering_Model_M->solverInfo, MAJOR_TIME_STEP);
  Steering_Model_M->intgData.x0 = Steering_Model_M->odeX0;
  Steering_Model_M->intgData.f0 = Steering_Model_M->odeF0;
  Steering_Model_M->intgData.x1start = Steering_Model_M->odeX1START;
  Steering_Model_M->intgData.f1 = Steering_Model_M->odeF1;
  Steering_Model_M->intgData.Delta = Steering_Model_M->odeDELTA;
  Steering_Model_M->intgData.E = Steering_Model_M->odeE;
  Steering_Model_M->intgData.fac = Steering_Model_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = Steering_Model_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(Steering_Model_M->odeFAC)/sizeof(real_T)); i
         ++) {
      f[i] = 1.5e-8;
    }
  }

  Steering_Model_M->intgData.DFDX = Steering_Model_M->odeDFDX;
  Steering_Model_M->intgData.W = Steering_Model_M->odeW;
  Steering_Model_M->intgData.pivots = Steering_Model_M->odePIVOTS;
  Steering_Model_M->intgData.xtmp = Steering_Model_M->odeXTMP;
  Steering_Model_M->intgData.ztmp = Steering_Model_M->odeZTMP;
  Steering_Model_M->intgData.M = Steering_Model_M->odeMASSMATRIX_M;
  Steering_Model_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&Steering_Model_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&Steering_Model_M->solverInfo, 1);
  Steering_Model_M->contStates = ((X_Steering_Model_T *) &Steering_Model_X);
  Steering_Model_M->massMatrixType = ((ssMatrixType)1);
  Steering_Model_M->massMatrixNzMax = (4);
  Steering_Model_M->massMatrixIr = (Steering_Model_MassMatrix.ir);
  Steering_Model_M->massMatrixJc = (Steering_Model_MassMatrix.jc);
  Steering_Model_M->massMatrixPr = (Steering_Model_MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&Steering_Model_M->solverInfo, (ssMatrixType)1);
  rtsiSetSolverMassMatrixNzMax(&Steering_Model_M->solverInfo, 4);
  rtsiSetSolverData(&Steering_Model_M->solverInfo, (void *)
                    &Steering_Model_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Steering_Model_M->solverInfo, false);
  rtsiSetSolverName(&Steering_Model_M->solverInfo,"ode14x");
  rtmSetTPtr(Steering_Model_M, &Steering_Model_M->Timing.tArray[0]);
  Steering_Model_M->Timing.stepSize0 = 2000.0;

  /* Root-level init GlobalMassMatrixPr offset */
  {
    Steering_Model_DW.STATE_1_MASS_MATRIX_PR = 2;/* '<S55>/STATE_1' */
  }

  {
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    int_T tmp_3;
    boolean_T tmp_0;
    boolean_T tmp_2;

    /* Start for SimscapeExecutionBlock: '<S55>/STATE_1' */
    tmp = nesl_lease_simulator("Steering_Model/Solver Configuration_1", 0, 0);
    Steering_Model_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Steering_Model_DW.STATE_1_Simulator);
    if (tmp_0) {
      Steering_Model_836bb176_1_gateway();
      tmp = nesl_lease_simulator("Steering_Model/Solver Configuration_1", 0, 0);
      Steering_Model_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Steering_Model_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Steering_Model_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    Steering_Model_B.modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    Steering_Model_B.modelParameters.mSolverAbsTol = 0.001;
    Steering_Model_B.modelParameters.mSolverRelTol = 0.001;
    Steering_Model_B.modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    Steering_Model_B.modelParameters.mStartTime = 0.0;
    Steering_Model_B.modelParameters.mLoadInitialState = false;
    Steering_Model_B.modelParameters.mUseSimState = false;
    Steering_Model_B.modelParameters.mLinTrimCompile = false;
    Steering_Model_B.modelParameters.mLoggingMode = SSC_LOGGING_ALL;
    Steering_Model_B.modelParameters.mRTWModifiedTimeStamp = 5.97793053E+8;
    Steering_Model_B.d = 0.001;
    Steering_Model_B.modelParameters.mSolverTolerance = Steering_Model_B.d;
    Steering_Model_B.d = 2000.0;
    Steering_Model_B.modelParameters.mFixedStepSize = Steering_Model_B.d;
    tmp_0 = false;
    Steering_Model_B.modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    Steering_Model_B.modelParameters.mIsUsingODEN = tmp_0;
    Steering_Model_B.modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Steering_Model_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    Steering_Model_B.i = nesl_initialize_simulator((NeslSimulator *)
      Steering_Model_DW.STATE_1_Simulator, &Steering_Model_B.modelParameters,
      diagnosticManager);
    if (Steering_Model_B.i != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Steering_Model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S55>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S55>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("Steering_Model/Solver Configuration_1", 1, 0);
    Steering_Model_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Steering_Model_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      Steering_Model_836bb176_1_gateway();
      tmp = nesl_lease_simulator("Steering_Model/Solver Configuration_1", 1, 0);
      Steering_Model_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Steering_Model_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Steering_Model_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    Steering_Model_B.modelParameters_m.mSolverType = NE_SOLVER_TYPE_DAE;
    Steering_Model_B.modelParameters_m.mSolverAbsTol = 0.001;
    Steering_Model_B.modelParameters_m.mSolverRelTol = 0.001;
    Steering_Model_B.modelParameters_m.mSolverModifyAbsTol =
      NE_MODIFY_ABS_TOL_NO;
    Steering_Model_B.modelParameters_m.mStartTime = 0.0;
    Steering_Model_B.modelParameters_m.mLoadInitialState = false;
    Steering_Model_B.modelParameters_m.mUseSimState = false;
    Steering_Model_B.modelParameters_m.mLinTrimCompile = false;
    Steering_Model_B.modelParameters_m.mLoggingMode = SSC_LOGGING_ALL;
    Steering_Model_B.modelParameters_m.mRTWModifiedTimeStamp = 5.97793053E+8;
    Steering_Model_B.d = 0.001;
    Steering_Model_B.modelParameters_m.mSolverTolerance = Steering_Model_B.d;
    Steering_Model_B.d = 2000.0;
    Steering_Model_B.modelParameters_m.mFixedStepSize = Steering_Model_B.d;
    tmp_0 = false;
    Steering_Model_B.modelParameters_m.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    Steering_Model_B.modelParameters_m.mIsUsingODEN = tmp_0;
    Steering_Model_B.modelParameters_m.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Steering_Model_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    Steering_Model_B.i = nesl_initialize_simulator((NeslSimulator *)
      Steering_Model_DW.OUTPUT_1_0_Simulator,
      &Steering_Model_B.modelParameters_m, diagnosticManager);
    if (Steering_Model_B.i != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Steering_Model_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(Steering_Model_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S55>/OUTPUT_1_0' */

    /* InitializeConditions for Integrator: '<S36>/Integrator' */
    Steering_Model_X.Integrator_CSTATE =
      Steering_Model_P.PIDController_InitialConditionForIntegrator;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    Steering_Model_DW.UnitDelay_DSTATE =
      Steering_Model_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Integrator: '<S31>/Filter' */
    Steering_Model_X.Filter_CSTATE =
      Steering_Model_P.PIDController_InitialConditionForFilter;

    /* InitializeConditions for SimscapeExecutionBlock: '<S55>/STATE_1' */
    tmp_0 = false;
    tmp_2 = false;
    if (tmp_2 || tmp_0) {
      Steering_Model_B.i = strcmp(rtsiGetSolverName
        (&Steering_Model_M->solverInfo), "daessc");
      Steering_Model_B.i1 = strcmp(rtsiGetSolverName
        (&Steering_Model_M->solverInfo), "ode14x");
      Steering_Model_B.i2 = strcmp(rtsiGetSolverName
        (&Steering_Model_M->solverInfo), "ode15s");
      Steering_Model_B.i3 = strcmp(rtsiGetSolverName
        (&Steering_Model_M->solverInfo), "ode1be");
      Steering_Model_B.i4 = strcmp(rtsiGetSolverName
        (&Steering_Model_M->solverInfo), "ode23t");
      tmp_3 = strcmp(rtsiGetSolverName(&Steering_Model_M->solverInfo), "odeN");
      if ((boolean_T)((Steering_Model_B.i != 0) & (Steering_Model_B.i1 != 0) &
                      (Steering_Model_B.i2 != 0) & (Steering_Model_B.i3 != 0) &
                      (Steering_Model_B.i4 != 0) & (tmp_3 != 0))) {
        rtmSetErrorStatus(Steering_Model_M,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S55>/STATE_1' */

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[4] = { 0, 1, 2, 3 };

      static int_T modelMassMatrixJc[11] = { 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4 };

      static real_T modelMassMatrixPr[4] = { 1.0, 1.0, 1.0, 1.0 };

      (void) memcpy(Steering_Model_MassMatrix.ir, modelMassMatrixIr,
                    4*sizeof(int_T));
      (void) memcpy(Steering_Model_MassMatrix.jc, modelMassMatrixJc,
                    11*sizeof(int_T));
      (void) memcpy(Steering_Model_MassMatrix.pr, modelMassMatrixPr,
                    4*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void Steering_Model_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S55>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Steering_Model_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Steering_Model_DW.STATE_1_SimData);
  nesl_erase_simulator("Steering_Model/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S55>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Steering_Model_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Steering_Model_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("Steering_Model/Solver Configuration_1");
  nesl_destroy_registry();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
