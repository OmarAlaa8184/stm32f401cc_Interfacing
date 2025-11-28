#ifndef RCC_INTERFACING_H_
#define RCC_INTERFACING_H_


#include "BIT_MATH.h"
#include "STD_TYPES.h"



/* Enum that contains types of clock sources */
typedef enum
{
    MRCC_enuHSE,       /* High-Speed External oscillator */
    MRCC_enuHSE_BYP,   /* High-Speed External oscillator bypass */
    MRCC_enuHSI,       /* High-Speed Internal oscillator */
    MRCC_enuPLL        /* Phase-Locked Loop clock */
} MRCC_enuClkTypes_t;

/* Enum for different bus types in the system */
typedef enum
{
    MRCC_enuAHB1,      /* AHB1 bus */
    MRCC_enuAHB2,      /* AHB2 bus */
    MRCC_enuAPB1,      /* APB1 bus */
    MRCC_enuAPB2       /* APB2 bus */
} MRCC_enuBusTypes_t;

/* Enum for AHB1 peripherals */
typedef enum
{
    GPIOA,      /* GPIO port A */
    GPIOB,      /* GPIO port B */
    GPIOC,      /* GPIO port C */
    GPIOD,      /* GPIO port D */
    GPIOE,      /* GPIO port E */
    GPIOH = 7,  /* GPIO port H */
    CRC = 12,   /* CRC peripheral */
    DMA1 = 21,  /* DMA1 peripheral */
    DMA2 = 22   /* DMA2 peripheral */
} MRCC_enuAHB1Peripherals_t;

/* Enum for AHB2 peripherals */
typedef enum
{
    OTGFSLP = 7 /*OTG_FS Low Power peripheral */
} MRCC_enuAHB2Peripherals_t;

/* Enum for APB1 peripherals */
typedef enum
{
    TIM2,       /*Timer 2 */
    TIM3,       /*Timer 3 */
    TIM4,       /*Timer 4 */
    TIM5,       /*Timer 5 */
    WWDG = 11,  /*Window Watchdog */
    SPI2 = 14,  /*SPI2 peripheral */
    SPI3 = 15,  /*SPI3 peripheral */
    USART2 = 17,/*USART2 peripheral */
    I2C1 = 21,  /*I2C1 peripheral */
    I2C2,       /*I2C2 peripheral */
    I2C3,       /*I2C3 peripheral */
    PWR = 28    /*Power peripheral */
} MRCC_enuAPB1Peripherals_t;

/* Enum for APB2 peripherals */
typedef enum
{
    TIM1,       /*Timer 1 */
    USART1 = 4, /*USART1 peripheral */
    USART6 = 5, /*USART6 peripheral */
    ADC1 = 8,   /*ADC1 peripheral */
    SDIO = 11,  /*SDIO peripheral */
    SPI1,       /*SPI1 peripheral */
    SPI4,       /*SPI4 peripheral */
    SYSCFG,     /*SYSCFG peripheral */
    TIM9 = 16,  /*Timer 9 */
    TIM10,      /*Timer 10 */
    TIM11       /*Timer 11 */
} MRCC_enuAPB2Peripherals_t;

/* Enum for different error status codes */
typedef enum
{
    MRCC_enuOK,                        /*  Operation successful */
    MRCC_enuNOK,                       /*  Operation failed */
    MRCC_enuTimeOut,                   /*  Timeout occurred */
    MRCC_enuINVALID_CLK,               /*  Invalid clock source */
    MRCC_enuINVALID_BUS,               /*  Invalid bus type */
    MRCC_enuINVALID_AHB1Peripherals,   /*  Invalid AHB1 peripheral */
    MRCC_enuINVALID_AHB2Peripherals,   /*  Invalid AHB2 peripheral */
    MRCC_enuINVALID_APB1Peripherals,   /*  Invalid APB1 peripheral */
    MRCC_enuINVALID_APB2Peripherals,   /*  Invalid APB2 peripheral */
    MRCC_enuINVALID_STATE,             /*  Invalid state */
    MRCC_enuNULL_PTR,                  /*  Null pointer error */
    MRCC_enuINVALID_PLLP,              /*  Invalid PLLP value */
    MRCC_enuINVALID_PLLM,              /*  Invalid PLLM value */
    MRCC_enuINVALID_PLLN,              /*  Invalid PLLN value */
    MRCC_enuINVALID_PLLQ,              /*  Invalid PLLQ value */
    MRCC_enuINVALID_VOC,               /*  Invalid VOC value */
    MRCC_enuPLL_ON                     /*  PLL is on */
} MRCC_enuErrorStatus_t;

/* Struct to enable a peripheral in a specific bus type */
typedef struct
{
    MRCC_enuBusTypes_t BusType;                /* The bus type (AHB1, AHB2, APB1, APB2) */
    MRCC_enuAHB1Peripherals_t AHB1Peripherals; /* AHB1 peripherals to enable */
    MRCC_enuAHB2Peripherals_t AHB2Peripherals; /* AHB2 peripherals to enable */
    MRCC_enuAPB1Peripherals_t APB1Peripherals; /* APB1 peripherals to enable */
    MRCC_enuAPB2Peripherals_t APB2Peripherals; /* APB2 peripherals to enable */
} MRCC_structEnablePeripheral_t;

/* Struct to configure PLL parameters */
typedef struct
{
    MRCC_enuClkTypes_t ClkType; /* Clock type (e.g., HSE, HSI, PLL) */
    u32 M;                      /* PLLM value */
    u32 N;                      /* PLLN value */
    u32 Q;                      /* PLLQ value */
    u32 P;                      /* PLLP value */
} MRCC_structPLL_Cfg_t;

/*
 * @brief  Enables the clock for a specific clock type.
 * @param  Copy_enuClk: The clock type to enable (e.g., HSE, HSI, PLL).
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuEnableClk(MRCC_enuClkTypes_t Copy_enuClk);

/*
 * @brief  Disables the clock for a specific clock type.
 * @param  Copy_enuClk: The clock type to disable (e.g., HSE, HSI, PLL).
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuDisableClk(MRCC_enuClkTypes_t Copy_enuClk);

/*
 * @brief  Enables the specified peripherals on the given bus type.
 * @param  Copy_Struct: Structure containing the bus type and peripherals to enable.
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuEnablePeripherals(MRCC_structEnablePeripheral_t Copy_Struct);

/*
 * @brief  Disables the specified peripherals on the given bus type.
 * @param  Copy_Struct: Structure containing the bus type and peripherals to disable.
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuDisablePeripherals(MRCC_structEnablePeripheral_t Copy_Struct);

/*
 * @brief  Retrieves the current status of a specific clock.
 * @param  Copy_enuClk: The clock type (e.g., HSE, HSI, PLL).
 * @param  Add_pu32ClkStatus: Pointer to a variable where the clock status will be stored.
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuGetClkStatus(MRCC_enuClkTypes_t Copy_enuClk, u32* Add_pu32ClkStatus);

/*
 * @brief  Selects the specified clock as the system clock.
 * @param  Copy_enuClk: The clock type to select (e.g., HSE, HSI, PLL).
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuSelectClk(MRCC_enuClkTypes_t Copy_enuClk);

/*
 * @brief  Configures the PLL (Phase-Locked Loop) with the specified parameters.
 * @param  Add_StructPLL: Pointer to a structure containing PLL configuration parameters (M, N, Q, P).
 * @retval MRCC_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 */
MRCC_enuErrorStatus_t MRCC_enuPLL_Cfg(MRCC_structPLL_Cfg_t* Add_StructPLL);






#endif /* RCC_INTERFACING_H_ */