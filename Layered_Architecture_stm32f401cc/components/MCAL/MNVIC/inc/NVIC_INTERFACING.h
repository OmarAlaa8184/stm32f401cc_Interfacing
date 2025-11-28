#ifndef NVIC_INTERFACING_H_
#define NVIC_INTERFACING_H_


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "NVIC_PRIV.h"
#include "NVIC_CFG.h"

typedef enum 
{
    NVIC_enuWWDG, /* Window Watchdog interrupt */
    NVIC_enuEXTI16_PVD, /* EXTI Line 16 interrupt / PVD through EXTI line detection interrupt */
    NVIC_enuEXTI21_TAMP_STAMP, /* EXTI Line 21 interrupt / Tamper and TimeStamp interrupts through EXTI line */
    NVIC_enuEXTI22_RTC_WKUP, /* EXTI Line 22 interrupt / RTC Wakeup interrupt through EXTI line */
    NVIC_enuFLASH, /* Flash global interrupt */
    NVIC_enuRCC, /* RCC global interrupt */
    NVIC_enuEXTI0, /* EXTI Line 0 interrupt */
    NVIC_enuEXTI1, /* EXTI Line 1 interrupt */
    NVIC_enuEXTI2, /* EXTI Line 2 interrupt */
    NVIC_enuEXTI3, /* EXTI Line 3 interrupt */
    NVIC_enuEXTI4, /* EXTI Line 4 interrupt */
    NVIC_enuDMA1_Stream0, /* DMA1 Stream 0 global interrupt */
    NVIC_enuDMA1_Stream1, /* DMA1 Stream 1 global interrupt */
    NVIC_enuDMA1_Stream2, /* DMA1 Stream 2 global interrupt */
    NVIC_enuDMA1_Stream3, /* DMA1 Stream 3 global interrupt */
    NVIC_enuDMA1_Stream4, /* DMA1 Stream 4 global interrupt */
    NVIC_enuDMA1_Stream5, /* DMA1 Stream 5 global interrupt */
    NVIC_enuDMA1_Stream6, /* DMA1 Stream 6 global interrupt */
    NVIC_enuADC, /* ADC1, ADC2 and ADC3 global interrupt */
    NVIC_enuEXTI9_5=23, /* EXTI Line[9:5] interrupts */
    NVIC_enuTIM1_BRK_TIM9, /* TIM1 Break interrupt and TIM9 global interrupt */
    NVIC_enuTIM1_UP_TIM10, /* TIM1 Update interrupt and TIM10 global interrupt */
    NVIC_enuTIM1_TRG_COM_TIM11, /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    NVIC_enuTIM1_CC, /* TIM1 Capture Compare interrupt */
    NVIC_enuTIM2, /* TIM2 global interrupt */
    NVIC_enuTIM3, /* TIM3 global interrupt */
    NVIC_enuTIM4, /* TIM4 global interrupt */
    NVIC_enuI2C1_EV, /* I2C1 event interrupt */
    NVIC_enuI2C1_ER, /* I2C1 error interrupt */
    NVIC_enuI2C2_EV, /* I2C2 event interrupt */
    NVIC_enuI2C2_ER, /* I2C2 error interrupt */
    NVIC_enuSPI1, /* SPI1 global interrupt */
    NVIC_enuSPI2, /* SPI2 global interrupt */
    NVIC_enuUSART1, /* USART1 global interrupt */
    NVIC_enuUSART2, /* USART2 global interrupt */
    NVIC_enuEXTI15_10=40, /* EXTI Line[15:10] interrupts */
    NVIC_enuEXTI17_RTC_Alarm, /* EXTI Line 17 interrupt / RTC Alarms (A and B) through EXTI line */
    NVIC_enuEXTI18_OTG_FS_WKUP, /* EXTI Line 18 interrupt / USB OTG FS Wakeup through EXTI line */
    NVIC_enuDMA1_Stream7=47, /* DMA1 Stream 7 global interrupt */
    NVIC_enuSDIO=49, /* SDIO global interrupt */
    NVIC_enuTIM5, /* TIM5 global interrupt */
    NVIC_enuSPI3, /* SPI3 global interrupt */
    NVIC_enuDMA2_Stream0=56, /* DMA2 Stream 0 global interrupt */
    NVIC_enuDMA2_Stream1, /* DMA2 Stream 1 global interrupt */
    NVIC_enuDMA2_Stream2, /* DMA2 Stream 2 global interrupt */
    NVIC_enuDMA2_Stream3, /* DMA2 Stream 3 global interrupt */
    NVIC_enuDMA2_Stream4, /* DMA2 Stream 4 global interrupt */
    NVIC_enuOTG_FS=67, /* USB OTG FS global interrupt */
    NVIC_enuDMA2_Stream5, /* DMA2 Stream 5 global interrupt */
    NVIC_enuDMA2_Stream6, /* DMA2 Stream 6 global interrupt */
    NVIC_enuDMA2_Stream7, /* DMA2 Stream 7 global interrupt */
    NVIC_enuUSART6, /* USART6 global interrupt */
    NVIC_enuI2C3_EV, /* I2C3 event interrupt */
    NVIC_enuI2C3_ER, /* I2C3 error interrupt */
    NVIC_enuFPU=81, /* Floating point unit interrupt */
    NVIC_enuSPI4=84 /* SPI4 global interrupt */
} MNVIC_enuIRQ_Type_t;

typedef enum
{ 
    MNVIC_enuAllGroup=0x05FA0300,   /* All group priority */
    MNVIC_enu3Groug1Sub=0x05FA0400, /* 3 group priority, 1 subpriority */
    MNVIC_enu2Groug2Sub=0x05FA0500, /* 2 group priority, 2 subpriority */
    MNVIC_enu1Groug3Sub=0x05FA0600, /* 1 group priority, 3 subpriority */
    MNVIC_enuAllSub=0x05FA0700,     /* All subpriority */
} MNVIC_enuPriorityGrouping_t;

typedef enum
{ 
    MNVIC_enuOK,                       /* Operation successful */
    MNVIC_enuNOK,                      /* Operation failed */
    MNVIC_enuINVALID_INPUT,            /* Invalid input parameter */
    MNVIC_enuINVALID_IRQ,              /* Invalid IRQ number */
    MNVIC_enuINVALID_PRIORITY,         /* Invalid priority value */
    MNVIC_enuINVALID_PRIORITYGrouping, /* Invalid priority grouping */
    MNVIC_enuNULL_PTR                  /* Null pointer error */
} MNVIC_enuErrorStatus_t;

/* Enables the specified IRQ (Interrupt Request) */
MNVIC_enuErrorStatus_t MNVIC_enuEnableIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ);

/* Disables the specified IRQ */
MNVIC_enuErrorStatus_t MNVIC_enuDisableIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ);

/* Sets the specified IRQ as pending */
MNVIC_enuErrorStatus_t MNVIC_enuSetPendingIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ);

/* Clears the pending status of the specified IRQ */
MNVIC_enuErrorStatus_t MNVIC_enuClearPendingIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ);

/* Gets the pending status of the specified IRQ and stores it in the provided variable */
MNVIC_enuErrorStatus_t MNVIC_enuGetPendingIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ, u32* Add_pu32BitValue);

/* Gets the active status of the specified IRQ and stores it in the provided variable */
MNVIC_enuErrorStatus_t MNVIC_enuGetActiveIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ, u32* Add_pu32BitValue);

/* Sets the priority of the specified IRQ */
MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ,u8 Copy_u32PriorityValue);

/* Gets the priority of the specified IRQ and stores it in the provided variable */
MNVIC_enuErrorStatus_t MNVIC_enuGetPriorityIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ,u8* Add_pu32BitValue);

/* Sets the priority grouping for the NVIC (Nested Vectored Interrupt Controller) */
MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityGrouping(MNVIC_enuPriorityGrouping_t Copy_enuPriorityGrouping);

#endif /* NVIC_INTERFACING_H_ */