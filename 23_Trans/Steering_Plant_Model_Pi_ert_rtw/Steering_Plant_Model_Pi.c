/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Steering_Plant_Model_Pi.c
 *
 * Code generated for Simulink model 'Steering_Plant_Model_Pi'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb  8 16:23:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Steering_Plant_Model_Pi.h"
#include "Steering_Plant_Model_Pi_types.h"
#include "rtwtypes.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "Steering_Plant_Model_Pi_private.h"

/* Block signals (default storage) */
B_Steering_Plant_Model_Pi_T Steering_Plant_Model_Pi_B;

/* Block states (default storage) */
DW_Steering_Plant_Model_Pi_T Steering_Plant_Model_Pi_DW;

/* Real-time model */
static RT_MODEL_Steering_Plant_Model_T Steering_Plant_Model_Pi_M_;
RT_MODEL_Steering_Plant_Model_T *const Steering_Plant_Model_Pi_M =
  &Steering_Plant_Model_Pi_M_;

/* Forward declaration for local functions */
static int8_T Steering_Plant_Model_P_filedata(void);
static int8_T Steering_Plant_Model_Pi_cfopen(const char_T *cfilename, const
  char_T *cpermission);
static void Steering_Plant_M_emxInit_char_T(emxArray_char_T_Steering_Plan_T
  **pEmxArray, int32_T numDimensions);
static FILE* Steering_Plant_Mode_fileManager(real_T varargin_1);
static void Steeri_emxEnsureCapacity_char_T(emxArray_char_T_Steering_Plan_T
  *emxArray, int32_T oldNumel);
static void Steering_Plant_M_emxFree_char_T(emxArray_char_T_Steering_Plan_T
  **pEmxArray);
static void Steering_Plant_Model_Pi_fgetl(real_T fileID,
  emxArray_char_T_Steering_Plan_T *out);
static int32_T Steering_Plant_Model_Pi_cfclose(real_T fid);
static void Steering_Pla_SystemCore_setup_g(codertarget_raspi_internal__g_T *obj);
static void Steering_Plant_SystemCore_setup(codertarget_raspi_internal_CA_T *obj);
static int8_T Steering_Plant_Model_P_filedata(void)
{
  int32_T b_k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 20)) {
    if (Steering_Plant_Model_Pi_DW.eml_openfiles[(int8_T)(b_k + 1) - 1] == NULL)
    {
      f = (int8_T)(b_k + 1);
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return f;
}

static int8_T Steering_Plant_Model_Pi_cfopen(const char_T *cfilename, const
  char_T *cpermission)
{
  FILE* filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Steering_Plant_Model_P_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Steering_Plant_Model_Pi_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

static void Steering_Plant_M_emxInit_char_T(emxArray_char_T_Steering_Plan_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Steering_Plan_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Steering_Plan_T *)malloc(sizeof
    (emxArray_char_T_Steering_Plan_T));
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

static FILE* Steering_Plant_Mode_fileManager(real_T varargin_1)
{
  FILE* f;
  int8_T fileid;
  fileid = (int8_T)varargin_1;
  if (varargin_1 != (int8_T)varargin_1) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Steering_Plant_Model_Pi_DW.eml_openfiles[fileid - 3];
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

static void Steeri_emxEnsureCapacity_char_T(emxArray_char_T_Steering_Plan_T
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

static void Steering_Plant_M_emxFree_char_T(emxArray_char_T_Steering_Plan_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Steering_Plan_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Steering_Plan_T *)NULL;
  }
}

static void Steering_Plant_Model_Pi_fgetl(real_T fileID,
  emxArray_char_T_Steering_Plan_T *out)
{
  emxArray_char_T_Steering_Plan_T *c_line;
  emxArray_char_T_Steering_Plan_T *outBuff;
  int32_T c_i;
  int32_T exitg1;
  int32_T i;
  char_T tmp;
  uint8_T buf;
  boolean_T exitg2;
  boolean_T fileEndAfterCarriageReturn;
  boolean_T newLineAfterCarriageReturn;
  boolean_T readNewline;
  Steering_Plant_Model_Pi_B.filestar = Steering_Plant_Mode_fileManager(fileID);
  if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
  } else {
    Steering_Plant_Model_Pi_B.filestar = NULL;
  }

  Steering_Plant_M_emxInit_char_T(&outBuff, 2);
  outBuff->size[0] = 1;
  outBuff->size[1] = 0;
  Steering_Plant_M_emxInit_char_T(&c_line, 2);
  if (Steering_Plant_Model_Pi_B.filestar == NULL) {
    c_line->size[0] = 1;
    c_line->size[1] = 0;
  } else {
    do {
      exitg1 = 0;
      Steering_Plant_Model_Pi_B.cOut = fgets
        (&Steering_Plant_Model_Pi_B.ReadBuff[0], 1024,
         Steering_Plant_Model_Pi_B.filestar);
      readNewline = false;
      Steering_Plant_Model_Pi_B.b_NULL = NULL;
      Steering_Plant_Model_Pi_B.filestar_c = Steering_Plant_Mode_fileManager
        (fileID);
      if (Steering_Plant_Model_Pi_B.filestar_c ==
          Steering_Plant_Model_Pi_B.b_NULL) {
        Steering_Plant_Model_Pi_B.reachedEndOfFile = 0;
      } else {
        Steering_Plant_Model_Pi_B.b_st = feof
          (Steering_Plant_Model_Pi_B.filestar_c);
        Steering_Plant_Model_Pi_B.reachedEndOfFile = ((int32_T)
          Steering_Plant_Model_Pi_B.b_st != 0);
      }

      if (Steering_Plant_Model_Pi_B.cOut == NULL) {
        exitg1 = 1;
      } else {
        Steering_Plant_Model_Pi_B.idx = 1;
        Steering_Plant_Model_Pi_B.carriageReturnAt = 0;
        if (Steering_Plant_Model_Pi_B.reachedEndOfFile != 0) {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1024)) {
            tmp = Steering_Plant_Model_Pi_B.ReadBuff[c_i - 1];
            if (tmp == '\x00') {
              Steering_Plant_Model_Pi_B.idx = c_i;
              exitg2 = true;
            } else {
              if ((Steering_Plant_Model_Pi_B.carriageReturnAt == 0) && (tmp ==
                   '\x0d')) {
                Steering_Plant_Model_Pi_B.carriageReturnAt = c_i;
              }

              c_i++;
            }
          }

          if (Steering_Plant_Model_Pi_B.ReadBuff[Steering_Plant_Model_Pi_B.idx -
              1] == '\x00') {
            Steering_Plant_Model_Pi_B.idx--;
          }
        } else {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1025)) {
            if (c_i > 1024) {
              Steering_Plant_Model_Pi_B.idx = 1023;
              exitg2 = true;
            } else {
              tmp = Steering_Plant_Model_Pi_B.ReadBuff[c_i - 1];
              if (tmp == '\x0a') {
                Steering_Plant_Model_Pi_B.idx = c_i;
                exitg2 = true;
              } else {
                if ((Steering_Plant_Model_Pi_B.carriageReturnAt == 0) && (tmp ==
                     '\x0d')) {
                  Steering_Plant_Model_Pi_B.carriageReturnAt = c_i;
                }

                c_i++;
              }
            }
          }

          readNewline =
            (Steering_Plant_Model_Pi_B.ReadBuff[Steering_Plant_Model_Pi_B.idx -
             1] == '\x0a');
        }

        if ((Steering_Plant_Model_Pi_B.carriageReturnAt > 0) &&
            (Steering_Plant_Model_Pi_B.carriageReturnAt < 1024)) {
          newLineAfterCarriageReturn =
            (Steering_Plant_Model_Pi_B.ReadBuff[Steering_Plant_Model_Pi_B.carriageReturnAt]
             == '\x0a');
          if ((Steering_Plant_Model_Pi_B.reachedEndOfFile != 0) &&
              (Steering_Plant_Model_Pi_B.ReadBuff[Steering_Plant_Model_Pi_B.carriageReturnAt]
               == '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }

        if ((Steering_Plant_Model_Pi_B.carriageReturnAt == 0) ||
            newLineAfterCarriageReturn || fileEndAfterCarriageReturn) {
          if (Steering_Plant_Model_Pi_B.idx < 1) {
            Steering_Plant_Model_Pi_B.idx = 0;
          }

          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += Steering_Plant_Model_Pi_B.idx;
          Steeri_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < Steering_Plant_Model_Pi_B.idx; i++) {
            outBuff->data[c_i + i] = Steering_Plant_Model_Pi_B.ReadBuff[i];
          }
        } else {
          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += Steering_Plant_Model_Pi_B.carriageReturnAt;
          Steeri_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < Steering_Plant_Model_Pi_B.carriageReturnAt; i++) {
            outBuff->data[c_i + i] = Steering_Plant_Model_Pi_B.ReadBuff[i];
          }

          Steering_Plant_Model_Pi_B.wherefrom = SEEK_CUR;
          Steering_Plant_Model_Pi_B.filestar_c = Steering_Plant_Mode_fileManager
            (fileID);
          if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
          } else {
            Steering_Plant_Model_Pi_B.filestar_c = NULL;
          }

          if (!(Steering_Plant_Model_Pi_B.filestar_c == NULL)) {
            fseek(Steering_Plant_Model_Pi_B.filestar_c, (long int)
                  (Steering_Plant_Model_Pi_B.carriageReturnAt -
                   Steering_Plant_Model_Pi_B.idx),
                  Steering_Plant_Model_Pi_B.wherefrom);
          }
        }

        if (readNewline || (Steering_Plant_Model_Pi_B.reachedEndOfFile != 0) ||
            (Steering_Plant_Model_Pi_B.carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    Steering_Plant_Model_Pi_B.b_NULL = NULL;
    Steering_Plant_Model_Pi_B.filestar = Steering_Plant_Mode_fileManager(fileID);
    if (Steering_Plant_Model_Pi_B.filestar == Steering_Plant_Model_Pi_B.b_NULL)
    {
      Steering_Plant_Model_Pi_B.reachedEndOfFile = 0;
    } else {
      Steering_Plant_Model_Pi_B.b_st = feof(Steering_Plant_Model_Pi_B.filestar);
      Steering_Plant_Model_Pi_B.reachedEndOfFile = ((int32_T)
        Steering_Plant_Model_Pi_B.b_st != 0);
    }

    if (Steering_Plant_Model_Pi_B.reachedEndOfFile == 0) {
      Steering_Plant_Model_Pi_B.filestar = Steering_Plant_Mode_fileManager
        (fileID);
      if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
      } else {
        Steering_Plant_Model_Pi_B.filestar = NULL;
      }

      if (!(Steering_Plant_Model_Pi_B.filestar == NULL)) {
        fread(&buf, sizeof(uint8_T), (size_t)1,
              Steering_Plant_Model_Pi_B.filestar);
      }

      Steering_Plant_Model_Pi_B.b_NULL = NULL;
      Steering_Plant_Model_Pi_B.filestar = Steering_Plant_Mode_fileManager
        (fileID);
      if (Steering_Plant_Model_Pi_B.filestar == Steering_Plant_Model_Pi_B.b_NULL)
      {
        Steering_Plant_Model_Pi_B.reachedEndOfFile = 0;
      } else {
        Steering_Plant_Model_Pi_B.b_st = feof(Steering_Plant_Model_Pi_B.filestar);
        Steering_Plant_Model_Pi_B.reachedEndOfFile = ((int32_T)
          Steering_Plant_Model_Pi_B.b_st != 0);
      }

      if (Steering_Plant_Model_Pi_B.reachedEndOfFile == 0) {
        Steering_Plant_Model_Pi_B.wherefrom = SEEK_CUR;
        Steering_Plant_Model_Pi_B.filestar = Steering_Plant_Mode_fileManager
          (fileID);
        if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
        } else {
          Steering_Plant_Model_Pi_B.filestar = NULL;
        }

        if (!(Steering_Plant_Model_Pi_B.filestar == NULL)) {
          fseek(Steering_Plant_Model_Pi_B.filestar, (long int)-1.0,
                Steering_Plant_Model_Pi_B.wherefrom);
        }
      }
    }

    i = c_line->size[0] * c_line->size[1];
    c_line->size[0] = 1;
    c_line->size[1] = outBuff->size[1];
    Steeri_emxEnsureCapacity_char_T(c_line, i);
    Steering_Plant_Model_Pi_B.reachedEndOfFile = outBuff->size[1];
    if (Steering_Plant_Model_Pi_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&c_line->data[0], &outBuff->data[0], (uint32_T)
             Steering_Plant_Model_Pi_B.reachedEndOfFile * sizeof(char_T));
    }
  }

  Steering_Plant_M_emxFree_char_T(&outBuff);
  if (c_line->size[1] == 0) {
    out->size[0] = 1;
    out->size[1] = 0;
  } else if (c_line->data[c_line->size[1] - 1] == '\x0a') {
    if ((c_line->size[1] > 1) && (c_line->data[c_line->size[1] - 2] == '\x0d'))
    {
      if (c_line->size[1] - 2 < 1) {
        Steering_Plant_Model_Pi_B.reachedEndOfFile = 0;
      } else {
        Steering_Plant_Model_Pi_B.reachedEndOfFile = c_line->size[1] - 2;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = Steering_Plant_Model_Pi_B.reachedEndOfFile;
      Steeri_emxEnsureCapacity_char_T(out, i);
      if (Steering_Plant_Model_Pi_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               Steering_Plant_Model_Pi_B.reachedEndOfFile * sizeof(char_T));
      }
    } else {
      if (c_line->size[1] - 1 < 1) {
        Steering_Plant_Model_Pi_B.reachedEndOfFile = 0;
      } else {
        Steering_Plant_Model_Pi_B.reachedEndOfFile = c_line->size[1] - 1;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = Steering_Plant_Model_Pi_B.reachedEndOfFile;
      Steeri_emxEnsureCapacity_char_T(out, i);
      if (Steering_Plant_Model_Pi_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               Steering_Plant_Model_Pi_B.reachedEndOfFile * sizeof(char_T));
      }
    }
  } else if (c_line->data[c_line->size[1] - 1] == '\x0d') {
    if (c_line->size[1] - 1 < 1) {
      Steering_Plant_Model_Pi_B.reachedEndOfFile = 0;
    } else {
      Steering_Plant_Model_Pi_B.reachedEndOfFile = c_line->size[1] - 1;
    }

    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = Steering_Plant_Model_Pi_B.reachedEndOfFile;
    Steeri_emxEnsureCapacity_char_T(out, i);
    if (Steering_Plant_Model_Pi_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&out->data[0], &c_line->data[0], (uint32_T)
             Steering_Plant_Model_Pi_B.reachedEndOfFile * sizeof(char_T));
    }
  } else {
    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = c_line->size[1];
    Steeri_emxEnsureCapacity_char_T(out, i);
    Steering_Plant_Model_Pi_B.reachedEndOfFile = c_line->size[1];
    memcpy(&out->data[0], &c_line->data[0], (uint32_T)
           Steering_Plant_Model_Pi_B.reachedEndOfFile * sizeof(char_T));
  }

  Steering_Plant_M_emxFree_char_T(&c_line);
}

static int32_T Steering_Plant_Model_Pi_cfclose(real_T fid)
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
    b_f = Steering_Plant_Model_Pi_DW.eml_openfiles[fileid_0 - 3];
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
      Steering_Plant_Model_Pi_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }

  return st;
}

static void Steering_Pla_SystemCore_setup_g(codertarget_raspi_internal__g_T *obj)
{
  emxArray_char_T_Steering_Plan_T *errString1;
  emxArray_char_T_Steering_Plan_T *tline;
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
  Steering_Plant_Model_Pi_B.canInterface[0] = 'c';
  Steering_Plant_Model_Pi_B.canInterface[1] = 'a';
  Steering_Plant_Model_Pi_B.canInterface[2] = 'n';
  Steering_Plant_Model_Pi_B.canInterface[3] = '0';
  Steering_Plant_Model_Pi_B.canInterface[4] = '\x00';
  Steering_Plant_Model_Pi_B.stat1 = -1;
  Steering_Plant_Model_Pi_B.stat2 = -1;
  MW_checkIFStatus(&Steering_Plant_Model_Pi_B.canInterface[0]);
  Steering_Plant_Model_Pi_B.len = MW_bitrate(&Steering_Plant_Model_Pi_B.bitRate
    [0]);
  if (Steering_Plant_Model_Pi_B.len < 1) {
    Steering_Plant_Model_Pi_B.j = -1;
  } else {
    Steering_Plant_Model_Pi_B.j = Steering_Plant_Model_Pi_B.len - 1;
  }

  memcpy(&Steering_Plant_Model_Pi_B.cmd_data[0], &tmp[0], 158U * sizeof(char_T));
  Steering_Plant_Model_Pi_B.cmd_data[158] = 'c';
  Steering_Plant_Model_Pi_B.cmd_data[159] = 'a';
  Steering_Plant_Model_Pi_B.cmd_data[160] = 'n';
  Steering_Plant_Model_Pi_B.cmd_data[161] = '0';
  for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 21;
       Steering_Plant_Model_Pi_B.len++) {
    Steering_Plant_Model_Pi_B.cmd_data[Steering_Plant_Model_Pi_B.len + 162] =
      tmp_0[Steering_Plant_Model_Pi_B.len];
  }

  if (Steering_Plant_Model_Pi_B.j >= 0) {
    memcpy(&Steering_Plant_Model_Pi_B.cmd_data[183],
           &Steering_Plant_Model_Pi_B.bitRate[0], (uint32_T)
           (Steering_Plant_Model_Pi_B.j + 1) * sizeof(char_T));
  }

  for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 32;
       Steering_Plant_Model_Pi_B.len++) {
    Steering_Plant_Model_Pi_B.cmd_data[(Steering_Plant_Model_Pi_B.len +
      Steering_Plant_Model_Pi_B.j) + 184] = tmp_1[Steering_Plant_Model_Pi_B.len];
  }

  Steering_Plant_Model_Pi_B.cmd_data[Steering_Plant_Model_Pi_B.j + 216] = '\x00';
  MW_loadCANModules(1);
  MW_setupCANLink(&Steering_Plant_Model_Pi_B.cmd_data[0], 1);
  fileid = Steering_Plant_Model_Pi_cfopen("MW_SocketCAN_Error_IPLink.txt", "rb");
  Steering_Plant_M_emxInit_char_T(&tline, 2);
  Steering_Plant_Model_Pi_fgetl((real_T)fileid, tline);
  Steering_Plant_Model_Pi_cfclose((real_T)fileid);
  Steering_Plant_M_emxInit_char_T(&errString1, 2);
  guard1 = false;
  guard2 = false;
  if (tline->size[1] == 0) {
    guard2 = true;
  } else {
    for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 42;
         Steering_Plant_Model_Pi_B.len++) {
      Steering_Plant_Model_Pi_B.patVal[Steering_Plant_Model_Pi_B.len] =
        tmp_2[Steering_Plant_Model_Pi_B.len];
    }

    Steering_Plant_Model_Pi_B.len = 1;
    do {
      exitg1 = 0;
      if (Steering_Plant_Model_Pi_B.len - 1 <= tline->size[1] - 42) {
        Steering_Plant_Model_Pi_B.j = 1;
        while ((Steering_Plant_Model_Pi_B.j <= 42) && (tline->data
                [(Steering_Plant_Model_Pi_B.len + Steering_Plant_Model_Pi_B.j) -
                2] ==
                Steering_Plant_Model_Pi_B.patVal[Steering_Plant_Model_Pi_B.j - 1]))
        {
          Steering_Plant_Model_Pi_B.j++;
        }

        if (Steering_Plant_Model_Pi_B.j > 42) {
          exitg1 = 1;
        } else {
          Steering_Plant_Model_Pi_B.len++;
        }
      } else {
        Steering_Plant_Model_Pi_B.len = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (Steering_Plant_Model_Pi_B.len > 0) {
      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 41;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len] =
          tmp_4[Steering_Plant_Model_Pi_B.len];
      }

      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 49;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len + 41] =
          tmp_5[Steering_Plant_Model_Pi_B.len];
      }

      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 45;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len + 90] =
          tmp_6[Steering_Plant_Model_Pi_B.len];
      }

      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 23;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len + 135] =
          tmp_7[Steering_Plant_Model_Pi_B.len];
      }

      Steering_Plant_Model_Pi_B.cmd[158] = 'c';
      Steering_Plant_Model_Pi_B.cmd[159] = 'a';
      Steering_Plant_Model_Pi_B.cmd[160] = 'n';
      Steering_Plant_Model_Pi_B.cmd[161] = '0';
      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 18;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len + 162] =
          tmp_8[Steering_Plant_Model_Pi_B.len];
      }

      Steering_Plant_Model_Pi_B.cmd[180] = 'a';
      Steering_Plant_Model_Pi_B.cmd[181] = 'w';
      Steering_Plant_Model_Pi_B.cmd[182] = 'k';
      Steering_Plant_Model_Pi_B.cmd[183] = ' ';
      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 12;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len + 184] =
          tmp_a[Steering_Plant_Model_Pi_B.len];
      }

      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 29;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.cmd[Steering_Plant_Model_Pi_B.len + 196] =
          tmp_b[Steering_Plant_Model_Pi_B.len];
      }

      Steering_Plant_Model_Pi_B.cmd[225] = '\x00';
      MW_executeCommand(&Steering_Plant_Model_Pi_B.cmd[0]);
      fileid = Steering_Plant_Model_Pi_cfopen("MW_SocketCAN_GetBitRate.txt",
        "rb");
      Steering_Plant_Model_Pi_fgetl((real_T)fileid, tline);
      Steering_Plant_Model_Pi_cfclose((real_T)fileid);
      Steering_Plant_Model_Pi_B.len = MW_bitrate
        (&Steering_Plant_Model_Pi_B.bitRate[0]);
      if (Steering_Plant_Model_Pi_B.len < 1) {
        Steering_Plant_Model_Pi_B.len = 0;
      }

      b_bool = false;
      e = (tline->size[1] == 0);
      if (e && (Steering_Plant_Model_Pi_B.len == 0)) {
        b_bool = true;
      } else if (Steering_Plant_Model_Pi_B.len != tline->size[1]) {
      } else {
        Steering_Plant_Model_Pi_B.j = 1;
        do {
          exitg1 = 0;
          if (Steering_Plant_Model_Pi_B.j - 1 <= (uint8_T)
              Steering_Plant_Model_Pi_B.len - 1) {
            if (tline->data[Steering_Plant_Model_Pi_B.j - 1] !=
                Steering_Plant_Model_Pi_B.bitRate[Steering_Plant_Model_Pi_B.j -
                1]) {
              exitg1 = 1;
            } else {
              Steering_Plant_Model_Pi_B.j++;
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
        Steering_Plant_Model_Pi_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1] + 30;
        Steeri_emxEnsureCapacity_char_T(errString1,
          Steering_Plant_Model_Pi_B.len);
        errString1->data[0] = 'c';
        errString1->data[1] = 'a';
        errString1->data[2] = 'n';
        errString1->data[3] = '0';
        for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len <
             24; Steering_Plant_Model_Pi_B.len++) {
          errString1->data[Steering_Plant_Model_Pi_B.len + 4] =
            tmp_d[Steering_Plant_Model_Pi_B.len];
        }

        Steering_Plant_Model_Pi_B.j = tline->size[1];
        if (Steering_Plant_Model_Pi_B.j - 1 >= 0) {
          memcpy(&errString1->data[28], &tline->data[0], (uint32_T)
                 Steering_Plant_Model_Pi_B.j * sizeof(char_T));
        }

        errString1->data[tline->size[1] + 28] = '\x0a';
        errString1->data[tline->size[1] + 29] = '\x00';
        MW_printError(&errString1->data[0]);
        guard1 = true;
      }
    } else {
      for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 25;
           Steering_Plant_Model_Pi_B.len++) {
        Steering_Plant_Model_Pi_B.patVal_m[Steering_Plant_Model_Pi_B.len] =
          tmp_3[Steering_Plant_Model_Pi_B.len];
      }

      Steering_Plant_Model_Pi_B.len = 1;
      do {
        exitg1 = 0;
        if (Steering_Plant_Model_Pi_B.len - 1 <= tline->size[1] - 25) {
          Steering_Plant_Model_Pi_B.j = 1;
          while ((Steering_Plant_Model_Pi_B.j <= 25) && (tline->data
                  [(Steering_Plant_Model_Pi_B.len + Steering_Plant_Model_Pi_B.j)
                  - 2] ==
                  Steering_Plant_Model_Pi_B.patVal_m[Steering_Plant_Model_Pi_B.j
                  - 1])) {
            Steering_Plant_Model_Pi_B.j++;
          }

          if (Steering_Plant_Model_Pi_B.j > 25) {
            exitg1 = 1;
          } else {
            Steering_Plant_Model_Pi_B.len++;
          }
        } else {
          Steering_Plant_Model_Pi_B.len = 0;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (Steering_Plant_Model_Pi_B.len > 0) {
        Steering_Plant_Model_Pi_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        Steeri_emxEnsureCapacity_char_T(errString1,
          Steering_Plant_Model_Pi_B.len);
        Steering_Plant_Model_Pi_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)
               Steering_Plant_Model_Pi_B.j * sizeof(char_T));
        MW_printError(&errString1->data[0]);
      } else {
        Steering_Plant_Model_Pi_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        Steeri_emxEnsureCapacity_char_T(errString1,
          Steering_Plant_Model_Pi_B.len);
        Steering_Plant_Model_Pi_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)
               Steering_Plant_Model_Pi_B.j * sizeof(char_T));
        MW_printError(&errString1->data[0]);
      }

      guard1 = true;
    }
  }

  if (guard2) {
    Steering_Plant_Model_Pi_B.stat1 = MW_createSocket
      (&Steering_Plant_Model_Pi_B.canInterface[0], &obj->sockHandleDataFrames);
    Steering_Plant_Model_Pi_B.stat2 = MW_createSocket
      (&Steering_Plant_Model_Pi_B.canInterface[0], &obj->sockHandleErrorFrames);
  }

  if (guard1) {
    for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 11;
         Steering_Plant_Model_Pi_B.len++) {
      Steering_Plant_Model_Pi_B.errString0[Steering_Plant_Model_Pi_B.len] =
        tmp_9[Steering_Plant_Model_Pi_B.len];
    }

    Steering_Plant_Model_Pi_B.errString0[11] = 'c';
    Steering_Plant_Model_Pi_B.errString0[12] = 'a';
    Steering_Plant_Model_Pi_B.errString0[13] = 'n';
    Steering_Plant_Model_Pi_B.errString0[14] = '0';
    Steering_Plant_Model_Pi_B.errString0[15] = '\x0a';
    Steering_Plant_Model_Pi_B.errString0[16] = '\x00';
    MW_printError(&Steering_Plant_Model_Pi_B.errString0[0]);
    Steering_Plant_Model_Pi_B.errString3[0] = 'c';
    Steering_Plant_Model_Pi_B.errString3[1] = 'a';
    Steering_Plant_Model_Pi_B.errString3[2] = 'n';
    Steering_Plant_Model_Pi_B.errString3[3] = '0';
    for (Steering_Plant_Model_Pi_B.len = 0; Steering_Plant_Model_Pi_B.len < 14;
         Steering_Plant_Model_Pi_B.len++) {
      Steering_Plant_Model_Pi_B.errString3[Steering_Plant_Model_Pi_B.len + 4] =
        tmp_c[Steering_Plant_Model_Pi_B.len];
    }

    Steering_Plant_Model_Pi_B.errString3[18] = '\x0a';
    Steering_Plant_Model_Pi_B.errString3[19] = '\x00';
    MW_printError(&Steering_Plant_Model_Pi_B.errString3[0]);
  }

  Steering_Plant_M_emxFree_char_T(&errString1);
  Steering_Plant_M_emxFree_char_T(&tline);
  if ((Steering_Plant_Model_Pi_B.stat1 == 0) && (Steering_Plant_Model_Pi_B.stat2
       == 0)) {
    obj->Initialized = true;
  } else {
    obj->Initialized = false;
  }

  obj->isSetupComplete = true;
}

static void Steering_Plant_SystemCore_setup(codertarget_raspi_internal_CA_T *obj)
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
    Steering_Plant_Model_Pi_B.errString1[0] = 'c';
    Steering_Plant_Model_Pi_B.errString1[1] = 'a';
    Steering_Plant_Model_Pi_B.errString1[2] = 'n';
    Steering_Plant_Model_Pi_B.errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      Steering_Plant_Model_Pi_B.errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    Steering_Plant_Model_Pi_B.errString1[23] = 'c';
    Steering_Plant_Model_Pi_B.errString1[24] = 'a';
    Steering_Plant_Model_Pi_B.errString1[25] = 'n';
    Steering_Plant_Model_Pi_B.errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      Steering_Plant_Model_Pi_B.errString1[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    Steering_Plant_Model_Pi_B.errString1[61] = '\x0a';
    Steering_Plant_Model_Pi_B.errString1[62] = '\x00';
    MW_printError(&Steering_Plant_Model_Pi_B.errString1[0]);
  } else if (isCANSetup == 2) {
    Steering_Plant_Model_Pi_B.errString2[0] = 'c';
    Steering_Plant_Model_Pi_B.errString2[1] = 'a';
    Steering_Plant_Model_Pi_B.errString2[2] = 'n';
    Steering_Plant_Model_Pi_B.errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      Steering_Plant_Model_Pi_B.errString2[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    Steering_Plant_Model_Pi_B.errString2[50] = '\x0a';
    Steering_Plant_Model_Pi_B.errString2[51] = '\x00';
    MW_printError(&Steering_Plant_Model_Pi_B.errString2[0]);
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

/* Model step function */
void Steering_Plant_Model_Pi_step(void)
{
  int32_T b_i;
  int32_T sockStatus;
  uint32_T rxid;
  char_T rxInterface[5];
  uint8_T txData[8];
  uint8_T dataLength;
  uint8_T error;
  uint8_T extended;
  uint8_T remote;
  uint8_T status;

  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  Steering_Plant_Model_Pi_B.CANPack.ID = 201524227U;
  Steering_Plant_Model_Pi_B.CANPack.Length = 8U;
  Steering_Plant_Model_Pi_B.CANPack.Extended = 1U;
  Steering_Plant_Model_Pi_B.CANPack.Remote = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[0] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[1] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[2] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[3] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[4] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[5] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[6] = 0;
  Steering_Plant_Model_Pi_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 10000.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = Steering_Plant_Model_Pi_P.Constant4_Value;

        /* no factor to apply */
        result = result - 10000.0;

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
            Steering_Plant_Model_Pi_B.CANPack.Data[0] =
              Steering_Plant_Model_Pi_B.CANPack.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Steering_Plant_Model_Pi_B.CANPack.Data[1] =
              Steering_Plant_Model_Pi_B.CANPack.Data[1] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit' */
  if (Steering_Plant_Model_Pi_DW.obj_h.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      txData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (Steering_Plant_Model_Pi_B.CANPack.Remote == 0) {
      sockStatus = Steering_Plant_Model_Pi_B.CANPack.Length - 1;
      for (b_i = 0; b_i <= sockStatus; b_i++) {
        txData[(uint8_T)((uint32_T)b_i + 1U) - 1] =
          Steering_Plant_Model_Pi_B.CANPack.Data[(uint8_T)((uint32_T)b_i + 1U) -
          1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (Steering_Plant_Model_Pi_B.CANPack.Extended == 0),
      Steering_Plant_Model_Pi_B.CANPack.ID,
      Steering_Plant_Model_Pi_B.CANPack.Length, &txData[0],
      Steering_Plant_Model_Pi_B.CANPack.Remote, &status, 0, 1.0,
      Steering_Plant_Model_Pi_DW.obj_h.sockHandleDataFrames,
      Steering_Plant_Model_Pi_DW.obj_h.sockHandleErrorFrames, (uint8_T)
      Steering_Plant_Model_Pi_DW.obj_h.notFirstStep);
    if (sockStatus != 0) {
      Steering_Plant_Model_Pi_DW.obj_h.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit' */

  /* MATLABSystem: '<Root>/CAN Receive' */
  if (Steering_Plant_Model_Pi_DW.obj.SampleTime !=
      Steering_Plant_Model_Pi_P.CANReceive_SampleTime) {
    Steering_Plant_Model_Pi_DW.obj.SampleTime =
      Steering_Plant_Model_Pi_P.CANReceive_SampleTime;
  }

  if (Steering_Plant_Model_Pi_DW.obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    sockStatus = MW_CAN_receiveCANMsg(&rxInterface[0], &rxid, &txData[0],
      &dataLength, &status, &extended, &remote, &error,
      Steering_Plant_Model_Pi_DW.obj.sockHandleDataFrames,
      Steering_Plant_Model_Pi_DW.obj.sockHandleErrorFrames);
    if (sockStatus != 0) {
      Steering_Plant_Model_Pi_DW.obj.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Receive' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Steering_Plant_Model_Pi_M->Timing.t[0] =
    ((time_T)(++Steering_Plant_Model_Pi_M->Timing.clockTick0)) *
    Steering_Plant_Model_Pi_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [1.12s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.12, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Steering_Plant_Model_Pi_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Steering_Plant_Model_Pi_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Steering_Plant_Model_Pi_M->solverInfo,
                          &Steering_Plant_Model_Pi_M->Timing.simTimeStep);
    rtsiSetTPtr(&Steering_Plant_Model_Pi_M->solverInfo, &rtmGetTPtr
                (Steering_Plant_Model_Pi_M));
    rtsiSetStepSizePtr(&Steering_Plant_Model_Pi_M->solverInfo,
                       &Steering_Plant_Model_Pi_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Steering_Plant_Model_Pi_M->solverInfo,
                          (&rtmGetErrorStatus(Steering_Plant_Model_Pi_M)));
    rtsiSetRTModelPtr(&Steering_Plant_Model_Pi_M->solverInfo,
                      Steering_Plant_Model_Pi_M);
  }

  rtsiSetSimTimeStep(&Steering_Plant_Model_Pi_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Steering_Plant_Model_Pi_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Steering_Plant_Model_Pi_M,
             &Steering_Plant_Model_Pi_M->Timing.tArray[0]);
  Steering_Plant_Model_Pi_M->Timing.stepSize0 = 1.12;

  /* Start for MATLABSystem: '<Root>/CAN Transmit' */
  Steering_Plant_Model_Pi_B.a = NULL;
  for (Steering_Plant_Model_Pi_B.i = 0; Steering_Plant_Model_Pi_B.i < 20;
       Steering_Plant_Model_Pi_B.i++) {
    Steering_Plant_Model_Pi_DW.eml_openfiles[Steering_Plant_Model_Pi_B.i] =
      Steering_Plant_Model_Pi_B.a;
  }

  Steering_Plant_Model_Pi_DW.obj_h.sockHandleDataFrames = 0;
  Steering_Plant_Model_Pi_DW.obj_h.sockHandleErrorFrames = 0;
  Steering_Plant_Model_Pi_DW.obj_h.notFirstStep = false;
  Steering_Plant_Model_Pi_DW.obj_h.isInitialized = 0;
  Steering_Plant_Model_Pi_DW.obj_h.matlabCodegenIsDeleted = false;
  Steering_Pla_SystemCore_setup_g(&Steering_Plant_Model_Pi_DW.obj_h);

  /* End of Start for MATLABSystem: '<Root>/CAN Transmit' */

  /* Start for MATLABSystem: '<Root>/CAN Receive' */
  Steering_Plant_Model_Pi_DW.obj.sockHandleDataFrames = 0;
  Steering_Plant_Model_Pi_DW.obj.sockHandleErrorFrames = 0;
  Steering_Plant_Model_Pi_DW.obj.isInitialized = 0;
  Steering_Plant_Model_Pi_DW.obj.matlabCodegenIsDeleted = false;
  Steering_Plant_Model_Pi_DW.obj.SampleTime =
    Steering_Plant_Model_Pi_P.CANReceive_SampleTime;
  Steering_Plant_SystemCore_setup(&Steering_Plant_Model_Pi_DW.obj);
}

/* Model terminate function */
void Steering_Plant_Model_Pi_terminate(void)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!Steering_Plant_Model_Pi_DW.obj_h.matlabCodegenIsDeleted) {
    Steering_Plant_Model_Pi_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Steering_Plant_Model_Pi_DW.obj_h.isInitialized == 1) &&
        Steering_Plant_Model_Pi_DW.obj_h.isSetupComplete &&
        Steering_Plant_Model_Pi_DW.obj_h.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Steering_Plant_Model_Pi_DW.obj_h.sockHandleDataFrames,
                     &canInterface[0]);
      MW_clearSocket(&Steering_Plant_Model_Pi_DW.obj_h.sockHandleErrorFrames,
                     &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */

  /* Terminate for MATLABSystem: '<Root>/CAN Receive' */
  if (!Steering_Plant_Model_Pi_DW.obj.matlabCodegenIsDeleted) {
    Steering_Plant_Model_Pi_DW.obj.matlabCodegenIsDeleted = true;
    if ((Steering_Plant_Model_Pi_DW.obj.isInitialized == 1) &&
        Steering_Plant_Model_Pi_DW.obj.isSetupComplete &&
        Steering_Plant_Model_Pi_DW.obj.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&Steering_Plant_Model_Pi_DW.obj.sockHandleDataFrames,
                     &canInterface[0]);
      MW_clearSocket(&Steering_Plant_Model_Pi_DW.obj.sockHandleErrorFrames,
                     &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Receive' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
