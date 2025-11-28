

#include "RCC_PRIV.h"
#include "RCC_INTERFACING.h"
#include "RCC_CFG.h"



/* Function to enable a clock source */
MRCC_enuErrorStatus_t MRCC_enuEnableClk(MRCC_enuClkTypes_t Copy_enuClk)
{
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuOK;  /* Initialize return error status */
    u16 Local_u8TimeOut = 1000;  /* Timeout counter */
    
    if (Copy_enuClk == MRCC_enuHSI)
    {
        M_RCC_CR |= M_RCC_CR_HSION_msk;  /* Enable HSI clock */
        while ((!(M_RCC_CR & M_RCC_CR_HSIRDY_msk)) && (Local_u8TimeOut > 0))
        {
            Local_u8TimeOut--;  /* Wait for HSI to be ready or timeout */
        }
        if ((M_RCC_CR & M_RCC_CR_HSIRDY_msk))
        {
            /* HSI is ready */
        }
        else
        {
            Ret_enuError = MRCC_enuTimeOut;  /* Timeout error */
        }
    }
    else if (Copy_enuClk == MRCC_enuHSE)
    {
        M_RCC_CR |= M_RCC_CR_HSEON_msk;  /* Enable HSE clock */
        while ((!(M_RCC_CR & M_RCC_CR_HSERDY_msk)) && (Local_u8TimeOut > 0))
        {
            Local_u8TimeOut--;  /* Wait for HSE to be ready or timeout */
        }
        if ((M_RCC_CR & M_RCC_CR_HSERDY_msk))
        {
            /* HSE is ready */
        }
        else
        {
            Ret_enuError = MRCC_enuTimeOut;  /* Timeout error */
        }
    }
    else if (Copy_enuClk == MRCC_enuHSE_BYP)
    {
        M_RCC_CR |= M_RCC_CR_HSEON_BYP_msk;  /* Enable HSE bypass */
        M_RCC_CR |= M_RCC_CR_HSEON_msk;      /* Enable HSE clock */
        while ((!(M_RCC_CR & M_RCC_CR_HSERDY_msk)) && Local_u8TimeOut--)
        {
            /* Wait for HSE to be ready or timeout */
        }
        if ((M_RCC_CR & M_RCC_CR_HSERDY_msk))
        {
            /* HSE is ready */
        }
        else
        {
            Ret_enuError = MRCC_enuTimeOut;  /* Timeout error */
        }
    }
    else if (Copy_enuClk == MRCC_enuPLL)
    {
        M_RCC_CR |= M_RCC_CR_PLLON_msk;  /* Enable PLL */
        while ((!(M_RCC_CR & M_RCC_CR_PLLRDY_msk)) && (Local_u8TimeOut > 0))
        {
            Local_u8TimeOut--;  /* Wait for PLL to be ready or timeout */
        }
        if ((M_RCC_CR & M_RCC_CR_PLLRDY_msk))
        {
            /* PLL is ready */
        }
        else
        {
            Ret_enuError = MRCC_enuTimeOut;  /* Timeout error */
        }
    }
    else
    {
        Ret_enuError = MRCC_enuNOK;  /* Invalid clock type */
    }
    return Ret_enuError;  /* Return error status */
}

/* Function to disable a clock source */
MRCC_enuErrorStatus_t MRCC_enuDisableClk(MRCC_enuClkTypes_t Copy_enuClk)
{
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuOK;  /* Initialize return error status */
    
    if (Copy_enuClk == MRCC_enuHSI)
    {
        M_RCC_CR &= ~(M_RCC_CR_HSION_msk);  /* Disable HSI clock */
    }
    else if (Copy_enuClk == MRCC_enuHSE)
    {
        M_RCC_CR &= ~(M_RCC_CR_HSEON_msk);  /* Disable HSE clock */
    }
    else if (Copy_enuClk == MRCC_enuHSE_BYP)
    {
        M_RCC_CR &= ~(M_RCC_CR_HSEON_BYP_msk);  /* Disable HSE bypass */
        M_RCC_CR &= ~(M_RCC_CR_HSEON_msk);      /* Disable HSE clock */
    }
    else if (Copy_enuClk == MRCC_enuPLL)
    {
        M_RCC_CR &= ~(M_RCC_CR_PLLON_msk);  /* Disable PLL */
    }
    else
    {
        Ret_enuError = MRCC_enuINVALID_CLK;  /* Invalid clock type */
    }
    return Ret_enuError;  /* Return error status */
}

/* Function to enable peripherals on a specific bus */

MRCC_enuErrorStatus_t MRCC_enuEnablePeripherals(MRCC_structEnablePeripheral_t Copy_Struct)
{
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuOK;  /* Initialize return error status */

    if (Copy_Struct.BusType == MRCC_enuAHB1)
    {
        switch (Copy_Struct.AHB1Peripherals)
        {
            case GPIOA:    M_RCC_AHB1ENR |= M_RCC_AHB1_GPIOA_msk; break;  /* Enable GPIOA on AHB1 */
            case GPIOB:    M_RCC_AHB1ENR |= M_RCC_AHB1_GPIOB_msk; break;  /* Enable GPIOB on AHB1 */
            case GPIOC:    M_RCC_AHB1ENR |= M_RCC_AHB1_GPIOC_msk; break;  /* Enable GPIOC on AHB1 */
            case GPIOD:    M_RCC_AHB1ENR |= M_RCC_AHB1_GPIOD_msk; break;  /* Enable GPIOD on AHB1 */
            case GPIOE:    M_RCC_AHB1ENR |= M_RCC_AHB1_GPIOE_msk; break;  /* Enable GPIOE on AHB1 */
            case GPIOH:    M_RCC_AHB1ENR |= M_RCC_AHB1_GPIOH_msk; break;  /* Enable GPIOH on AHB1 */
            case CRC:      M_RCC_AHB1ENR |= M_RCC_AHB1_CRC_msk;   break;  /* Enable CRC on AHB1 */
            case DMA1:     M_RCC_AHB1ENR |= M_RCC_AHB1_DMA1_msk;  break;  /* Enable DMA1 on AHB1 */
            case DMA2:     M_RCC_AHB1ENR |= M_RCC_AHB1_DMA2_msk;  break;  /* Enable DMA2 on AHB1 */
            default:       Ret_enuError = MRCC_enuINVALID_AHB1Peripherals; break;  /* Invalid AHB1 peripheral */
        }
    }
    else if (Copy_Struct.BusType == MRCC_enuAHB2)
    {
        switch (Copy_Struct.AHB2Peripherals)
        {
            case OTGFSLP:  M_RCC_AHB2ENR |= M_RCC_AHB2_OTGFS_msk; break;  /* Enable OTGFS on AHB2 */
            default:       Ret_enuError = MRCC_enuINVALID_AHB2Peripherals; break;  /* Invalid AHB2 peripheral */
        }
    }
    else if (Copy_Struct.BusType == MRCC_enuAPB1)
    {
        switch (Copy_Struct.APB1Peripherals)
        {
            case TIM2:     M_RCC_APB1ENR |= M_RCC_APB1_TIM2_msk;   break;  /* Enable TIM2 on APB1 */
            case TIM3:     M_RCC_APB1ENR |= M_RCC_APB1_TIM3_msk;   break;  /* Enable TIM3 on APB1 */
            case TIM4:     M_RCC_APB1ENR |= M_RCC_APB1_TIM4_msk;   break;  /* Enable TIM4 on APB1 */
            case TIM5:     M_RCC_APB1ENR |= M_RCC_APB1_TIM5_msk;   break;  /* Enable TIM5 on APB1 */
            case WWDG:     M_RCC_APB1ENR |= M_RCC_APB1_WWDG_msk;   break;  /* Enable WWDG on APB1 */
            case SPI2:     M_RCC_APB1ENR |= M_RCC_APB1_SPI2_msk;   break;  /* Enable SPI2 on APB1 */
            case SPI3:     M_RCC_APB1ENR |= M_RCC_APB1_SPI3_msk;   break;  /* Enable SPI3 on APB1 */
            case USART2:   M_RCC_APB1ENR |= M_RCC_APB1_USART2_msk; break;  /* Enable USART2 on APB1 */
            case I2C1:     M_RCC_APB1ENR |= M_RCC_APB1_I2C1_msk;   break;  /* Enable I2C1 on APB1 */
            case I2C2:     M_RCC_APB1ENR |= M_RCC_APB1_I2C2_msk;   break;  /* Enable I2C2 on APB1 */
            case I2C3:     M_RCC_APB1ENR |= M_RCC_APB1_I2C3_msk;   break;  /* Enable I2C3 on APB1 */
            case PWR:      M_RCC_APB1ENR |= M_RCC_APB1_PWR_msk;    break;  /* Enable PWR on APB1 */
             default: Ret_enuError = MRCC_enuINVALID_APB1Peripherals; break;  /* Invalid APB1 peripheral */
        }
    }
    else if (Copy_Struct.BusType == MRCC_enuAPB2)
    {
        switch (Copy_Struct.APB2Peripherals)
        {
            case TIM1:    M_RCC_APB2ENR |= M_RCC_APB2_TIM1_msk;    break;  /* Enable TIM1 on APB2 */
            case USART1:  M_RCC_APB2ENR |= M_RCC_APB2_USART1_msk;  break;  /* Enable USART1 on APB2 */
            case USART6:  M_RCC_APB2ENR |= M_RCC_APB2_USART6_msk;  break;  /* Enable USART6 on APB2 */
            case ADC1:    M_RCC_APB2ENR |= M_RCC_APB2_ADC1_msk;    break;  /* Enable ADC1 on APB2 */
            case SDIO:    M_RCC_APB2ENR |= M_RCC_APB2_SDIO_msk;    break;  /* Enable SDIO on APB2 */
            case SPI1:    M_RCC_APB2ENR |= M_RCC_APB2_SPI1_msk;    break;  /* Enable SPI1 on APB2 */
            case SPI4:    M_RCC_APB2ENR |= M_RCC_APB2_SPI4_msk;    break;  /* Enable SPI4 on APB2 */
            case SYSCFG:  M_RCC_APB2ENR |= M_RCC_APB2_SYSCFG_msk;  break;  /* Enable SYSCFG on APB2 */
            case TIM9:    M_RCC_APB2ENR |= M_RCC_APB2_TIM9_msk;    break;  /* Enable TIM9 on APB2 */
            case TIM10:   M_RCC_APB2ENR |= M_RCC_APB2_TIM10_msk;   break;  /* Enable TIM10 on APB2 */
            case TIM11:   M_RCC_APB2ENR |= M_RCC_APB2_TIM11_msk;   break;  /* Enable TIM11 on APB2 */
            default:      Ret_enuError = MRCC_enuINVALID_APB2Peripherals; break;  /* Invalid APB2 peripheral */
        }
    }
    else
    {
        Ret_enuError = MRCC_enuINVALID_BUS;  /* Invalid bus type */
    }
    
    return Ret_enuError;  /* Return error status */
}

/* Function to disable peripherals on a specific bus */
MRCC_enuErrorStatus_t MRCC_enuDisablePeripherals(MRCC_structEnablePeripheral_t Copy_Struct)
{
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuOK;  /* Initialize return error status */

    if (Copy_Struct.BusType == MRCC_enuAHB1)
    {
        switch (Copy_Struct.AHB1Peripherals)
        {
            case GPIOA:    M_RCC_AHB1ENR &= ~(M_RCC_AHB1_GPIOA_msk); break;  /* Disable GPIOA on AHB1 */
            case GPIOB:    M_RCC_AHB1ENR &= ~(M_RCC_AHB1_GPIOB_msk); break;  /* Disable GPIOB on AHB1 */
            case GPIOC:    M_RCC_AHB1ENR &= ~(M_RCC_AHB1_GPIOC_msk); break;  /* Disable GPIOC on AHB1 */
            case GPIOD:    M_RCC_AHB1ENR &= ~(M_RCC_AHB1_GPIOD_msk); break;  /* Disable GPIOD on AHB1 */
            case GPIOE:    M_RCC_AHB1ENR &= ~(M_RCC_AHB1_GPIOE_msk); break;  /* Disable GPIOE on AHB1 */
            case GPIOH:    M_RCC_AHB1ENR &= ~(M_RCC_AHB1_GPIOH_msk); break;  /* Disable GPIOH on AHB1 */
            case CRC:      M_RCC_AHB1ENR &= ~(M_RCC_AHB1_CRC_msk);   break;  /* Disable CRC on AHB1 */
            case DMA1:     M_RCC_AHB1ENR &= ~(M_RCC_AHB1_DMA1_msk);  break;  /* Disable DMA1 on AHB1 */
            case DMA2:     M_RCC_AHB1ENR &= ~(M_RCC_AHB1_DMA2_msk);  break;  /* Disable DMA2 on AHB1 */
            default:       Ret_enuError = MRCC_enuINVALID_AHB1Peripherals; break;  /* Invalid AHB1 peripheral */
        }
    }
    else if (Copy_Struct.BusType == MRCC_enuAHB2)
    {
        switch (Copy_Struct.AHB2Peripherals)
        {
            case OTGFSLP:  M_RCC_AHB2ENR &= ~(M_RCC_AHB2_OTGFS_msk); break;  /* Disable OTGFS on AHB2 */
            default:       Ret_enuError = MRCC_enuINVALID_AHB2Peripherals; break;  /* Invalid AHB2 peripheral */
        }
    }
    else if (Copy_Struct.BusType == MRCC_enuAPB1)
    {
        switch (Copy_Struct.APB1Peripherals)
        {
            case TIM2:     M_RCC_APB1ENR &= ~(M_RCC_APB1_TIM2_msk);   break;  /* Disable TIM2 on APB1 */
            case TIM3:     M_RCC_APB1ENR &= ~(M_RCC_APB1_TIM3_msk);   break;  /* Disable TIM3 on APB1 */
            case TIM4:     M_RCC_APB1ENR &= ~(M_RCC_APB1_TIM4_msk);   break;  /* Disable TIM4 on APB1 */
            case TIM5:     M_RCC_APB1ENR &= ~(M_RCC_APB1_TIM5_msk);   break;  /* Disable TIM5 on APB1 */
            case WWDG:     M_RCC_APB1ENR &= ~(M_RCC_APB1_WWDG_msk);   break;  /* Disable WWDG on APB1 */
            case SPI2:     M_RCC_APB1ENR &= ~(M_RCC_APB1_SPI2_msk);   break;  /* Disable SPI2 on APB1 */
            case SPI3:     M_RCC_APB1ENR &= ~(M_RCC_APB1_SPI3_msk);   break;  /* Disable SPI3 on APB1 */
            case USART2:   M_RCC_APB1ENR &= ~(M_RCC_APB1_USART2_msk); break;  /* Disable USART2 on APB1 */
            case I2C1:     M_RCC_APB1ENR &= ~(M_RCC_APB1_I2C1_msk);   break;  /* Disable I2C1 on APB1 */
            case I2C2:     M_RCC_APB1ENR &= ~(M_RCC_APB1_I2C2_msk);   break;  /* Disable I2C2 on APB1 */
            case I2C3:     M_RCC_APB1ENR &= ~(M_RCC_APB1_I2C3_msk);   break;  /* Disable I2C3 on APB1 */
            case PWR:      M_RCC_APB1ENR &= ~(M_RCC_APB1_PWR_msk);    break;  /* Disable PWR on APB1 */
            default:       Ret_enuError = MRCC_enuINVALID_APB1Peripherals; break;  /* Invalid APB1 peripheral */
        }
    }
    else if (Copy_Struct.BusType == MRCC_enuAPB2)
    {
        switch (Copy_Struct.APB2Peripherals)
        {
            case TIM1:    M_RCC_APB2ENR &= ~(M_RCC_APB2_TIM1_msk);    break;  /* Disable TIM1 on APB2 */
            case USART1:  M_RCC_APB2ENR &= ~(M_RCC_APB2_USART1_msk);  break;  /* Disable USART1 on APB2 */
            case USART6:  M_RCC_APB2ENR &= ~(M_RCC_APB2_USART6_msk);  break;  /* Disable USART6 on APB2 */
            case ADC1:    M_RCC_APB2ENR &= ~(M_RCC_APB2_ADC1_msk);    break;  /* Disable ADC1 on APB2 */
            case SDIO:    M_RCC_APB2ENR &= ~(M_RCC_APB2_SDIO_msk);    break;  /* Disable SDIO on APB2 */
            case SPI1:    M_RCC_APB2ENR &= ~(M_RCC_APB2_SPI1_msk);    break;  /* Disable SPI1 on APB2 */
            case SPI4:    M_RCC_APB2ENR &= ~(M_RCC_APB2_SPI4_msk);    break;  /* Disable SPI4 on APB2 */
            case SYSCFG:  M_RCC_APB2ENR &= ~(M_RCC_APB2_SYSCFG_msk);  break;  /* Disable SYSCFG on APB2 */
            case TIM9:    M_RCC_APB2ENR &= ~(M_RCC_APB2_TIM9_msk);    break;  /* Disable TIM9 on APB2 */
            case TIM10:   M_RCC_APB2ENR &= ~(M_RCC_APB2_TIM10_msk);   break;  /* Disable TIM10 on APB2 */
            case TIM11:   M_RCC_APB2ENR &= ~(M_RCC_APB2_TIM11_msk);   break;  /* Disable TIM11 on APB2 */
            default:      Ret_enuError = MRCC_enuINVALID_APB2Peripherals; break;  /* Invalid APB2 peripheral */
        }
    }
    else
    {
        Ret_enuError = MRCC_enuINVALID_BUS;  /* Invalid bus type */
    }
    
    return Ret_enuError;  /* Return error status */
}

/* Function to get the status of a clock source */
MRCC_enuErrorStatus_t MRCC_enuGetClkStatus(MRCC_enuClkTypes_t Copy_enuClk, u32* Add_pu32ClkStatus)
{
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuOK;  /* Initialize return error status */
    
    if (Add_pu32ClkStatus == NULL)
    {
        Ret_enuError = MRCC_enuNULL_PTR;  /* Null pointer error */
    }
    else
    {
        switch (Copy_enuClk)
        {
            case MRCC_enuHSI:  *Add_pu32ClkStatus = GET_BIT(M_RCC_CR, M_RCC_HSIRDY); break;  /* Get HSI status */
            case MRCC_enuHSE:  *Add_pu32ClkStatus = GET_BIT(M_RCC_CR, M_RCC_HSERDY); break;  /* Get HSE status */
            case MRCC_enuPLL:  *Add_pu32ClkStatus = GET_BIT(M_RCC_CR, M_RCC_PLLRDY); break;  /* Get PLL status */
            default: Ret_enuError = MRCC_enuINVALID_CLK; break;  /* Invalid clock type */
        }
    }

    return Ret_enuError;  /* Return error status */
}

/* Function to select a clock source */
MRCC_enuErrorStatus_t MRCC_enuSelectClk(MRCC_enuClkTypes_t Copy_enuClk)
{
    u32 Local_u32ClkOn;
    u32 Local_u32Temp;
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuGetClkStatus(Copy_enuClk, &Local_u32ClkOn);
    
    if (Local_u32ClkOn == 0)
    {
        Ret_enuError = MRCC_enuINVALID_CLK;  /* Invalid clock type */
    }
    else
    {
        switch (Copy_enuClk)
        {
            case MRCC_enuHSI:     
                Local_u32Temp = M_RCC_CFGR;
                Local_u32Temp &= M_RCC_CFGR_SW_msk;
                Local_u32Temp |= M_RCC_CFGR_SW_HSI; 
                M_RCC_CFGR = Local_u32Temp;  /* Select HSI as system clock */
                break;

            case MRCC_enuHSE:  
                Local_u32Temp = M_RCC_CFGR;
                Local_u32Temp &= M_RCC_CFGR_SW_msk;
                Local_u32Temp |= M_RCC_CFGR_SW_HSE; 
                M_RCC_CFGR = Local_u32Temp;  /* Select HSE as system clock */
                break;

            case MRCC_enuPLL:  
                Local_u32Temp = M_RCC_CFGR;
                Local_u32Temp &= M_RCC_CFGR_SW_msk;
                Local_u32Temp |= M_RCC_CFGR_SW_PLL; 
                M_RCC_CFGR = Local_u32Temp;  /* Select PLL as system clock */
                break;

            default: Ret_enuError = MRCC_enuINVALID_CLK; break;  /* Invalid clock type */
        }
    }
    
    return Ret_enuError;  /* Return error status */
}

/* Function to configure the PLL */
MRCC_enuErrorStatus_t MRCC_enuPLL_Cfg(MRCC_structPLL_Cfg_t* Add_StructPLL)
{
    MRCC_enuErrorStatus_t Ret_enuError = MRCC_enuOK;  /* Initialize return error status */
    u32 Local_u32ClkOn = 0;
    u32 Local_u32PLLOn = 0;
    u32 Local_u32Temp = 0;
    u32 Local_u32ClkVco = 0;
    u32 Local_u32ClkPLLClkIn = 0;
    u32 Local_u32ClkVcoUsb = 0;

    Ret_enuError = MRCC_enuGetClkStatus(Add_StructPLL->ClkType, &Local_u32ClkOn);
    Ret_enuError = MRCC_enuGetClkStatus(MRCC_enuPLL, &Local_u32PLLOn);
   
    if (Local_u32ClkOn == 0)
    {
        Ret_enuError = MRCC_enuINVALID_CLK;  /* Invalid clock type */
    }
    else if (Local_u32PLLOn == 1)
    {
        Ret_enuError = MRCC_enuPLL_ON;  /* PLL is already on */
    }
    else if (Add_StructPLL == NULL)
    {
        Ret_enuError = MRCC_enuNULL_PTR;  /* Null pointer error */
    } 
    else if (Add_StructPLL->Q < 2 || Add_StructPLL->Q > 15)
    {
        Ret_enuError = MRCC_enuINVALID_PLLQ;  /* Invalid PLL Q value */
    }
    else if (Add_StructPLL->N < 2 || Add_StructPLL->N > 432)
    {
        Ret_enuError = MRCC_enuINVALID_PLLN;  /* Invalid PLL N value */
    }
    else if (Add_StructPLL->M < 2 || Add_StructPLL->M > 63)
    {
        Ret_enuError = MRCC_enuINVALID_PLLM;  /* Invalid PLL M value */
    }
    else
    {
        if (Add_StructPLL->ClkType == MRCC_enuHSI)
        {
            Local_u32ClkPLLClkIn = M_RCC_HSI_ClkHz; 
            Local_u32Temp = M_RCC_PLLCFGR;
            Local_u32Temp &= M_RCC_PLLCFGR_PLLSRC_msk;
            Local_u32Temp |= M_RCC_PLLCFGR_PLLSRC_HSI; 
            M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL source to HSI */
        }
        else
        {
            Local_u32ClkPLLClkIn = M_RCC_HSE_ClkHz; 
            Local_u32Temp = M_RCC_PLLCFGR;
            Local_u32Temp &= M_RCC_PLLCFGR_PLLSRC_msk;
            Local_u32Temp |= M_RCC_PLLCFGR_PLLSRC_HSE; 
            M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL source to HSE */
        }
        
        Local_u32ClkVco = Local_u32ClkPLLClkIn / Add_StructPLL->M;
       
        if ((Local_u32ClkVco < 1000000ULL) || (Local_u32ClkVco > 2000000ULL))
        {
            Ret_enuError = MRCC_enuINVALID_VOC;  /* Invalid VCO frequency */
        }
        else
        {
            Local_u32ClkVco *= Add_StructPLL->N;
            if ((Local_u32ClkVco < 192000000ULL) || (Local_u32ClkVco > 432000000ULL))
            {
                Ret_enuError = MRCC_enuINVALID_VOC;  /* Invalid VCO frequency */
            }
            else
            {
                Local_u32ClkVcoUsb = Local_u32ClkVco / Add_StructPLL->Q;
                Local_u32ClkVco /= Add_StructPLL->P;
                
                if (Local_u32ClkVco > 84000000ULL)
                {
                    Ret_enuError = MRCC_enuINVALID_VOC;  /* Invalid VCO frequency */
                } 
                else if (Local_u32ClkVcoUsb > 48000000ULL)
                {
                    Ret_enuError = MRCC_enuINVALID_VOC;  /* Invalid VCO USB frequency */
                } 
                else
                {
                    /* Do Nothing */
                }    
            }
        } 

        if (Ret_enuError == MRCC_enuOK)
        {
            switch (Add_StructPLL->P)
            {
                case 2: 
                    Local_u32Temp = M_RCC_PLLCFGR;
                    Local_u32Temp &= M_RCC_PLLCFGR_PLLP_msk;
                    Local_u32Temp |= M_RCC_PLLCFGR_PLLP_2; 
                    M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL P value to 2 */
                    break;

                case 4: 
                    Local_u32Temp = M_RCC_PLLCFGR;
                    Local_u32Temp &= M_RCC_PLLCFGR_PLLP_msk;
                    Local_u32Temp |= M_RCC_PLLCFGR_PLLP_4; 
                    M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL P value to 4 */
                    break;

                case 6:
                    Local_u32Temp = M_RCC_PLLCFGR;
                    Local_u32Temp &= M_RCC_PLLCFGR_PLLP_msk;
                    Local_u32Temp |= M_RCC_PLLCFGR_PLLP_6; 
                    M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL P value to 6 */
                    break;

                case 8: 
                    Local_u32Temp = M_RCC_PLLCFGR;
                    Local_u32Temp &= M_RCC_PLLCFGR_PLLP_msk;
                    Local_u32Temp |= M_RCC_PLLCFGR_PLLP_8; 
                    M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL P value to 8 */
                    break;

                default: Ret_enuError = MRCC_enuINVALID_PLLP; break;  /* Invalid PLL P value */
            }
            
            Local_u32Temp = M_RCC_PLLCFGR;
            Local_u32Temp &= M_RCC_PLLCFGR_PLLN_msk;
            Local_u32Temp |= ((Add_StructPLL->N) << 6); 
            M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL N value */
            
            Local_u32Temp = M_RCC_PLLCFGR;
            Local_u32Temp &= M_RCC_PLLCFGR_PLLQ_msk;
            Local_u32Temp |= ((Add_StructPLL->Q) << 24); 
            M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL Q value */
            
            Local_u32Temp = M_RCC_PLLCFGR;
            Local_u32Temp &= M_RCC_PLLCFGR_PLLM_msk;
            Local_u32Temp |= Add_StructPLL->M; 
            M_RCC_PLLCFGR = Local_u32Temp;  /* Set PLL M value */
        }
        else
        {
            /* Do Nothing */
        }
    }
    return Ret_enuError;  /* Return error status */
}






