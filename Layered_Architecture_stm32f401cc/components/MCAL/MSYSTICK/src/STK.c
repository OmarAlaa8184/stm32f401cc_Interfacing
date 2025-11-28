#include "STK_PRIV.h"
#include "STK_INTERFACING.h"
#include "STK_CFG.h"


/* Declare a global counter variable, marked as volatile to prevent compiler optimizations */
static volatile u32 Global_u32Counter = 0;

/* Declare a global value variable, marked as volatile to prevent compiler optimizations */
static volatile u32 Global_u32Value = 0;

/* Declare a global callback function pointer, initialized to NULL */
static Cbf_t CallBack = NULL;

/* Define a structure to represent the SysTick timer registers */
typedef struct
{
  volatile u32 STK_CTRL;   /* SysTick Control and Status Register */
  volatile u32 STK_LOAD;   /* SysTick Reload Value Register */
  volatile u32 STK_VAL;    /* SysTick Current Value Register */
  volatile u32 STK_CALIB;  /* SysTick Calibration Value Register */
} MSTK_StructRegElments_t;

/* Define the base address of the SysTick timer peripheral */
#define MSTK_BASE_ADD ((MSTK_StructRegElments_t*)(0xE000E010))

/* Function to initialize the SysTick timer */
void MSTK_vSTKSInit(void)
{
  u32 Local_u32Temp = 0;       /* Temporary variable to manipulate register values */
  u32 Local_u32LoadValue = 0;  /* Variable to store the calculated load value */
  u32 Local_u32Delay = 1000;   /* Delay value for timer configuration */

  /* Configure the clock source for the SysTick timer */
  #if M_STK_CTRL_CLKSOURCE == M_STK_CTRL_CLKSOURCE_AHB
    Local_u32Temp = MSTK_BASE_ADD->STK_CTRL;  /* Read the current value of the control register */
    Local_u32Temp &= M_STK_CTRL_CLKSOURCE_msk; /* Clear the clock source bits */
    Local_u32Temp |= M_STK_CTRL_CLKSOURCE_AHB; /* Set the clock source to AHB */
    MSTK_BASE_ADD->STK_CTRL = Local_u32Temp;   /* Write the updated value back to the control register */

  #elif M_STK_CTRL_CLKSOURCE == M_STK_CTRL_CLKSOURCE_AHB_8
    Local_u32Temp = MSTK_BASE_ADD->STK_CTRL;  /* Read the current value of the control register */
    Local_u32Temp &= M_STK_CTRL_CLKSOURCE_msk; /* Clear the clock source bits */
    Local_u32Temp |= M_STK_CTRL_CLKSOURCE_AHB_8; /* Set the clock source to AHB divided by 8 */
    MSTK_BASE_ADD->STK_CTRL = Local_u32Temp;   /* Write the updated value back to the control register */
  #endif

  /* Configure the SysTick interrupt */
  #if M_STK_CTRL_TICKINT == M_STK_CTRL_TICKINT_EnException
    Local_u32Temp = MSTK_BASE_ADD->STK_CTRL;  /* Read the current value of the control register */
    Local_u32Temp &= M_STK_CTRL_TICKINT_msk; /* Clear the interrupt enable bit */
    Local_u32Temp |= M_STK_CTRL_TICKINT_EnException; /* Enable the SysTick interrupt */
    MSTK_BASE_ADD->STK_CTRL = Local_u32Temp;  /* Write the updated value back to the control register */

  #elif M_STK_CTRL_TICKINT == M_STK_CTRL_TICKINT_DisException
    Local_u32Temp = MSTK_BASE_ADD->STK_CTRL;  /* Read the current value of the control register */
    Local_u32Temp &= M_STK_CTRL_TICKINT_msk; /* Clear the interrupt enable bit */
    Local_u32Temp |= M_STK_CTRL_TICKINT_DisException; /* Disable the SysTick interrupt */
    MSTK_BASE_ADD->STK_CTRL = Local_u32Temp;  /* Write the updated value back to the control register */
  #endif

  /* Calculate the reload value for the timer */
  Local_u32LoadValue = ((M_STK_CTRL_CLKTYPE / Local_u32Delay) + 1);

  /* Set the reload value in the SysTick timer */
  Local_u32Temp = MSTK_BASE_ADD->STK_LOAD;  /* Read the current value of the load register */
  Local_u32Temp &= M_STK_LOAD_RELOAD_msk;  /* Clear the reload value bits */
  Local_u32Temp |= Local_u32LoadValue;      /* Set the calculated reload value */
  MSTK_BASE_ADD->STK_LOAD = Local_u32Temp;  /* Write the updated value back to the load register */
}

/* Function to start the SysTick timer */
void MSTK_vSTKStart(void)
{
  u32 Local_u32Temp = 0;  /* Temporary variable to manipulate register values */
  Local_u32Temp = MSTK_BASE_ADD->STK_CTRL;  /* Read the current value of the control register */
  Local_u32Temp &= M_STK_CTRL_ENABLE_msk;   /* Clear the enable bit */
  Local_u32Temp |= M_STK_CTRL_ENABLE_EN;    /* Enable the SysTick timer */
  MSTK_BASE_ADD->STK_CTRL = Local_u32Temp;  /* Write the updated value back to the control register */
}

/* Function to stop the SysTick timer */
void MSTK_vSTKStop(void)
{
  u32 Local_u32Temp = 0;  /* Temporary variable to manipulate register values */
  Local_u32Temp = MSTK_BASE_ADD->STK_CTRL;  /* Read the current value of the control register */
  Local_u32Temp &= M_STK_CTRL_ENABLE_msk;   /* Clear the enable bit */
  Local_u32Temp |= M_STK_CTRL_ENABLE_DIS;   /* Disable the SysTick timer */
  MSTK_BASE_ADD->STK_CTRL = Local_u32Temp;  /* Write the updated value back to the control register */
}

/* Function to set a cyclic callback function for the SysTick timer */
MSTK_enuErrorStatus_t MSTK_enuSetCyclicFunction(Cbf_t Copy_CbfAddressFunction, u32 Copy_u32Counter)
{
  MSTK_enuErrorStatus_t Ret_enuError = MSTK_enuOK;  /* Variable to store the function's return status */

  /* Check if the provided callback function pointer is NULL */
  if (Copy_CbfAddressFunction == NULL)
  {
    Ret_enuError = MSTK_enuNULL_PTR;  /* Return an error if the pointer is NULL */
  }
  else
  {
    CallBack = Copy_CbfAddressFunction;  /* Set the global callback function pointer */
    Global_u32Value = Copy_u32Counter;   /* Set the global counter value */
  }

  return Ret_enuError;  /* Return the function's status */
}

/* SysTick interrupt handler */
void SysTick_Handler(void)
{
  Global_u32Counter++;  /* Increment the global counter */

  /* Check if the counter has reached the specified value */
  if (Global_u32Counter == Global_u32Value)
  {
    CallBack();           /* Execute the callback function */
    Global_u32Counter = 0; /* Reset the counter */
  }
}



 


