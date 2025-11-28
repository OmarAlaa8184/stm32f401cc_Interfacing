#ifndef GPIO_INTERFACING_H_
#define GPIO_INTERFACING_H_


#include "BIT_MATH.h"
#include "STD_TYPES.h"



/* Enum for GPIO port numbers */
typedef enum
{
	MGPIO_enuPORTA,  /* GPIO Port A */
	MGPIO_enuPORTB,  /* GPIO Port B */
	MGPIO_enuPORTC,  /* GPIO Port C */
	MGPIO_enuPORTD,  /* GPIO Port D */
	MGPIO_enuPORTE,  /* GPIO Port E */
	MGPIO_enuPORTH   /* GPIO Port H */
	
} MGPIO_enuPortNum_t;

/* Enum for GPIO pin numbers */
typedef enum
{
	MGPIO_enuPIN0,   /* GPIO Pin 0 */
	MGPIO_enuPIN1,   /* GPIO Pin 1 */
	MGPIO_enuPIN2,   /* GPIO Pin 2 */
	MGPIO_enuPIN3,   /* GPIO Pin 3 */
	MGPIO_enuPIN4,   /* GPIO Pin 4 */
	MGPIO_enuPIN5,   /* GPIO Pin 5 */
	MGPIO_enuPIN6,   /* GPIO Pin 6 */
	MGPIO_enuPIN7,   /* GPIO Pin 7 */
	MGPIO_enuPIN8,   /* GPIO Pin 8 */
	MGPIO_enuPIN9,   /* GPIO Pin 9 */
	MGPIO_enuPIN10,  /* GPIO Pin 10 */
	MGPIO_enuPIN11,  /* GPIO Pin 11 */
	MGPIO_enuPIN12,  /* GPIO Pin 12 */
	MGPIO_enuPIN13,  /* GPIO Pin 13 */
	MGPIO_enuPIN14,  /* GPIO Pin 14 */
	MGPIO_enuPIN15   /* GPIO Pin 15 */
	
} MGPIO_enuPinNum_t;

/* Enum for GPIO modes */
typedef enum
{
	MGPIO_enuInput,              /* GPIO Input mode */
	MGPIO_enuOutput,             /* GPIO Output mode */
	MGPIO_enuAlternate_function, /* GPIO Alternate function mode */
    MGPIO_enuAnalog              /* GPIO Analog mode */
	
} MGPIO_enuMODE_t;

/* Enum for GPIO output types */
typedef enum
{
   MGPIO_enuOutputPushPull,  /* GPIO Output push-pull */
   MGPIO_enuOutputOpenDrain  /* GPIO Output open-drain */
	
} MGPIO_enuOutputType_t;

/* Enum for GPIO speed */
typedef enum 
{
	MGPIO_enuLowSpeed,       /* GPIO Low speed */
    MGPIO_enuMediumSpeed,    /* GPIO Medium speed */
    MGPIO_enuHighSpeed,      /* GPIO High speed */
    MGPIO_enuVeryHighSpeed   /* GPIO Very high speed */

} MGPIO_enuSpeed_t;

/* Enum for GPIO pull-up/pull-down */
typedef enum
{
    MGPIO_NoUpDown,    /* No pull-up/pull-down */
    MGPIO_enuPullUp,   /* Pull-up */
    MGPIO_enuPullDown, /* Pull-down */
    MGPIO_Reserved     /* Reserved */

} MGPIO_enuPuPd_t;

/* Enum for GPIO alternate functions */
typedef enum 
{
   MGPIO_enuAF0,   /* GPIO Alternate function 0 */
   MGPIO_enuAF1,   /* GPIO Alternate function 1 */
   MGPIO_enuAF2,   /* GPIO Alternate function 2 */
   MGPIO_enuAF3,   /* GPIO Alternate function 3 */
   MGPIO_enuAF4,   /* GPIO Alternate function 4 */
   MGPIO_enuAF5,   /* GPIO Alternate function 5 */
   MGPIO_enuAF6,   /* GPIO Alternate function 6 */
   MGPIO_enuAF7,   /* GPIO Alternate function 7 */
   MGPIO_enuAF8,   /* GPIO Alternate function 8 */
   MGPIO_enuAF9,   /* GPIO Alternate function 9 */
   MGPIO_enuAF10,  /* GPIO Alternate function 10 */
   MGPIO_enuAF11,  /* GPIO Alternate function 11 */
   MGPIO_enuAF12,  /* GPIO Alternate function 12 */
   MGPIO_enuAF13,  /* GPIO Alternate function 13 */
   MGPIO_enuAF14,  /* GPIO Alternate function 14 */
   MGPIO_enuAF15   /* GPIO Alternate function 15 */

} MGPIO_enuAlternateFunction_t;

/* Enum for GPIO pin states */
typedef enum
{
   MGPIO_enuLOWPIN,  /* GPIO Low pin state */
   MGPIO_enuHIGHPIN  /* GPIO High pin state */
	
} MGPIO_enuPinState;

/* Enum for GPIO error statuses */
typedef enum
{ 
	MGPIO_enuOK,                /* Operation successful */
	MGPIO_enuNOK,               /* Operation failed */
	MGPIO_enuINVALID_INPUT,     /* Invalid input */
	MGPIO_enuINVALID_OutputType,/* Invalid output type */
	MGPIO_enuINVALID_PORT,      /* Invalid port */
	MGPIO_enuINVALID_PIN,       /* Invalid pin */
	MGPIO_enuINVALID_MODE,      /* Invalid mode */
	MGPIO_enuINVALID_SPEED,     /* Invalid speed */
	MGPIO_enuINVALID_PUPDSTATE, /* Invalid pull-up/pull-down state */
	MGPIO_enuINVALID_AF,        /* Invalid alternate function */
	MGPIO_enuINVALID_STATE,     /* Invalid state */
	MGPIO_enuNULL_PTR           /* Null pointer */
	
} MGPIO_enuErrorStatus_t;

/* Struct for GPIO configuration elements */
typedef struct
{
  MGPIO_enuPortNum_t           PORT;       /* GPIO port number */
  MGPIO_enuPinNum_t            PIN;        /* GPIO pin number */
  MGPIO_enuMODE_t              MODE;       /* GPIO mode */
  MGPIO_enuOutputType_t        OutputType; /* GPIO output type */
  MGPIO_enuSpeed_t             SPEED;      /* GPIO speed */
  MGPIO_enuPuPd_t              PU_PD;      /* GPIO pull-up/pull-down */
  MGPIO_enuAlternateFunction_t AF;         /* GPIO alternate function */

} MGPIO_StructCfgElments_t;



/*
 * @brief  Sets the configuration of a GPIO pin according to the parameters
 *         specified in the structure.
 * @param  Adrr_structCfg: Pointer to a structure that contains the configuration details
 *         for the GPIO pin (e.g., mode, speed, pull-up/pull-down, output type, etc.).
 * @retval MGPIO_enuErrorStatus_t: Return value indicating the success or failure of the operation.
 */
MGPIO_enuErrorStatus_t MGPIO_enuSetCfg(MGPIO_StructCfgElments_t* Adrr_structCfg);


/*
 * @brief  Sets the value (HIGH or LOW) of a specific GPIO pin on a given port.
 * @param  Copy_enuPort: The GPIO port number (e.g., Port A, Port B).
 * @param  Copy_enuPin: The pin number within the specified port (e.g., Pin 0, Pin 1).
 * @param  Copy_u32Value: The value to set the pin to (0 for LOW, 1 for HIGH).
 * @retval MGPIO_enuErrorStatus_t: Return value indicating the success or failure of the operation.
 */
MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue(MGPIO_enuPortNum_t Copy_enuPort, MGPIO_enuPinNum_t Copy_enuPin,MGPIO_enuPinState Copy_u32Value);


/*
 * @brief  Retrieves the current value (HIGH or LOW) of a specific GPIO pin on a given port.
 * @param  Copy_enuPort: The GPIO port number (e.g., Port A, Port B).
 * @param  Copy_enuPin: The pin number within the specified port (e.g., Pin 0, Pin 1).
 * @param  Copy_u32AddValue: A pointer to a variable where the current pin value (0 or 1) will be stored.
 * @retval MGPIO_enuErrorStatus_t: Return value indicating the success or failure of the operation.
 */
MGPIO_enuErrorStatus_t MGPIO_enuGetPinValue(MGPIO_enuPortNum_t Copy_enuPort,MGPIO_enuPinNum_t Copy_enuPin,u32 *Copy_u32AddValue);
                                           
                                            



#endif /* GPIO_INTERFACING_H_ */