#ifndef STK_PRIV_H_
#define STK_PRIV_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* Define the clock frequency of the HSI (High-Speed Internal) oscillator in Hz */
#define M_STK_HSI_ClkHz 16000000ULL  

/* Mask to clear the ENABLE bit in the SysTick Control and Status Register */
#define M_STK_CTRL_ENABLE_msk                0xFFFFFFFEUL

/* Value to enable the SysTick timer */
#define M_STK_CTRL_ENABLE_EN                 0x00000001UL

/* Value to disable the SysTick timer */
#define M_STK_CTRL_ENABLE_DIS                0x00000000UL

/* Mask to clear the TICKINT bit in the SysTick Control and Status Register */
#define M_STK_CTRL_TICKINT_msk               0xFFFFFFFDUL 

/* Value to enable the SysTick exception request */
#define M_STK_CTRL_TICKINT_EnException       0x00000002UL

/* Value to disable the SysTick exception request */
#define M_STK_CTRL_TICKINT_DisException      0x00000000UL

/* Mask to clear the CLKSOURCE bit in the SysTick Control and Status Register */
#define M_STK_CTRL_CLKSOURCE_msk             0xFFFFFFFBUL 

/* Value to set the SysTick clock source to the processor clock (AHB) */
#define M_STK_CTRL_CLKSOURCE_AHB             0x00000004UL

/* Value to set the SysTick clock source to the processor clock divided by 8 (AHB/8) */
#define M_STK_CTRL_CLKSOURCE_AHB_8           0x00000000UL

/* Mask to clear the COUNTFLAG bit in the SysTick Control and Status Register */
#define M_STK_CTRL_COUNTFLAG_msk             0xFFFEFFFFUL  

/* Mask to clear the RELOAD value in the SysTick Reload Value Register */
#define M_STK_LOAD_RELOAD_msk                0xFF000000UL




#endif /* STK_PRIV_H_ */