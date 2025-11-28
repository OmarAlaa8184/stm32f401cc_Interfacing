
#ifndef STK_CFG_H_
#define STK_CFG_H_




/* Define the clock source for the SysTick timer as the processor clock (AHB) */
#define M_STK_CTRL_CLKSOURCE   M_STK_CTRL_CLKSOURCE_AHB 

/* Enable the SysTick exception (interrupt) when the timer reaches zero */
#define M_STK_CTRL_TICKINT     M_STK_CTRL_TICKINT_EnException

/* Define the clock type for the SysTick timer as the HSI clock frequency */
#define M_STK_CTRL_CLKTYPE     M_STK_HSI_ClkHz


#endif /* STK_CFG_H_ */