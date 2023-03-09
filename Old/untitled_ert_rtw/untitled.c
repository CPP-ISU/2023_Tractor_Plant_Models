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
 * C/C++ source code generated on : Tue Mar  7 18:12:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_types.h"
#include "rtwtypes.h"
#include "untitled_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define untitled_IN_Disabled           ((uint8_T)1U)
#define untitled_IN_Enabled            ((uint8_T)2U)
#define untitled_IN_End                ((uint8_T)1U)
#define untitled_IN_Load_Increase      ((uint8_T)1U)
#define untitled_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define untitled_IN_Start              ((uint8_T)2U)
#define untitled_IN_Throttle_Setting   ((uint8_T)2U)

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_SystemCore_setup(codertarget_raspi_internal_CA_T *obj);
static void untitled_SystemCore_setup_b(codertarget_raspi_internal__b_T *obj);
static void untitled_SystemCore_setup(codertarget_raspi_internal_CA_T *obj)
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
    untitled_B.errString1_m[0] = 'c';
    untitled_B.errString1_m[1] = 'a';
    untitled_B.errString1_m[2] = 'n';
    untitled_B.errString1_m[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      untitled_B.errString1_m[isCANSetup + 4] = tmp[isCANSetup];
    }

    untitled_B.errString1_m[23] = 'c';
    untitled_B.errString1_m[24] = 'a';
    untitled_B.errString1_m[25] = 'n';
    untitled_B.errString1_m[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      untitled_B.errString1_m[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    untitled_B.errString1_m[61] = '\x0a';
    untitled_B.errString1_m[62] = '\x00';
    MW_printError(&untitled_B.errString1_m[0]);
  } else if (isCANSetup == 2) {
    untitled_B.errString2_c[0] = 'c';
    untitled_B.errString2_c[1] = 'a';
    untitled_B.errString2_c[2] = 'n';
    untitled_B.errString2_c[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      untitled_B.errString2_c[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    untitled_B.errString2_c[50] = '\x0a';
    untitled_B.errString2_c[51] = '\x00';
    MW_printError(&untitled_B.errString2_c[0]);
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

static void untitled_SystemCore_setup_b(codertarget_raspi_internal__b_T *obj)
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
    untitled_B.errString1[0] = 'c';
    untitled_B.errString1[1] = 'a';
    untitled_B.errString1[2] = 'n';
    untitled_B.errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      untitled_B.errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    untitled_B.errString1[23] = 'c';
    untitled_B.errString1[24] = 'a';
    untitled_B.errString1[25] = 'n';
    untitled_B.errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      untitled_B.errString1[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    untitled_B.errString1[61] = '\x0a';
    untitled_B.errString1[62] = '\x00';
    MW_printError(&untitled_B.errString1[0]);
  } else if (isCANSetup == 2) {
    untitled_B.errString2[0] = 'c';
    untitled_B.errString2[1] = 'a';
    untitled_B.errString2[2] = 'n';
    untitled_B.errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      untitled_B.errString2[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    untitled_B.errString2[50] = '\x0a';
    untitled_B.errString2[51] = '\x00';
    MW_printError(&untitled_B.errString2[0]);
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
void untitled_step(void)
{
  real_T Enable_prev;
  int32_T b_i;
  int32_T sockStatus;
  char_T rxInterface[5];
  uint8_T rxData[8];
  uint8_T remote;
  uint8_T status;

  /* MATLABSystem: '<Root>/CAN Receive' */
  if (untitled_DW.obj.SampleTime != untitled_P.CANReceive_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.CANReceive_SampleTime;
  }

  if (untitled_DW.obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    sockStatus = MW_CAN_receiveCANMsg(&rxInterface[0],
      &untitled_B.CANReceive_o1.ID, &rxData[0], &untitled_B.CANReceive_o1.Length,
      &status, &untitled_B.CANReceive_o1.Extended, &remote,
      &untitled_B.CANReceive_o1.Error, untitled_DW.obj.sockHandleDataFrames,
      untitled_DW.obj.sockHandleErrorFrames);
    untitled_B.CANReceive_o1.Remote = (uint8_T)(remote == 0);
    if (sockStatus != 0) {
      untitled_DW.obj.Initialized = false;
    }

    untitled_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      untitled_B.CANReceive_o1.Data[sockStatus] = rxData[sockStatus];
    }
  } else {
    untitled_B.CANReceive_o1.Extended = 0U;
    untitled_B.CANReceive_o1.Length = 0U;
    untitled_B.CANReceive_o1.Remote = 0U;
    untitled_B.CANReceive_o1.Error = 0U;
    untitled_B.CANReceive_o1.ID = 0U;
    untitled_B.CANReceive_o1.Timestamp = 0.0;
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      untitled_B.CANReceive_o1.Data[sockStatus] = 0U;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Receive' */

  /* S-Function (scanunpack): '<Root>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == untitled_B.CANReceive_o1.Length) && (untitled_B.CANReceive_o1.ID
         != INVALID_CAN_ID) ) {
      if ((469828098 == untitled_B.CANReceive_o1.ID) && (1U ==
           untitled_B.CANReceive_o1.Extended) ) {
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
                    (untitled_B.CANReceive_o1.Data[0]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (untitled_B.CANReceive_o1.Data[1]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled_B.CANUnpack_o1 = result;
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
                    (untitled_B.CANReceive_o1.Data[2]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (untitled_B.CANReceive_o1.Data[3]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled_B.CANUnpack_o2 = result;
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
                    (untitled_B.CANReceive_o1.Data[6]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled_B.CANUnpack_o3 = result;
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
                    (untitled_B.CANReceive_o1.Data[4]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (untitled_B.CANReceive_o1.Data[5]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              untitled_B.CANUnpack_o4 = result;
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
  if (untitled_DW.temporalCounter_i1 < 511U) {
    untitled_DW.temporalCounter_i1++;
  }

  Enable_prev = untitled_DW.Enable_start;
  untitled_DW.Enable_start = untitled_B.CANUnpack_o3;
  if (untitled_DW.is_active_c3_untitled == 0U) {
    untitled_DW.is_active_c3_untitled = 1U;
    untitled_DW.is_c3_untitled = untitled_IN_Disabled;
    untitled_B.Load_Enable = false;
    untitled_B.Load = 0.0;
    untitled_B.Throttle = untitled_P.Constant7_Value;
  } else if (untitled_DW.is_c3_untitled == untitled_IN_Disabled) {
    if ((Enable_prev != untitled_DW.Enable_start) && (untitled_DW.Enable_start ==
         1.0)) {
      untitled_DW.is_c3_untitled = untitled_IN_Enabled;
      untitled_DW.is_Enabled = untitled_IN_Throttle_Setting;
      untitled_DW.Count = 0.0;
      untitled_DW.is_Throttle_Setting = untitled_IN_Start;
      untitled_B.Load_Enable = true;
      untitled_B.Load = 0.0;
    } else {
      untitled_B.Load_Enable = false;
      untitled_B.Load = 0.0;
      untitled_B.Throttle = untitled_P.Constant7_Value;
    }

    /* case IN_Enabled: */
  } else if (!(untitled_B.CANUnpack_o3 != 0.0)) {
    untitled_DW.is_Throttle_Setting = untitled_IN_NO_ACTIVE_CHILD;
    untitled_DW.is_Enabled = untitled_IN_NO_ACTIVE_CHILD;
    untitled_DW.is_c3_untitled = untitled_IN_Disabled;
    untitled_B.Load_Enable = false;
    untitled_B.Load = 0.0;
    untitled_B.Throttle = untitled_P.Constant7_Value;
  } else if (untitled_DW.is_Enabled == untitled_IN_End) {
    untitled_B.Throttle = untitled_P.Constant7_Value;
    untitled_B.Load = 0.0;
    untitled_B.Load_Enable = false;

    /* case IN_Throttle_Setting: */
  } else if (untitled_DW.Count == 5.0) {
    if (untitled_B.Throttle >= untitled_P.Constant6_Value) {
      untitled_DW.is_Throttle_Setting = untitled_IN_NO_ACTIVE_CHILD;
      untitled_DW.is_Enabled = untitled_IN_End;
      untitled_B.Throttle = untitled_P.Constant7_Value;
      untitled_B.Load = 0.0;
      untitled_B.Load_Enable = false;
    } else {
      untitled_B.Throttle += untitled_P.Constant5_Value;
      untitled_DW.is_Enabled = untitled_IN_Throttle_Setting;
      untitled_DW.Count = 0.0;
      untitled_DW.is_Throttle_Setting = untitled_IN_Start;
      untitled_B.Load_Enable = true;
      untitled_B.Load = 0.0;
    }
  } else if (untitled_DW.is_Throttle_Setting == untitled_IN_Load_Increase) {
    if (untitled_DW.temporalCounter_i1 >= 500U) {
      if (untitled_B.CANUnpack_o1 <= untitled_P.Constant3_Value) {
        untitled_DW.Count++;
        untitled_DW.is_Throttle_Setting = untitled_IN_Start;
        untitled_B.Load_Enable = true;
        untitled_B.Load = 0.0;
      } else {
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.Load += untitled_P.Constant4_Value;
      }
    }
  } else {
    /* case IN_Start: */
    untitled_DW.is_Throttle_Setting = untitled_IN_Load_Increase;
    untitled_DW.temporalCounter_i1 = 0U;
    untitled_B.Load += untitled_P.Constant4_Value;
  }

  /* End of Chart: '<Root>/Chart' */

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  untitled_B.Divide2 = untitled_B.Load * untitled_P.Constant9_Value /
    untitled_B.CANUnpack_o2;

  /* S-Function (scanpack): '<Root>/CAN Pack' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
  untitled_B.CANPack.ID = 469827841U;
  untitled_B.CANPack.Length = 8U;
  untitled_B.CANPack.Extended = 1U;
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
        uint32_T result = (uint32_T) (untitled_B.Load_Enable);

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
            untitled_B.CANPack.Data[7] = untitled_B.CANPack.Data[7] | (uint8_T)
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
        real64_T result = untitled_P.Constant_Value;

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
            untitled_B.CANPack.Data[0] = untitled_B.CANPack.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled_B.CANPack.Data[1] = untitled_B.CANPack.Data[1] | (uint8_T)
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
        real64_T result = untitled_B.Divide2;

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
            untitled_B.CANPack.Data[2] = untitled_B.CANPack.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled_B.CANPack.Data[3] = untitled_B.CANPack.Data[3] | (uint8_T)
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
        real64_T result = untitled_B.Throttle;

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
            untitled_B.CANPack.Data[5] = untitled_B.CANPack.Data[5] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            untitled_B.CANPack.Data[6] = untitled_B.CANPack.Data[6] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLABSystem: '<Root>/CAN Transmit' */
  if (untitled_DW.obj_g.Initialized) {
    for (sockStatus = 0; sockStatus < 8; sockStatus++) {
      rxData[sockStatus] = 0U;
    }

    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    if (untitled_B.CANPack.Remote == 0) {
      sockStatus = untitled_B.CANPack.Length - 1;
      for (b_i = 0; b_i <= sockStatus; b_i++) {
        rxData[(uint8_T)((uint32_T)b_i + 1U) - 1] = untitled_B.CANPack.Data
          [(uint8_T)((uint32_T)b_i + 1U) - 1];
      }
    }

    sockStatus = MW_CAN_transmitCANMsg(&rxInterface[0], (uint8_T)
      (untitled_B.CANPack.Extended == 0), untitled_B.CANPack.ID,
      untitled_B.CANPack.Length, &rxData[0], untitled_B.CANPack.Remote, &status,
      0, 1.0, untitled_DW.obj_g.sockHandleDataFrames,
      untitled_DW.obj_g.sockHandleErrorFrames, (uint8_T)
      untitled_DW.obj_g.notFirstStep);
    if (sockStatus != 0) {
      untitled_DW.obj_g.Initialized = false;
    }
  }

  /* End of MATLABSystem: '<Root>/CAN Transmit' */
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack' */

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for MATLABSystem: '<Root>/CAN Receive' */
  untitled_DW.obj.sockHandleDataFrames = 0;
  untitled_DW.obj.sockHandleErrorFrames = 0;
  untitled_DW.obj.isInitialized = 0;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.CANReceive_SampleTime;
  untitled_SystemCore_setup(&untitled_DW.obj);

  /* Start for MATLABSystem: '<Root>/CAN Transmit' */
  untitled_DW.obj_g.sockHandleDataFrames = 0;
  untitled_DW.obj_g.sockHandleErrorFrames = 0;
  untitled_DW.obj_g.notFirstStep = false;
  untitled_DW.obj_g.isInitialized = 0;
  untitled_DW.obj_g.matlabCodegenIsDeleted = false;
  untitled_SystemCore_setup_b(&untitled_DW.obj_g);
}

/* Model terminate function */
void untitled_terminate(void)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Receive' */
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

  /* End of Terminate for MATLABSystem: '<Root>/CAN Receive' */

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!untitled_DW.obj_g.matlabCodegenIsDeleted) {
    untitled_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_g.isInitialized == 1) &&
        untitled_DW.obj_g.isSetupComplete && untitled_DW.obj_g.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&untitled_DW.obj_g.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&untitled_DW.obj_g.sockHandleErrorFrames, &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
