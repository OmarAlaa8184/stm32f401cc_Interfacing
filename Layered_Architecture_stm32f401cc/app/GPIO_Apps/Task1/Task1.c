

#include "RCC_INTERFACING.h"
#include "GPIO_INTERFACING.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Task1.h"


int main(void)
{ 

    while (1) 
    {
	  FlashLed();
	  
    }
}


void FlashLed (void)
{

    MRCC_structEnablePeripheral_t app0={MRCC_enuAHB1,GPIOA,0,0,0};
	MRCC_structEnablePeripheral_t app4={MRCC_enuAHB1,GPIOB,0,0,0};
	MGPIO_StructCfgElments_t app1={
		                           MGPIO_enuPORTA,
	                               MGPIO_enuPIN7,
	                               MGPIO_enuOutput,
	                               MGPIO_enuOutputPushPull,
	                               MGPIO_enuMediumSpeed,
	                               MGPIO_enuPullUp,
	                               MGPIO_enuAF0
								   };
	MGPIO_StructCfgElments_t app2={MGPIO_enuPORTB,
	                               MGPIO_enuPIN15,
	                               MGPIO_enuInput,
	                               MGPIO_enuOutputPushPull,
	                               MGPIO_enuMediumSpeed,
	                               MGPIO_enuPullUp,
	                               MGPIO_enuAF0
								   };
     u32 ADD;
     MRCC_enuEnableClk(MRCC_enuHSE);
     MRCC_enuSelectClk(MRCC_enuHSE);
     MRCC_enuEnablePeripherals(app0);
     MRCC_enuEnablePeripherals(app4);
     MGPIO_enuSetCfg(&app1);
	 MGPIO_enuSetCfg(&app2);
	 while (1)
	 {
	  	MGPIO_enuGetPinValue(MGPIO_enuPORTB,MGPIO_enuPIN15,&ADD);  

	    if (ADD==1)
		{
		   MGPIO_enuSetPinValue(MGPIO_enuPORTA,MGPIO_enuPIN7,MGPIO_enuLOWPIN);
		}
		else
		{
           
		   MGPIO_enuSetPinValue(MGPIO_enuPORTA,MGPIO_enuPIN7,MGPIO_enuHIGHPIN); 
		}
		
	 
	 }


}


