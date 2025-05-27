/*
 * SCHED.C
 *
 * Created: 1/13/2025
 *  Author: Omar Alaa
 */ 

#include "STK_INTERFACING.h"
#include "SCHED_INTERFACING.h"

/* Array to store pointers to runnable configurations, indexed by priority */
HSCHED_sSCHEDRunnableCfg_t* HSCHED_sArrSavedRunnable[HSCHED_Max_Runnable]; 

/* Function prototype for the runnable manager, which handles scheduling */
static void HSCHED_vRunnableManger(void);

/* Function to initialize the scheduler */
void HSCHED_vInit(void)
{
   /* Initialize the SysTick timer */
   MSTK_vSTKSInit();

   /* Set the runnable manager as the cyclic function to be called every tick */
   MSTK_enuSetCyclicFunction(HSCHED_vRunnableManger, 1);
}

/* Function to start the scheduler */
void HSCHED_vStart(void)
{
    /* Start the SysTick timer */
    MSTK_vSTKStart();   
}

/* Function to stop the scheduler */
void HSCHED_vStop(void)
{
   /* Stop the SysTick timer */
   MSTK_vSTKStop();
}  

/* Function to register a runnable task with the scheduler */
HSCHED_enuErrorStatus_t HSCHED_enuRegisterRunnable(HSCHED_sSCHEDRunnableCfg_t *Add_SCHED_cbf)
{
    /* Variable to store the function's return status */
    HSCHED_enuErrorStatus_t Ret_enuError = HSCHED_enuOK;

    /* Check if the provided runnable configuration pointer is NULL */
    if (Add_SCHED_cbf == NULL)
    {
        Ret_enuError = MSTK_enuNULL_PTR;  /* Return NULL pointer error */
    }
    /* Check if the priority is out of range */
    else if (Add_SCHED_cbf->Priority >= HSCHED_Max_Runnable)
    {
        Ret_enuError = HSCHED_enuINVALID_PRIORITY_NUM;  /* Return invalid priority error */
    }
    /* Check if the priority slot is empty */
    else if (HSCHED_sArrSavedRunnable[Add_SCHED_cbf->Priority] == NULL)
    {
        /* Save the runnable configuration in the array at the specified priority */
        HSCHED_sArrSavedRunnable[Add_SCHED_cbf->Priority] = Add_SCHED_cbf;
    }
    else
    {
        Ret_enuError = MSTK_enuNULL_PTR;  /* Return NULL pointer error (priority slot already occupied) */
    }

    return Ret_enuError;  /* Return the function's status */
}

/* Runnable manager function, called periodically by the SysTick timer */
static void HSCHED_vRunnableManger(void)
{
    /* Static variable to keep track of the number of ticks */
    static u64 Local_f64Tick = 1;

    /* Iterate through all runnable tasks */
    for (u32 Local_u32Counter = 0; Local_u32Counter < HSCHED_Max_Runnable; Local_u32Counter++)
    {
        /* Check if the current runnable task is valid (non-NULL) */
        if (HSCHED_sArrSavedRunnable[Local_u32Counter] != NULL)
        {
            /* Check if the task has a first delay */
            if (HSCHED_sArrSavedRunnable[Local_u32Counter]->First_Delay != 0)
            {
                /* Decrement the first delay */
                HSCHED_sArrSavedRunnable[Local_u32Counter]->First_Delay--;
            }
            /* Check if the task's cyclic time matches the current tick */
            else if (Local_f64Tick % HSCHED_sArrSavedRunnable[Local_u32Counter]->Cyclic_Time == 0)
            {
                /* Execute the task's callback function */
                HSCHED_sArrSavedRunnable[Local_u32Counter]->CBF_t();
            }
            else
            {
                /* Do nothing if the task is not ready to execute */
            }
        }
        else
        {
            /* Do nothing if the runnable task is NULL */
        }
    }

    /* Increment the tick counter */
    Local_f64Tick++;
}