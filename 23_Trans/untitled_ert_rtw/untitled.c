/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jan 27 14:21:57 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_types.h"
#include "rtwtypes.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static int8_T untitled_filedata(void);
static int8_T untitled_cfopen(const char_T *cfilename, const char_T *cpermission);
static void untitled_emxInit_char_T(emxArray_char_T_untitled_T **pEmxArray,
  int32_T numDimensions);
static FILE* untitled_fileManager(real_T varargin_1);
static void untitl_emxEnsureCapacity_char_T(emxArray_char_T_untitled_T *emxArray,
  int32_T oldNumel);
static void untitled_emxFree_char_T(emxArray_char_T_untitled_T **pEmxArray);
static void untitled_fgetl(real_T fileID, emxArray_char_T_untitled_T *out);
static int32_T untitled_cfclose(real_T fid);
static void untitled_SystemCore_setup(codertarget_raspi_internal_CA_T *obj);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 * 0 - success
 * 1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

static int8_T untitled_filedata(void)
{
  int32_T b_k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 20)) {
    if (untitled_DW.eml_openfiles[(int8_T)(b_k + 1) - 1] == NULL) {
      f = (int8_T)(b_k + 1);
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return f;
}

static int8_T untitled_cfopen(const char_T *cfilename, const char_T *cpermission)
{
  FILE* filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = untitled_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      untitled_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

static void untitled_emxInit_char_T(emxArray_char_T_untitled_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_char_T_untitled_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_untitled_T *)malloc(sizeof
    (emxArray_char_T_untitled_T));
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

static FILE* untitled_fileManager(real_T varargin_1)
{
  FILE* f;
  int8_T fileid;
  fileid = (int8_T)varargin_1;
  if (varargin_1 != (int8_T)varargin_1) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = untitled_DW.eml_openfiles[fileid - 3];
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

static void untitl_emxEnsureCapacity_char_T(emxArray_char_T_untitled_T *emxArray,
  int32_T oldNumel)
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

static void untitled_emxFree_char_T(emxArray_char_T_untitled_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_untitled_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_untitled_T *)NULL;
  }
}

static void untitled_fgetl(real_T fileID, emxArray_char_T_untitled_T *out)
{
  emxArray_char_T_untitled_T *c_line;
  emxArray_char_T_untitled_T *outBuff;
  int32_T c_i;
  int32_T exitg1;
  int32_T i;
  char_T tmp;
  uint8_T buf;
  boolean_T exitg2;
  boolean_T fileEndAfterCarriageReturn;
  boolean_T newLineAfterCarriageReturn;
  boolean_T readNewline;
  untitled_B.filestar = untitled_fileManager(fileID);
  if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
  } else {
    untitled_B.filestar = NULL;
  }

  untitled_emxInit_char_T(&outBuff, 2);
  outBuff->size[0] = 1;
  outBuff->size[1] = 0;
  untitled_emxInit_char_T(&c_line, 2);
  if (untitled_B.filestar == NULL) {
    c_line->size[0] = 1;
    c_line->size[1] = 0;
  } else {
    do {
      exitg1 = 0;
      untitled_B.cOut = fgets(&untitled_B.ReadBuff[0], 1024, untitled_B.filestar);
      readNewline = false;
      untitled_B.b_NULL = NULL;
      untitled_B.filestar_c = untitled_fileManager(fileID);
      if (untitled_B.filestar_c == untitled_B.b_NULL) {
        untitled_B.reachedEndOfFile = 0;
      } else {
        untitled_B.b_st = feof(untitled_B.filestar_c);
        untitled_B.reachedEndOfFile = ((int32_T)untitled_B.b_st != 0);
      }

      if (untitled_B.cOut == NULL) {
        exitg1 = 1;
      } else {
        untitled_B.idx = 1;
        untitled_B.carriageReturnAt = 0;
        if (untitled_B.reachedEndOfFile != 0) {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1024)) {
            tmp = untitled_B.ReadBuff[c_i - 1];
            if (tmp == '\x00') {
              untitled_B.idx = c_i;
              exitg2 = true;
            } else {
              if ((untitled_B.carriageReturnAt == 0) && (tmp == '\x0d')) {
                untitled_B.carriageReturnAt = c_i;
              }

              c_i++;
            }
          }

          if (untitled_B.ReadBuff[untitled_B.idx - 1] == '\x00') {
            untitled_B.idx--;
          }
        } else {
          c_i = 1;
          exitg2 = false;
          while ((!exitg2) && (c_i - 1 < 1025)) {
            if (c_i > 1024) {
              untitled_B.idx = 1023;
              exitg2 = true;
            } else {
              tmp = untitled_B.ReadBuff[c_i - 1];
              if (tmp == '\x0a') {
                untitled_B.idx = c_i;
                exitg2 = true;
              } else {
                if ((untitled_B.carriageReturnAt == 0) && (tmp == '\x0d')) {
                  untitled_B.carriageReturnAt = c_i;
                }

                c_i++;
              }
            }
          }

          readNewline = (untitled_B.ReadBuff[untitled_B.idx - 1] == '\x0a');
        }

        if ((untitled_B.carriageReturnAt > 0) && (untitled_B.carriageReturnAt <
             1024)) {
          newLineAfterCarriageReturn =
            (untitled_B.ReadBuff[untitled_B.carriageReturnAt] == '\x0a');
          if ((untitled_B.reachedEndOfFile != 0) &&
              (untitled_B.ReadBuff[untitled_B.carriageReturnAt] == '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }

        if ((untitled_B.carriageReturnAt == 0) || newLineAfterCarriageReturn ||
            fileEndAfterCarriageReturn) {
          if (untitled_B.idx < 1) {
            untitled_B.idx = 0;
          }

          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += untitled_B.idx;
          untitl_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < untitled_B.idx; i++) {
            outBuff->data[c_i + i] = untitled_B.ReadBuff[i];
          }
        } else {
          c_i = outBuff->size[1];
          i = outBuff->size[0] * outBuff->size[1];
          outBuff->size[1] += untitled_B.carriageReturnAt;
          untitl_emxEnsureCapacity_char_T(outBuff, i);
          for (i = 0; i < untitled_B.carriageReturnAt; i++) {
            outBuff->data[c_i + i] = untitled_B.ReadBuff[i];
          }

          untitled_B.wherefrom = SEEK_CUR;
          untitled_B.filestar_c = untitled_fileManager(fileID);
          if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
          } else {
            untitled_B.filestar_c = NULL;
          }

          if (!(untitled_B.filestar_c == NULL)) {
            fseek(untitled_B.filestar_c, (long int)(untitled_B.carriageReturnAt
                   - untitled_B.idx), untitled_B.wherefrom);
          }
        }

        if (readNewline || (untitled_B.reachedEndOfFile != 0) ||
            (untitled_B.carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    untitled_B.b_NULL = NULL;
    untitled_B.filestar = untitled_fileManager(fileID);
    if (untitled_B.filestar == untitled_B.b_NULL) {
      untitled_B.reachedEndOfFile = 0;
    } else {
      untitled_B.b_st = feof(untitled_B.filestar);
      untitled_B.reachedEndOfFile = ((int32_T)untitled_B.b_st != 0);
    }

    if (untitled_B.reachedEndOfFile == 0) {
      untitled_B.filestar = untitled_fileManager(fileID);
      if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
      } else {
        untitled_B.filestar = NULL;
      }

      if (!(untitled_B.filestar == NULL)) {
        fread(&buf, sizeof(uint8_T), (size_t)1, untitled_B.filestar);
      }

      untitled_B.b_NULL = NULL;
      untitled_B.filestar = untitled_fileManager(fileID);
      if (untitled_B.filestar == untitled_B.b_NULL) {
        untitled_B.reachedEndOfFile = 0;
      } else {
        untitled_B.b_st = feof(untitled_B.filestar);
        untitled_B.reachedEndOfFile = ((int32_T)untitled_B.b_st != 0);
      }

      if (untitled_B.reachedEndOfFile == 0) {
        untitled_B.wherefrom = SEEK_CUR;
        untitled_B.filestar = untitled_fileManager(fileID);
        if ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0)) {
        } else {
          untitled_B.filestar = NULL;
        }

        if (!(untitled_B.filestar == NULL)) {
          fseek(untitled_B.filestar, (long int)-1.0, untitled_B.wherefrom);
        }
      }
    }

    i = c_line->size[0] * c_line->size[1];
    c_line->size[0] = 1;
    c_line->size[1] = outBuff->size[1];
    untitl_emxEnsureCapacity_char_T(c_line, i);
    untitled_B.reachedEndOfFile = outBuff->size[1];
    if (untitled_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&c_line->data[0], &outBuff->data[0], (uint32_T)
             untitled_B.reachedEndOfFile * sizeof(char_T));
    }
  }

  untitled_emxFree_char_T(&outBuff);
  if (c_line->size[1] == 0) {
    out->size[0] = 1;
    out->size[1] = 0;
  } else if (c_line->data[c_line->size[1] - 1] == '\x0a') {
    if ((c_line->size[1] > 1) && (c_line->data[c_line->size[1] - 2] == '\x0d'))
    {
      if (c_line->size[1] - 2 < 1) {
        untitled_B.reachedEndOfFile = 0;
      } else {
        untitled_B.reachedEndOfFile = c_line->size[1] - 2;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = untitled_B.reachedEndOfFile;
      untitl_emxEnsureCapacity_char_T(out, i);
      if (untitled_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               untitled_B.reachedEndOfFile * sizeof(char_T));
      }
    } else {
      if (c_line->size[1] - 1 < 1) {
        untitled_B.reachedEndOfFile = 0;
      } else {
        untitled_B.reachedEndOfFile = c_line->size[1] - 1;
      }

      i = out->size[0] * out->size[1];
      out->size[0] = 1;
      out->size[1] = untitled_B.reachedEndOfFile;
      untitl_emxEnsureCapacity_char_T(out, i);
      if (untitled_B.reachedEndOfFile - 1 >= 0) {
        memcpy(&out->data[0], &c_line->data[0], (uint32_T)
               untitled_B.reachedEndOfFile * sizeof(char_T));
      }
    }
  } else if (c_line->data[c_line->size[1] - 1] == '\x0d') {
    if (c_line->size[1] - 1 < 1) {
      untitled_B.reachedEndOfFile = 0;
    } else {
      untitled_B.reachedEndOfFile = c_line->size[1] - 1;
    }

    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = untitled_B.reachedEndOfFile;
    untitl_emxEnsureCapacity_char_T(out, i);
    if (untitled_B.reachedEndOfFile - 1 >= 0) {
      memcpy(&out->data[0], &c_line->data[0], (uint32_T)
             untitled_B.reachedEndOfFile * sizeof(char_T));
    }
  } else {
    i = out->size[0] * out->size[1];
    out->size[0] = 1;
    out->size[1] = c_line->size[1];
    untitl_emxEnsureCapacity_char_T(out, i);
    untitled_B.reachedEndOfFile = c_line->size[1];
    memcpy(&out->data[0], &c_line->data[0], (uint32_T)
           untitled_B.reachedEndOfFile * sizeof(char_T));
  }

  untitled_emxFree_char_T(&c_line);
}

static int32_T untitled_cfclose(real_T fid)
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
    b_f = untitled_DW.eml_openfiles[fileid_0 - 3];
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
      untitled_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }

  return st;
}

static void untitled_SystemCore_setup(codertarget_raspi_internal_CA_T *obj)
{
  emxArray_char_T_untitled_T *errString1;
  emxArray_char_T_untitled_T *tline;
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
  untitled_B.canInterface[0] = 'c';
  untitled_B.canInterface[1] = 'a';
  untitled_B.canInterface[2] = 'n';
  untitled_B.canInterface[3] = '0';
  untitled_B.canInterface[4] = '\x00';
  untitled_B.stat1 = -1;
  untitled_B.stat2 = -1;
  MW_checkIFStatus(&untitled_B.canInterface[0]);
  untitled_B.len = MW_bitrate(&untitled_B.bitRate[0]);
  if (untitled_B.len < 1) {
    untitled_B.j = -1;
  } else {
    untitled_B.j = untitled_B.len - 1;
  }

  memcpy(&untitled_B.cmd_data[0], &tmp[0], 158U * sizeof(char_T));
  untitled_B.cmd_data[158] = 'c';
  untitled_B.cmd_data[159] = 'a';
  untitled_B.cmd_data[160] = 'n';
  untitled_B.cmd_data[161] = '0';
  for (untitled_B.len = 0; untitled_B.len < 21; untitled_B.len++) {
    untitled_B.cmd_data[untitled_B.len + 162] = tmp_0[untitled_B.len];
  }

  if (untitled_B.j >= 0) {
    memcpy(&untitled_B.cmd_data[183], &untitled_B.bitRate[0], (uint32_T)
           (untitled_B.j + 1) * sizeof(char_T));
  }

  for (untitled_B.len = 0; untitled_B.len < 32; untitled_B.len++) {
    untitled_B.cmd_data[(untitled_B.len + untitled_B.j) + 184] =
      tmp_1[untitled_B.len];
  }

  untitled_B.cmd_data[untitled_B.j + 216] = '\x00';
  MW_loadCANModules(1);
  MW_setupCANLink(&untitled_B.cmd_data[0], 1);
  fileid = untitled_cfopen("MW_SocketCAN_Error_IPLink.txt", "rb");
  untitled_emxInit_char_T(&tline, 2);
  untitled_fgetl((real_T)fileid, tline);
  untitled_cfclose((real_T)fileid);
  untitled_emxInit_char_T(&errString1, 2);
  guard1 = false;
  guard2 = false;
  if (tline->size[1] == 0) {
    guard2 = true;
  } else {
    for (untitled_B.len = 0; untitled_B.len < 42; untitled_B.len++) {
      untitled_B.patVal[untitled_B.len] = tmp_2[untitled_B.len];
    }

    untitled_B.len = 1;
    do {
      exitg1 = 0;
      if (untitled_B.len - 1 <= tline->size[1] - 42) {
        untitled_B.j = 1;
        while ((untitled_B.j <= 42) && (tline->data[(untitled_B.len +
                 untitled_B.j) - 2] == untitled_B.patVal[untitled_B.j - 1])) {
          untitled_B.j++;
        }

        if (untitled_B.j > 42) {
          exitg1 = 1;
        } else {
          untitled_B.len++;
        }
      } else {
        untitled_B.len = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (untitled_B.len > 0) {
      for (untitled_B.len = 0; untitled_B.len < 41; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len] = tmp_4[untitled_B.len];
      }

      for (untitled_B.len = 0; untitled_B.len < 49; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len + 41] = tmp_5[untitled_B.len];
      }

      for (untitled_B.len = 0; untitled_B.len < 45; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len + 90] = tmp_6[untitled_B.len];
      }

      for (untitled_B.len = 0; untitled_B.len < 23; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len + 135] = tmp_7[untitled_B.len];
      }

      untitled_B.cmd[158] = 'c';
      untitled_B.cmd[159] = 'a';
      untitled_B.cmd[160] = 'n';
      untitled_B.cmd[161] = '0';
      for (untitled_B.len = 0; untitled_B.len < 18; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len + 162] = tmp_8[untitled_B.len];
      }

      untitled_B.cmd[180] = 'a';
      untitled_B.cmd[181] = 'w';
      untitled_B.cmd[182] = 'k';
      untitled_B.cmd[183] = ' ';
      for (untitled_B.len = 0; untitled_B.len < 12; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len + 184] = tmp_a[untitled_B.len];
      }

      for (untitled_B.len = 0; untitled_B.len < 29; untitled_B.len++) {
        untitled_B.cmd[untitled_B.len + 196] = tmp_b[untitled_B.len];
      }

      untitled_B.cmd[225] = '\x00';
      MW_executeCommand(&untitled_B.cmd[0]);
      fileid = untitled_cfopen("MW_SocketCAN_GetBitRate.txt", "rb");
      untitled_fgetl((real_T)fileid, tline);
      untitled_cfclose((real_T)fileid);
      untitled_B.len = MW_bitrate(&untitled_B.bitRate[0]);
      if (untitled_B.len < 1) {
        untitled_B.len = 0;
      }

      b_bool = false;
      e = (tline->size[1] == 0);
      if (e && (untitled_B.len == 0)) {
        b_bool = true;
      } else if (untitled_B.len != tline->size[1]) {
      } else {
        untitled_B.j = 1;
        do {
          exitg1 = 0;
          if (untitled_B.j - 1 <= (uint8_T)untitled_B.len - 1) {
            if (tline->data[untitled_B.j - 1] != untitled_B.bitRate[untitled_B.j
                - 1]) {
              exitg1 = 1;
            } else {
              untitled_B.j++;
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
        untitled_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1] + 30;
        untitl_emxEnsureCapacity_char_T(errString1, untitled_B.len);
        errString1->data[0] = 'c';
        errString1->data[1] = 'a';
        errString1->data[2] = 'n';
        errString1->data[3] = '0';
        for (untitled_B.len = 0; untitled_B.len < 24; untitled_B.len++) {
          errString1->data[untitled_B.len + 4] = tmp_d[untitled_B.len];
        }

        untitled_B.j = tline->size[1];
        if (untitled_B.j - 1 >= 0) {
          memcpy(&errString1->data[28], &tline->data[0], (uint32_T)untitled_B.j *
                 sizeof(char_T));
        }

        errString1->data[tline->size[1] + 28] = '\x0a';
        errString1->data[tline->size[1] + 29] = '\x00';
        MW_printError(&errString1->data[0]);
        guard1 = true;
      }
    } else {
      for (untitled_B.len = 0; untitled_B.len < 25; untitled_B.len++) {
        untitled_B.patVal_m[untitled_B.len] = tmp_3[untitled_B.len];
      }

      untitled_B.len = 1;
      do {
        exitg1 = 0;
        if (untitled_B.len - 1 <= tline->size[1] - 25) {
          untitled_B.j = 1;
          while ((untitled_B.j <= 25) && (tline->data[(untitled_B.len +
                   untitled_B.j) - 2] == untitled_B.patVal_m[untitled_B.j - 1]))
          {
            untitled_B.j++;
          }

          if (untitled_B.j > 25) {
            exitg1 = 1;
          } else {
            untitled_B.len++;
          }
        } else {
          untitled_B.len = 0;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (untitled_B.len > 0) {
        untitled_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        untitl_emxEnsureCapacity_char_T(errString1, untitled_B.len);
        untitled_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)untitled_B.j *
               sizeof(char_T));
        MW_printError(&errString1->data[0]);
      } else {
        untitled_B.len = errString1->size[0] * errString1->size[1];
        errString1->size[0] = 1;
        errString1->size[1] = tline->size[1];
        untitl_emxEnsureCapacity_char_T(errString1, untitled_B.len);
        untitled_B.j = tline->size[1];
        memcpy(&errString1->data[0], &tline->data[0], (uint32_T)untitled_B.j *
               sizeof(char_T));
        MW_printError(&errString1->data[0]);
      }

      guard1 = true;
    }
  }

  if (guard2) {
    untitled_B.stat1 = MW_createSocket(&untitled_B.canInterface[0],
      &obj->sockHandleDataFrames);
    untitled_B.stat2 = MW_createSocket(&untitled_B.canInterface[0],
      &obj->sockHandleErrorFrames);
  }

  if (guard1) {
    for (untitled_B.len = 0; untitled_B.len < 11; untitled_B.len++) {
      untitled_B.errString0[untitled_B.len] = tmp_9[untitled_B.len];
    }

    untitled_B.errString0[11] = 'c';
    untitled_B.errString0[12] = 'a';
    untitled_B.errString0[13] = 'n';
    untitled_B.errString0[14] = '0';
    untitled_B.errString0[15] = '\x0a';
    untitled_B.errString0[16] = '\x00';
    MW_printError(&untitled_B.errString0[0]);
    untitled_B.errString3[0] = 'c';
    untitled_B.errString3[1] = 'a';
    untitled_B.errString3[2] = 'n';
    untitled_B.errString3[3] = '0';
    for (untitled_B.len = 0; untitled_B.len < 14; untitled_B.len++) {
      untitled_B.errString3[untitled_B.len + 4] = tmp_c[untitled_B.len];
    }

    untitled_B.errString3[18] = '\x0a';
    untitled_B.errString3[19] = '\x00';
    MW_printError(&untitled_B.errString3[0]);
  }

  untitled_emxFree_char_T(&errString1);
  untitled_emxFree_char_T(&tline);
  if ((untitled_B.stat1 == 0) && (untitled_B.stat2 == 0)) {
    obj->Initialized = true;
  } else {
    obj->Initialized = false;
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void untitled_step(void)
{
  int32_T c;
  int32_T sockStatus;
  char_T rxInterface[5];
  uint8_T txData[8];
  uint8_T status;

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  untitled_B.Add += untitled_P.Constant_Value;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  untitled_B.Add1 = untitled_DW.UnitDelay1_DSTATE + untitled_P.Constant1_Value;

  /* S-Function (scanpack): '<Root>/CAN Pack' */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  untitled_B.CANPack.ID = 1234U;
  untitled_B.CANPack.Length = 8U;
  untitled_B.CANPack.Extended = 0U;
  untitled_B.CANPack.Remote = 0;
  untitled_B.CANPack.Data[0] = 0;
  untitled_B.CANPack.Data[1] = 0;
  untitled_B.CANPack.Data[2] = 0;
  untitled_B.CANPack.Data[3] = 0;
  untitled_B.CANPack.Data[4] = 0;
  untitled_B.CANPack.Data[5] = 0;
  untitled_B.CANPack.Data[6] = 0;
  untitled_B.CANPack.Data[7] = 0;

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
        real64_T result = untitled_B.Add;

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
            untitled_B.CANPack.Data[0] = untitled_B.CANPack.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled_B.CANPack.Data[1] = untitled_B.CANPack.Data[1] | (uint8_T)
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
        real64_T result = untitled_B.Add1;

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
            untitled_B.CANPack.Data[2] = untitled_B.CANPack.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled_B.CANPack.Data[3] = untitled_B.CANPack.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit' */
  if (untitled_DW.obj.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      txData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (untitled_B.CANPack.Remote == 0) {
      c = untitled_B.CANPack.Length - 1;
      for (sockStatus = 0; sockStatus <= c; sockStatus++) {
        txData[(uint8_T)((uint32_T)sockStatus + 1U) - 1] =
          untitled_B.CANPack.Data[(uint8_T)((uint32_T)sockStatus + 1U) - 1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (untitled_B.CANPack.Extended == 0), untitled_B.CANPack.ID,
      untitled_B.CANPack.Length, &txData[0], untitled_B.CANPack.Remote, &status,
      0, 1.0, untitled_DW.obj.sockHandleDataFrames,
      untitled_DW.obj.sockHandleErrorFrames, (uint8_T)
      untitled_DW.obj.notFirstStep);
    if (sockStatus != 0) {
      untitled_DW.obj.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit' */
  /* ToFile: '<Root>/To File' */
  {
    if (!(++untitled_DW.ToFile_IWORK.Decimation % 1) &&
        (untitled_DW.ToFile_IWORK.Count * (1 + 1)) + 1 < 100000000 ) {
      FILE *fp = (FILE *) untitled_DW.ToFile_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[1 + 1];
        untitled_DW.ToFile_IWORK.Decimation = 0;
        u[0] = untitled_M->Timing.taskTime0;
        u[1] = untitled_B.Add1;
        if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
          rtmSetErrorStatus(untitled_M, "Error writing to MAT-file untitled.mat");
          return;
        }

        if (((++untitled_DW.ToFile_IWORK.Count) * (1 + 1))+1 >= 100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file untitled.mat.\n");
        }
      }
    }
  }

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  untitled_DW.UnitDelay1_DSTATE = untitled_B.Add1;

  {                                    /* Sample time: [4.0s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, 200.0);
  untitled_M->Timing.stepSize0 = 4.0;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (16840947U);
  untitled_M->Sizes.checksums[1] = (3113309621U);
  untitled_M->Sizes.checksums[2] = (1603427643U);
  untitled_M->Sizes.checksums[3] = (1108455936U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "untitled.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(untitled_M, "Error creating .mat file untitled.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "ans")) {
      rtmSetErrorStatus(untitled_M,
                        "Error writing mat file header to file untitled.mat");
      return;
    }

    untitled_DW.ToFile_IWORK.Count = 0;
    untitled_DW.ToFile_IWORK.Decimation = -1;
    untitled_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  untitled_B.Add = untitled_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  untitled_DW.UnitDelay1_DSTATE = untitled_P.UnitDelay1_InitialCondition;

  /* Start for MATLABSystem: '<Root>/CAN Transmit' */
  untitled_B.a = NULL;
  for (untitled_B.i = 0; untitled_B.i < 20; untitled_B.i++) {
    untitled_DW.eml_openfiles[untitled_B.i] = untitled_B.a;
  }

  untitled_DW.obj.sockHandleDataFrames = 0;
  untitled_DW.obj.sockHandleErrorFrames = 0;
  untitled_DW.obj.notFirstStep = false;
  untitled_DW.obj.isInitialized = 0;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_SystemCore_setup(&untitled_DW.obj);

  /* End of Start for MATLABSystem: '<Root>/CAN Transmit' */
}

/* Model terminate function */
void untitled_terminate(void)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete &&
        untitled_DW.obj.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&untitled_DW.obj.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&untitled_DW.obj.sockHandleErrorFrames, &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) untitled_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "untitled.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(untitled_M, "Error closing MAT-file untitled.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(untitled_M, "Error reopening MAT-file untitled.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, untitled_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(untitled_M,
                          "Error writing header for ans to MAT-file untitled.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(untitled_M, "Error closing MAT-file untitled.mat");
        return;
      }

      untitled_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
