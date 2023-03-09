/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle_dyno.c
 *
 * Code generated for Simulink model 'Throttle_dyno'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  7 17:16:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Throttle_dyno.h"
#include "Throttle_dyno_types.h"
#include "rtwtypes.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "Throttle_dyno_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Throttle_dy_IN_Throttle_Setting ((uint8_T)2U)
#define Throttle_dyn_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Throttle_dyno_IN_Disabled      ((uint8_T)1U)
#define Throttle_dyno_IN_Enabled       ((uint8_T)2U)
#define Throttle_dyno_IN_End           ((uint8_T)1U)
#define Throttle_dyno_IN_Load_Increase ((uint8_T)1U)
#define Throttle_dyno_IN_Start         ((uint8_T)2U)

/* Block signals (default storage) */
B_Throttle_dyno_T Throttle_dyno_B;

/* Block states (default storage) */
DW_Throttle_dyno_T Throttle_dyno_DW;

/* Real-time model */
static RT_MODEL_Throttle_dyno_T Throttle_dyno_M_;
RT_MODEL_Throttle_dyno_T *const Throttle_dyno_M = &Throttle_dyno_M_;

/* Forward declaration for local functions */
static void Throttle_dyno_SystemCore_setup(codertarget_raspi_internal_CA_T *obj);
static int8_T Throttle_dyno_filedata(void);
static int8_T Throttle_dyno_cfopen(const char_T *cfilename, const char_T
  *cpermission);
static void Throttle_dyno_emxInit_char_T(emxArray_char_T_Throttle_dyno_T
  **pEmxArray, int32_T numDimensions);
static FILE* Throttle_dyno_fileManager(real_T varargin_1);
static void Thrott_emxEnsureCapacity_char_T(emxArray_char_T_Throttle_dyno_T
  *emxArray, int32_T oldNumel);
static void Throttle_dyno_emxFree_char_T(emxArray_char_T_Throttle_dyno_T
  **pEmxArray);
static void Throttle_dyno_fgetl(real_T fileID, emxArray_char_T_Throttle_dyno_T
  *out);
static int32_T Throttle_dyno_cfclose(real_T fid);
static void Throttle_dyn_SystemCore_setup_k(codertarget_raspi_internal__k_T *obj);
static void Throttle_dyno_SystemCore_setup(codertarget_raspi_internal_CA_T *obj)
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
    Throttle_dyno_B.errString1[0] = 'c';
    Throttle_dyno_B.errString1[1] = 'a';
    Throttle_dyno_B.errString1[2] = 'n';
    Throttle_dyno_B.errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      Throttle_dyno_B.errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    Throttle_dyno_B.errString1[23] = 'c';
    Throttle_dyno_B.errString1[24] = 'a';
    Throttle_dyno_B.errString1[25] = 'n';
    Throttle_dyno_B.errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      Throttle_dyno_B.errString1[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    Throttle_dyno_B.errString1[61] = '\x0a';
    Throttle_dyno_B.errString1[62] = '\x00';
    MW_printError(&Throttle_dyno_B.errString1[0]);
  } else if (isCANSetup == 2) {
    Throttle_dyno_B.errString2[0] = 'c';
    Throttle_dyno_B.errString2[1] = 'a';
    Throttle_dyno_B.errString2[2] = 'n';
    Throttle_dyno_B.errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      Throttle_dyno_B.errString2[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    Throttle_dyno_B.errString2[50] = '\x0a';
    Throttle_dyno_B.errString2[51] = '\x00';
    MW_printError(&Throttle_dyno_B.errString2[0]);
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

static int8_T Throttle_dyno_filedata(void)
{
  int32_T b_k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 20)) {
    if (Throttle_dyno_DW.eml_openfiles[(int8_T)(b_k + 1) - 1] == NULL) {
      f = (int8_T)(b_k + 1);
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return f;
}

static int8_T Throttle_dyno_cfopen(const char_T *cfilename, const char_T
  *cpermission)
{
  FILE* filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Throttle_dyno_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Throttle_dyno_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

static void Throttle_dyno_emxInit_char_T(emxArray_char_T_Throttle_dyno_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Throttle_dyno_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Throttle_dyno_T *)malloc(sizeof
    (emxArray_char_T_Throttle_dyno_T));
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

static FILE* Throttle_dyno_fileManager(real_T varargin_1)
{
  FILE* f;
  int8_T fileid;
  fileid = (int8_T)varargin_1;
  if (varargin_1 != (int8_T)varargin_1) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Throttle_dyno_DW.eml_openfiles[fileid - 3];
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

static void Thrott_emxEnsureCapacity_char_T(emxArray_char_T_Throttle_dyno_T
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

static void Throttle_dyno_emxFree_char_T(emxArray_char_T_Throttle_dyno_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Throttle_dyno_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Throttle_dyno_T *)NULL;
  }
}

static void Throttle_dyno_fgetl(real_T fileID, emxArray_char_T_Throttle_dyno_T
  *out)
{
  emxArray_char_T_Throttle_dyno_T *c_line;
  emxArray_char_T_Throttle_dyno_T *outBuff;
  int32_T c_i;
  int32_T exitg1;
  int32_T i;
  char_T tmp;
  uint8_T buf;
  boolean_T exitg2;
  boolean_T fileEndAfterCarriageReturn;
  boolean_T newLineAfterCarriageReturn;
  boolean_T readNewline;
  Throttle_dyno_B.filestar = Throttle_dyno_fileManager(fileID);
  if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
  } else {
    Throttle_dyno_B.filestar = NULL;
  }

  Throttle_dyno_emxInit_char_T(&outBuff, 2);
  outBuff->size[0] = 1;
  outBuff->size[1] = 0;
  Throttle_dyno_emxInit_char_T(&c_line, 2);
  if (Throttle_dyno_B.filestar == NULL) {
    c_line->size[0] = 1;
    c_line->size[1] = 0;
  } else {
    do {
      exitg1 = 0;
      Throttle_dyno_B.cOut = fgets(&Throttle_dyno_B.ReadBuff[0], 1024,
        Throttle_dyno_B.filestar);
      readNewline = false;
      Throttle_dyno_B.b_NULL = NULL;
      Throttle_dyno_B.filestar_c = Throttle_dyno_fileManager(fileID);
      if (Throttle_dyno_B.filestar_c == Throttle_dyno_B.b_NULL) {
        Throttle_dyno_B.reachedEndOfFile = 0;
      } else {
        Throttle_dyno_B.b_st = feof(Throttle_dyno_B.filestar_c);
        Throttle_dyno_B.reachedEndOfFile = ((int32_T)Throttle_dyno_B.b_st != 0);
      }

      if (Throttle_dyno_B.cOut == NULL) {
        exitg1 = 1;
      } else {
        Throttle_dyno_B.idx = 1;
        Throttle_dyno_B.carriageReturnAt = 0;
        if (Throttle_dyno_B.reachedEndOfFile != 0) {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1024)) {
            tmp = Throttle_dyno_B.ReadBuff[c_i - 1];
            if (tmp == '\x00') {
              Throttle_dyno_B.idx = c_i;
              exitg2 = true;
            } else {
              if ((Throttle_dyno_B.carriageReturnAt == 0) && (tmp == '\x0d')) {
                Throttle_dyno_B.carriageReturnAt = c_i;
              }

              c_i++;
            }
          }

          if (Throttle_dyno_B.ReadBuff[Throttle_dyno_B.idx - 1] == '\x00') {
            Throttle_dyno_B.idx--;
          }
        } else {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1025)) {
            if (c_i > 1024) {
              Throttle_dyno_B.idx = 1023;
              exitg2 = true;
            } else {
              tmp = Throttle_dyno_B.ReadBuff[c_i - 1];
              if (tmp == '\x0a') {
                Throttle_dyno_B.idx = c_i;
                exitg2 = true;
              } else {
                if ((Throttle_dyno_B.carriageReturnAt == 0) && (tmp == '\x0d'))
                {
                  Throttle_dyno_B.carriageReturnAt = c_i;
                }

                c_i++;
              }
            }
          }

          readNewline = (Throttle_dyno_B.ReadBuff[Throttle_dyno_B.idx - 1] ==
                         '\x0a');
        }

        if ((Throttle_dyno_B.carriageReturnAt > 0) &&
            (Throttle_dyno_B.carriageReturnAt < 1024)) {
          newLineAfterCarriageReturn =
            (Throttle_dyno_B.ReadBuff[Throttle_dyno_B.carriageReturnAt] ==
             '\x0a');
          if ((Throttle_dyno_B.reachedEndOfFile != 0) &&
              (Throttle_dyno_B.ReadBuff[Throttle_dyno_B.carriageReturnAt] ==
               '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }

        if ((Throttle_dyno_B.carriageReturnAt == 0) ||
            newLineAfterCarriageReturn || fileEndAfterCarriageReturn) {
          if (Throttle_dyno_B.idx < 1) {
            Throttle_dyno_B.idx = 0;
          }

          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += Throttle_dyno_B.idx;
          Thrott_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < Throttle_dyno_B.idx; i++) {
            outBuff->data[c_i + i] = Throttle_dyno_B.ReadBuff[i];
          }
        } else {
          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += Throttle_dyno_B.carriageReturnAt;
          Thrott_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < Throttle_dyno_B.carriageReturnAt; i++) {
            outBuff->data[c_i + i] = Throttle_dyno_B.ReadBuff[i];
          }

          Throttle_dyno_B.wherefrom = SEEK_CUR;
          Throttle_dyno_B.filestar_c = Throttle_dyno_fileManager(fileID);
          if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
          } else {
            Throttle_dyno_B.filestar_c = NULL;
          }

          if (!(Throttle_dyno_B.filestar_c == NULL)) {
            fseek(Throttle_dyno_B.filestar_c, (long int)
                  (Throttle_dyno_B.carriageReturnAt - Throttle_dyno_B.idx),
                  Throttle_dyno_B.wherefrom);
          }
        }

        if (readNewline || (Throttle_dyno_B.reachedEndOfFile != 0) ||
            (Throttle_dyno_B.carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    Throttle_dyno_B.b_NULL = NULL;
    Throttle_dyno_B.filestar = Throttle_dyno_fileManager(fileID);
    if (Throttle_dyno_B.filestar == Throttle_dyno_B.b_NULL) {
      Throttle_dyno_B.reachedEndOfFile = 0;
    } else {
      Throttle_dyno_B.b_st = feof(Throttle_dyno_B.filestar);
      Throttle_dyno_B.reachedEndOfFile = ((int32_T)Throttle_dyno_B.b_st != 0);
    }

    if (Throttle_dyno_B.reachedEndOfFile == 0) {
      Throttle_dyno_B.filestar = Throttle_dyno_fileManager(fileID);
      if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
      } else {
        Throttle_dyno_B.filestar = NULL;
      }

      if (!(Throttle_dyno_B.filestar == NULL)) {
        fread(&buf, sizeof(uint8_T), (size_t)1, Throttle_dyno_B.filestar);
      }

      Throttle_dyno_B.b_NULL = NULL;
      Throttle_dyno_B.filestar = Throttle_dyno_fileManager(fileID);
      if (Throttle_dyno_B.filestar == Throttle_dyno_B.b_NULL) {
        Throttle_dyno_B.reachedEndOfFile = 0;
      } else {
        Throttle_dyno_B.b_st = feof(Throttle_dyno_B.filestar);
        Throttle_dyno_B.reachedEndOfFile = ((int32_T)Throttle_dyno_B.b_st != 0);
      }

      if (Throttle_dyno_B.reachedEndOfFile == 0) {
        Throttle_dyno_B.wherefrom = SEEK_CUR;
        Throttle_dyno_B.filestar = Throttle_dyno_fileManager(fileID);
        if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
        } else {
          Throttle_dyno_B.filestar = NULL;
        }

        if (!(Throttle_dyno_B.filestar == NULL)) {
          fseek(Throttle_dyno_B.filestar, (long int)-1.0,
                Throttle_dyno_B.wherefrom);
        }
      }
    }

    i = c_line->size[0] * c_line->size[1];
    c_line->size[0] = 1;
    c_line->size[1] = outBuff->size[1];
    Thrott_emxEnsureCapacity_char_T(c_line, i);
    Throttle_dyno_B.reachedEndOfFile = outBuff->size[1];
    if (Throttle_dyno_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&c_line->data[0], &outBuff->data[0], (uint32_T)
             Throttle_dyno_B.reachedEndOfFile * sizeof(char_T));
    }
  }

  Throttle_dyno_emxFree_char_T(&outBuff);
  if (c_line->size[1] == 0) {
    out->size[0] = 1;
    out->size[1] = 0;
  } else if (c_line->data[c_line->size[1] - 1] == '\x0a') {
    if ((c_line->size[1] > 1) && (c_line->data[c_line->size[1] - 2] == '\x0d'))
    {
      if (c_line->size[1] - 2 < 1) {
        Throttle_dyno_B.reachedEndOfFile = 0;
      } else {
        Throttle_dyno_B.reachedEndOfFile = c_line->size[1] - 2;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = Throttle_dyno_B.reachedEndOfFile;
      Thrott_emxEnsureCapacity_char_T(out, i);
      if (Throttle_dyno_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               Throttle_dyno_B.reachedEndOfFile * sizeof(char_T));
      }
    } else {
      if (c_line->size[1] - 1 < 1) {
        Throttle_dyno_B.reachedEndOfFile = 0;
      } else {
        Throttle_dyno_B.reachedEndOfFile = c_line->size[1] - 1;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = Throttle_dyno_B.reachedEndOfFile;
      Thrott_emxEnsureCapacity_char_T(out, i);
      if (Throttle_dyno_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               Throttle_dyno_B.reachedEndOfFile * sizeof(char_T));
      }
    }
  } else if (c_line->data[c_line->size[1] - 1] == '\x0d') {
    if (c_line->size[1] - 1 < 1) {
      Throttle_dyno_B.reachedEndOfFile = 0;
    } else {
      Throttle_dyno_B.reachedEndOfFile = c_line->size[1] - 1;
    }

    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = Throttle_dyno_B.reachedEndOfFile;
    Thrott_emxEnsureCapacity_char_T(out, i);
    if (Throttle_dyno_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&out->data[0], &c_line->data[0], (uint32_T)
             Throttle_dyno_B.reachedEndOfFile * sizeof(char_T));
    }
  } else {
    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = c_line->size[1];
    Thrott_emxEnsureCapacity_char_T(out, i);
    Throttle_dyno_B.reachedEndOfFile = c_line->size[1];
    memcpy(&out->data[0], &c_line->data[0], (uint32_T)
           Throttle_dyno_B.reachedEndOfFile * sizeof(char_T));
  }

  Throttle_dyno_emxFree_char_T(&c_line);
}

static int32_T Throttle_dyno_cfclose(real_T fid)
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
    b_f = Throttle_dyno_DW.eml_openfiles[fileid_0 - 3];
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
      Throttle_dyno_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }

  return st;
}

static void Throttle_dyn_SystemCore_setup_k(codertarget_raspi_internal__k_T *obj)
{
  emxArray_char_T_Throttle_dyno_T *errString1;
  emxArray_char_T_Throttle_dyno_T *tline;
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
  Throttle_dyno_B.canInterface[0] = 'c';
  Throttle_dyno_B.canInterface[1] = 'a';
  Throttle_dyno_B.canInterface[2] = 'n';
  Throttle_dyno_B.canInterface[3] = '0';
  Throttle_dyno_B.canInterface[4] = '\x00';
  Throttle_dyno_B.stat1 = -1;
  Throttle_dyno_B.stat2 = -1;
  MW_checkIFStatus(&Throttle_dyno_B.canInterface[0]);
  Throttle_dyno_B.len = MW_bitrate(&Throttle_dyno_B.bitRate[0]);
  if (Throttle_dyno_B.len < 1) {
    Throttle_dyno_B.j = -1;
  } else {
    Throttle_dyno_B.j = Throttle_dyno_B.len - 1;
  }

  memcpy(&Throttle_dyno_B.cmd_data[0], &tmp[0], 158U * sizeof(char_T));
  Throttle_dyno_B.cmd_data[158] = 'c';
  Throttle_dyno_B.cmd_data[159] = 'a';
  Throttle_dyno_B.cmd_data[160] = 'n';
  Throttle_dyno_B.cmd_data[161] = '0';
  for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 21; Throttle_dyno_B.len++)
  {
    Throttle_dyno_B.cmd_data[Throttle_dyno_B.len + 162] =
      tmp_0[Throttle_dyno_B.len];
  }

  if (Throttle_dyno_B.j >= 0) {
    memcpy(&Throttle_dyno_B.cmd_data[183], &Throttle_dyno_B.bitRate[0],
           (uint32_T)(Throttle_dyno_B.j + 1) * sizeof(char_T));
  }

  for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 32; Throttle_dyno_B.len++)
  {
    Throttle_dyno_B.cmd_data[(Throttle_dyno_B.len + Throttle_dyno_B.j) + 184] =
      tmp_1[Throttle_dyno_B.len];
  }

  Throttle_dyno_B.cmd_data[Throttle_dyno_B.j + 216] = '\x00';
  MW_loadCANModules(1);
  MW_setupCANLink(&Throttle_dyno_B.cmd_data[0], 1);
  fileid = Throttle_dyno_cfopen("MW_SocketCAN_Error_IPLink.txt", "rb");
  Throttle_dyno_emxInit_char_T(&tline, 2);
  Throttle_dyno_fgetl((real_T)fileid, tline);
  Throttle_dyno_cfclose((real_T)fileid);
  Throttle_dyno_emxInit_char_T(&errString1, 2);
  guard1 = false;
  guard2 = false;
  if (tline->size[1] == 0) {
    guard2 = true;
  } else {
    for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 42; Throttle_dyno_B.len
         ++) {
      Throttle_dyno_B.patVal[Throttle_dyno_B.len] = tmp_2[Throttle_dyno_B.len];
    }

    Throttle_dyno_B.len = 1;
    do {
      exitg1 = 0;
      if (Throttle_dyno_B.len - 1 <= tline->size[1] - 42) {
        Throttle_dyno_B.j = 1;
        while ((Throttle_dyno_B.j <= 42) && (tline->data[(Throttle_dyno_B.len +
                 Throttle_dyno_B.j) - 2] ==
                Throttle_dyno_B.patVal[Throttle_dyno_B.j - 1])) {
          Throttle_dyno_B.j++;
        }

        if (Throttle_dyno_B.j > 42) {
          exitg1 = 1;
        } else {
          Throttle_dyno_B.len++;
        }
      } else {
        Throttle_dyno_B.len = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (Throttle_dyno_B.len > 0) {
      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 41;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len] = tmp_4[Throttle_dyno_B.len];
      }

      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 49;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len + 41] =
          tmp_5[Throttle_dyno_B.len];
      }

      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 45;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len + 90] =
          tmp_6[Throttle_dyno_B.len];
      }

      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 23;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len + 135] =
          tmp_7[Throttle_dyno_B.len];
      }

      Throttle_dyno_B.cmd[158] = 'c';
      Throttle_dyno_B.cmd[159] = 'a';
      Throttle_dyno_B.cmd[160] = 'n';
      Throttle_dyno_B.cmd[161] = '0';
      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 18;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len + 162] =
          tmp_8[Throttle_dyno_B.len];
      }

      Throttle_dyno_B.cmd[180] = 'a';
      Throttle_dyno_B.cmd[181] = 'w';
      Throttle_dyno_B.cmd[182] = 'k';
      Throttle_dyno_B.cmd[183] = ' ';
      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 12;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len + 184] =
          tmp_a[Throttle_dyno_B.len];
      }

      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 29;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.cmd[Throttle_dyno_B.len + 196] =
          tmp_b[Throttle_dyno_B.len];
      }

      Throttle_dyno_B.cmd[225] = '\x00';
      MW_executeCommand(&Throttle_dyno_B.cmd[0]);
      fileid = Throttle_dyno_cfopen("MW_SocketCAN_GetBitRate.txt", "rb");
      Throttle_dyno_fgetl((real_T)fileid, tline);
      Throttle_dyno_cfclose((real_T)fileid);
      Throttle_dyno_B.len = MW_bitrate(&Throttle_dyno_B.bitRate[0]);
      if (Throttle_dyno_B.len < 1) {
        Throttle_dyno_B.len = 0;
      }

      b_bool = false;
      e = (tline->size[1] == 0);
      if (e && (Throttle_dyno_B.len == 0)) {
        b_bool = true;
      } else if (Throttle_dyno_B.len != tline->size[1]) {
      } else {
        Throttle_dyno_B.j = 1;
        do {
          exitg1 = 0;
          if (Throttle_dyno_B.j - 1 <= (uint8_T)Throttle_dyno_B.len - 1) {
            if (tline->data[Throttle_dyno_B.j - 1] !=
                Throttle_dyno_B.bitRate[Throttle_dyno_B.j - 1]) {
              exitg1 = 1;
            } else {
              Throttle_dyno_B.j++;
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
        Throttle_dyno_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1] + 30;
        Thrott_emxEnsureCapacity_char_T(errString1, Throttle_dyno_B.len);
        errString1->data[0] = 'c';
        errString1->data[1] = 'a';
        errString1->data[2] = 'n';
        errString1->data[3] = '0';
        for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 24;
             Throttle_dyno_B.len++) {
          errString1->data[Throttle_dyno_B.len + 4] = tmp_d[Throttle_dyno_B.len];
        }

        Throttle_dyno_B.j = tline->size[1];
        if (Throttle_dyno_B.j - 1 >= 0) {
          memcpy(&errString1->data[28], &tline->data[0], (uint32_T)
                 Throttle_dyno_B.j * sizeof(char_T));
        }

        errString1->data[tline->size[1] + 28] = '\x0a';
        errString1->data[tline->size[1] + 29] = '\x00';
        MW_printError(&errString1->data[0]);
        guard1 = true;
      }
    } else {
      for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 25;
           Throttle_dyno_B.len++) {
        Throttle_dyno_B.patVal_m[Throttle_dyno_B.len] =
          tmp_3[Throttle_dyno_B.len];
      }

      Throttle_dyno_B.len = 1;
      do {
        exitg1 = 0;
        if (Throttle_dyno_B.len - 1 <= tline->size[1] - 25) {
          Throttle_dyno_B.j = 1;
          while ((Throttle_dyno_B.j <= 25) && (tline->data[(Throttle_dyno_B.len
                   + Throttle_dyno_B.j) - 2] ==
                  Throttle_dyno_B.patVal_m[Throttle_dyno_B.j - 1])) {
            Throttle_dyno_B.j++;
          }

          if (Throttle_dyno_B.j > 25) {
            exitg1 = 1;
          } else {
            Throttle_dyno_B.len++;
          }
        } else {
          Throttle_dyno_B.len = 0;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (Throttle_dyno_B.len > 0) {
        Throttle_dyno_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        Thrott_emxEnsureCapacity_char_T(errString1, Throttle_dyno_B.len);
        Throttle_dyno_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)
               Throttle_dyno_B.j * sizeof(char_T));
        MW_printError(&errString1->data[0]);
      } else {
        Throttle_dyno_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        Thrott_emxEnsureCapacity_char_T(errString1, Throttle_dyno_B.len);
        Throttle_dyno_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)
               Throttle_dyno_B.j * sizeof(char_T));
        MW_printError(&errString1->data[0]);
      }

      guard1 = true;
    }
  }

  if (guard2) {
    Throttle_dyno_B.stat1 = MW_createSocket(&Throttle_dyno_B.canInterface[0],
      &obj->sockHandleDataFrames);
    Throttle_dyno_B.stat2 = MW_createSocket(&Throttle_dyno_B.canInterface[0],
      &obj->sockHandleErrorFrames);
  }

  if (guard1) {
    for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 11; Throttle_dyno_B.len
         ++) {
      Throttle_dyno_B.errString0[Throttle_dyno_B.len] =
        tmp_9[Throttle_dyno_B.len];
    }

    Throttle_dyno_B.errString0[11] = 'c';
    Throttle_dyno_B.errString0[12] = 'a';
    Throttle_dyno_B.errString0[13] = 'n';
    Throttle_dyno_B.errString0[14] = '0';
    Throttle_dyno_B.errString0[15] = '\x0a';
    Throttle_dyno_B.errString0[16] = '\x00';
    MW_printError(&Throttle_dyno_B.errString0[0]);
    Throttle_dyno_B.errString3[0] = 'c';
    Throttle_dyno_B.errString3[1] = 'a';
    Throttle_dyno_B.errString3[2] = 'n';
    Throttle_dyno_B.errString3[3] = '0';
    for (Throttle_dyno_B.len = 0; Throttle_dyno_B.len < 14; Throttle_dyno_B.len
         ++) {
      Throttle_dyno_B.errString3[Throttle_dyno_B.len + 4] =
        tmp_c[Throttle_dyno_B.len];
    }

    Throttle_dyno_B.errString3[18] = '\x0a';
    Throttle_dyno_B.errString3[19] = '\x00';
    MW_printError(&Throttle_dyno_B.errString3[0]);
  }

  Throttle_dyno_emxFree_char_T(&errString1);
  Throttle_dyno_emxFree_char_T(&tline);
  if ((Throttle_dyno_B.stat1 == 0) && (Throttle_dyno_B.stat2 == 0)) {
    obj->Initialized = true;
  } else {
    obj->Initialized = false;
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Throttle_dyno_step(void)
{
  real_T Enable_prev;
  int32_T b_i;
  int32_T sockStatus;
  char_T rxInterface[5];
  uint8_T rxData[8];
  uint8_T remote;
  uint8_T status;

  /* MATLABSystem: '<Root>/CAN Receive' */
  if (Throttle_dyno_DW.obj.SampleTime != Throttle_dyno_P.CANReceive_SampleTime)
  {
    Throttle_dyno_DW.obj.SampleTime = Throttle_dyno_P.CANReceive_SampleTime;
  }

  if (Throttle_dyno_DW.obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    sockStatus = MW_CAN_receiveCANMsg(&rxInterface[0],
      &Throttle_dyno_B.CANReceive_o1.ID, &rxData[0],
      &Throttle_dyno_B.CANReceive_o1.Length, &status,
      &Throttle_dyno_B.CANReceive_o1.Extended, &remote,
      &Throttle_dyno_B.CANReceive_o1.Error,
      Throttle_dyno_DW.obj.sockHandleDataFrames,
      Throttle_dyno_DW.obj.sockHandleErrorFrames);
    Throttle_dyno_B.CANReceive_o1.Remote = (uint8_T)(remote == 0);
    if (sockStatus != 0) {
      Throttle_dyno_DW.obj.Initialized = false;
    }

    Throttle_dyno_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      Throttle_dyno_B.CANReceive_o1.Data[sockStatus] = rxData[sockStatus];
    }
  } else {
    Throttle_dyno_B.CANReceive_o1.Extended = 0U;
    Throttle_dyno_B.CANReceive_o1.Length = 0U;
    Throttle_dyno_B.CANReceive_o1.Remote = 0U;
    Throttle_dyno_B.CANReceive_o1.Error = 0U;
    Throttle_dyno_B.CANReceive_o1.ID = 0U;
    Throttle_dyno_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      Throttle_dyno_B.CANReceive_o1.Data[sockStatus] = 0U;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Receive' */

  /* S-Function (scanunpack): '<Root>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == Throttle_dyno_B.CANReceive_o1.Length) &&
        (Throttle_dyno_B.CANReceive_o1.ID != INVALID_CAN_ID) ) {
      if ((469828098 == Throttle_dyno_B.CANReceive_o1.ID) && (1U ==
           Throttle_dyno_B.CANReceive_o1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
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
                    (Throttle_dyno_B.CANReceive_o1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Throttle_dyno_B.CANReceive_o1.Data[1]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Throttle_dyno_B.CANUnpack_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
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
                    (Throttle_dyno_B.CANReceive_o1.Data[2]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Throttle_dyno_B.CANReceive_o1.Data[3]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Throttle_dyno_B.CANUnpack_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 48
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Throttle_dyno_B.CANReceive_o1.Data[6]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Throttle_dyno_B.CANUnpack_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
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
                    (Throttle_dyno_B.CANReceive_o1.Data[4]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (Throttle_dyno_B.CANReceive_o1.Data[5]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              Throttle_dyno_B.CANUnpack_o4 = result;
            }
          }
        }
      }
    }
  }

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   */
  if (Throttle_dyno_DW.temporalCounter_i1 < 511U) {
    Throttle_dyno_DW.temporalCounter_i1++;
  }

  Enable_prev = Throttle_dyno_DW.Enable_start;
  Throttle_dyno_DW.Enable_start = Throttle_dyno_B.CANUnpack_o3;
  if (Throttle_dyno_DW.is_active_c3_Throttle_dyno == 0U) {
    Throttle_dyno_DW.is_active_c3_Throttle_dyno = 1U;
    Throttle_dyno_DW.is_c3_Throttle_dyno = Throttle_dyno_IN_Disabled;
    Throttle_dyno_B.Load_Enable = false;
    Throttle_dyno_B.Load = 0.0;
    Throttle_dyno_B.Throttle = Throttle_dyno_P.Constant7_Value;
  } else if (Throttle_dyno_DW.is_c3_Throttle_dyno == Throttle_dyno_IN_Disabled)
  {
    if ((Enable_prev != Throttle_dyno_DW.Enable_start) &&
        (Throttle_dyno_DW.Enable_start == 1.0)) {
      Throttle_dyno_DW.is_c3_Throttle_dyno = Throttle_dyno_IN_Enabled;
      Throttle_dyno_DW.is_Enabled = Throttle_dy_IN_Throttle_Setting;
      Throttle_dyno_DW.Count = 0.0;
      Throttle_dyno_DW.is_Throttle_Setting = Throttle_dyno_IN_Start;
      Throttle_dyno_B.Load_Enable = true;
      Throttle_dyno_B.Load = 0.0;
    } else {
      Throttle_dyno_B.Load_Enable = false;
      Throttle_dyno_B.Load = 0.0;
      Throttle_dyno_B.Throttle = Throttle_dyno_P.Constant7_Value;
    }

    /* case IN_Enabled: */
  } else if ((!(Throttle_dyno_B.CANUnpack_o3 != 0.0)) ||
             (Throttle_dyno_B.CANUnpack_o1 < 1000.0)) {
    Throttle_dyno_DW.is_Throttle_Setting = Throttle_dyn_IN_NO_ACTIVE_CHILD;
    Throttle_dyno_DW.is_Enabled = Throttle_dyn_IN_NO_ACTIVE_CHILD;
    Throttle_dyno_DW.is_c3_Throttle_dyno = Throttle_dyno_IN_Disabled;
    Throttle_dyno_B.Load_Enable = false;
    Throttle_dyno_B.Load = 0.0;
    Throttle_dyno_B.Throttle = Throttle_dyno_P.Constant7_Value;
  } else if (Throttle_dyno_DW.is_Enabled == Throttle_dyno_IN_End) {
    Throttle_dyno_B.Throttle = Throttle_dyno_P.Constant7_Value;
    Throttle_dyno_B.Load = 0.0;
    Throttle_dyno_B.Load_Enable = false;

    /* case IN_Throttle_Setting: */
  } else if (Throttle_dyno_DW.Count == 5.0) {
    if (Throttle_dyno_B.Throttle >= Throttle_dyno_P.Constant6_Value) {
      Throttle_dyno_DW.is_Throttle_Setting = Throttle_dyn_IN_NO_ACTIVE_CHILD;
      Throttle_dyno_DW.is_Enabled = Throttle_dyno_IN_End;
      Throttle_dyno_B.Throttle = Throttle_dyno_P.Constant7_Value;
      Throttle_dyno_B.Load = 0.0;
      Throttle_dyno_B.Load_Enable = false;
    } else {
      Throttle_dyno_B.Throttle += Throttle_dyno_P.Constant5_Value;
      Throttle_dyno_DW.is_Enabled = Throttle_dy_IN_Throttle_Setting;
      Throttle_dyno_DW.Count = 0.0;
      Throttle_dyno_DW.is_Throttle_Setting = Throttle_dyno_IN_Start;
      Throttle_dyno_B.Load_Enable = true;
      Throttle_dyno_B.Load = 0.0;
    }
  } else if (Throttle_dyno_DW.is_Throttle_Setting ==
             Throttle_dyno_IN_Load_Increase) {
    if (Throttle_dyno_DW.temporalCounter_i1 >= 500U) {
      if (Throttle_dyno_B.CANUnpack_o1 <= Throttle_dyno_P.Constant3_Value) {
        Throttle_dyno_DW.Count++;
        Throttle_dyno_DW.is_Throttle_Setting = Throttle_dyno_IN_Start;
        Throttle_dyno_B.Load_Enable = true;
        Throttle_dyno_B.Load = 0.0;
      } else {
        Throttle_dyno_DW.temporalCounter_i1 = 0U;
        Throttle_dyno_B.Load += Throttle_dyno_P.Constant4_Value;
      }
    }
  } else {
    /* case IN_Start: */
    Throttle_dyno_DW.is_Throttle_Setting = Throttle_dyno_IN_Load_Increase;
    Throttle_dyno_DW.temporalCounter_i1 = 0U;
    Throttle_dyno_B.Load += Throttle_dyno_P.Constant4_Value;
  }

  /* End of Chart: '<Root>/Chart' */

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  Throttle_dyno_B.Divide2 = Throttle_dyno_B.Load *
    Throttle_dyno_P.Constant9_Value / Throttle_dyno_B.CANUnpack_o2;

  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  Throttle_dyno_B.CANPack.ID = 469827841U;
  Throttle_dyno_B.CANPack.Length = 8U;
  Throttle_dyno_B.CANPack.Extended = 1U;
  Throttle_dyno_B.CANPack.Remote = 0;
  Throttle_dyno_B.CANPack.Data[0] = 0;
  Throttle_dyno_B.CANPack.Data[1] = 0;
  Throttle_dyno_B.CANPack.Data[2] = 0;
  Throttle_dyno_B.CANPack.Data[3] = 0;
  Throttle_dyno_B.CANPack.Data[4] = 0;
  Throttle_dyno_B.CANPack.Data[5] = 0;
  Throttle_dyno_B.CANPack.Data[6] = 0;
  Throttle_dyno_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 63
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (Throttle_dyno_B.Load_Enable);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            Throttle_dyno_B.CANPack.Data[7] = Throttle_dyno_B.CANPack.Data[7] |
              (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
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
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = Throttle_dyno_P.Constant_Value;

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
            Throttle_dyno_B.CANPack.Data[0] = Throttle_dyno_B.CANPack.Data[0] |
              (uint8_T)((uint16_T)(packedValue & (uint16_T)0xFFU));
            Throttle_dyno_B.CANPack.Data[1] = Throttle_dyno_B.CANPack.Data[1] |
              (uint8_T)((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >>
              8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
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
        real64_T result = Throttle_dyno_B.Divide2;

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
            Throttle_dyno_B.CANPack.Data[2] = Throttle_dyno_B.CANPack.Data[2] |
              (uint8_T)((uint16_T)(packedValue & (uint16_T)0xFFU));
            Throttle_dyno_B.CANPack.Data[3] = Throttle_dyno_B.CANPack.Data[3] |
              (uint8_T)((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >>
              8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 40
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
        real64_T result = Throttle_dyno_B.Throttle;

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
            Throttle_dyno_B.CANPack.Data[5] = Throttle_dyno_B.CANPack.Data[5] |
              (uint8_T)((uint16_T)(packedValue & (uint16_T)0xFFU));
            Throttle_dyno_B.CANPack.Data[6] = Throttle_dyno_B.CANPack.Data[6] |
              (uint8_T)((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >>
              8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit' */
  if (Throttle_dyno_DW.obj_j.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      rxData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (Throttle_dyno_B.CANPack.Remote == 0) {
      sockStatus = Throttle_dyno_B.CANPack.Length - 1;
      for (b_i = 0; b_i <= sockStatus; b_i++) {
        rxData[(uint8_T)((uint32_T)b_i + 1U) - 1] =
          Throttle_dyno_B.CANPack.Data[(uint8_T)((uint32_T)b_i + 1U) - 1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (Throttle_dyno_B.CANPack.Extended == 0), Throttle_dyno_B.CANPack.ID,
      Throttle_dyno_B.CANPack.Length, &rxData[0], Throttle_dyno_B.CANPack.Remote,
      &status, 0, 1.0, Throttle_dyno_DW.obj_j.sockHandleDataFrames,
      Throttle_dyno_DW.obj_j.sockHandleErrorFrames, (uint8_T)
      Throttle_dyno_DW.obj_j.notFirstStep);
    if (sockStatus != 0) {
      Throttle_dyno_DW.obj_j.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit' */
}

/* Model initialize function */
void Throttle_dyno_initialize(void)
{
  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack' */

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for MATLABSystem: '<Root>/CAN Receive' */
  Throttle_dyno_DW.obj.sockHandleDataFrames = 0;
  Throttle_dyno_DW.obj.sockHandleErrorFrames = 0;
  Throttle_dyno_DW.obj.isInitialized = 0;
  Throttle_dyno_DW.obj.matlabCodegenIsDeleted = false;
  Throttle_dyno_DW.obj.SampleTime = Throttle_dyno_P.CANReceive_SampleTime;
  Throttle_dyno_SystemCore_setup(&Throttle_dyno_DW.obj);

  /* Start for MATLABSystem: '<Root>/CAN Transmit' */
  Throttle_dyno_B.a = NULL;
  for (Throttle_dyno_B.i = 0; Throttle_dyno_B.i < 20; Throttle_dyno_B.i++) {
    Throttle_dyno_DW.eml_openfiles[Throttle_dyno_B.i] = Throttle_dyno_B.a;
  }

  Throttle_dyno_DW.obj_j.sockHandleDataFrames = 0;
  Throttle_dyno_DW.obj_j.sockHandleErrorFrames = 0;
  Throttle_dyno_DW.obj_j.notFirstStep = false;
  Throttle_dyno_DW.obj_j.isInitialized = 0;
  Throttle_dyno_DW.obj_j.matlabCodegenIsDeleted = false;
  Throttle_dyn_SystemCore_setup_k(&Throttle_dyno_DW.obj_j);

  /* End of Start for MATLABSystem: '<Root>/CAN Transmit' */
}

/* Model terminate function */
void Throttle_dyno_terminate(void)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Receive' */
  if (!Throttle_dyno_DW.obj.matlabCodegenIsDeleted) {
    Throttle_dyno_DW.obj.matlabCodegenIsDeleted = true;
    if ((Throttle_dyno_DW.obj.isInitialized == 1) &&
        Throttle_dyno_DW.obj.isSetupComplete && Throttle_dyno_DW.obj.Initialized)
    {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Throttle_dyno_DW.obj.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&Throttle_dyno_DW.obj.sockHandleErrorFrames, &canInterface
                     [0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Receive' */

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!Throttle_dyno_DW.obj_j.matlabCodegenIsDeleted) {
    Throttle_dyno_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Throttle_dyno_DW.obj_j.isInitialized == 1) &&
        Throttle_dyno_DW.obj_j.isSetupComplete &&
        Throttle_dyno_DW.obj_j.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Throttle_dyno_DW.obj_j.sockHandleDataFrames,
                     &canInterface[0]);
      MW_clearSocket(&Throttle_dyno_DW.obj_j.sockHandleErrorFrames,
                     &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
