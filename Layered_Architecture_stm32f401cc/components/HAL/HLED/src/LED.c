/*
 * LED.C
 *
 * Created: 1/2/2025
 *  Author: Omar Alaa
 */ 

#include "GPIO_INTERFACING.h"
#include "LED_INTERFACING.h"
#include "LED_CFG.h"


/* 
 * External declaration of the LED configuration array.
 * This array contains the port and pin configuration for each LED in the system.
 */
extern HLED_sLedCfg_t HLED_sArrLedCfg[HLED_NUM_OF_LEDS];

/* 
 * Function: HLED_vInit
 * --------------------
 * Initializes the direction of all LEDs in the system.
 * Each LED's port and pin are retrieved from the configuration array and set to output.
 */
void HLED_vInit(void)
{
     /* Iterate through all LEDs in the configuration array */
    for (u32 Local_u32Conter = 0; Local_u32Conter < HLED_NUM_OF_LEDS; Local_u32Conter++)
    {
       /*Set Configuration for MGPIO_enuSetCfg Function */ 
     MGPIO_StructCfgElments_t Local_StructLed={
                                                .PORT=HLED_sArrLedCfg[Local_u32Conter].port,
                                                .PIN=HLED_sArrLedCfg[Local_u32Conter].pin,
                                                .MODE=MGPIO_enuOutput,
                                                .OutputType=HLED_sArrLedCfg[Local_u32Conter].OutputType,
                                                .SPEED=MGPIO_enuMediumSpeed,
                                                .PU_PD=MGPIO_enuPullUp,
                                                .AF=MGPIO_enuAF0,
                                             };
        MGPIO_enuSetCfg(&Local_StructLed);
    }
}

/* 
 * Function: HLED_enuSetLedState
 * -----------------------------
 * Sets the state (ON/OFF) of a specific LED.
 * 
 * Parameters:
 *   Copy_u32LedNum - The LED number to control (e.g., LED_0 to LED_7).
 *   Copy_u32State  - The desired state of the LED (HLED_LED_ON or HLED_LED_OFF).
 * 
 * Returns:
 *   HLED_enuErrorStatus_t - Error status indicating success or failure:
 *      - HLED_enuOK for success
 *      - HLED_enuINVALID_LED_NUM if the LED number is invalid
 *      - HLED_enuSTATE if the state value is invalid
 */
HLED_enuErrorStatus_t HLED_enuSetLedState(u32 Copy_u32LedNum, u32 Copy_u32State)
{
    HLED_enuErrorStatus_t Ret_enuError = HLED_enuNOK; /* Default return error status */

    /* Validate LED number */
    if (Copy_u32LedNum > LED_7 || Copy_u32LedNum < LED_0)
    {
        Ret_enuError = HLED_enuINVALID_LED_NUM;
    }
    /* Validate LED state */
    else if (Copy_u32State > HLED_LED_ON || Copy_u32State < HLED_LED_OFF)
    {
        Ret_enuError = HLED_enuSTATE;
    }
    else
    {   
        Ret_enuError = HLED_enuOK; /* Update return status to success */
        
        /* Set the pin value for the specified LED based on the desired state */
       MGPIO_enuSetPinValue(HLED_sArrLedCfg[Copy_u32LedNum].port,HLED_sArrLedCfg[Copy_u32LedNum].pin,Copy_u32State);
    }

    return Ret_enuError; /* Return the error status */
}
