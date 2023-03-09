/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "untitled1.h"
#include "untitled1_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "ext_mode.h"
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(untitled1_M) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      untitled1_M->Timing.taskTime0;

    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    untitled1_step();

    /* Get model outputs here */

    /* Trigger External Mode event */
    extmodeEvent(0, currentTime);
    stopRequested = !((rtmGetErrorStatus(untitled1_M) == (NULL)));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(untitled1_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  MW_killPyserver();
  mwRaspiTerminate();

  /* Terminate model */
  untitled1_terminate();
  extmodeReset();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  mwRaspiInit();
  MW_launchPyserver();
  rtmSetErrorStatus(untitled1_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(argc, (const char_T **)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  /* Initialize model */
  untitled1_initialize();

  /* External Mode initialization */
  errorCode = extmodeInit(untitled1_M->extModeInfo, &rtmGetTFinal(untitled1_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(untitled1_M, true);
    }
  }

  /* Call RTOS Initialization function */
  myRTOSInit(0.01, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
