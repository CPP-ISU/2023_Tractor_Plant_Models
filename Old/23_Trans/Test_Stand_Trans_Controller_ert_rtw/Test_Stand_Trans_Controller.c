/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test_Stand_Trans_Controller.c
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
#include "Test_Stand_Trans_Controller_types.h"
#include "rtwtypes.h"
#include <stdio.h>
#include "Test_Stand_Trans_Controller_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#define Test_Stand_Trans_Control_period (0.01)

/* Block signals (default storage) */
B_Test_Stand_Trans_Controller_T Test_Stand_Trans_Controller_B;

/* Block states (default storage) */
DW_Test_Stand_Trans_Controlle_T Test_Stand_Trans_Controller_DW;

/* Real-time model */
static RT_MODEL_Test_Stand_Trans_Con_T Test_Stand_Trans_Controller_M_;
RT_MODEL_Test_Stand_Trans_Con_T *const Test_Stand_Trans_Controller_M =
  &Test_Stand_Trans_Controller_M_;

/* Forward declaration for local functions */
static void Test_Stand_Tra_SystemCore_setup(codertarget_raspi_internal_CA_T *obj);
static int8_T Test_Stand_Trans_Contr_filedata(void);
static int8_T Test_Stand_Trans_Control_cfopen(const char_T *cfilename, const
  char_T *cpermission);
static void Test_Stand_Trans_emxInit_char_T(emxArray_char_T_Test_Stand_Tr_T
  **pEmxArray, int32_T numDimensions);
static FILE* Test_Stand_Trans_Co_fileManager(real_T varargin_1);
static void Test_S_emxEnsureCapacity_char_T(emxArray_char_T_Test_Stand_Tr_T
  *emxArray, int32_T oldNumel);
static void Test_Stand_Trans_emxFree_char_T(emxArray_char_T_Test_Stand_Tr_T
  **pEmxArray);
static void Test_Stand_Trans_Controll_fgetl(real_T fileID,
  emxArray_char_T_Test_Stand_Tr_T *out);
static int32_T Test_Stand_Trans_Contro_cfclose(real_T fid);
static void Test_Stand_T_SystemCore_setup_l(codertarget_raspi_internal__l_T *obj);
static void Test_Stand__SystemCore_setup_lm(codertarget_raspi_internal__l_T *obj);

/* n-D Spline interpolation function */
real_T look_SplNBinCZcd(uint32_T numDims, const real_T* u, const
  rt_LUTSplineWork * const SWork)
{
  /*
   *   n-D column-major table lookup operating on real_T with:
   *       - Spline interpolation
   *       - Clipping
   *       - Binary breakpoint search
   *       - Index search starts at the same place each time
   */
  rt_LUTnWork * const TWork_look = SWork->m_TWork;
  real_T* const fraction = (real_T*) TWork_look->m_bpLambda;
  uint32_T* const bpIdx = TWork_look->m_bpIndex;
  const uint32_T* const maxIndex = TWork_look->m_maxIndex;
  uint32_T k;
  for (k = 0U; k < numDims; k++) {
    const real_T* const bpData = ((const real_T * const *)
      TWork_look->m_bpDataSet)[k];
    bpIdx[k] = plook_binc(u[k], bpData, maxIndex[k], &fraction[k]);
  }

  return(intrp_NSplcd(numDims, SWork, 1U));
}

/*
 * Second derivative initialization function for spline
 * for last dimension.
 */
void rt_Spline2Derivd(const real_T *x, const real_T *y, uint32_T n, real_T *u,
                      real_T *y2)
{
  real_T p, qn, sig, un;
  uint32_T n1, i, k;
  n1 = n - 1U;
  y2[0U] = 0.0;
  u[0U] = 0.0;
  for (i = 1U; i < n1; i++) {
    real_T dxm1 = x[i] - x[i - 1U];
    real_T dxp1 = x[i + 1U] - x[i];
    real_T dxpm = dxp1 + dxm1;
    sig = dxm1 / dxpm;
    p = (sig * y2[i - 1U]) + 2.0;
    y2[i] = (sig - 1.0) / p;
    u[i] = ((y[i + 1U] - y[i]) / dxp1) - ((y[i] - y[i - 1U]) / dxm1);
    u[i] = (((6.0 * u[i]) / dxpm) - (sig * u[i - 1U])) / p;
  }

  qn = 0.0;
  un = 0.0;
  y2[n1] = (un - (qn * u[n1 - 1U])) / ((qn * y2[n1 - 1U]) + 1.0);
  for (k = n1; k > 0U; k--) {
    y2[k-1U] = (y2[k-1U] * y2[k]) + u[k-1U];
  }

  return;
}

/* n-D natural spline calculation function */
real_T intrp_NSplcd(uint32_T numDims, const rt_LUTSplineWork * const splWork,
                    uint32_T extrapMethod)
{
  uint32_T il;
  uint32_T iu, k, i;
  real_T h, s, p, smsq, pmsq;

  /* intermediate results work areas "this" and "next" */
  const rt_LUTnWork *TWork_interp = (const rt_LUTnWork *)splWork->m_TWork;
  const real_T *fraction = (real_T *) TWork_interp->m_bpLambda;
  const real_T *yp = (real_T *) TWork_interp->m_tableData;
  real_T *yyA = (real_T *) splWork->m_yyA;
  real_T *yyB = (real_T *) splWork->m_yyB;
  real_T *yy2 = (real_T *) splWork->m_yy2;
  real_T *up = (real_T *) splWork->m_up;
  real_T *y2 = (real_T *) splWork->m_y2;
  uint8_T* reCalc = splWork->m_reCalc;
  real_T *dp = (real_T *) splWork->m_preBp0AndTable;
  const real_T **bpDataSet = (const real_T **) TWork_interp->m_bpDataSet;
  const real_T *xp = bpDataSet[0U];
  real_T *yy = yyA;
  uint32_T bufBank = 0U;
  uint32_T len = TWork_interp->m_maxIndex[0U] + 1U;

  /* compare bp0 and table to see whether they get changed */
  {
    /* compare the bp0 data */
    if (memcmp(dp, xp,
               len * sizeof(real_T)) != 0) {
      *reCalc = 1;
      (void) memcpy(dp, xp,
                    len * sizeof(real_T));
    }

    /* compare the table data */
    dp = &(dp[len]);
    if (memcmp(dp, yp,
               len * splWork->m_numYWorkElts[0U] * sizeof(real_T)) != 0) {
      *reCalc = 1;
      (void) memcpy(dp, yp,
                    len * splWork->m_numYWorkElts[0U] * sizeof(real_T));
    }
  }

  if (*reCalc == 1) {
    /* If table and bps are tunable calculate 1st dim 2nd deriv */
    /* Generate first dimension's second derivatives */
    for (i = 0U; i < splWork->m_numYWorkElts[0U]; i++) {
      rt_Spline2Derivd(xp, yp, len, up, y2);
      yp = &yp[len];
      y2 = &y2[len];
    }

    /* Set pointers back to beginning */
    yp = (const real_T *) TWork_interp->m_tableData;
    y2 = (real_T *) splWork->m_y2;
  }

  *reCalc = 0;

  /* Generate at-point splines in each dimension */
  for (k = 0U; k < numDims; k++ ) {
    /* this dimension's input setup */
    xp = bpDataSet[k];
    len = TWork_interp->m_maxIndex[k] + 1U;
    il = TWork_interp->m_bpIndex[k];
    iu = il + 1U;
    h = xp[iu] - xp[il];
    p = fraction[k];
    s = 1.0 - p;
    pmsq = p * ((p*p) - 1.0);
    smsq = s * ((s*s) - 1.0);

    /*
     * Calculate spline curves for input in this
     * dimension at each value of the higher
     * other dimensions\' points in the table.
     */
    if ((p > 1.0) && (extrapMethod == 2U) ) {
      real_T slope;
      for (i = 0U; i < splWork->m_numYWorkElts[k]; i++) {
        slope = (yp[iu] - yp[il]) + ((y2[il]*h*h)*(1.0/6.0));
        yy[i] = yp[iu] + (slope * (p-1.0));
        yp = &yp[len];
        y2 = &y2[len];
      }
    } else if ((p < 0.0) && (extrapMethod == 2U) ) {
      real_T slope;
      for (i = 0U; i < splWork->m_numYWorkElts[k]; i++) {
        slope = (yp[iu] - yp[il]) - ((y2[iu]*h*h)*(1.0/6.0));
        yy[i] = yp[il] + (slope * p);
        yp = &yp[len];
        y2 = &y2[len];
      }
    } else {
      for (i = 0U; i < splWork->m_numYWorkElts[k]; i++) {
        yy[i] = yp[il] + p * (yp[iu] - yp[il]) +
          ((smsq * y2[il] + pmsq * y2[iu])*h*h)*(1.0/6.0);
        yp = &yp[len];
        y2 = &y2[len];
      }
    }

    /* set pointers to new result and calculate second derivatives */
    yp = yy;
    y2 = yy2;
    if (splWork->m_numYWorkElts[k+1U] > 0U ) {
      uint32_T nextLen = TWork_interp->m_maxIndex[k+1U] + 1U;
      const real_T *nextXp = bpDataSet[k+1U];
      for (i = 0U; i < splWork->m_numYWorkElts[k+1U]; i++) {
        rt_Spline2Derivd(nextXp, yp, nextLen, up, y2);
        yp = &yp[nextLen];
        y2 = &y2[nextLen];
      }
    }

    /*
     * Set work vectors yp, y2 and yy for next iteration;
     * the yy just calculated becomes the yp in the
     * next iteration, y2 was just calculated for these
     * new points and the yy buffer is swapped to the space
     * for storing the next iteration\'s results.
     */
    yp = yy;
    y2 = yy2;

    /*
     * Swap buffers for next dimension and
     * toggle bufBank for next iteration.
     */
    if (bufBank == 0U) {
      yy = yyA;
      bufBank = 1U;
    } else {
      yy = yyB;
      bufBank = 0U;
    }
  }

  return( yp[0U] );
}

uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void Test_Stand_Tra_SystemCore_setup(codertarget_raspi_internal_CA_T *obj)
{
  int32_T isCANSetup;
  int32_T stat;
  char_T errString3[20];
  char_T canInterface[5];
  static const char_T tmp[19] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'u',
    'p', '.', ' ', 'S', 'e', 't', ' ', 'u', 'p', ' ' };

  static const char_T tmp_0[14] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 's',
    'e', 't', ' ', 'u', 'p' };

  static const char_T tmp_1[46] = { ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't',
    ' ', 'e', 'x', 'i', 's', 't', '.', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ',
    'a', ' ', 'v', 'a', 'l', 'i', 'd', ' ', 'C', 'A', 'N', ' ', 'i', 'n', 't',
    'e', 'r', 'f', 'a', 'c', 'e', '.' };

  static const char_T tmp_2[34] = { ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'l',
    'a', 'u', 'n', 'c', 'h', 'i', 'n', 'g', ' ', 't', 'h', 'e', ' ', 'a', 'p',
    'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', '.' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  canInterface[0] = 'c';
  canInterface[1] = 'a';
  canInterface[2] = 'n';
  canInterface[3] = '0';
  canInterface[4] = '\x00';
  stat = -1;
  isCANSetup = MW_checkIFStatus(&canInterface[0]);
  if (isCANSetup == 0) {
    MW_createSocket(&canInterface[0], &obj->sockHandleDataFrames);
    stat = MW_createSocket(&canInterface[0], &obj->sockHandleErrorFrames);
  } else if (isCANSetup == 1) {
    Test_Stand_Trans_Controller_B.errString1_m[0] = 'c';
    Test_Stand_Trans_Controller_B.errString1_m[1] = 'a';
    Test_Stand_Trans_Controller_B.errString1_m[2] = 'n';
    Test_Stand_Trans_Controller_B.errString1_m[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      Test_Stand_Trans_Controller_B.errString1_m[isCANSetup + 4] =
        tmp[isCANSetup];
    }

    Test_Stand_Trans_Controller_B.errString1_m[23] = 'c';
    Test_Stand_Trans_Controller_B.errString1_m[24] = 'a';
    Test_Stand_Trans_Controller_B.errString1_m[25] = 'n';
    Test_Stand_Trans_Controller_B.errString1_m[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      Test_Stand_Trans_Controller_B.errString1_m[isCANSetup + 27] =
        tmp_2[isCANSetup];
    }

    Test_Stand_Trans_Controller_B.errString1_m[61] = '\x0a';
    Test_Stand_Trans_Controller_B.errString1_m[62] = '\x00';
    MW_printError(&Test_Stand_Trans_Controller_B.errString1_m[0]);
  } else if (isCANSetup == 2) {
    Test_Stand_Trans_Controller_B.errString2_c[0] = 'c';
    Test_Stand_Trans_Controller_B.errString2_c[1] = 'a';
    Test_Stand_Trans_Controller_B.errString2_c[2] = 'n';
    Test_Stand_Trans_Controller_B.errString2_c[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      Test_Stand_Trans_Controller_B.errString2_c[isCANSetup + 4] =
        tmp_1[isCANSetup];
    }

    Test_Stand_Trans_Controller_B.errString2_c[50] = '\x0a';
    Test_Stand_Trans_Controller_B.errString2_c[51] = '\x00';
    MW_printError(&Test_Stand_Trans_Controller_B.errString2_c[0]);
  } else {
    errString3[0] = 'c';
    errString3[1] = 'a';
    errString3[2] = 'n';
    errString3[3] = '0';
    for (isCANSetup = 0; isCANSetup < 14; isCANSetup++) {
      errString3[isCANSetup + 4] = tmp_0[isCANSetup];
    }

    errString3[18] = '\x0a';
    errString3[19] = '\x00';
    MW_printError(&errString3[0]);
  }

  obj->Initialized = (stat == 0);
  obj->isSetupComplete = true;
}

static int8_T Test_Stand_Trans_Contr_filedata(void)
{
  int32_T b_k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 20)) {
    if (Test_Stand_Trans_Controller_DW.eml_openfiles[(int8_T)(b_k + 1) - 1] ==
        NULL) {
      f = (int8_T)(b_k + 1);
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return f;
}

static int8_T Test_Stand_Trans_Control_cfopen(const char_T *cfilename, const
  char_T *cpermission)
{
  FILE* filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Test_Stand_Trans_Contr_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Test_Stand_Trans_Controller_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

static void Test_Stand_Trans_emxInit_char_T(emxArray_char_T_Test_Stand_Tr_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Test_Stand_Tr_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Test_Stand_Tr_T *)malloc(sizeof
    (emxArray_char_T_Test_Stand_Tr_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static FILE* Test_Stand_Trans_Co_fileManager(real_T varargin_1)
{
  FILE* f;
  int8_T fileid;
  fileid = (int8_T)varargin_1;
  if (varargin_1 != (int8_T)varargin_1) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Test_Stand_Trans_Controller_DW.eml_openfiles[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

static void Test_S_emxEnsureCapacity_char_T(emxArray_char_T_Test_Stand_Tr_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void Test_Stand_Trans_emxFree_char_T(emxArray_char_T_Test_Stand_Tr_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Test_Stand_Tr_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Test_Stand_Tr_T *)NULL;
  }
}

static void Test_Stand_Trans_Controll_fgetl(real_T fileID,
  emxArray_char_T_Test_Stand_Tr_T *out)
{
  emxArray_char_T_Test_Stand_Tr_T *c_line;
  emxArray_char_T_Test_Stand_Tr_T *outBuff;
  int32_T c_i;
  int32_T exitg1;
  int32_T i;
  char_T tmp;
  uint8_T buf;
  boolean_T exitg2;
  boolean_T fileEndAfterCarriageReturn;
  boolean_T newLineAfterCarriageReturn;
  boolean_T readNewline;
  Test_Stand_Trans_Controller_B.filestar = Test_Stand_Trans_Co_fileManager
    (fileID);
  if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
  } else {
    Test_Stand_Trans_Controller_B.filestar = NULL;
  }

  Test_Stand_Trans_emxInit_char_T(&outBuff, 2);
  outBuff->size[0] = 1;
  outBuff->size[1] = 0;
  Test_Stand_Trans_emxInit_char_T(&c_line, 2);
  if (Test_Stand_Trans_Controller_B.filestar == NULL) {
    c_line->size[0] = 1;
    c_line->size[1] = 0;
  } else {
    do {
      exitg1 = 0;
      Test_Stand_Trans_Controller_B.cOut = fgets
        (&Test_Stand_Trans_Controller_B.ReadBuff[0], 1024,
         Test_Stand_Trans_Controller_B.filestar);
      readNewline = false;
      Test_Stand_Trans_Controller_B.b_NULL = NULL;
      Test_Stand_Trans_Controller_B.filestar_c = Test_Stand_Trans_Co_fileManager
        (fileID);
      if (Test_Stand_Trans_Controller_B.filestar_c ==
          Test_Stand_Trans_Controller_B.b_NULL) {
        Test_Stand_Trans_Controller_B.reachedEndOfFile = 0;
      } else {
        Test_Stand_Trans_Controller_B.b_st = feof
          (Test_Stand_Trans_Controller_B.filestar_c);
        Test_Stand_Trans_Controller_B.reachedEndOfFile = ((int32_T)
          Test_Stand_Trans_Controller_B.b_st != 0);
      }

      if (Test_Stand_Trans_Controller_B.cOut == NULL) {
        exitg1 = 1;
      } else {
        Test_Stand_Trans_Controller_B.idx = 1;
        Test_Stand_Trans_Controller_B.carriageReturnAt = 0;
        if (Test_Stand_Trans_Controller_B.reachedEndOfFile != 0) {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1024)) {
            tmp = Test_Stand_Trans_Controller_B.ReadBuff[c_i - 1];
            if (tmp == '\x00') {
              Test_Stand_Trans_Controller_B.idx = c_i;
              exitg2 = true;
            } else {
              if ((Test_Stand_Trans_Controller_B.carriageReturnAt == 0) && (tmp ==
                   '\x0d')) {
                Test_Stand_Trans_Controller_B.carriageReturnAt = c_i;
              }

              c_i++;
            }
          }

          if (Test_Stand_Trans_Controller_B.ReadBuff[Test_Stand_Trans_Controller_B.idx
              - 1] == '\x00') {
            Test_Stand_Trans_Controller_B.idx--;
          }
        } else {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1025)) {
            if (c_i > 1024) {
              Test_Stand_Trans_Controller_B.idx = 1023;
              exitg2 = true;
            } else {
              tmp = Test_Stand_Trans_Controller_B.ReadBuff[c_i - 1];
              if (tmp == '\x0a') {
                Test_Stand_Trans_Controller_B.idx = c_i;
                exitg2 = true;
              } else {
                if ((Test_Stand_Trans_Controller_B.carriageReturnAt == 0) &&
                    (tmp == '\x0d')) {
                  Test_Stand_Trans_Controller_B.carriageReturnAt = c_i;
                }

                c_i++;
              }
            }
          }

          readNewline =
            (Test_Stand_Trans_Controller_B.ReadBuff[Test_Stand_Trans_Controller_B.idx
             - 1] == '\x0a');
        }

        if ((Test_Stand_Trans_Controller_B.carriageReturnAt > 0) &&
            (Test_Stand_Trans_Controller_B.carriageReturnAt < 1024)) {
          newLineAfterCarriageReturn =
            (Test_Stand_Trans_Controller_B.ReadBuff[Test_Stand_Trans_Controller_B.carriageReturnAt]
             == '\x0a');
          if ((Test_Stand_Trans_Controller_B.reachedEndOfFile != 0) &&
              (Test_Stand_Trans_Controller_B.ReadBuff[Test_Stand_Trans_Controller_B.carriageReturnAt]
               == '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }

        if ((Test_Stand_Trans_Controller_B.carriageReturnAt == 0) ||
            newLineAfterCarriageReturn || fileEndAfterCarriageReturn) {
          if (Test_Stand_Trans_Controller_B.idx < 1) {
            Test_Stand_Trans_Controller_B.idx = 0;
          }

          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += Test_Stand_Trans_Controller_B.idx;
          Test_S_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < Test_Stand_Trans_Controller_B.idx; i++) {
            outBuff->data[c_i + i] = Test_Stand_Trans_Controller_B.ReadBuff[i];
          }
        } else {
          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += Test_Stand_Trans_Controller_B.carriageReturnAt;
          Test_S_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < Test_Stand_Trans_Controller_B.carriageReturnAt; i++) {
            outBuff->data[c_i + i] = Test_Stand_Trans_Controller_B.ReadBuff[i];
          }

          Test_Stand_Trans_Controller_B.wherefrom = SEEK_CUR;
          Test_Stand_Trans_Controller_B.filestar_c =
            Test_Stand_Trans_Co_fileManager(fileID);
          if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
          } else {
            Test_Stand_Trans_Controller_B.filestar_c = NULL;
          }

          if (!(Test_Stand_Trans_Controller_B.filestar_c == NULL)) {
            fseek(Test_Stand_Trans_Controller_B.filestar_c, (long int)
                  (Test_Stand_Trans_Controller_B.carriageReturnAt -
                   Test_Stand_Trans_Controller_B.idx),
                  Test_Stand_Trans_Controller_B.wherefrom);
          }
        }

        if (readNewline || (Test_Stand_Trans_Controller_B.reachedEndOfFile != 0)
            || (Test_Stand_Trans_Controller_B.carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    Test_Stand_Trans_Controller_B.b_NULL = NULL;
    Test_Stand_Trans_Controller_B.filestar = Test_Stand_Trans_Co_fileManager
      (fileID);
    if (Test_Stand_Trans_Controller_B.filestar ==
        Test_Stand_Trans_Controller_B.b_NULL) {
      Test_Stand_Trans_Controller_B.reachedEndOfFile = 0;
    } else {
      Test_Stand_Trans_Controller_B.b_st = feof
        (Test_Stand_Trans_Controller_B.filestar);
      Test_Stand_Trans_Controller_B.reachedEndOfFile = ((int32_T)
        Test_Stand_Trans_Controller_B.b_st != 0);
    }

    if (Test_Stand_Trans_Controller_B.reachedEndOfFile == 0) {
      Test_Stand_Trans_Controller_B.filestar = Test_Stand_Trans_Co_fileManager
        (fileID);
      if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
      } else {
        Test_Stand_Trans_Controller_B.filestar = NULL;
      }

      if (!(Test_Stand_Trans_Controller_B.filestar == NULL)) {
        fread(&buf, sizeof(uint8_T), (size_t)1,
              Test_Stand_Trans_Controller_B.filestar);
      }

      Test_Stand_Trans_Controller_B.b_NULL = NULL;
      Test_Stand_Trans_Controller_B.filestar = Test_Stand_Trans_Co_fileManager
        (fileID);
      if (Test_Stand_Trans_Controller_B.filestar ==
          Test_Stand_Trans_Controller_B.b_NULL) {
        Test_Stand_Trans_Controller_B.reachedEndOfFile = 0;
      } else {
        Test_Stand_Trans_Controller_B.b_st = feof
          (Test_Stand_Trans_Controller_B.filestar);
        Test_Stand_Trans_Controller_B.reachedEndOfFile = ((int32_T)
          Test_Stand_Trans_Controller_B.b_st != 0);
      }

      if (Test_Stand_Trans_Controller_B.reachedEndOfFile == 0) {
        Test_Stand_Trans_Controller_B.wherefrom = SEEK_CUR;
        Test_Stand_Trans_Controller_B.filestar = Test_Stand_Trans_Co_fileManager
          (fileID);
        if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
        } else {
          Test_Stand_Trans_Controller_B.filestar = NULL;
        }

        if (!(Test_Stand_Trans_Controller_B.filestar == NULL)) {
          fseek(Test_Stand_Trans_Controller_B.filestar, (long int)-1.0,
                Test_Stand_Trans_Controller_B.wherefrom);
        }
      }
    }

    i = c_line->size[0] * c_line->size[1];
    c_line->size[0] = 1;
    c_line->size[1] = outBuff->size[1];
    Test_S_emxEnsureCapacity_char_T(c_line, i);
    Test_Stand_Trans_Controller_B.reachedEndOfFile = outBuff->size[1];
    if (Test_Stand_Trans_Controller_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&c_line->data[0], &outBuff->data[0], (uint32_T)
             Test_Stand_Trans_Controller_B.reachedEndOfFile * sizeof(char_T));
    }
  }

  Test_Stand_Trans_emxFree_char_T(&outBuff);
  if (c_line->size[1] == 0) {
    out->size[0] = 1;
    out->size[1] = 0;
  } else if (c_line->data[c_line->size[1] - 1] == '\x0a') {
    if ((c_line->size[1] > 1) && (c_line->data[c_line->size[1] - 2] == '\x0d'))
    {
      if (c_line->size[1] - 2 < 1) {
        Test_Stand_Trans_Controller_B.reachedEndOfFile = 0;
      } else {
        Test_Stand_Trans_Controller_B.reachedEndOfFile = c_line->size[1] - 2;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = Test_Stand_Trans_Controller_B.reachedEndOfFile;
      Test_S_emxEnsureCapacity_char_T(out, i);
      if (Test_Stand_Trans_Controller_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               Test_Stand_Trans_Controller_B.reachedEndOfFile * sizeof(char_T));
      }
    } else {
      if (c_line->size[1] - 1 < 1) {
        Test_Stand_Trans_Controller_B.reachedEndOfFile = 0;
      } else {
        Test_Stand_Trans_Controller_B.reachedEndOfFile = c_line->size[1] - 1;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = Test_Stand_Trans_Controller_B.reachedEndOfFile;
      Test_S_emxEnsureCapacity_char_T(out, i);
      if (Test_Stand_Trans_Controller_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               Test_Stand_Trans_Controller_B.reachedEndOfFile * sizeof(char_T));
      }
    }
  } else if (c_line->data[c_line->size[1] - 1] == '\x0d') {
    if (c_line->size[1] - 1 < 1) {
      Test_Stand_Trans_Controller_B.reachedEndOfFile = 0;
    } else {
      Test_Stand_Trans_Controller_B.reachedEndOfFile = c_line->size[1] - 1;
    }

    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = Test_Stand_Trans_Controller_B.reachedEndOfFile;
    Test_S_emxEnsureCapacity_char_T(out, i);
    if (Test_Stand_Trans_Controller_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&out->data[0], &c_line->data[0], (uint32_T)
             Test_Stand_Trans_Controller_B.reachedEndOfFile * sizeof(char_T));
    }
  } else {
    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = c_line->size[1];
    Test_S_emxEnsureCapacity_char_T(out, i);
    Test_Stand_Trans_Controller_B.reachedEndOfFile = c_line->size[1];
    memcpy(&out->data[0], &c_line->data[0], (uint32_T)
           Test_Stand_Trans_Controller_B.reachedEndOfFile * sizeof(char_T));
  }

  Test_Stand_Trans_emxFree_char_T(&c_line);
}

static int32_T Test_Stand_Trans_Contro_cfclose(real_T fid)
{
  FILE* b_f;
  int32_T cst;
  int32_T st;
  int8_T fileid;
  int8_T fileid_0;
  st = -1;
  fileid = (int8_T)fid;
  if (fid != (int8_T)fid) {
    fileid = -1;
  }

  fileid_0 = fileid;
  if (fileid < 0) {
    fileid_0 = -1;
  }

  if (fileid_0 >= 3) {
    b_f = Test_Stand_Trans_Controller_DW.eml_openfiles[fileid_0 - 3];
  } else if (fileid_0 == 0) {
    b_f = stdin;
  } else if (fileid_0 == 1) {
    b_f = stdout;
  } else if (fileid_0 == 2) {
    b_f = stderr;
  } else {
    b_f = NULL;
  }

  if ((b_f != NULL) && (fileid >= 3)) {
    cst = fclose(b_f);
    if (cst == 0) {
      st = 0;
      Test_Stand_Trans_Controller_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }

  return st;
}

static void Test_Stand_T_SystemCore_setup_l(codertarget_raspi_internal__l_T *obj)
{
  emxArray_char_T_Test_Stand_Tr_T *errString1;
  emxArray_char_T_Test_Stand_Tr_T *tline;
  int8_T fileid;
  boolean_T b_bool;
  boolean_T e;
  static const char_T tmp[158] = { 's', 'u', 'd', 'o', ' ', 't', 'o', 'u', 'c',
    'h', ' ', 'M', 'W', '_', 'S', 'o', 'c', 'k', 'e', 't', 'C', 'A', 'N', '_',
    'E', 'r', 'r', 'o', 'r', '_', 'I', 'P', 'L', 'i', 'n', 'k', '.', 't', 'x',
    't', ' ', ';', ' ', 's', 'u', 'd', 'o', ' ', 't', 'r', 'u', 'n', 'c', 'a',
    't', 'e', ' ', '-', 's', ' ', '0', ' ', 'M', 'W', '_', 'S', 'o', 'c', 'k',
    'e', 't', 'C', 'A', 'N', '_', 'E', 'r', 'r', 'o', 'r', '_', 'I', 'P', 'L',
    'i', 'n', 'k', '.', 't', 'x', 't', ' ', ';', ' ', 's', 'u', 'd', 'o', ' ',
    'c', 'h', 'm', 'o', 'd', ' ', '7', '7', '7', ' ', 'M', 'W', '_', 'S', 'o',
    'c', 'k', 'e', 't', 'C', 'A', 'N', '_', 'E', 'r', 'r', 'o', 'r', '_', 'I',
    'P', 'L', 'i', 'n', 'k', '.', 't', 'x', 't', ' ', ';', ' ', 's', 'u', 'd',
    'o', ' ', 'i', 'p', ' ', 'l', 'i', 'n', 'k', ' ', 's', 'e', 't', ' ' };

  static const char_T tmp_0[21] = { ' ', 'u', 'p', ' ', 't', 'y', 'p', 'e', ' ',
    'c', 'a', 'n', ' ', 'b', 'i', 't', 'r', 'a', 't', 'e', ' ' };

  static const char_T tmp_1[32] = { ' ', '2', '>', 'M', 'W', '_', 'S', 'o', 'c',
    'k', 'e', 't', 'C', 'A', 'N', '_', 'E', 'r', 'r', 'o', 'r', '_', 'I', 'P',
    'L', 'i', 'n', 'k', '.', 't', 'x', 't' };

  static const char_T tmp_2[42] = { 'R', 'T', 'N', 'E', 'T', 'L', 'I', 'N', 'K',
    ' ', 'a', 'n', 's', 'w', 'e', 'r', 's', ':', ' ', 'D', 'e', 'v', 'i', 'c',
    'e', ' ', 'o', 'r', ' ', 'r', 'e', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'b',
    'u', 's', 'y' };

  static const char_T tmp_3[25] = { 'C', 'a', 'n', 'n', 'o', 't', ' ', 'f', 'i',
    'n', 'd', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ', '\"', 'c', 'a', 'n', '0',
    '\"' };

  static const char_T tmp_4[41] = { 's', 'u', 'd', 'o', ' ', 't', 'o', 'u', 'c',
    'h', ' ', 'M', 'W', '_', 'S', 'o', 'c', 'k', 'e', 't', 'C', 'A', 'N', '_',
    'G', 'e', 't', 'B', 'i', 't', 'R', 'a', 't', 'e', '.', 't', 'x', 't', ' ',
    ';', ' ' };

  static const char_T tmp_5[49] = { 's', 'u', 'd', 'o', ' ', 't', 'r', 'u', 'n',
    'c', 'a', 't', 'e', ' ', '-', 's', ' ', '0', ' ', 'M', 'W', '_', 'S', 'o',
    'c', 'k', 'e', 't', 'C', 'A', 'N', '_', 'G', 'e', 't', 'B', 'i', 't', 'R',
    'a', 't', 'e', '.', 't', 'x', 't', ' ', ';', ' ' };

  static const char_T tmp_6[45] = { 's', 'u', 'd', 'o', ' ', 'c', 'h', 'm', 'o',
    'd', ' ', '7', '7', '7', ' ', 'M', 'W', '_', 'S', 'o', 'c', 'k', 'e', 't',
    'C', 'A', 'N', '_', 'G', 'e', 't', 'B', 'i', 't', 'R', 'a', 't', 'e', '.',
    't', 'x', 't', ' ', ';', ' ' };

  static const char_T tmp_7[23] = { 's', 'u', 'd', 'o', ' ', 'i', 'p', ' ', '-',
    'd', 'e', 't', ' ', 'l', 'i', 'n', 'k', ' ', 's', 'h', 'o', 'w', ' ' };

  static const char_T tmp_8[18] = { ' ', '|', ' ', 'g', 'r', 'e', 'p', ' ', 'b',
    'i', 't', 'r', 'a', 't', 'e', ' ', '|', ' ' };

  static const char_T tmp_9[11] = { 'C', 'a', 'n', 'n', 'o', 't', ' ', 's', 'e',
    't', ' ' };

  static const char_T tmp_a[12] = { '\'', '{', 'p', 'r', 'i', 'n', 't', ' ', '$',
    '2', '}', '\'' };

  static const char_T tmp_b[29] = { ' ', '>', 'M', 'W', '_', 'S', 'o', 'c', 'k',
    'e', 't', 'C', 'A', 'N', '_', 'G', 'e', 't', 'B', 'i', 't', 'R', 'a', 't',
    'e', '.', 't', 'x', 't' };

  static const char_T tmp_c[14] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 's',
    'e', 't', ' ', 'u', 'p' };

  static const char_T tmp_d[24] = { ' ', 'i', 's', ' ', 'a', 'l', 'r', 'e', 'a',
    'd', 'y', ' ', 's', 'e', 't', ' ', 'u', 'p', ' ', 'w', 'i', 't', 'h', ' ' };

  int32_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Test_Stand_Trans_Controller_B.canInterface[0] = 'c';
  Test_Stand_Trans_Controller_B.canInterface[1] = 'a';
  Test_Stand_Trans_Controller_B.canInterface[2] = 'n';
  Test_Stand_Trans_Controller_B.canInterface[3] = '0';
  Test_Stand_Trans_Controller_B.canInterface[4] = '\x00';
  Test_Stand_Trans_Controller_B.stat1 = -1;
  Test_Stand_Trans_Controller_B.stat2 = -1;
  MW_checkIFStatus(&Test_Stand_Trans_Controller_B.canInterface[0]);
  Test_Stand_Trans_Controller_B.len = MW_bitrate
    (&Test_Stand_Trans_Controller_B.bitRate[0]);
  if (Test_Stand_Trans_Controller_B.len < 1) {
    Test_Stand_Trans_Controller_B.j = -1;
  } else {
    Test_Stand_Trans_Controller_B.j = Test_Stand_Trans_Controller_B.len - 1;
  }

  memcpy(&Test_Stand_Trans_Controller_B.cmd_data[0], &tmp[0], 158U * sizeof
         (char_T));
  Test_Stand_Trans_Controller_B.cmd_data[158] = 'c';
  Test_Stand_Trans_Controller_B.cmd_data[159] = 'a';
  Test_Stand_Trans_Controller_B.cmd_data[160] = 'n';
  Test_Stand_Trans_Controller_B.cmd_data[161] = '0';
  for (Test_Stand_Trans_Controller_B.len = 0; Test_Stand_Trans_Controller_B.len <
       21; Test_Stand_Trans_Controller_B.len++) {
    Test_Stand_Trans_Controller_B.cmd_data[Test_Stand_Trans_Controller_B.len +
      162] = tmp_0[Test_Stand_Trans_Controller_B.len];
  }

  if (Test_Stand_Trans_Controller_B.j >= 0) {
    memcpy(&Test_Stand_Trans_Controller_B.cmd_data[183],
           &Test_Stand_Trans_Controller_B.bitRate[0], (uint32_T)
           (Test_Stand_Trans_Controller_B.j + 1) * sizeof(char_T));
  }

  for (Test_Stand_Trans_Controller_B.len = 0; Test_Stand_Trans_Controller_B.len <
       32; Test_Stand_Trans_Controller_B.len++) {
    Test_Stand_Trans_Controller_B.cmd_data[(Test_Stand_Trans_Controller_B.len +
      Test_Stand_Trans_Controller_B.j) + 184] =
      tmp_1[Test_Stand_Trans_Controller_B.len];
  }

  Test_Stand_Trans_Controller_B.cmd_data[Test_Stand_Trans_Controller_B.j + 216] =
    '\x00';
  MW_loadCANModules(1);
  MW_setupCANLink(&Test_Stand_Trans_Controller_B.cmd_data[0], 1);
  fileid = Test_Stand_Trans_Control_cfopen("MW_SocketCAN_Error_IPLink.txt", "rb");
  Test_Stand_Trans_emxInit_char_T(&tline, 2);
  Test_Stand_Trans_Controll_fgetl((real_T)fileid, tline);
  Test_Stand_Trans_Contro_cfclose((real_T)fileid);
  Test_Stand_Trans_emxInit_char_T(&errString1, 2);
  guard1 = false;
  guard2 = false;
  if (tline->size[1] == 0) {
    guard2 = true;
  } else {
    for (Test_Stand_Trans_Controller_B.len = 0;
         Test_Stand_Trans_Controller_B.len < 42;
         Test_Stand_Trans_Controller_B.len++) {
      Test_Stand_Trans_Controller_B.patVal[Test_Stand_Trans_Controller_B.len] =
        tmp_2[Test_Stand_Trans_Controller_B.len];
    }

    Test_Stand_Trans_Controller_B.len = 1;
    do {
      exitg1 = 0;
      if (Test_Stand_Trans_Controller_B.len - 1 <= tline->size[1] - 42) {
        Test_Stand_Trans_Controller_B.j = 1;
        while ((Test_Stand_Trans_Controller_B.j <= 42) && (tline->data
                [(Test_Stand_Trans_Controller_B.len +
                  Test_Stand_Trans_Controller_B.j) - 2] ==
                Test_Stand_Trans_Controller_B.patVal[Test_Stand_Trans_Controller_B.j
                - 1])) {
          Test_Stand_Trans_Controller_B.j++;
        }

        if (Test_Stand_Trans_Controller_B.j > 42) {
          exitg1 = 1;
        } else {
          Test_Stand_Trans_Controller_B.len++;
        }
      } else {
        Test_Stand_Trans_Controller_B.len = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (Test_Stand_Trans_Controller_B.len > 0) {
      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 41;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len] =
          tmp_4[Test_Stand_Trans_Controller_B.len];
      }

      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 49;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len + 41]
          = tmp_5[Test_Stand_Trans_Controller_B.len];
      }

      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 45;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len + 90]
          = tmp_6[Test_Stand_Trans_Controller_B.len];
      }

      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 23;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len +
          135] = tmp_7[Test_Stand_Trans_Controller_B.len];
      }

      Test_Stand_Trans_Controller_B.cmd[158] = 'c';
      Test_Stand_Trans_Controller_B.cmd[159] = 'a';
      Test_Stand_Trans_Controller_B.cmd[160] = 'n';
      Test_Stand_Trans_Controller_B.cmd[161] = '0';
      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 18;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len +
          162] = tmp_8[Test_Stand_Trans_Controller_B.len];
      }

      Test_Stand_Trans_Controller_B.cmd[180] = 'a';
      Test_Stand_Trans_Controller_B.cmd[181] = 'w';
      Test_Stand_Trans_Controller_B.cmd[182] = 'k';
      Test_Stand_Trans_Controller_B.cmd[183] = ' ';
      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 12;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len +
          184] = tmp_a[Test_Stand_Trans_Controller_B.len];
      }

      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 29;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.cmd[Test_Stand_Trans_Controller_B.len +
          196] = tmp_b[Test_Stand_Trans_Controller_B.len];
      }

      Test_Stand_Trans_Controller_B.cmd[225] = '\x00';
      MW_executeCommand(&Test_Stand_Trans_Controller_B.cmd[0]);
      fileid = Test_Stand_Trans_Control_cfopen("MW_SocketCAN_GetBitRate.txt",
        "rb");
      Test_Stand_Trans_Controll_fgetl((real_T)fileid, tline);
      Test_Stand_Trans_Contro_cfclose((real_T)fileid);
      Test_Stand_Trans_Controller_B.len = MW_bitrate
        (&Test_Stand_Trans_Controller_B.bitRate[0]);
      if (Test_Stand_Trans_Controller_B.len < 1) {
        Test_Stand_Trans_Controller_B.len = 0;
      }

      b_bool = false;
      e = (tline->size[1] == 0);
      if (e && (Test_Stand_Trans_Controller_B.len == 0)) {
        b_bool = true;
      } else if (Test_Stand_Trans_Controller_B.len != tline->size[1]) {
      } else {
        Test_Stand_Trans_Controller_B.j = 1;
        do {
          exitg1 = 0;
          if (Test_Stand_Trans_Controller_B.j - 1 <= (uint8_T)
              Test_Stand_Trans_Controller_B.len - 1) {
            if (tline->data[Test_Stand_Trans_Controller_B.j - 1] !=
                Test_Stand_Trans_Controller_B.bitRate[Test_Stand_Trans_Controller_B.j
                - 1]) {
              exitg1 = 1;
            } else {
              Test_Stand_Trans_Controller_B.j++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        guard2 = true;
      } else {
        Test_Stand_Trans_Controller_B.len = errString1->size[0] *
          errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1] + 30;
        Test_S_emxEnsureCapacity_char_T(errString1,
          Test_Stand_Trans_Controller_B.len);
        errString1->data[0] = 'c';
        errString1->data[1] = 'a';
        errString1->data[2] = 'n';
        errString1->data[3] = '0';
        for (Test_Stand_Trans_Controller_B.len = 0;
             Test_Stand_Trans_Controller_B.len < 24;
             Test_Stand_Trans_Controller_B.len++) {
          errString1->data[Test_Stand_Trans_Controller_B.len + 4] =
            tmp_d[Test_Stand_Trans_Controller_B.len];
        }

        Test_Stand_Trans_Controller_B.j = tline->size[1];
        if (Test_Stand_Trans_Controller_B.j - 1 >= 0) {
          memcpy(&errString1->data[28], &tline->data[0], (uint32_T)
                 Test_Stand_Trans_Controller_B.j * sizeof(char_T));
        }

        errString1->data[tline->size[1] + 28] = '\x0a';
        errString1->data[tline->size[1] + 29] = '\x00';
        MW_printError(&errString1->data[0]);
        guard1 = true;
      }
    } else {
      for (Test_Stand_Trans_Controller_B.len = 0;
           Test_Stand_Trans_Controller_B.len < 25;
           Test_Stand_Trans_Controller_B.len++) {
        Test_Stand_Trans_Controller_B.patVal_k[Test_Stand_Trans_Controller_B.len]
          = tmp_3[Test_Stand_Trans_Controller_B.len];
      }

      Test_Stand_Trans_Controller_B.len = 1;
      do {
        exitg1 = 0;
        if (Test_Stand_Trans_Controller_B.len - 1 <= tline->size[1] - 25) {
          Test_Stand_Trans_Controller_B.j = 1;
          while ((Test_Stand_Trans_Controller_B.j <= 25) && (tline->data
                  [(Test_Stand_Trans_Controller_B.len +
                    Test_Stand_Trans_Controller_B.j) - 2] ==
                  Test_Stand_Trans_Controller_B.patVal_k[Test_Stand_Trans_Controller_B.j
                  - 1])) {
            Test_Stand_Trans_Controller_B.j++;
          }

          if (Test_Stand_Trans_Controller_B.j > 25) {
            exitg1 = 1;
          } else {
            Test_Stand_Trans_Controller_B.len++;
          }
        } else {
          Test_Stand_Trans_Controller_B.len = 0;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (Test_Stand_Trans_Controller_B.len > 0) {
        Test_Stand_Trans_Controller_B.len = errString1->size[0] *
          errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        Test_S_emxEnsureCapacity_char_T(errString1,
          Test_Stand_Trans_Controller_B.len);
        Test_Stand_Trans_Controller_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)
               Test_Stand_Trans_Controller_B.j * sizeof(char_T));
        MW_printError(&errString1->data[0]);
      } else {
        Test_Stand_Trans_Controller_B.len = errString1->size[0] *
          errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        Test_S_emxEnsureCapacity_char_T(errString1,
          Test_Stand_Trans_Controller_B.len);
        Test_Stand_Trans_Controller_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)
               Test_Stand_Trans_Controller_B.j * sizeof(char_T));
        MW_printError(&errString1->data[0]);
      }

      guard1 = true;
    }
  }

  if (guard2) {
    Test_Stand_Trans_Controller_B.stat1 = MW_createSocket
      (&Test_Stand_Trans_Controller_B.canInterface[0],
       &obj->sockHandleDataFrames);
    Test_Stand_Trans_Controller_B.stat2 = MW_createSocket
      (&Test_Stand_Trans_Controller_B.canInterface[0],
       &obj->sockHandleErrorFrames);
  }

  if (guard1) {
    for (Test_Stand_Trans_Controller_B.len = 0;
         Test_Stand_Trans_Controller_B.len < 11;
         Test_Stand_Trans_Controller_B.len++) {
      Test_Stand_Trans_Controller_B.errString0[Test_Stand_Trans_Controller_B.len]
        = tmp_9[Test_Stand_Trans_Controller_B.len];
    }

    Test_Stand_Trans_Controller_B.errString0[11] = 'c';
    Test_Stand_Trans_Controller_B.errString0[12] = 'a';
    Test_Stand_Trans_Controller_B.errString0[13] = 'n';
    Test_Stand_Trans_Controller_B.errString0[14] = '0';
    Test_Stand_Trans_Controller_B.errString0[15] = '\x0a';
    Test_Stand_Trans_Controller_B.errString0[16] = '\x00';
    MW_printError(&Test_Stand_Trans_Controller_B.errString0[0]);
    Test_Stand_Trans_Controller_B.errString3[0] = 'c';
    Test_Stand_Trans_Controller_B.errString3[1] = 'a';
    Test_Stand_Trans_Controller_B.errString3[2] = 'n';
    Test_Stand_Trans_Controller_B.errString3[3] = '0';
    for (Test_Stand_Trans_Controller_B.len = 0;
         Test_Stand_Trans_Controller_B.len < 14;
         Test_Stand_Trans_Controller_B.len++) {
      Test_Stand_Trans_Controller_B.errString3[Test_Stand_Trans_Controller_B.len
        + 4] = tmp_c[Test_Stand_Trans_Controller_B.len];
    }

    Test_Stand_Trans_Controller_B.errString3[18] = '\x0a';
    Test_Stand_Trans_Controller_B.errString3[19] = '\x00';
    MW_printError(&Test_Stand_Trans_Controller_B.errString3[0]);
  }

  Test_Stand_Trans_emxFree_char_T(&errString1);
  Test_Stand_Trans_emxFree_char_T(&tline);
  if ((Test_Stand_Trans_Controller_B.stat1 == 0) &&
      (Test_Stand_Trans_Controller_B.stat2 == 0)) {
    obj->Initialized = true;
  } else {
    obj->Initialized = false;
  }

  obj->isSetupComplete = true;
}

static void Test_Stand__SystemCore_setup_lm(codertarget_raspi_internal__l_T *obj)
{
  int32_T isCANSetup;
  int32_T stat1;
  int32_T stat2;
  char_T errString3[20];
  char_T canInterface[5];
  static const char_T tmp[19] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'u',
    'p', '.', ' ', 'S', 'e', 't', ' ', 'u', 'p', ' ' };

  static const char_T tmp_0[14] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 's',
    'e', 't', ' ', 'u', 'p' };

  static const char_T tmp_1[46] = { ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't',
    ' ', 'e', 'x', 'i', 's', 't', '.', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ',
    'a', ' ', 'v', 'a', 'l', 'i', 'd', ' ', 'C', 'A', 'N', ' ', 'i', 'n', 't',
    'e', 'r', 'f', 'a', 'c', 'e', '.' };

  static const char_T tmp_2[34] = { ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'l',
    'a', 'u', 'n', 'c', 'h', 'i', 'n', 'g', ' ', 't', 'h', 'e', ' ', 'a', 'p',
    'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', '.' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  canInterface[0] = 'c';
  canInterface[1] = 'a';
  canInterface[2] = 'n';
  canInterface[3] = '0';
  canInterface[4] = '\x00';
  stat1 = -1;
  stat2 = -1;
  isCANSetup = MW_checkIFStatus(&canInterface[0]);
  if (isCANSetup == 0) {
    stat1 = MW_createSocket(&canInterface[0], &obj->sockHandleDataFrames);
    stat2 = MW_createSocket(&canInterface[0], &obj->sockHandleErrorFrames);
  } else if (isCANSetup == 1) {
    Test_Stand_Trans_Controller_B.errString1[0] = 'c';
    Test_Stand_Trans_Controller_B.errString1[1] = 'a';
    Test_Stand_Trans_Controller_B.errString1[2] = 'n';
    Test_Stand_Trans_Controller_B.errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      Test_Stand_Trans_Controller_B.errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    Test_Stand_Trans_Controller_B.errString1[23] = 'c';
    Test_Stand_Trans_Controller_B.errString1[24] = 'a';
    Test_Stand_Trans_Controller_B.errString1[25] = 'n';
    Test_Stand_Trans_Controller_B.errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      Test_Stand_Trans_Controller_B.errString1[isCANSetup + 27] =
        tmp_2[isCANSetup];
    }

    Test_Stand_Trans_Controller_B.errString1[61] = '\x0a';
    Test_Stand_Trans_Controller_B.errString1[62] = '\x00';
    MW_printError(&Test_Stand_Trans_Controller_B.errString1[0]);
  } else if (isCANSetup == 2) {
    Test_Stand_Trans_Controller_B.errString2[0] = 'c';
    Test_Stand_Trans_Controller_B.errString2[1] = 'a';
    Test_Stand_Trans_Controller_B.errString2[2] = 'n';
    Test_Stand_Trans_Controller_B.errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      Test_Stand_Trans_Controller_B.errString2[isCANSetup + 4] =
        tmp_1[isCANSetup];
    }

    Test_Stand_Trans_Controller_B.errString2[50] = '\x0a';
    Test_Stand_Trans_Controller_B.errString2[51] = '\x00';
    MW_printError(&Test_Stand_Trans_Controller_B.errString2[0]);
  } else {
    errString3[0] = 'c';
    errString3[1] = 'a';
    errString3[2] = 'n';
    errString3[3] = '0';
    for (isCANSetup = 0; isCANSetup < 14; isCANSetup++) {
      errString3[isCANSetup + 4] = tmp_0[isCANSetup];
    }

    errString3[18] = '\x0a';
    errString3[19] = '\x00';
    MW_printError(&errString3[0]);
  }

  if ((stat1 == 0) && (stat2 == 0)) {
    obj->Initialized = true;
  } else {
    obj->Initialized = false;
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Test_Stand_Trans_Controller_step(void)
{
  real_T rtb_Gain11_tmp;
  real_T rtb_IC3_tmp;
  int32_T b_i;
  int32_T sockStatus;
  char_T rxInterface[5];
  uint8_T remote;
  uint8_T status;
  boolean_T rtb_IC2;

  /* MATLABSystem: '<Root>/CAN Receive' */
  if (Test_Stand_Trans_Controller_DW.obj.SampleTime !=
      Test_Stand_Trans_Controller_P.CANReceive_SampleTime) {
    Test_Stand_Trans_Controller_DW.obj.SampleTime =
      Test_Stand_Trans_Controller_P.CANReceive_SampleTime;
  }

  if (Test_Stand_Trans_Controller_DW.obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    sockStatus = MW_CAN_receiveCANMsg(&rxInterface[0],
      &Test_Stand_Trans_Controller_B.CANReceive_o1.ID,
      &Test_Stand_Trans_Controller_B.rxData[0],
      &Test_Stand_Trans_Controller_B.CANReceive_o1.Length, &status,
      &Test_Stand_Trans_Controller_B.CANReceive_o1.Extended, &remote,
      &Test_Stand_Trans_Controller_B.CANReceive_o1.Error,
      Test_Stand_Trans_Controller_DW.obj.sockHandleDataFrames,
      Test_Stand_Trans_Controller_DW.obj.sockHandleErrorFrames);
    Test_Stand_Trans_Controller_B.CANReceive_o1.Remote = (uint8_T)(remote == 0);
    if (sockStatus != 0) {
      Test_Stand_Trans_Controller_DW.obj.Initialized = false;
    }

    Test_Stand_Trans_Controller_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      Test_Stand_Trans_Controller_B.CANReceive_o1.Data[sockStatus] =
        Test_Stand_Trans_Controller_B.rxData[sockStatus];
    }
  } else {
    Test_Stand_Trans_Controller_B.CANReceive_o1.Extended = 0U;
    Test_Stand_Trans_Controller_B.CANReceive_o1.Length = 0U;
    Test_Stand_Trans_Controller_B.CANReceive_o1.Remote = 0U;
    Test_Stand_Trans_Controller_B.CANReceive_o1.Error = 0U;
    Test_Stand_Trans_Controller_B.CANReceive_o1.ID = 0U;
    Test_Stand_Trans_Controller_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      Test_Stand_Trans_Controller_B.CANReceive_o1.Data[sockStatus] = 0U;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Receive' */

  /* S-Function (scanunpack): '<Root>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == Test_Stand_Trans_Controller_B.CANReceive_o1.Length) &&
        (Test_Stand_Trans_Controller_B.CANReceive_o1.ID != INVALID_CAN_ID) ) {
      if ((201392387 == Test_Stand_Trans_Controller_B.CANReceive_o1.ID) && (1U ==
           Test_Stand_Trans_Controller_B.CANReceive_o1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[4]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[5]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Test_Stand_Trans_Controller_B.Pressure_A = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[6]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[7]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Test_Stand_Trans_Controller_B.Pressure_B = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[1]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Test_Stand_Trans_Controller_B.MP1_Speed = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[2]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Test_Stand_Trans_Controller_B.CANReceive_o1.Data[3]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Test_Stand_Trans_Controller_B.MP2_Speed = result;
            }
          }
        }
      }
    }
  }

  /* Sum: '<S1>/Add3' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   */
  rtb_Gain11_tmp = Test_Stand_Trans_Controller_P.Constant1_Value +
    Test_Stand_Trans_Controller_P.Constant3_Value;

  /* Gain: '<S1>/Gain11' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  Product: '<S1>/Divide16'
   *  Product: '<S1>/Divide17'
   *  Product: '<S1>/Divide18'
   *  Product: '<S1>/Product11'
   *  Product: '<S1>/Product12'
   *  Product: '<S1>/Product13'
   *  Product: '<S1>/Product14'
   *  Sum: '<S1>/Add3'
   *  Sum: '<S1>/Subtract4'
   */
  Test_Stand_Trans_Controller_B.Gain11 =
    (Test_Stand_Trans_Controller_P.Constant7_Value *
     Test_Stand_Trans_Controller_B.MP2_Speed /
     Test_Stand_Trans_Controller_P.Constant6_Value * rtb_Gain11_tmp -
     Test_Stand_Trans_Controller_B.MP1_Speed *
     Test_Stand_Trans_Controller_P.Constant5_Value /
     Test_Stand_Trans_Controller_P.Constant4_Value *
     Test_Stand_Trans_Controller_P.Constant3_Value) /
    Test_Stand_Trans_Controller_P.Constant1_Value *
    Test_Stand_Trans_Controller_P.Gain11_Gain;

  /* Saturate: '<S1>/Saturation14' incorporates:
   *  Gain: '<S1>/Gain13'
   */
  Test_Stand_Trans_Controller_B.Saturation14 =
    Test_Stand_Trans_Controller_P.Gain13_Gain *
    Test_Stand_Trans_Controller_B.Gain11;

  /* Fcn: '<S1>/MaxTorqueatSpeed' */
  Test_Stand_Trans_Controller_B.MaxTorque = (-1.9E-5 * rt_powd_snf
    (Test_Stand_Trans_Controller_B.Saturation14, 2.0) + 0.102035 *
    Test_Stand_Trans_Controller_B.Saturation14) - 80.132873;

  /* Sum: '<S1>/Subtract8' incorporates:
   *  Sum: '<S1>/Subtract10'
   *  Sum: '<S1>/Subtract2'
   *  Sum: '<S1>/Subtract3'
   */
  Test_Stand_Trans_Controller_B.Min1 = Test_Stand_Trans_Controller_B.Pressure_A
    - Test_Stand_Trans_Controller_B.Pressure_B;

  /* Saturate: '<S1>/Saturation14' incorporates:
   *  Abs: '<S1>/Abs10'
   *  Sum: '<S1>/Subtract8'
   */
  Test_Stand_Trans_Controller_B.Saturation14 =
    Test_Stand_Trans_Controller_B.Min1;
  Test_Stand_Trans_Controller_B.Saturation14 = fabs
    (Test_Stand_Trans_Controller_B.Saturation14);

  /* Saturate: '<S1>/Saturation8' */
  if (Test_Stand_Trans_Controller_B.Saturation14 >
      Test_Stand_Trans_Controller_P.Saturation8_UpperSat) {
    /* Saturate: '<S1>/Saturation14' */
    Test_Stand_Trans_Controller_B.Saturation14 =
      Test_Stand_Trans_Controller_P.Saturation8_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.Saturation14 <
             Test_Stand_Trans_Controller_P.Saturation8_LowerSat) {
    /* Saturate: '<S1>/Saturation14' */
    Test_Stand_Trans_Controller_B.Saturation14 =
      Test_Stand_Trans_Controller_P.Saturation8_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation8' */

  /* Saturate: '<S1>/Saturation14' incorporates:
   *  Gain: '<S1>/Gain25'
   */
  Test_Stand_Trans_Controller_B.Saturation14 *=
    Test_Stand_Trans_Controller_P.Gain25_Gain;

  /* Abs: '<S1>/Abs11' */
  Test_Stand_Trans_Controller_B.IC = fabs
    (Test_Stand_Trans_Controller_B.MP2_Speed);

  /* RateLimiter: '<Root>/Rate Limiter1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  Test_Stand_Trans_Controller_B.Product6 =
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE -
    Test_Stand_Trans_Controller_DW.PrevY;
  if (Test_Stand_Trans_Controller_B.Product6 >
      Test_Stand_Trans_Controller_P.RateLimiter1_RisingLim *
      Test_Stand_Trans_Control_period) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.RateLimiter1_RisingLim *
      Test_Stand_Trans_Control_period + Test_Stand_Trans_Controller_DW.PrevY;
  } else if (Test_Stand_Trans_Controller_B.Product6 <
             Test_Stand_Trans_Controller_P.RateLimiter1_FallingLim *
             Test_Stand_Trans_Control_period) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.RateLimiter1_FallingLim *
      Test_Stand_Trans_Control_period + Test_Stand_Trans_Controller_DW.PrevY;
  }

  Test_Stand_Trans_Controller_DW.PrevY =
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Abs: '<S1>/Abs12'
   *  Gain: '<S1>/Gain24'
   *  InitialCondition: '<S1>/IC3'
   */
  Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_P.Gain24_Gain *
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE;
  Test_Stand_Trans_Controller_B.IC3 = fabs(Test_Stand_Trans_Controller_B.IC3);

  /* Lookup_n-D: '<S1>/3-D Lookup Table1' */
  /*
   * About '<S1>/3-D Lookup Table1':
   *       Table size:  3 x 3 x 3
   *    Interpolation:  Spline
   *    Extrapolation:  None - Clip
   *   Breakpt Search:  Binary
   *    Breakpt Cache:  OFF
   */
  {
    real_T rt_LUTuVect[3];
    rt_LUTuVect[0] = Test_Stand_Trans_Controller_B.Saturation14;
    rt_LUTuVect[1] = Test_Stand_Trans_Controller_B.IC;
    rt_LUTuVect[2] = Test_Stand_Trans_Controller_B.IC3;
    Test_Stand_Trans_Controller_B.Saturation14 = look_SplNBinCZcd(3U,
      rt_LUTuVect, (rt_LUTSplineWork*)&Test_Stand_Trans_Controller_DW.SWork[0]);
  }

  /* Saturate: '<S1>/Saturation14' */
  if (Test_Stand_Trans_Controller_B.Saturation14 >
      Test_Stand_Trans_Controller_P.Saturation14_UpperSat) {
    /* Saturate: '<S1>/Saturation14' */
    Test_Stand_Trans_Controller_B.Saturation14 =
      Test_Stand_Trans_Controller_P.Saturation14_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.Saturation14 <
             Test_Stand_Trans_Controller_P.Saturation14_LowerSat) {
    /* Saturate: '<S1>/Saturation14' */
    Test_Stand_Trans_Controller_B.Saturation14 =
      Test_Stand_Trans_Controller_P.Saturation14_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation14' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Abs: '<S1>/Abs1'
   *  InitialCondition: '<S1>/IC3'
   *  Sum: '<S1>/Subtract3'
   */
  Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_B.Min1;
  Test_Stand_Trans_Controller_B.IC3 = fabs(Test_Stand_Trans_Controller_B.IC3);

  /* Product: '<S1>/Divide15' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  Product: '<S1>/Divide2'
   */
  rtb_IC3_tmp = Test_Stand_Trans_Controller_P.Constant6_Value /
    Test_Stand_Trans_Controller_P.Constant7_Value;

  /* MinMax: '<S1>/Min' incorporates:
   *  Abs: '<S1>/Abs2'
   *  Constant: '<S1>/Constant18'
   *  Gain: '<S1>/Gain6'
   *  InitialCondition: '<S1>/IC3'
   *  Product: '<S1>/Divide14'
   *  Product: '<S1>/Divide15'
   *  Product: '<S1>/Product10'
   *  Product: '<S1>/Product23'
   *  Product: '<S1>/Product9'
   */
  Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_P.Gain6_Gain *
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE *
    Test_Stand_Trans_Controller_B.IC3 /
    Test_Stand_Trans_Controller_P.Constant18_Value *
    Test_Stand_Trans_Controller_B.Saturation14 * rtb_IC3_tmp;
  Test_Stand_Trans_Controller_B.IC3 = fabs(Test_Stand_Trans_Controller_B.IC3);

  /* Gain: '<S1>/Gain10' */
  Test_Stand_Trans_Controller_B.MP2 = Test_Stand_Trans_Controller_P.Gain10_Gain *
    Test_Stand_Trans_Controller_B.IC3;

  /* MinMax: '<S1>/Min' incorporates:
   *  Abs: '<S1>/Abs'
   *  InitialCondition: '<S1>/IC3'
   *  Sum: '<S1>/Subtract2'
   */
  Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_B.Min1;
  Test_Stand_Trans_Controller_B.IC3 = fabs(Test_Stand_Trans_Controller_B.IC3);

  /* RateLimiter: '<Root>/Rate Limiter' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  Test_Stand_Trans_Controller_B.Product6 =
    Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE -
    Test_Stand_Trans_Controller_DW.PrevY_b;
  if (Test_Stand_Trans_Controller_B.Product6 >
      Test_Stand_Trans_Controller_P.RateLimiter_RisingLim *
      Test_Stand_Trans_Control_period) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.RateLimiter_RisingLim *
      Test_Stand_Trans_Control_period + Test_Stand_Trans_Controller_DW.PrevY_b;
  } else if (Test_Stand_Trans_Controller_B.Product6 <
             Test_Stand_Trans_Controller_P.RateLimiter_FallingLim *
             Test_Stand_Trans_Control_period) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.RateLimiter_FallingLim *
      Test_Stand_Trans_Control_period + Test_Stand_Trans_Controller_DW.PrevY_b;
  } else {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE;
  }

  Test_Stand_Trans_Controller_DW.PrevY_b =
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE;

  /* End of RateLimiter: '<Root>/Rate Limiter' */

  /* Product: '<S1>/Product6' incorporates:
   *  Gain: '<S1>/Gain5'
   */
  Test_Stand_Trans_Controller_B.Product6 =
    Test_Stand_Trans_Controller_P.Gain5_Gain *
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE *
    Test_Stand_Trans_Controller_B.IC3;

  /* MinMax: '<S1>/Min' incorporates:
   *  Abs: '<S1>/Abs13'
   *  InitialCondition: '<S1>/IC3'
   *  Sum: '<S1>/Subtract10'
   */
  Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_B.Min1;
  Test_Stand_Trans_Controller_B.IC3 = fabs(Test_Stand_Trans_Controller_B.IC3);

  /* Saturate: '<S1>/Saturation10' */
  if (Test_Stand_Trans_Controller_B.IC3 >
      Test_Stand_Trans_Controller_P.Saturation10_UpperSat) {
    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation10_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.IC3 <
             Test_Stand_Trans_Controller_P.Saturation10_LowerSat) {
    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation10_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation10' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Gain: '<S1>/Gain29'
   *  InitialCondition: '<S1>/IC3'
   */
  Test_Stand_Trans_Controller_B.IC3 *= Test_Stand_Trans_Controller_P.Gain29_Gain;

  /* Abs: '<S1>/Abs14' */
  Test_Stand_Trans_Controller_B.IC = fabs
    (Test_Stand_Trans_Controller_B.MP1_Speed);

  /* Abs: '<S1>/Abs15' incorporates:
   *  Gain: '<S1>/Gain28'
   */
  Test_Stand_Trans_Controller_B.Min1 = fabs
    (Test_Stand_Trans_Controller_P.Gain28_Gain *
     Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE);

  /* Lookup_n-D: '<S1>/3-D Lookup Table3' */
  /*
   * About '<S1>/3-D Lookup Table3':
   *       Table size:  3 x 3 x 3
   *    Interpolation:  Spline
   *    Extrapolation:  None - Clip
   *   Breakpt Search:  Binary
   *    Breakpt Cache:  OFF
   */
  {
    real_T rt_LUTuVect[3];
    rt_LUTuVect[0] = Test_Stand_Trans_Controller_B.IC3;
    rt_LUTuVect[1] = Test_Stand_Trans_Controller_B.IC;
    rt_LUTuVect[2] = Test_Stand_Trans_Controller_B.Min1;
    Test_Stand_Trans_Controller_B.IC3 = look_SplNBinCZcd(3U, rt_LUTuVect,
      (rt_LUTSplineWork*)&Test_Stand_Trans_Controller_DW.SWork_l[0]);
  }

  /* Saturate: '<S1>/Saturation12' */
  if (Test_Stand_Trans_Controller_B.IC3 >
      Test_Stand_Trans_Controller_P.Saturation12_UpperSat) {
    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation12_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.IC3 <
             Test_Stand_Trans_Controller_P.Saturation12_LowerSat) {
    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation12_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation12' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Constant: '<S1>/Constant17'
   *  InitialCondition: '<S1>/IC3'
   *  Product: '<S1>/Divide12'
   *  Product: '<S1>/Product24'
   */
  Test_Stand_Trans_Controller_B.IC3 *= Test_Stand_Trans_Controller_B.Product6 /
    Test_Stand_Trans_Controller_P.Constant17_Value;

  /* Product: '<S1>/Divide13' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Product: '<S1>/Divide1'
   */
  Test_Stand_Trans_Controller_B.Min1 =
    Test_Stand_Trans_Controller_P.Constant4_Value /
    Test_Stand_Trans_Controller_P.Constant5_Value;

  /* MinMax: '<S1>/Min1' incorporates:
   *  Abs: '<S1>/Abs3'
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S1>/Gain9'
   *  Product: '<S1>/Divide11'
   *  Product: '<S1>/Divide13'
   *  Product: '<S1>/Product7'
   *  Product: '<S1>/Product8'
   *  Sum: '<S1>/Add2'
   */
  Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE = fabs
    (Test_Stand_Trans_Controller_B.Min1 * Test_Stand_Trans_Controller_B.IC3 *
     (rtb_Gain11_tmp / Test_Stand_Trans_Controller_P.Constant3_Value) *
     Test_Stand_Trans_Controller_P.Gain9_Gain) +
    Test_Stand_Trans_Controller_B.MP2;

  /* RateLimiter: '<S1>/Rate Limiter' */
  Test_Stand_Trans_Controller_B.Product6 =
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE -
    Test_Stand_Trans_Controller_DW.PrevY_g;
  if (Test_Stand_Trans_Controller_B.Product6 >
      Test_Stand_Trans_Controller_P.RateLimiter_RisingLim_e *
      Test_Stand_Trans_Control_period) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.RateLimiter_RisingLim_e *
      Test_Stand_Trans_Control_period + Test_Stand_Trans_Controller_DW.PrevY_g;
  } else if (Test_Stand_Trans_Controller_B.Product6 <
             Test_Stand_Trans_Controller_P.RateLimiter_FallingLim_d *
             Test_Stand_Trans_Control_period) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.RateLimiter_FallingLim_d *
      Test_Stand_Trans_Control_period + Test_Stand_Trans_Controller_DW.PrevY_g;
  }

  Test_Stand_Trans_Controller_DW.PrevY_g =
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE;

  /* End of RateLimiter: '<S1>/Rate Limiter' */

  /* MinMax: '<S1>/Min1' incorporates:
   *  Constant: '<S1>/Constant19'
   *  Gain: '<S1>/Gain17'
   *  Product: '<S1>/Divide20'
   *  Product: '<S1>/Product16'
   *  Product: '<S1>/Product17'
   */
  Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
    Test_Stand_Trans_Controller_P.Constant19_Value *
    Test_Stand_Trans_Controller_B.MaxTorque *
    Test_Stand_Trans_Controller_P.Gain17_Gain /
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE *
    Test_Stand_Trans_Controller_B.Gain11;

  /* Saturate: '<S1>/Saturation3' */
  if (Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE >
      Test_Stand_Trans_Controller_P.Saturation3_UpperSat) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.Saturation3_UpperSat;
  } else if (Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE <
             Test_Stand_Trans_Controller_P.Saturation3_LowerSat) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.Saturation3_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation3' */

  /* MinMax: '<S1>/Min1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if ((!(Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE <=
         Test_Stand_Trans_Controller_P.Constant_Value_k)) && (!rtIsNaN
       (Test_Stand_Trans_Controller_P.Constant_Value_k))) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.Constant_Value_k;
  }

  /* End of MinMax: '<S1>/Min1' */

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<S1>/Divide21'
   */
  rtb_IC2 = (Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE /
             Test_Stand_Trans_Controller_B.Gain11 >=
             Test_Stand_Trans_Controller_P.CompareToConstant_const);

  /* InitialCondition: '<S1>/IC2' */
  if (Test_Stand_Trans_Controller_DW.IC2_FirstOutputTime) {
    Test_Stand_Trans_Controller_DW.IC2_FirstOutputTime = false;
    rtb_IC2 = Test_Stand_Trans_Controller_P.IC2_Value;
  }

  /* End of InitialCondition: '<S1>/IC2' */

  /* Gain: '<S1>/Gain1' incorporates:
   *  Product: '<S1>/Product4'
   */
  Test_Stand_Trans_Controller_B.MaxTorque = rtb_IC3_tmp *
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE *
    Test_Stand_Trans_Controller_P.Gain1_Gain;

  /* Switch: '<S1>/Switch3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant36'
   *  Product: '<S1>/Divide8'
   *  Product: '<S1>/Product3'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  if (rtb_IC2) {
    Test_Stand_Trans_Controller_B.IC =
      Test_Stand_Trans_Controller_P.Constant_Value;
  } else {
    Test_Stand_Trans_Controller_B.IC = Test_Stand_Trans_Controller_B.MaxTorque *
      Test_Stand_Trans_Controller_P.Constant36_Value /
      Test_Stand_Trans_Controller_DW.UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S1>/Switch3' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Constant: '<S1>/Constant20'
   *  Constant: '<S1>/Constant21'
   *  Constant: '<S1>/Constant22'
   *  Constant: '<S1>/Constant37'
   *  Gain: '<S1>/Gain15'
   *  Gain: '<S1>/Gain16'
   *  Gain: '<S1>/Gain18'
   *  Gain: '<S1>/Gain30'
   *  InitialCondition: '<S1>/IC3'
   *  Product: '<S1>/Divide22'
   *  Product: '<S1>/Product18'
   *  Sum: '<S1>/Subtract11'
   */
  Test_Stand_Trans_Controller_B.IC3 = (Test_Stand_Trans_Controller_P.Gain18_Gain
    * Test_Stand_Trans_Controller_B.IC3 -
    Test_Stand_Trans_Controller_P.Constant37_Value) *
    Test_Stand_Trans_Controller_P.Gain30_Gain *
    Test_Stand_Trans_Controller_P.Gain15_Gain *
    Test_Stand_Trans_Controller_P.Constant20_Value *
    Test_Stand_Trans_Controller_P.Constant22_Value /
    Test_Stand_Trans_Controller_P.Constant21_Value *
    Test_Stand_Trans_Controller_P.Gain16_Gain;
  if ((Test_Stand_Trans_Controller_B.IC >= Test_Stand_Trans_Controller_B.IC3) ||
      rtIsNaN(Test_Stand_Trans_Controller_B.IC3)) {
    Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_B.IC;
  }

  /* Saturate: '<S1>/Saturation' */
  if (Test_Stand_Trans_Controller_B.IC3 >
      Test_Stand_Trans_Controller_P.Saturation_UpperSat) {
    /* MinMax: '<S1>/Min' */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.IC3 <
             Test_Stand_Trans_Controller_P.Saturation_LowerSat) {
    /* MinMax: '<S1>/Min' */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation_LowerSat;
  }

  /* Gain: '<S1>/Gain3' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  Test_Stand_Trans_Controller_B.IC = Test_Stand_Trans_Controller_P.Gain3_Gain *
    Test_Stand_Trans_Controller_B.IC3;

  /* InitialCondition: '<S1>/IC' */
  if (Test_Stand_Trans_Controller_DW.IC_FirstOutputTime) {
    Test_Stand_Trans_Controller_DW.IC_FirstOutputTime = false;
    Test_Stand_Trans_Controller_B.IC = Test_Stand_Trans_Controller_P.IC_Value;
  }

  /* End of InitialCondition: '<S1>/IC' */

  /* Saturate: '<S1>/Saturation6' */
  if (Test_Stand_Trans_Controller_B.IC >
      Test_Stand_Trans_Controller_P.Saturation6_UpperSat) {
    Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE =
      Test_Stand_Trans_Controller_P.Saturation6_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.IC <
             Test_Stand_Trans_Controller_P.Saturation6_LowerSat) {
    Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE =
      Test_Stand_Trans_Controller_P.Saturation6_LowerSat;
  } else {
    Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE =
      Test_Stand_Trans_Controller_B.IC;
  }

  /* End of Saturate: '<S1>/Saturation6' */

  /* Gain: '<Root>/Gain' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  Test_Stand_Trans_Controller_B.Gain = Test_Stand_Trans_Controller_P.Gain_Gain *
    Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE;

  /* MinMax: '<S1>/Min' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant3'
   *  InitialCondition: '<S1>/IC3'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Subtract'
   */
  Test_Stand_Trans_Controller_B.IC3 = (rtb_Gain11_tmp *
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE -
    Test_Stand_Trans_Controller_B.Gain11 *
    Test_Stand_Trans_Controller_P.Constant1_Value) /
    Test_Stand_Trans_Controller_P.Constant3_Value;

  /* InitialCondition: '<S1>/IC1' */
  if (Test_Stand_Trans_Controller_DW.IC1_FirstOutputTime) {
    Test_Stand_Trans_Controller_DW.IC1_FirstOutputTime = false;

    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC1'
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_P.IC1_Value;
  }

  /* End of InitialCondition: '<S1>/IC1' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Product: '<S1>/Product2'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  Test_Stand_Trans_Controller_DW.UnitDelay3_DSTATE =
    Test_Stand_Trans_Controller_B.Min1 * Test_Stand_Trans_Controller_B.IC3 *
    Test_Stand_Trans_Controller_P.Gain_Gain_e;

  /* Switch: '<S1>/Switch2' */
  if (rtb_IC2) {
    /* MinMax: '<S1>/Min' incorporates:
     *  Constant: '<S1>/Constant35'
     *  InitialCondition: '<S1>/IC3'
     *  Product: '<S1>/Divide9'
     *  Product: '<S1>/Product5'
     *  UnitDelay: '<S1>/Unit Delay3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_DW.UnitDelay3_DSTATE *
      Test_Stand_Trans_Controller_P.Constant35_Value /
      Test_Stand_Trans_Controller_B.MaxTorque;
  } else {
    /* MinMax: '<S1>/Min' incorporates:
     *  Constant: '<S1>/Constant8'
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Constant8_Value;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Saturate: '<S1>/Saturation1' */
  if (Test_Stand_Trans_Controller_B.IC3 >
      Test_Stand_Trans_Controller_P.Saturation1_UpperSat) {
    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation1_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.IC3 <
             Test_Stand_Trans_Controller_P.Saturation1_LowerSat) {
    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 =
      Test_Stand_Trans_Controller_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Gain: '<S1>/Gain4'
   *  InitialCondition: '<S1>/IC3'
   */
  Test_Stand_Trans_Controller_B.IC3 *= Test_Stand_Trans_Controller_P.Gain4_Gain;

  /* InitialCondition: '<S1>/IC3' */
  if (Test_Stand_Trans_Controller_DW.IC3_FirstOutputTime) {
    Test_Stand_Trans_Controller_DW.IC3_FirstOutputTime = false;

    /* MinMax: '<S1>/Min' incorporates:
     *  InitialCondition: '<S1>/IC3'
     */
    Test_Stand_Trans_Controller_B.IC3 = Test_Stand_Trans_Controller_P.IC3_Value;
  }

  /* End of InitialCondition: '<S1>/IC3' */

  /* Saturate: '<S1>/Saturation5' */
  if (Test_Stand_Trans_Controller_B.IC3 >
      Test_Stand_Trans_Controller_P.Saturation5_UpperSat) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.Saturation5_UpperSat;
  } else if (Test_Stand_Trans_Controller_B.IC3 <
             Test_Stand_Trans_Controller_P.Saturation5_LowerSat) {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_P.Saturation5_LowerSat;
  } else {
    /* MinMax: '<S1>/Min1' */
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
      Test_Stand_Trans_Controller_B.IC3;
  }

  /* End of Saturate: '<S1>/Saturation5' */

  /* Gain: '<Root>/Gain1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  Test_Stand_Trans_Controller_B.Gain1 =
    Test_Stand_Trans_Controller_P.Gain1_Gain_f *
    Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE;

  /* S-Function (scanpack): '<Root>/CAN Pack' */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  Test_Stand_Trans_Controller_B.CANPack.ID = 201392897U;
  Test_Stand_Trans_Controller_B.CANPack.Length = 8U;
  Test_Stand_Trans_Controller_B.CANPack.Extended = 1U;
  Test_Stand_Trans_Controller_B.CANPack.Remote = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[0] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[1] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[2] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[3] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[4] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[5] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[6] = 0;
  Test_Stand_Trans_Controller_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -10000.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = Test_Stand_Trans_Controller_B.Gain;

        /* no factor to apply */
        result = result - -10000.0;

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Test_Stand_Trans_Controller_B.CANPack.Data[0] =
              Test_Stand_Trans_Controller_B.CANPack.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            Test_Stand_Trans_Controller_B.CANPack.Data[1] =
              Test_Stand_Trans_Controller_B.CANPack.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -10000.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = Test_Stand_Trans_Controller_B.Gain1;

        /* no factor to apply */
        result = result - -10000.0;

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Test_Stand_Trans_Controller_B.CANPack.Data[2] =
              Test_Stand_Trans_Controller_B.CANPack.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            Test_Stand_Trans_Controller_B.CANPack.Data[3] =
              Test_Stand_Trans_Controller_B.CANPack.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit' */
  if (Test_Stand_Trans_Controller_DW.obj_p.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      Test_Stand_Trans_Controller_B.rxData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (Test_Stand_Trans_Controller_B.CANPack.Remote == 0) {
      sockStatus = Test_Stand_Trans_Controller_B.CANPack.Length - 1;
      for (b_i = 0; b_i <= sockStatus; b_i++) {
        Test_Stand_Trans_Controller_B.rxData[(uint8_T)((uint32_T)b_i + 1U) - 1] =
          Test_Stand_Trans_Controller_B.CANPack.Data[(uint8_T)((uint32_T)b_i +
          1U) - 1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (Test_Stand_Trans_Controller_B.CANPack.Extended == 0),
      Test_Stand_Trans_Controller_B.CANPack.ID,
      Test_Stand_Trans_Controller_B.CANPack.Length,
      &Test_Stand_Trans_Controller_B.rxData[0],
      Test_Stand_Trans_Controller_B.CANPack.Remote, &status, 0, 1.0,
      Test_Stand_Trans_Controller_DW.obj_p.sockHandleDataFrames,
      Test_Stand_Trans_Controller_DW.obj_p.sockHandleErrorFrames, (uint8_T)
      Test_Stand_Trans_Controller_DW.obj_p.notFirstStep);
    if (sockStatus != 0) {
      Test_Stand_Trans_Controller_DW.obj_p.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit' */

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  Product: '<Root>/Divide'
   */
  Test_Stand_Trans_Controller_B.Product =
    Test_Stand_Trans_Controller_P.Gain3_Gain_h *
    Test_Stand_Trans_Controller_P.Constant2_Value /
    (Test_Stand_Trans_Controller_P.Gain2_Gain *
     Test_Stand_Trans_Controller_P.Constant1_Value_c) *
    (Test_Stand_Trans_Controller_P.Constant4_Value_d *
     Test_Stand_Trans_Controller_P.Constant3_Value_o);

  /* S-Function (scanpack): '<Root>/CAN Pack1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  Test_Stand_Trans_Controller_B.CANPack1.ID = 201392641U;
  Test_Stand_Trans_Controller_B.CANPack1.Length = 8U;
  Test_Stand_Trans_Controller_B.CANPack1.Extended = 1U;
  Test_Stand_Trans_Controller_B.CANPack1.Remote = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[0] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[1] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[2] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[3] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[4] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[5] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[6] = 0;
  Test_Stand_Trans_Controller_B.CANPack1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = Test_Stand_Trans_Controller_B.Product;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Test_Stand_Trans_Controller_B.CANPack1.Data[2] =
              Test_Stand_Trans_Controller_B.CANPack1.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            Test_Stand_Trans_Controller_B.CANPack1.Data[3] =
              Test_Stand_Trans_Controller_B.CANPack1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = -10000.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = Test_Stand_Trans_Controller_P.Constant1_Value_c;

        /* no factor to apply */
        result = result - -10000.0;

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real64_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real64_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Test_Stand_Trans_Controller_B.CANPack1.Data[0] =
              Test_Stand_Trans_Controller_B.CANPack1.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            Test_Stand_Trans_Controller_B.CANPack1.Data[1] =
              Test_Stand_Trans_Controller_B.CANPack1.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit1' */
  if (Test_Stand_Trans_Controller_DW.obj_pl.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      Test_Stand_Trans_Controller_B.rxData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (Test_Stand_Trans_Controller_B.CANPack1.Remote == 0) {
      sockStatus = Test_Stand_Trans_Controller_B.CANPack1.Length - 1;
      for (b_i = 0; b_i <= sockStatus; b_i++) {
        Test_Stand_Trans_Controller_B.rxData[(uint8_T)((uint32_T)b_i + 1U) - 1] =
          Test_Stand_Trans_Controller_B.CANPack1.Data[(uint8_T)((uint32_T)b_i +
          1U) - 1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (Test_Stand_Trans_Controller_B.CANPack1.Extended == 0),
      Test_Stand_Trans_Controller_B.CANPack1.ID,
      Test_Stand_Trans_Controller_B.CANPack1.Length,
      &Test_Stand_Trans_Controller_B.rxData[0],
      Test_Stand_Trans_Controller_B.CANPack1.Remote, &status, 0, 1.0,
      Test_Stand_Trans_Controller_DW.obj_pl.sockHandleDataFrames,
      Test_Stand_Trans_Controller_DW.obj_pl.sockHandleErrorFrames, (uint8_T)
      Test_Stand_Trans_Controller_DW.obj_pl.notFirstStep);
    if (sockStatus != 0) {
      Test_Stand_Trans_Controller_DW.obj_pl.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit1' */
}

/* Model initialize function */
void Test_Stand_Trans_Controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Test_Stand_Trans_Controller_P.RateLimiter_RisingLim_e = rtInf;
  Test_Stand_Trans_Controller_P.RateLimiter_FallingLim_d = rtMinusInf;

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack' */

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for Lookup_n-D: '<S1>/3-D Lookup Table1' */
  {
    rt_LUTnWork *TWork_start = (rt_LUTnWork *)
      &Test_Stand_Trans_Controller_DW.TWork[0];
    void **bpDataSet = (void **) &Test_Stand_Trans_Controller_DW.m_bpDataSet[0];
    TWork_start->m_dimSizes = (const uint32_T *)
      Test_Stand_Trans_Controller_P.uDLookupTable1_dimSizes;
    TWork_start->m_tableData = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable1_tableData;
    TWork_start->m_bpDataSet = bpDataSet;
    TWork_start->m_bpIndex = &Test_Stand_Trans_Controller_DW.m_bpIndex[0];
    TWork_start->m_bpLambda = &Test_Stand_Trans_Controller_DW.m_bpLambda[0];
    TWork_start->m_maxIndex = (const uint32_T *)
      Test_Stand_Trans_Controller_P.uDLookupTable1_maxIndex;
    bpDataSet[0] = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable1_bp01Data;
    bpDataSet[1] = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable1_bp02Data;
    bpDataSet[2] = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable1_bp03Data;
  }

  {
    const real_T **bpDataSet;
    const real_T *xp, *yp;
    real_T *dp;
    uint32_T len;
    const rt_LUTnWork *TWork_interp;
    rt_LUTSplineWork *rt_SplWk = (rt_LUTSplineWork*)
      &Test_Stand_Trans_Controller_DW.SWork[0];
    rt_SplWk->m_TWork = (rt_LUTnWork*)&Test_Stand_Trans_Controller_DW.TWork[0];
    rt_SplWk->m_yyA = &Test_Stand_Trans_Controller_DW.m_yyA[0];
    rt_SplWk->m_yyB = &Test_Stand_Trans_Controller_DW.m_yyB[0];
    rt_SplWk->m_yy2 = &Test_Stand_Trans_Controller_DW.m_yy2[0];
    rt_SplWk->m_up = &Test_Stand_Trans_Controller_DW.m_up[0];
    rt_SplWk->m_y2 = &Test_Stand_Trans_Controller_DW.m_y2[0];
    rt_SplWk->m_numYWorkElts =
      Test_Stand_Trans_Controller_P.uDLookupTable1_numYWorkElts;
    rt_SplWk->m_reCalc =
      &Test_Stand_Trans_Controller_DW.reCalcSecDerivFirstDimCoeffs;
    rt_SplWk->m_preBp0AndTable =
      &Test_Stand_Trans_Controller_DW.prevBp0AndTableData[0];
    *rt_SplWk->m_reCalc = 1;

    /* cache table data and first breakpoint data */
    TWork_interp = (const rt_LUTnWork *)rt_SplWk->m_TWork;
    bpDataSet = (const real_T **) TWork_interp->m_bpDataSet;
    xp = bpDataSet[0U];
    len = TWork_interp->m_maxIndex[0U] + 1U;
    dp = (real_T *) rt_SplWk->m_preBp0AndTable;
    yp = (real_T *) TWork_interp->m_tableData;
    (void) memcpy(dp, xp,
                  len * sizeof(real_T));
    dp = &(dp[len]);

    /* save the table data */
    (void) memcpy(dp, yp,
                  len * rt_SplWk->m_numYWorkElts[0U] * sizeof(real_T));
  }

  /* Start for Lookup_n-D: '<S1>/3-D Lookup Table3' */
  {
    rt_LUTnWork *TWork_start = (rt_LUTnWork *)
      &Test_Stand_Trans_Controller_DW.TWork_i[0];
    void **bpDataSet = (void **) &Test_Stand_Trans_Controller_DW.m_bpDataSet_l[0];
    TWork_start->m_dimSizes = (const uint32_T *)
      Test_Stand_Trans_Controller_P.uDLookupTable3_dimSizes;
    TWork_start->m_tableData = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable3_tableData;
    TWork_start->m_bpDataSet = bpDataSet;
    TWork_start->m_bpIndex = &Test_Stand_Trans_Controller_DW.m_bpIndex_h[0];
    TWork_start->m_bpLambda = &Test_Stand_Trans_Controller_DW.m_bpLambda_m[0];
    TWork_start->m_maxIndex = (const uint32_T *)
      Test_Stand_Trans_Controller_P.uDLookupTable3_maxIndex;
    bpDataSet[0] = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable3_bp01Data;
    bpDataSet[1] = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable3_bp02Data;
    bpDataSet[2] = (void *)
      Test_Stand_Trans_Controller_P.uDLookupTable3_bp03Data;
  }

  {
    const real_T **bpDataSet;
    const real_T *xp, *yp;
    real_T *dp;
    uint32_T len;
    const rt_LUTnWork *TWork_interp;
    rt_LUTSplineWork *rt_SplWk = (rt_LUTSplineWork*)
      &Test_Stand_Trans_Controller_DW.SWork_l[0];
    rt_SplWk->m_TWork = (rt_LUTnWork*)&Test_Stand_Trans_Controller_DW.TWork_i[0];
    rt_SplWk->m_yyA = &Test_Stand_Trans_Controller_DW.m_yyA_h[0];
    rt_SplWk->m_yyB = &Test_Stand_Trans_Controller_DW.m_yyB_n[0];
    rt_SplWk->m_yy2 = &Test_Stand_Trans_Controller_DW.m_yy2_a[0];
    rt_SplWk->m_up = &Test_Stand_Trans_Controller_DW.m_up_g[0];
    rt_SplWk->m_y2 = &Test_Stand_Trans_Controller_DW.m_y2_o[0];
    rt_SplWk->m_numYWorkElts =
      Test_Stand_Trans_Controller_P.uDLookupTable3_numYWorkElts;
    rt_SplWk->m_reCalc =
      &Test_Stand_Trans_Controller_DW.reCalcSecDerivFirstDimCoeffs_j;
    rt_SplWk->m_preBp0AndTable =
      &Test_Stand_Trans_Controller_DW.prevBp0AndTableData_k[0];
    *rt_SplWk->m_reCalc = 1;

    /* cache table data and first breakpoint data */
    TWork_interp = (const rt_LUTnWork *)rt_SplWk->m_TWork;
    bpDataSet = (const real_T **) TWork_interp->m_bpDataSet;
    xp = bpDataSet[0U];
    len = TWork_interp->m_maxIndex[0U] + 1U;
    dp = (real_T *) rt_SplWk->m_preBp0AndTable;
    yp = (real_T *) TWork_interp->m_tableData;
    (void) memcpy(dp, xp,
                  len * sizeof(real_T));
    dp = &(dp[len]);

    /* save the table data */
    (void) memcpy(dp, yp,
                  len * rt_SplWk->m_numYWorkElts[0U] * sizeof(real_T));
  }

  /* Start for InitialCondition: '<S1>/IC2' */
  Test_Stand_Trans_Controller_DW.IC2_FirstOutputTime = true;

  /* Start for InitialCondition: '<S1>/IC' */
  Test_Stand_Trans_Controller_DW.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<S1>/IC1' */
  Test_Stand_Trans_Controller_DW.IC1_FirstOutputTime = true;

  /* Start for InitialCondition: '<S1>/IC3' */
  Test_Stand_Trans_Controller_DW.IC3_FirstOutputTime = true;

  /* InitializeConditions for MinMax: '<S1>/Min1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  Test_Stand_Trans_Controller_DW.UnitDelay1_DSTATE =
    Test_Stand_Trans_Controller_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter1' */
  Test_Stand_Trans_Controller_DW.PrevY =
    Test_Stand_Trans_Controller_P.RateLimiter1_IC;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  Test_Stand_Trans_Controller_DW.UnitDelay_DSTATE =
    Test_Stand_Trans_Controller_P.UnitDelay_InitialCondition;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter' */
  Test_Stand_Trans_Controller_DW.PrevY_b =
    Test_Stand_Trans_Controller_P.RateLimiter_IC;

  /* InitializeConditions for RateLimiter: '<S1>/Rate Limiter' */
  Test_Stand_Trans_Controller_DW.PrevY_g =
    Test_Stand_Trans_Controller_P.RateLimiter_IC_f;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay3' */
  Test_Stand_Trans_Controller_DW.UnitDelay3_DSTATE =
    Test_Stand_Trans_Controller_P.UnitDelay3_InitialCondition;

  /* Start for MATLABSystem: '<Root>/CAN Receive' */
  Test_Stand_Trans_Controller_DW.obj.sockHandleDataFrames = 0;
  Test_Stand_Trans_Controller_DW.obj.sockHandleErrorFrames = 0;
  Test_Stand_Trans_Controller_DW.obj.isInitialized = 0;
  Test_Stand_Trans_Controller_DW.obj.matlabCodegenIsDeleted = false;
  Test_Stand_Trans_Controller_DW.obj.SampleTime =
    Test_Stand_Trans_Controller_P.CANReceive_SampleTime;
  Test_Stand_Tra_SystemCore_setup(&Test_Stand_Trans_Controller_DW.obj);

  /* Start for MATLABSystem: '<Root>/CAN Transmit' */
  Test_Stand_Trans_Controller_B.a = NULL;
  for (Test_Stand_Trans_Controller_B.i = 0; Test_Stand_Trans_Controller_B.i < 20;
       Test_Stand_Trans_Controller_B.i++) {
    Test_Stand_Trans_Controller_DW.eml_openfiles[Test_Stand_Trans_Controller_B.i]
      = Test_Stand_Trans_Controller_B.a;
  }

  Test_Stand_Trans_Controller_DW.obj_p.sockHandleDataFrames = 0;
  Test_Stand_Trans_Controller_DW.obj_p.sockHandleErrorFrames = 0;
  Test_Stand_Trans_Controller_DW.obj_p.notFirstStep = false;
  Test_Stand_Trans_Controller_DW.obj_p.isInitialized = 0;
  Test_Stand_Trans_Controller_DW.obj_p.matlabCodegenIsDeleted = false;
  Test_Stand_T_SystemCore_setup_l(&Test_Stand_Trans_Controller_DW.obj_p);

  /* End of Start for MATLABSystem: '<Root>/CAN Transmit' */

  /* Start for MATLABSystem: '<Root>/CAN Transmit1' */
  Test_Stand_Trans_Controller_DW.obj_pl.sockHandleDataFrames = 0;
  Test_Stand_Trans_Controller_DW.obj_pl.sockHandleErrorFrames = 0;
  Test_Stand_Trans_Controller_DW.obj_pl.notFirstStep = false;
  Test_Stand_Trans_Controller_DW.obj_pl.isInitialized = 0;
  Test_Stand_Trans_Controller_DW.obj_pl.matlabCodegenIsDeleted = false;
  Test_Stand__SystemCore_setup_lm(&Test_Stand_Trans_Controller_DW.obj_pl);
}

/* Model terminate function */
void Test_Stand_Trans_Controller_terminate(void)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Receive' */
  if (!Test_Stand_Trans_Controller_DW.obj.matlabCodegenIsDeleted) {
    Test_Stand_Trans_Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((Test_Stand_Trans_Controller_DW.obj.isInitialized == 1) &&
        Test_Stand_Trans_Controller_DW.obj.isSetupComplete &&
        Test_Stand_Trans_Controller_DW.obj.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Test_Stand_Trans_Controller_DW.obj.sockHandleDataFrames,
                     &canInterface[0]);
      MW_clearSocket(&Test_Stand_Trans_Controller_DW.obj.sockHandleErrorFrames,
                     &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Receive' */

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!Test_Stand_Trans_Controller_DW.obj_p.matlabCodegenIsDeleted) {
    Test_Stand_Trans_Controller_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Test_Stand_Trans_Controller_DW.obj_p.isInitialized == 1) &&
        Test_Stand_Trans_Controller_DW.obj_p.isSetupComplete &&
        Test_Stand_Trans_Controller_DW.obj_p.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Test_Stand_Trans_Controller_DW.obj_p.sockHandleDataFrames,
                     &canInterface[0]);
      MW_clearSocket(&Test_Stand_Trans_Controller_DW.obj_p.sockHandleErrorFrames,
                     &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit1' */
  if (!Test_Stand_Trans_Controller_DW.obj_pl.matlabCodegenIsDeleted) {
    Test_Stand_Trans_Controller_DW.obj_pl.matlabCodegenIsDeleted = true;
    if ((Test_Stand_Trans_Controller_DW.obj_pl.isInitialized == 1) &&
        Test_Stand_Trans_Controller_DW.obj_pl.isSetupComplete &&
        Test_Stand_Trans_Controller_DW.obj_pl.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Test_Stand_Trans_Controller_DW.obj_pl.sockHandleDataFrames,
                     &canInterface[0]);
      MW_clearSocket
        (&Test_Stand_Trans_Controller_DW.obj_pl.sockHandleErrorFrames,
         &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
