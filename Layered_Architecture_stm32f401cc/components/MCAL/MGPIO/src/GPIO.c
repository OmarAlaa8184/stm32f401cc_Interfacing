#include "GPIO_PRIV.h"
#include "GPIO_INTERFACING.h"
#include "GPIO_CFG.h"


/* GPIO register structure that defines the configuration and state of GPIO pins */
typedef struct
{
  volatile u32 GPIO_MODER;   /* GPIO mode register */
  volatile u32 GPIO_OTYPER;  /* GPIO output type register */
  volatile u32 GPIO_OSPEEDR; /* GPIO output speed register */
  volatile u32 GPIO_PUPDR;   /* GPIO pull-up/pull-down register */
  volatile u32 GPIO_IDR;     /* GPIO input data register */
  volatile u32 GPIO_ODR;     /* GPIO output data register */
  volatile u32 GPIO_BSRR;    /* GPIO bit set/reset register */
  volatile u32 GPIO_LCKR;    /* GPIO configuration lock register */
  volatile u32 GPIO_AFRL;    /* GPIO alternate function low register */
  volatile u32 GPIO_AFRH;    /* GPIO alternate function high register */
} MGPIO_StructRegElments_t;

/* Macro to access base addresses of different GPIO ports */
#define MGPIO_PORTA_BASE_ADD ((MGPIO_StructRegElments_t*)(0x40020000))  /* Base address for GPIO Port A */
#define MGPIO_PORTB_BASE_ADD ((MGPIO_StructRegElments_t*)(0x40020400))  /* Base address for GPIO Port B */
#define MGPIO_PORTC_BASE_ADD ((MGPIO_StructRegElments_t*)(0x40020800))  /* Base address for GPIO Port C */
#define MGPIO_PORTD_BASE_ADD ((MGPIO_StructRegElments_t*)(0x40020C00))  /* Base address for GPIO Port D */
#define MGPIO_PORTE_BASE_ADD ((MGPIO_StructRegElments_t*)(0x40021000))  /* Base address for GPIO Port E */
#define MGPIO_PORTH_BASE_ADD ((MGPIO_StructRegElments_t*)(0x40021C00))  /* Base address for GPIO Port H */

/* Array to access different GPIO ports */
MGPIO_StructRegElments_t* MGPIO_StructArrPorts[MGPIO_NUM_OF_PORTS] =
{
    MGPIO_PORTA_BASE_ADD, /* GPIO Port A */
    MGPIO_PORTB_BASE_ADD, /* GPIO Port B */
    MGPIO_PORTC_BASE_ADD, /* GPIO Port C */
    MGPIO_PORTD_BASE_ADD, /* GPIO Port D */
    MGPIO_PORTE_BASE_ADD, /* GPIO Port E */
    MGPIO_PORTH_BASE_ADD  /* GPIO Port H */
};


/*
 * @brief  Configures the GPIO pin settings like output type, speed, pull-up/down, and alternate function.
 * @param  Adrr_structCfg: A pointer to the configuration structure containing GPIO settings.
 * @retval MGPIO_enuErrorStatus_t: Returns error status indicating the success or failure of the operation.
 * 
 * This function configures various registers for a GPIO pin including its output type, speed, pull-up/down resistors,
 * and alternate function (AF) by using the values provided in the configuration structure. The function first validates
 * the input parameters, then modifies the corresponding registers based on the pin configuration.
 */
MGPIO_enuErrorStatus_t MGPIO_enuSetCfg(MGPIO_StructCfgElments_t* Adrr_structCfg)
{
    MGPIO_enuErrorStatus_t Ret_enuError = MGPIO_enuOK;
    
    MGPIO_StructRegElments_t* GpioPort = MGPIO_StructArrPorts[Adrr_structCfg->PORT];  /* Select the correct GPIO port */
    u32 Local_u32Temp = 0;

    /* Validate the input configuration structure and parameters */
    if (Adrr_structCfg == NULL)
    {
        Ret_enuError = MGPIO_enuNULL_PTR;  /* Check if the configuration structure is a NULL pointer */
    }
    else if (Adrr_structCfg->PORT > MGPIO_enuPORTH)
    {
        Ret_enuError = MGPIO_enuINVALID_PORT;  /* Check if the port is valid */
    }
    else if (Adrr_structCfg->PIN > MGPIO_enuPIN15)
    {
        Ret_enuError = MGPIO_enuINVALID_PIN;   /* Check if the pin is valid */
    }
    else if (Adrr_structCfg->MODE > MGPIO_enuAnalog)
    {
        Ret_enuError = MGPIO_enuINVALID_MODE;  /* Check if the mode is valid */
    }
    else if (Adrr_structCfg->OutputType > MGPIO_enuOutputOpenDrain)
    {
        Ret_enuError = MGPIO_enuINVALID_OutputType;  /* Check if the output type is valid */
    }
    else if (Adrr_structCfg->SPEED > MGPIO_enuVeryHighSpeed)
    {
        Ret_enuError = MGPIO_enuINVALID_SPEED;  /* Check if the speed is valid */
    }
    else if (Adrr_structCfg->PU_PD > MGPIO_enuPullDown)
    {
        Ret_enuError = MGPIO_enuINVALID_PUPDSTATE;  /* Check if the pull-up/pull-down state is valid */
    }
    else if (Adrr_structCfg->AF > MGPIO_enuAF15)
    {
        Ret_enuError = MGPIO_enuINVALID_AF;  /* Check if the alternate function is valid */
    }
    else
    {
        /* GPIO_MODER (Mode Register): Set the pin mode (input, output, alternate function, analog) */
        Local_u32Temp = GpioPort->GPIO_MODER;
        Local_u32Temp &= Local_u32ArrMode[Adrr_structCfg->PIN];  /* Clear the mode for the pin */
        Local_u32Temp |= (Adrr_structCfg->MODE << (Adrr_structCfg->PIN * M_GPIO_PIN_REG_NUM_OFFSET));  /* Set the new mode */
        GpioPort->GPIO_MODER = Local_u32Temp;  /* Write back to the GPIO_MODER register */

        /* GPIO_OTYPER (Output Type Register): Configure the pin as push-pull or open-drain */
        Local_u32Temp = GpioPort->GPIO_OTYPER;
        Local_u32Temp &= Local_u32ArrOutputType[Adrr_structCfg->PIN];  /* Clear the output type for the pin */
        Local_u32Temp |= (Adrr_structCfg->OutputType << (Adrr_structCfg->PIN));  /* Set the new output type */
        GpioPort->GPIO_OTYPER = Local_u32Temp;  /* Write back to the GPIO_OTYPER register */

        /* GPIO_OSPEEDR (Output Speed Register): Configure the speed of the pin (low, medium, high, very high) */
        Local_u32Temp = GpioPort->GPIO_OSPEEDR;
        Local_u32Temp &= Local_u32ArrSpeed[Adrr_structCfg->PIN];  /* Clear the speed settings for the pin */
        Local_u32Temp |= (Adrr_structCfg->SPEED << (Adrr_structCfg->PIN * M_GPIO_PIN_REG_NUM_OFFSET));  /* Set the new speed */
        GpioPort->GPIO_OSPEEDR = Local_u32Temp;  /* Write back to the GPIO_OSPEEDR register */

        /* GPIO_PUPDR (Pull-up/Pull-down Register): Configure the pull-up or pull-down resistor for the pin */
        Local_u32Temp = GpioPort->GPIO_PUPDR;
        Local_u32Temp &= Local_u32ArrPUPDR[Adrr_structCfg->PIN];  /* Clear the pull-up/down settings for the pin */
        Local_u32Temp |= (Adrr_structCfg->PU_PD << (Adrr_structCfg->PIN * M_GPIO_PIN_REG_NUM_OFFSET));  /* Set the new pull-up/down state */
        GpioPort->GPIO_PUPDR = Local_u32Temp;  /* Write back to the GPIO_PUPDR register */

        /* GPIO_AFRL (Alternate Function Low Register): Configure the alternate function for pins 0-7 */
        if (Adrr_structCfg->AF < MGPIO_enuAF8 && Adrr_structCfg->PIN < MGPIO_enuPIN8)
        {
            Local_u32Temp = GpioPort->GPIO_AFRL;
            Local_u32Temp &= Local_u32ArrAF[Adrr_structCfg->PIN];  /* Clear the alternate function for the pin */
            Local_u32Temp |= (Adrr_structCfg->AF << (Adrr_structCfg->PIN * M_GPIO_AF_REG_OFFSET));  /* Set the new alternate function */
            GpioPort->GPIO_AFRL = Local_u32Temp;  /* Write back to the GPIO_AFRL register */
        }
        /* GPIO_AFRH (Alternate Function High Register): Configure the alternate function for pins 8-15 */
        else if (Adrr_structCfg->AF < MGPIO_enuAF15 && Adrr_structCfg->PIN < MGPIO_enuPIN15)
        {
            Local_u32Temp = GpioPort->GPIO_AFRH;
            Local_u32Temp &= Local_u32ArrAF[Adrr_structCfg->PIN];  /* Clear the alternate function for the pin */
            Local_u32Temp |= (Adrr_structCfg->AF << (Adrr_structCfg->PIN * M_GPIO_AF_REG_OFFSET));  /* Set the new alternate function */
            GpioPort->GPIO_AFRH = Local_u32Temp;  /* Write back to the GPIO_AFRH register */
        }
        else
        {
            Ret_enuError = MGPIO_enuINVALID_AF;  /* Invalid alternate function or pin number */
        }
    }

    return Ret_enuError;
}


/*
 * @brief  Sets the state (high or low) of a specific GPIO pin.
 * @param  Copy_enuPort: The GPIO port number (e.g., GPIOA, GPIOB).
 * @param  Copy_enuPin: The GPIO pin number (e.g., PIN0, PIN1).
 * @param  Copy_u32Value: The value to set (MGPIO_enuLOWPIN or MGPIO_enuHIGHPIN).
 * @retval MGPIO_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 * 
 * This function sets a GPIO pin to either a low or high state by modifying the corresponding bit in the
 * GPIO's output data register (GPIO_ODR). It checks the port, pin, and value before applying the change.
 */
MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue(MGPIO_enuPortNum_t Copy_enuPort, MGPIO_enuPinNum_t Copy_enuPin, MGPIO_enuPinState Copy_u32Value)
{
    MGPIO_enuErrorStatus_t Ret_enuError = MGPIO_enuOK;

    MGPIO_StructRegElments_t* GpioPort = MGPIO_StructArrPorts[Copy_enuPort];  /* Get GPIO port */
    u32 Local_u32Temp = 0;

    /* Validate the input parameters */
    if (Copy_enuPort > MGPIO_enuPORTH)
    {
        Ret_enuError = MGPIO_enuINVALID_PORT;  /* Invalid port number */
    }
    else if (Copy_enuPin > MGPIO_enuPIN15)
    {
        Ret_enuError = MGPIO_enuINVALID_PIN;   /* Invalid pin number */
    }
    else if (Copy_u32Value > MGPIO_enuHIGHPIN)
    {
        Ret_enuError = MGPIO_enuINVALID_STATE; /* Invalid pin state */
    }
    else
    {
        /* Set the pin to low or high based on the provided value */
        if (Copy_u32Value == MGPIO_enuLOWPIN)
        {
            Local_u32Temp = GpioPort->GPIO_ODR;
            Local_u32Temp &= ((M_GPIO_ODR_msk) << Copy_enuPin);  /* Clear the pin value */
            Local_u32Temp |= ((MGPIO_enuLOWPIN) << Copy_enuPin);  /* Set the pin to low */
            GpioPort->GPIO_ODR = Local_u32Temp;
        }
        else if (Copy_u32Value == MGPIO_enuHIGHPIN)
        {
            Local_u32Temp = GpioPort->GPIO_ODR;
            Local_u32Temp &= ((M_GPIO_ODR_msk) << Copy_enuPin);  /* Clear the pin value */
            Local_u32Temp |= ((MGPIO_enuHIGHPIN) << Copy_enuPin);  /* Set the pin to high */
            GpioPort->GPIO_ODR = Local_u32Temp;
        }
        else
        {
            Ret_enuError = MGPIO_enuINVALID_STATE;  /* Invalid state (not high or low) */
        }
    }

    return Ret_enuError;
}

/*
 * @brief  Reads the state of a specific GPIO pin (high or low).
 * @param  Copy_enuPort: The GPIO port number (e.g., GPIOA, GPIOB).
 * @param  Copy_enuPin: The GPIO pin number (e.g., PIN0, PIN1).
 * @param  Copy_u32AddValue: Pointer to store the value of the pin (high or low).
 * @retval MGPIO_enuErrorStatus_t: Return status indicating the success or failure of the operation.
 * 
 * This function reads the current value of a specific GPIO pin by accessing the GPIO input data register 
 * (GPIO_IDR) and returns the value (either high or low) through the provided pointer.
 */
MGPIO_enuErrorStatus_t MGPIO_enuGetPinValue(MGPIO_enuPortNum_t Copy_enuPort, MGPIO_enuPinNum_t Copy_enuPin, u32* Copy_u32AddValue)
{
    MGPIO_enuErrorStatus_t Ret_enuError = MGPIO_enuOK;

    MGPIO_StructRegElments_t* GpioPort = MGPIO_StructArrPorts[Copy_enuPort];  /* Get GPIO port */

    /* Validate input parameters */
    if (Copy_u32AddValue == NULL)
    {
        Ret_enuError = MGPIO_enuNULL_PTR;  /* Null pointer error */
    }
    else if (Copy_enuPort > MGPIO_enuPORTH)
    {
        Ret_enuError = MGPIO_enuINVALID_PORT;  /* Invalid port number */
    }
    else if (Copy_enuPin > MGPIO_enuPIN15)
    {
        Ret_enuError = MGPIO_enuINVALID_PIN;   /* Invalid pin number */
    }
    else
    {
        *Copy_u32AddValue = GET_BIT(GpioPort->GPIO_IDR, Copy_enuPin);  /* Get the pin value (high or low) */
    }

    return Ret_enuError;
}

