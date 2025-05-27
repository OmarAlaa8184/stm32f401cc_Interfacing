/*
 * SCHED_INTERFACING.h
 *
 * Created: 1/13/2025
 *  Author: Omar Alaa
 */ 



#ifndef SCHED_INTERFACING_H_
#define SCHED_INTERFACING_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SCHED_CFG.h"



/* Enumeration to represent the possible error statuses for scheduler operations */
typedef enum
{ 
    HSCHED_enuOK,                    /* Operation completed successfully */
    HSCHED_enuNOK,                   /* Operation failed */
    HSCHED_enuINVALID_PRIORITY_NUM,  /* Invalid priority number provided */
    HSCHED_enuSTATE,                 /* Invalid scheduler state */
    HSCHED_enuNULL_PTR               /* Null pointer encountered */
} HSCHED_enuErrorStatus_t;

/* Function prototype for initializing the scheduler */
void HSCHED_vInit(void);

/* Function prototype for starting the scheduler */
void HSCHED_vStart(void);

/* Function prototype for stopping the scheduler */
void HSCHED_vStop(void);

/* Function prototype for registering a runnable task with the scheduler */
HSCHED_enuErrorStatus_t HSCHED_enuRegisterRunnable(HSCHED_sSCHEDRunnableCfg_t *Add_SCHED_cbf);



#endif /* SCHED_INTERFACING_H_ */