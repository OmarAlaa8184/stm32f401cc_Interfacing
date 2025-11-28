#ifndef STK_INTERFACING_H_
#define STK_INTERFACING_H_


#include "BIT_MATH.h"
#include "STD_TYPES.h"



/* Define a function pointer type for callback functions */
typedef void (*Cbf_t)(void);

/* Enumeration to represent the possible error statuses for SysTick operations */
typedef enum
{ 
    MSTK_enuOK,                /* Operation completed successfully */
    MSTK_enuNOK,               /* Operation failed */
    MSTK_enuINVALID_INPUT,     /* Invalid input provided */
    MSTK_enuNULL_PTR           /* Null pointer encountered */
} MSTK_enuErrorStatus_t;

/* Function prototype for initializing the SysTick timer */
void MSTK_vSTKSInit(void);

/* Function prototype for starting the SysTick timer */
void MSTK_vSTKStart(void);

/* Function prototype for stopping the SysTick timer */
void MSTK_vSTKStop(void);

/* Function prototype for setting a cyclic callback function */
MSTK_enuErrorStatus_t MSTK_enuSetCyclicFunction(Cbf_t Copy_CbfAddressFunction, u32 Copy_u32Counter);



#endif /* STK_INTERFACING_H_ */