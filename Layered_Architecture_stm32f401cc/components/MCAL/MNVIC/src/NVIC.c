
#include "NVIC_INTERFACING.h"

/* Define a structure to represent the NVIC registers */
typedef struct
{
  volatile u32 NVIC_ISER[8];         /* Interrupt Set Enable Registers (8 registers, 32 bits each) */
  const volatile u32 NVIC_RSE1[24];  /* Reserved space (24 registers) */
  volatile u32 NVIC_ICER[8];         /* Interrupt Clear Enable Registers (8 registers, 32 bits each) */
  const volatile u32 NVIC_RSE2[24];  /* Reserved space (24 registers) */
  volatile u32 NVIC_ISPR[8];         /* Interrupt Set Pending Registers (8 registers, 32 bits each) */
  const volatile u32 NVIC_RSE3[24];  /* Reserved space (24 registers) */
  volatile u32 NVIC_ICPR[8];         /* Interrupt Clear Pending Registers (8 registers, 32 bits each) */
  const volatile u32 NVIC_RSE4[24];  /* Reserved space (24 registers) */
  volatile u32 NVIC_IABR[8];         /* Interrupt Active Bit Registers (8 registers, 32 bits each) */
  const volatile u32 NVIC_RSE5[56];  /* Reserved space (56 registers) */
  volatile u8 NVIC_IPR[240];         /* Interrupt Priority Registers (240 registers, 8 bits each) */
  const volatile u32 NVIC_RSE6[644]; /* Reserved space (644 registers) */
  volatile u32 NVIC_STIR;            /* Software Trigger Interrupt Register */
} MNVIC_StructRegElments_t;

/* Define the base address of the NVIC registers */
#define MNVIC_BASE_ADD ((MNVIC_StructRegElments_t*)(0xE000E100))

/* Define the address of the Application Interrupt and Reset Control Register (AIRCR) */
#define MSCB_AIRCR_ADD *((volatile u32*)(0xE000ED0C))

/* Function to enable an interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuEnableIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32BITNUM = Copy_enuIRQ % 32;           /* Calculate the bit position in the register */
    u32 Local_u32REGNUM = Copy_enuIRQ / 32;           /* Calculate the register index */
    
    /* Check if the IRQ number is valid */
    if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Enable the interrupt by setting the corresponding bit in the NVIC_ISER register */
        MNVIC_BASE_ADD->NVIC_ISER[Local_u32REGNUM] |= (1 << Local_u32BITNUM);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to disable an interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuDisableIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32BITNUM = Copy_enuIRQ % 32;           /* Calculate the bit position in the register */
    u32 Local_u32REGNUM = Copy_enuIRQ / 32;           /* Calculate the register index */
    
    /* Check if the IRQ number is valid */
    if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Disable the interrupt by setting the corresponding bit in the NVIC_ICER register */
        MNVIC_BASE_ADD->NVIC_ICER[Local_u32REGNUM] |= (1 << Local_u32BITNUM);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to set an interrupt as pending */
MNVIC_enuErrorStatus_t MNVIC_enuSetPendingIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32BITNUM = Copy_enuIRQ % 32;           /* Calculate the bit position in the register */
    u32 Local_u32REGNUM = Copy_enuIRQ / 32;           /* Calculate the register index */
    
    /* Check if the IRQ number is valid */
    if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Set the interrupt as pending by setting the corresponding bit in the NVIC_ISPR register */
        MNVIC_BASE_ADD->NVIC_ISPR[Local_u32REGNUM] |= (1 << Local_u32BITNUM);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to clear a pending interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuClearPendingIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32BITNUM = Copy_enuIRQ % 32;           /* Calculate the bit position in the register */
    u32 Local_u32REGNUM = Copy_enuIRQ / 32;           /* Calculate the register index */
    
    /* Check if the IRQ number is valid */
    if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Clear the pending interrupt by setting the corresponding bit in the NVIC_ICPR register */
        MNVIC_BASE_ADD->NVIC_ICPR[Local_u32REGNUM] |= (1 << Local_u32BITNUM);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to get the pending status of an interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuGetPendingIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ, u32* Add_pu32BitValue)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32BITNUM = Copy_enuIRQ % 32;           /* Calculate the bit position in the register */
    u32 Local_u32REGNUM = Copy_enuIRQ / 32;           /* Calculate the register index */
    
    /* Check if the pointer to store the result is valid */
    if (Add_pu32BitValue == NULL)
    {
        Ret_enuError = MNVIC_enuNULL_PTR; /* Set error status if pointer is NULL */
    }
    
    /* Check if the IRQ number is valid */
    if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Get the pending status of the interrupt from the NVIC_ISPR register */
        *Add_pu32BitValue = GET_BIT(MNVIC_BASE_ADD->NVIC_ISPR[Local_u32REGNUM], Local_u32BITNUM);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to get the active status of an interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuGetActiveIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ, u32* Add_pu32BitValue)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32BITNUM = Copy_enuIRQ % 32;           /* Calculate the bit position in the register */
    u32 Local_u32REGNUM = Copy_enuIRQ / 32;           /* Calculate the register index */
    
    /* Check if the pointer to store the result is valid */
    if (Add_pu32BitValue == NULL)
    {
        Ret_enuError = MNVIC_enuNULL_PTR; /* Set error status if pointer is NULL */
    }
    /* Check if the IRQ number is valid */
    else if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Get the active status of the interrupt from the NVIC_IABR register */
        *Add_pu32BitValue = GET_BIT(MNVIC_BASE_ADD->NVIC_IABR[Local_u32REGNUM], Local_u32BITNUM);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to set the priority of an interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ, u8 Copy_u32PriorityValue)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u8 Local_u8TEMP = 0; /* Temporary variable to manipulate priority value */
    
    /* Check if the IRQ number is valid */
    if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    /* Check if the priority value is valid */
    else if (Copy_u32PriorityValue > 15)
    {
        Ret_enuError = MNVIC_enuINVALID_PRIORITY; /* Set error status if priority is invalid */
    }
    else
    {
        /* Read the current priority value */
        Local_u8TEMP = MNVIC_BASE_ADD->NVIC_IPR[Copy_enuIRQ];
        /* Clear the existing priority bits */
        Local_u8TEMP &= MNVIC_IPR_REG_msk;
        /* Set the new priority value */
        Local_u8TEMP |= Copy_u32PriorityValue << 4;
        /* Write the updated priority value back to the NVIC_IPR register */
        MNVIC_BASE_ADD->NVIC_IPR[Copy_enuIRQ] = Local_u8TEMP;
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to get the priority of an interrupt */
MNVIC_enuErrorStatus_t MNVIC_enuGetPriorityIRQ(MNVIC_enuIRQ_Type_t Copy_enuIRQ, u8* Add_pu32BitValue)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    
    /* Check if the pointer to store the result is valid */
    if (Add_pu32BitValue == NULL)
    {
        Ret_enuError = MNVIC_enuNULL_PTR; /* Set error status if pointer is NULL */
    }
    /* Check if the IRQ number is valid */
    else if (Copy_enuIRQ > MNVIC_MAX_NUM_IRQ)
    {
        Ret_enuError = MNVIC_enuINVALID_IRQ; /* Set error status if IRQ is invalid */
    }
    else
    {
        /* Get the priority value from the NVIC_IPR register */
        *Add_pu32BitValue = GET_HIGH_NIB(MNVIC_BASE_ADD->NVIC_IPR[Copy_enuIRQ]);
    }
    
    return Ret_enuError; /* Return the status */
}

/* Function to set the priority grouping */
MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityGrouping(MNVIC_enuPriorityGrouping_t Copy_enuPriorityGrouping)
{
    MNVIC_enuErrorStatus_t Ret_enuError = MNVIC_enuOK; /* Initialize return status to OK */
    u32 Local_u32TEMP = 0; /* Temporary variable to manipulate AIRCR value */
    
    /* Check if the priority grouping value is valid */
    if (Copy_enuPriorityGrouping > MNVIC_enuAllSub)
    {
        Ret_enuError = MNVIC_enuINVALID_PRIORITYGrouping; /* Set error status if grouping is invalid */
    }
    else
    {
        /* Read the current value of the AIRCR register */
        Local_u32TEMP = MSCB_AIRCR_ADD;
        /* Clear the existing priority grouping bits */
        Local_u32TEMP &= MSCB_AIRCR_REG_msk;
        /* Set the new priority grouping value */
        Local_u32TEMP |= Copy_enuPriorityGrouping;
        /* Write the updated value back to the AIRCR register */
        MSCB_AIRCR_ADD = Local_u32TEMP;
    }
    
    return Ret_enuError; /* Return the status */
}