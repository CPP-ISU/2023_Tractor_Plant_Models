/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar  7 22:28:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "untitled1_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define untitled1_IN_Disabled          (1U)
#define untitled1_IN_Enabled           (2U)
#define untitled1_IN_End               (1U)
#define untitled1_IN_Load_Increase     (1U)
#define untitled1_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define untitled1_IN_Run               (1U)
#define untitled1_IN_Speed             (1U)
#define untitled1_IN_Start             (2U)
#define untitled1_IN_Throttle_Setting  (2U)

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Forward declaration for local functions */
static void untitled1_SystemCore_setup(codertarget_raspi_internal_CA_T *obj);
static void untitled1_SystemCore_setup_l(codertarget_raspi_internal__l_T *obj);
static void untitled1_SystemCore_setup(codertarget_raspi_internal_CA_T *obj)
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
    untitled1_B.errString1_m[0] = 'c';
    untitled1_B.errString1_m[1] = 'a';
    untitled1_B.errString1_m[2] = 'n';
    untitled1_B.errString1_m[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      untitled1_B.errString1_m[isCANSetup + 4] = tmp[isCANSetup];
    }

    untitled1_B.errString1_m[23] = 'c';
    untitled1_B.errString1_m[24] = 'a';
    untitled1_B.errString1_m[25] = 'n';
    untitled1_B.errString1_m[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      untitled1_B.errString1_m[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    untitled1_B.errString1_m[61] = '\x0a';
    untitled1_B.errString1_m[62] = '\x00';
    MW_printError(&untitled1_B.errString1_m[0]);
  } else if (isCANSetup == 2) {
    untitled1_B.errString2_c[0] = 'c';
    untitled1_B.errString2_c[1] = 'a';
    untitled1_B.errString2_c[2] = 'n';
    untitled1_B.errString2_c[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      untitled1_B.errString2_c[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    untitled1_B.errString2_c[50] = '\x0a';
    untitled1_B.errString2_c[51] = '\x00';
    MW_printError(&untitled1_B.errString2_c[0]);
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

static void untitled1_SystemCore_setup_l(codertarget_raspi_internal__l_T *obj)
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
    untitled1_B.errString1[0] = 'c';
    untitled1_B.errString1[1] = 'a';
    untitled1_B.errString1[2] = 'n';
    untitled1_B.errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      untitled1_B.errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    untitled1_B.errString1[23] = 'c';
    untitled1_B.errString1[24] = 'a';
    untitled1_B.errString1[25] = 'n';
    untitled1_B.errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      untitled1_B.errString1[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    untitled1_B.errString1[61] = '\x0a';
    untitled1_B.errString1[62] = '\x00';
    MW_printError(&untitled1_B.errString1[0]);
  } else if (isCANSetup == 2) {
    untitled1_B.errString2[0] = 'c';
    untitled1_B.errString2[1] = 'a';
    untitled1_B.errString2[2] = 'n';
    untitled1_B.errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      untitled1_B.errString2[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    untitled1_B.errString2[50] = '\x0a';
    untitled1_B.errString2[51] = '\x00';
    MW_printError(&untitled1_B.errString2[0]);
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
void untitled1_step(void)
{
  real_T Enable_prev;
  int32_T c;
  int32_T sockStatus;
  char_T rxInterface[5];
  uint8_T rxData[8];
  uint8_T remote;
  boolean_T guard1 = false;

  /* Constant: '<Root>/Constant4' */
  untitled1_B.Constant4 = untitled1_P.Constant4_Value;

  /* Constant: '<Root>/Constant3' */
  untitled1_B.Constant3 = untitled1_P.Constant3_Value;

  /* Constant: '<Root>/Constant5' */
  untitled1_B.Constant5 = untitled1_P.Constant5_Value;

  /* Constant: '<Root>/Constant6' */
  untitled1_B.Constant6 = untitled1_P.Constant6_Value;

  /* Constant: '<Root>/Constant7' */
  untitled1_B.Constant7 = untitled1_P.Constant7_Value;

  /* MATLABSystem: '<Root>/CAN Receive' */
  if (untitled1_DW.obj.SampleTime != untitled1_P.CANReceive_SampleTime) {
    untitled1_DW.obj.SampleTime = untitled1_P.CANReceive_SampleTime;
  }

  if (untitled1_DW.obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    sockStatus = MW_CAN_receiveCANMsg(&rxInterface[0],
      &untitled1_B.CANReceive_o1.ID, &rxData[0],
      &untitled1_B.CANReceive_o1.Length, &untitled1_B.CANReceive_o2,
      &untitled1_B.CANReceive_o1.Extended, &remote,
      &untitled1_B.CANReceive_o1.Error, untitled1_DW.obj.sockHandleDataFrames,
      untitled1_DW.obj.sockHandleErrorFrames);
    untitled1_B.CANReceive_o1.Remote = (uint8_T)(remote == 0);
    if (sockStatus != 0) {
      untitled1_DW.obj.Initialized = false;
    }

    untitled1_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      untitled1_B.CANReceive_o1.Data[sockStatus] = rxData[sockStatus];
    }
  } else {
    untitled1_B.CANReceive_o1.Extended = 0U;
    untitled1_B.CANReceive_o1.Length = 0U;
    untitled1_B.CANReceive_o1.Remote = 0U;
    untitled1_B.CANReceive_o1.Error = 0U;
    untitled1_B.CANReceive_o1.ID = 0U;
    untitled1_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      untitled1_B.CANReceive_o1.Data[sockStatus] = 0U;
    }

    /* MATLABSystem: '<Root>/CAN Receive' */
    untitled1_B.CANReceive_o2 = 0U;
  }

  /* End of MATLABSystem: '<Root>/CAN Receive' */

  /* S-Function (scanunpack): '<Root>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    uint8_T msgReceived = 0;
    if ((8 == untitled1_B.CANReceive_o1.Length) && (untitled1_B.CANReceive_o1.ID
         != INVALID_CAN_ID) ) {
      if ((469828098 == untitled1_B.CANReceive_o1.ID) && (1U ==
           untitled1_B.CANReceive_o1.Extended) ) {
        msgReceived = 1;

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
                    (untitled1_B.CANReceive_o1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (untitled1_B.CANReceive_o1.Data[1]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled1_B.CANUnpack_o1 = result;
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
                    (untitled1_B.CANReceive_o1.Data[2]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (untitled1_B.CANReceive_o1.Data[3]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled1_B.CANUnpack_o2 = result;
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
                    (untitled1_B.CANReceive_o1.Data[6]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled1_B.CANUnpack_o3 = result;
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
                    (untitled1_B.CANReceive_o1.Data[4]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (untitled1_B.CANReceive_o1.Data[5]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled1_B.CANUnpack_o4 = result;
            }
          }
        }

        /* Extract the Timestamp */
        untitled1_B.CANUnpack_o5 = untitled1_B.CANReceive_o1.Timestamp;

        /* Extract the Error */
        untitled1_B.CANUnpack_o6 = untitled1_B.CANReceive_o1.Error;
      }
    }

    /* Status port */
    untitled1_B.CANUnpack_o7 = msgReceived;
  }

  /* Constant: '<Root>/Constant10' */
  untitled1_B.Constant10 = untitled1_P.Constant10_Value;

  /* Chart: '<Root>/Chart' */
  if (untitled1_DW.temporalCounter_i1 < MAX_uint32_T) {
    untitled1_DW.temporalCounter_i1++;
  }

  Enable_prev = untitled1_DW.Enable_start;
  untitled1_DW.Enable_start = untitled1_B.CANUnpack_o3;
  if (untitled1_DW.is_active_c3_untitled1 == 0U) {
    untitled1_DW.is_active_c3_untitled1 = 1U;
    untitled1_DW.is_c3_untitled1 = untitled1_IN_Disabled;
    untitled1_B.Load_Enable = false;
    untitled1_B.Load = 0.0;
    untitled1_B.Throttle = untitled1_B.Constant6;
  } else if (untitled1_DW.is_c3_untitled1 == untitled1_IN_Disabled) {
    if ((Enable_prev != untitled1_DW.Enable_start) && (untitled1_DW.Enable_start
         == 1.0)) {
      untitled1_DW.is_c3_untitled1 = untitled1_IN_Enabled;
      untitled1_DW.is_Enabled = untitled1_IN_Throttle_Setting;
      untitled1_DW.Count = 0.0;
      untitled1_DW.is_Throttle_Setting = untitled1_IN_Start;
      untitled1_B.Load_Enable = true;
      untitled1_B.Load = 0.0;
    } else {
      untitled1_B.Load_Enable = false;
      untitled1_B.Load = 0.0;
      untitled1_B.Throttle = untitled1_B.Constant6;
    }

    /* case IN_Enabled: */
  } else if (!(untitled1_B.CANUnpack_o3 != 0.0)) {
    untitled1_DW.is_Speed = untitled1_IN_NO_ACTIVE_CHILD;
    untitled1_DW.is_Load_Increase = untitled1_IN_NO_ACTIVE_CHILD;
    untitled1_DW.is_Throttle_Setting = untitled1_IN_NO_ACTIVE_CHILD;
    untitled1_DW.is_Enabled = untitled1_IN_NO_ACTIVE_CHILD;
    untitled1_DW.is_c3_untitled1 = untitled1_IN_Disabled;
    untitled1_B.Load_Enable = false;
    untitled1_B.Load = 0.0;
    untitled1_B.Throttle = untitled1_B.Constant6;
  } else if (untitled1_DW.is_Enabled == untitled1_IN_End) {
    untitled1_B.Throttle = untitled1_B.Constant7;
    untitled1_B.Load = 0.0;
    untitled1_B.Load_Enable = false;

    /* case IN_Throttle_Setting: */
  } else if (untitled1_DW.Count == 5.0) {
    if (untitled1_B.Throttle <= untitled1_B.Constant7) {
      untitled1_DW.is_Speed = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Load_Increase = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Throttle_Setting = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Enabled = untitled1_IN_End;
      untitled1_B.Throttle = untitled1_B.Constant7;
      untitled1_B.Load = 0.0;
      untitled1_B.Load_Enable = false;
    } else {
      untitled1_B.Throttle += untitled1_B.Constant5;
      untitled1_DW.is_Speed = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Load_Increase = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Enabled = untitled1_IN_Throttle_Setting;
      untitled1_DW.Count = 0.0;
      untitled1_DW.is_Throttle_Setting = untitled1_IN_Start;
      untitled1_B.Load_Enable = true;
      untitled1_B.Load = 0.0;
    }
  } else if (untitled1_DW.is_Throttle_Setting == untitled1_IN_Load_Increase) {
    if (untitled1_B.Speed_Target <= untitled1_B.Constant3) {
      untitled1_DW.Count++;
      untitled1_DW.is_Speed = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Load_Increase = untitled1_IN_NO_ACTIVE_CHILD;
      untitled1_DW.is_Throttle_Setting = untitled1_IN_Start;
      untitled1_B.Load_Enable = true;
      untitled1_B.Load = 0.0;
    } else {
      if ((!(untitled1_B.CANUnpack_o1 > untitled1_B.Speed_Target - 30.0)) ||
          (!(untitled1_B.CANUnpack_o1 < untitled1_B.Speed_Target + 30.0))) {
        untitled1_DW.durationCounter_1 = 0U;
      }

      if (untitled1_DW.durationCounter_1 > 300U) {
        untitled1_B.Speed_Target -= 50.0;
        untitled1_DW.durationCounter_1 = 0U;
        untitled1_DW.is_Load_Increase = untitled1_IN_Speed;
        untitled1_B.Load = 0.0;
        untitled1_DW.is_Speed = untitled1_IN_Run;
        untitled1_DW.temporalCounter_i1 = 0U;
      } else {
        guard1 = false;
        if (((uint32_T)((int32_T)untitled1_DW.temporalCounter_i1 * 10) >=
             (uint32_T)ceil(untitled1_B.Constant10)) &&
            (untitled1_B.CANUnpack_o1 > untitled1_B.Speed_Target + 30.0)) {
          untitled1_B.Load += untitled1_B.Constant4;
          guard1 = true;
        } else if (untitled1_B.CANUnpack_o1 < untitled1_B.Speed_Target - 30.0) {
          untitled1_B.Load -= untitled1_B.Constant4;
          guard1 = true;
        }

        if (guard1) {
          untitled1_DW.is_Speed = untitled1_IN_Run;
          untitled1_DW.temporalCounter_i1 = 0U;
        }
      }
    }
  } else {
    /* case IN_Start: */
    untitled1_DW.is_Throttle_Setting = untitled1_IN_Load_Increase;
    untitled1_B.Speed_Target = untitled1_B.CANUnpack_o1 - 200.0;
    untitled1_DW.durationCounter_1 = 0U;
    untitled1_DW.is_Load_Increase = untitled1_IN_Speed;
    untitled1_B.Load = 0.0;
    untitled1_DW.is_Speed = untitled1_IN_Run;
    untitled1_DW.temporalCounter_i1 = 0U;
  }

  if ((untitled1_B.CANUnpack_o1 > untitled1_B.Speed_Target - 30.0) &&
      (untitled1_B.CANUnpack_o1 < untitled1_B.Speed_Target + 30.0)) {
    untitled1_DW.durationCounter_1++;
  } else {
    untitled1_DW.durationCounter_1 = 0U;
  }

  /* End of Chart: '<Root>/Chart' */
  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  untitled1_B.Divide2 = untitled1_B.Load * untitled1_P.Constant9_Value /
    untitled1_B.CANUnpack_o2;

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant12'
   */
  untitled1_B.Divide3 = untitled1_B.Divide2 / untitled1_P.Constant11_Value *
    untitled1_P.Constant12_Value;

  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  untitled1_B.CANPack.ID = 469827841U;
  untitled1_B.CANPack.Length = 8U;
  untitled1_B.CANPack.Extended = 1U;
  untitled1_B.CANPack.Remote = 0;
  untitled1_B.CANPack.Data[0] = 0;
  untitled1_B.CANPack.Data[1] = 0;
  untitled1_B.CANPack.Data[2] = 0;
  untitled1_B.CANPack.Data[3] = 0;
  untitled1_B.CANPack.Data[4] = 0;
  untitled1_B.CANPack.Data[5] = 0;
  untitled1_B.CANPack.Data[6] = 0;
  untitled1_B.CANPack.Data[7] = 0;

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
        uint32_T result = (uint32_T) (untitled1_B.Load_Enable);

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
            untitled1_B.CANPack.Data[7] = untitled1_B.CANPack.Data[7] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
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
        real64_T result = untitled1_P.Constant_Value;

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
            untitled1_B.CANPack.Data[0] = untitled1_B.CANPack.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled1_B.CANPack.Data[1] = untitled1_B.CANPack.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
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
        real64_T result = untitled1_B.Divide3;

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
            untitled1_B.CANPack.Data[2] = untitled1_B.CANPack.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled1_B.CANPack.Data[3] = untitled1_B.CANPack.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
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
        real64_T result = untitled1_B.Throttle;

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
            untitled1_B.CANPack.Data[5] = untitled1_B.CANPack.Data[5] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled1_B.CANPack.Data[6] = untitled1_B.CANPack.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit' */
  if (untitled1_DW.obj_h.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      rxData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (untitled1_B.CANPack.Remote == 0) {
      c = untitled1_B.CANPack.Length - 1;
      for (sockStatus = 0; sockStatus <= c; sockStatus++) {
        rxData[(uint8_T)((uint32_T)sockStatus + 1U) - 1] =
          untitled1_B.CANPack.Data[(uint8_T)((uint32_T)sockStatus + 1U) - 1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (untitled1_B.CANPack.Extended == 0), untitled1_B.CANPack.ID,
      untitled1_B.CANPack.Length, &rxData[0], untitled1_B.CANPack.Remote,
      &remote, 0, 1.0, untitled1_DW.obj_h.sockHandleDataFrames,
      untitled1_DW.obj_h.sockHandleErrorFrames, (uint8_T)
      untitled1_DW.obj_h.notFirstStep);
    if (sockStatus != 0) {
      untitled1_DW.obj_h.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.taskTime0 =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled1_M, 10000.0);
  untitled1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (2635992332U);
  untitled1_M->Sizes.checksums[1] = (768027001U);
  untitled1_M->Sizes.checksums[2] = (461624191U);
  untitled1_M->Sizes.checksums[3] = (516713086U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* Start for Constant: '<Root>/Constant4' */
  untitled1_B.Constant4 = untitled1_P.Constant4_Value;

  /* Start for Constant: '<Root>/Constant3' */
  untitled1_B.Constant3 = untitled1_P.Constant3_Value;

  /* Start for Constant: '<Root>/Constant5' */
  untitled1_B.Constant5 = untitled1_P.Constant5_Value;

  /* Start for Constant: '<Root>/Constant6' */
  untitled1_B.Constant6 = untitled1_P.Constant6_Value;

  /* Start for Constant: '<Root>/Constant7' */
  untitled1_B.Constant7 = untitled1_P.Constant7_Value;

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack' */

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for Constant: '<Root>/Constant10' */
  untitled1_B.Constant10 = untitled1_P.Constant10_Value;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  untitled1_B.Speed_Target = 3600.0;

  /* Start for MATLABSystem: '<Root>/CAN Receive' */
  untitled1_DW.obj.sockHandleDataFrames = 0;
  untitled1_DW.obj.sockHandleErrorFrames = 0;
  untitled1_DW.obj.isInitialized = 0;
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.SampleTime = untitled1_P.CANReceive_SampleTime;
  untitled1_SystemCore_setup(&untitled1_DW.obj);

  /* Start for MATLABSystem: '<Root>/CAN Transmit' */
  untitled1_DW.obj_h.sockHandleDataFrames = 0;
  untitled1_DW.obj_h.sockHandleErrorFrames = 0;
  untitled1_DW.obj_h.notFirstStep = false;
  untitled1_DW.obj_h.isInitialized = 0;
  untitled1_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled1_SystemCore_setup_l(&untitled1_DW.obj_h);
}

/* Model terminate function */
void untitled1_terminate(void)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Receive' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj.isInitialized == 1) &&
        untitled1_DW.obj.isSetupComplete && untitled1_DW.obj.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&untitled1_DW.obj.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&untitled1_DW.obj.sockHandleErrorFrames, &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Receive' */
  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!untitled1_DW.obj_h.matlabCodegenIsDeleted) {
    untitled1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_h.isInitialized == 1) &&
        untitled1_DW.obj_h.isSetupComplete && untitled1_DW.obj_h.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&untitled1_DW.obj_h.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&untitled1_DW.obj_h.sockHandleErrorFrames, &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
