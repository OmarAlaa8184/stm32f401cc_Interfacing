#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_


/* RCC Base Address */
#define RCC_BASE  0x40023800UL    /* Base address for RCC (Reset and Clock Control) registers*/

/* Register Definitions */

/* RCC Control Register */
#define M_RCC_CR                 *((volatile u32*)(RCC_BASE)) /* RCC_CR: Clock Control Register*/

/* RCC PLL Configuration Register */
#define M_RCC_PLLCFGR            *((volatile u32*)(RCC_BASE+(0x04UL))) /* RCC_PLLCFGR: PLL Configuration Register*/

/* RCC Clock Configuration Register */
#define M_RCC_CFGR               *((volatile u32*)(RCC_BASE+(0x08UL))) /* RCC_CFGR: Clock Configuration Register*/

/* RCC Clock Interrupt Register */
#define M_RCC_CIR                *((volatile u32*)(RCC_BASE+(0x0CUL))) /* RCC_CIR: Clock Interrupt Register*/

/* RCC AHB1 Peripheral Reset Register */
#define M_RCC_AHB1RSTR           *((volatile u32*)(RCC_BASE+(0x10UL))) /* RCC_AHB1RSTR: AHB1 Peripheral Reset Register*/

/* RCC AHB2 Peripheral Reset Register */
#define M_RCC_AHB2RSTR           *((volatile u32*)(RCC_BASE+(0x14UL))) /* RCC_AHB2RSTR: AHB2 Peripheral Reset Register*/

/* RCC APB1 Peripheral Reset Register */
#define M_RCC_APB1RSTR           *((volatile u32*)(RCC_BASE+(0x20UL))) /* RCC_APB1RSTR: APB1 Peripheral Reset Register*/

/* RCC APB2 Peripheral Reset Register */
#define M_RCC_APB2RSTR           *((volatile u32*)(RCC_BASE+(0x24UL))) /* RCC_APB2RSTR: APB2 Peripheral Reset Register*/

/* RCC AHB1 Peripheral Enable Register */
#define M_RCC_AHB1ENR            *((volatile u32*)(RCC_BASE+(0x30UL))) /* RCC_AHB1ENR: AHB1 Peripheral Enable Register*/

/* RCC AHB2 Peripheral Enable Register */
#define M_RCC_AHB2ENR            *((volatile u32*)(RCC_BASE+(0x34UL))) /* RCC_AHB2ENR: AHB2 Peripheral Enable Register*/

/* RCC APB1 Peripheral Enable Register */
#define M_RCC_APB1ENR            *((volatile u32*)(RCC_BASE+(0x40UL))) /* RCC_APB1ENR: APB1 Peripheral Enable Register*/

/* RCC APB2 Peripheral Enable Register */
#define M_RCC_APB2ENR            *((volatile u32*)(RCC_BASE+(0x44UL))) /* RCC_APB2ENR: APB2 Peripheral Enable Register*/

/* RCC AHB1 Low Power Enable Register */
#define M_RCC_AHB1LPENR          *((volatile u32*)(RCC_BASE+(0x50UL))) /* RCC_AHB1LPENR: AHB1 Low Power Enable Register*/

/* RCC AHB2 Low Power Enable Register */
#define M_RCC_AHB2LPENR          *((volatile u32*)(RCC_BASE+(0x54UL))) /* RCC_AHB2LPENR: AHB2 Low Power Enable Register*/

/* RCC APB1 Low Power Enable Register */
#define M_RCC_APB1LPENR          *((volatile u32*)(RCC_BASE+(0x60UL))) /* RCC_APB1LPENR: APB1 Low Power Enable Register*/

/* RCC APB2 Low Power Enable Register */
#define M_RCC_APB2LPENR          *((volatile u32*)(RCC_BASE+(0x64UL))) /* RCC_APB2LPENR: APB2 Low Power Enable Register*/

/* RCC Backup Domain Control Register */
#define M_RCC_BDCR               *((volatile u32*)(RCC_BASE+(0x70UL))) /* RCC_BDCR: Backup Domain Control Register*/

/* RCC Control/Status Register */
#define M_RCC_CSR                *((volatile u32*)(RCC_BASE+(0x74UL))) /* RCC_CSR: Control/Status Register*/

/* RCC Spread Spectrum Clock Generation Register */
#define M_RCC_SSCGR              *((volatile u32*)(RCC_BASE+(0x80UL))) /* RCC_SSCGR: Spread Spectrum Clock Generation Register*/

/* RCC PLLI2S Configuration Register */
#define M_RCC_PLLI2SCFGR         *((volatile u32*)(RCC_BASE+(0x84UL))) /* RCC_PLLI2SCFGR: PLLI2S Configuration Register*/

/* RCC Domain Clocks Configuration Register */
#define M_RCC_DCKCFGR            *((volatile u32*)(RCC_BASE+(0x8CUL))) /* RCC_DCKCFGR: Domain Clocks Configuration Register*/

/* Status Flags */
#define M_RCC_HSIRDY  1        /* HSIRDY: High-Speed Internal Ready Flag*/
#define M_RCC_HSERDY  17       /* HSERDY: High-Speed External Ready Flag*/
#define M_RCC_PLLRDY  25       /* PLLRDY: PLL Ready Flag*/

/* Masks */

/* RCC CR Register Masks */
#define M_RCC_CR_HSION_msk          0x00000001UL /* HSION: High-Speed Internal Oscillator Enable*/
#define M_RCC_CR_HSIRDY_msk         0x00000002UL /* HSIRDY: High-Speed Internal Oscillator Ready*/

#define M_RCC_CR_HSEON_msk          0x00010000UL /* HSEON: High-Speed External Oscillator Enable*/
#define M_RCC_CR_HSERDY_msk         0X00020000UL /* HSERDY: High-Speed External Oscillator Ready*/
#define M_RCC_CR_HSEON_BYP_msk      0X00040000UL /* HSEON_BYP: High-Speed External Oscillator Bypass Enable*/

#define M_RCC_CR_PLLON_msk          0x01000000UL /* PLLON: Phase-Locked Loop Enable*/
#define M_RCC_CR_PLLRDY_msk         0x02000000UL /* PLLRDY: PLL Ready Flag*/

/* AHB1 Peripheral Masks */
#define M_RCC_AHB1_GPIOA_msk        0x00000001UL /* GPIOA Peripheral Enable*/
#define M_RCC_AHB1_GPIOB_msk        0x00000002UL /* GPIOB Peripheral Enable*/
#define M_RCC_AHB1_GPIOC_msk        0x00000004UL /* GPIOC Peripheral Enable*/
#define M_RCC_AHB1_GPIOD_msk        0x00000008UL /* GPIOD Peripheral Enable*/
#define M_RCC_AHB1_GPIOE_msk        0x00000010UL /* GPIOE Peripheral Enable*/
#define M_RCC_AHB1_GPIOH_msk        0x00000080UL /* GPIOH Peripheral Enable*/
#define M_RCC_AHB1_CRC_msk          0x00001000UL /* CRC Peripheral Enable*/
#define M_RCC_AHB1_DMA1_msk         0x00200000UL /* DMA1 Peripheral Enable*/
#define M_RCC_AHB1_DMA2_msk         0x00400000UL /* DMA2 Peripheral Enable*/

/* AHB2 Peripheral Masks */
#define M_RCC_AHB2_OTGFS_msk        0x00000080UL /* OTG FS Peripheral Enable*/

/* APB1 Peripheral Masks */
#define M_RCC_APB1_TIM2_msk         0x00000001UL /* TIM2 Peripheral Enable*/
#define M_RCC_APB1_TIM3_msk         0x00000002UL /* TIM3 Peripheral Enable*/
#define M_RCC_APB1_TIM4_msk         0x00000004UL /* TIM4 Peripheral Enable*/
#define M_RCC_APB1_TIM5_msk         0x00000008UL /* TIM5 Peripheral Enable*/
#define M_RCC_APB1_WWDG_msk         0x00000800UL /* WWDG Peripheral Enable*/
#define M_RCC_APB1_SPI2_msk         0x00004000UL /* SPI2 Peripheral Enable*/
#define M_RCC_APB1_SPI3_msk         0x00008000UL /* SPI3 Peripheral Enable*/
#define M_RCC_APB1_USART2_msk       0x00020000UL /* USART2 Peripheral Enable*/
#define M_RCC_APB1_I2C1_msk         0X00200000UL /* I2C1 Peripheral Enable*/
#define M_RCC_APB1_I2C2_msk         0x00400000UL /* I2C2 Peripheral Enable*/
#define M_RCC_APB1_I2C3_msk         0x00800000UL /* I2C3 Peripheral Enable*/
#define M_RCC_APB1_PWR_msk          0x10000000UL /* PWR Peripheral Enable*/

/* APB2 Peripheral Masks */
#define M_RCC_APB2_TIM1_msk         0x00000001UL /* TIM1 Peripheral Enable*/
#define M_RCC_APB2_USART1_msk       0x00000010UL /* USART1 Peripheral Enable*/
#define M_RCC_APB2_USART6_msk       0x00000020UL /* USART6 Peripheral Enable*/
#define M_RCC_APB2_ADC1_msk         0x00000100UL /* ADC1 Peripheral Enable*/
#define M_RCC_APB2_SDIO_msk         0x00000800UL /* SDIO Peripheral Enable*/
#define M_RCC_APB2_SPI1_msk         0x00001000UL /* SPI1 Peripheral Enable*/
#define M_RCC_APB2_SPI4_msk         0x00002000UL /* SPI4 Peripheral Enable*/
#define M_RCC_APB2_SYSCFG_msk       0x00004000UL /* SYSCFG Peripheral Enable*/
#define M_RCC_APB2_TIM9_msk         0x00010000UL /* TIM9 Peripheral Enable*/
#define M_RCC_APB2_TIM10_msk        0x00020000UL /* TIM10 Peripheral Enable*/
#define M_RCC_APB2_TIM11_msk        0x00040000UL /* TIM11 Peripheral Enable*/

/* RCC CFGR Register Masks */
#define M_RCC_CFGR_SW_msk           0xFFFFFFFCUL /* SW: System Clock Switch Mask*/
#define M_RCC_CFGR_SW_HSI           0x00000000UL /* HSI: High-Speed Internal Clock Selection*/
#define M_RCC_CFGR_SW_HSE           0x00000001UL /* HSE: High-Speed External Clock Selection*/
#define M_RCC_CFGR_SW_PLL           0x00000002UL /* PLL: Phase-Locked Loop Clock Selection*/

#define M_RCC_CFGR_SWS_msk          0xFFFFFFF3UL /* SWS: System Clock Switch Status Mask*/
#define M_RCC_CFGR_SWS_HSI          0x00000000UL /* HSI: High-Speed Internal Clock Status*/
#define M_RCC_CFGR_SWS_HSE          0x00000001UL /* HSE: High-Speed External Clock Status*/
#define M_RCC_CFGR_SWS_PLL          0x00000002UL /* PLL: Phase-Locked Loop Clock Status*/

/* PLL Configuration Masks */
#define M_RCC_PLLCFGR_PLLP_msk      0xFFFCFFFFUL /* PLLP: PLLP Prescaler Mask*/
#define M_RCC_PLLCFGR_PLLP_2        0x00000000UL /* PLLP = 2*/
#define M_RCC_PLLCFGR_PLLP_4        0x00010000UL /* PLLP = 4*/
#define M_RCC_PLLCFGR_PLLP_6        0x00020000UL /* PLLP = 6*/
#define M_RCC_PLLCFGR_PLLP_8        0x00030000UL /* PLLP = 8*/

#define M_RCC_PLLCFGR_PLLM_msk      0xFFFFFFE0UL /* PLLM: PLLM Divider Mask*/
#define M_RCC_PLLCFGR_PLLN_msk      0xFFFF803FUL /* PLLN: PLLN Multiplier Mask*/
#define M_RCC_PLLCFGR_PLLQ_msk      0xF0FFFFFFUL /* PLLQ: PLLQ Divider Mask*/

#define M_RCC_PLLCFGR_PLLSRC_msk    0xFFBFFFFFUL /* PLLSRC: PLL Source Mask*/
#define M_RCC_PLLCFGR_PLLSRC_HSI    0x00000000UL /* PLL Source: HSI*/
#define M_RCC_PLLCFGR_PLLSRC_HSE    0x00400000UL /* PLL Source: HSE*/




#endif