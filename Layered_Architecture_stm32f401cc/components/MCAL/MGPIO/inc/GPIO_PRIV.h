#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#define M_GPIO_PIN_OFFSET            1  /* Offset for GPIO pin */
#define M_GPIO_PIN_REG_NUM_OFFSET    2  /* Offset for GPIO pin register number */
#define M_GPIO_AF_REG_OFFSET         4  /* Offset for GPIO alternate function register */

/* Masks for GPIO mode register */
#define M_GPIO_MODER_MODER0_msk      0xFFFFFFFCUL  /* Mask for GPIO mode register 0 */
#define M_GPIO_MODER_MODER1_msk      0xFFFFFFF3UL  /* Mask for GPIO mode register 1 */
#define M_GPIO_MODER_MODER2_msk      0xFFFFFFCFUL  /* Mask for GPIO mode register 2 */
#define M_GPIO_MODER_MODER3_msk      0xFFFFFF3FUL  /* Mask for GPIO mode register 3 */
#define M_GPIO_MODER_MODER4_msk      0xFFFFFCFFUL  /* Mask for GPIO mode register 4 */
#define M_GPIO_MODER_MODER5_msk      0xFFFFF3FFUL  /* Mask for GPIO mode register 5 */
#define M_GPIO_MODER_MODER6_msk      0xFFFFCFFFUL  /* Mask for GPIO mode register 6 */
#define M_GPIO_MODER_MODER7_msk      0xFFFF3FFFUL  /* Mask for GPIO mode register 7 */
#define M_GPIO_MODER_MODER8_msk      0xFFFCFFFFUL  /* Mask for GPIO mode register 8 */
#define M_GPIO_MODER_MODER9_msk      0xFFF3FFFFUL  /* Mask for GPIO mode register 9 */
#define M_GPIO_MODER_MODER10_msk     0xFFCFFFFFUL  /* Mask for GPIO mode register 10 */
#define M_GPIO_MODER_MODER11_msk     0xFF3FFFFFUL  /* Mask for GPIO mode register 11 */
#define M_GPIO_MODER_MODER12_msk     0xFCFFFFFFUL  /* Mask for GPIO mode register 12 */
#define M_GPIO_MODER_MODER13_msk     0xF3FFFFFFUL  /* Mask for GPIO mode register 13 */
#define M_GPIO_MODER_MODER14_msk     0xCFFFFFFFUL  /* Mask for GPIO mode register 14 */
#define M_GPIO_MODER_MODER15_msk     0x3FFFFFFFUL  /* Mask for GPIO mode register 15 */

/* Masks for GPIO output type register */
#define M_GPIO_OTYPER_OT0_msk        0x0000FFFEUL  /* Mask for GPIO output type register 0 */
#define M_GPIO_OTYPER_OT1_msk        0x0000FFFDUL  /* Mask for GPIO output type register 1 */
#define M_GPIO_OTYPER_OT2_msk        0x0000FFFBUL  /* Mask for GPIO output type register 2 */
#define M_GPIO_OTYPER_OT3_msk        0x0000FFF7UL  /* Mask for GPIO output type register 3 */
#define M_GPIO_OTYPER_OT4_msk        0x0000FFEFUL  /* Mask for GPIO output type register 4 */
#define M_GPIO_OTYPER_OT5_msk        0x0000FFDFUL  /* Mask for GPIO output type register 5 */
#define M_GPIO_OTYPER_OT6_msk        0x0000FFBFUL  /* Mask for GPIO output type register 6 */
#define M_GPIO_OTYPER_OT7_msk        0x0000FF7FUL  /* Mask for GPIO output type register 7 */
#define M_GPIO_OTYPER_OT8_msk        0x0000FEFFUL  /* Mask for GPIO output type register 8 */
#define M_GPIO_OTYPER_OT9_msk        0x0000FDFFUL  /* Mask for GPIO output type register 9 */
#define M_GPIO_OTYPER_OT10_msk       0x0000FBFFUL  /* Mask for GPIO output type register 10 */
#define M_GPIO_OTYPER_OT11_msk       0x0000F7FFUL  /* Mask for GPIO output type register 11 */
#define M_GPIO_OTYPER_OT12_msk       0x0000EFFFUL  /* Mask for GPIO output type register 12 */
#define M_GPIO_OTYPER_OT13_msk       0x0000DFEFUL  /* Mask for GPIO output type register 13 */
#define M_GPIO_OTYPER_OT14_msk       0x0000BFFFUL  /* Mask for GPIO output type register 14 */
#define M_GPIO_OTYPER_OT15_msk       0x00007FFFUL  /* Mask for GPIO output type register 15 */

/* Masks for GPIO speed register */
#define M_GPIO_OSPEEDR_OSPEEDR0_msk  0xFFFFFFFCUL  /* Mask for GPIO speed register 0 */
#define M_GPIO_OSPEEDR_OSPEEDR1_msk  0xFFFFFFF3UL  /* Mask for GPIO speed register 1 */
#define M_GPIO_OSPEEDR_OSPEEDR2_msk  0xFFFFFFCFUL  /* Mask for GPIO speed register 2 */
#define M_GPIO_OSPEEDR_OSPEEDR3_msk  0xFFFFFF3FUL  /* Mask for GPIO speed register 3 */
#define M_GPIO_OSPEEDR_OSPEEDR4_msk  0xFFFFFCFFUL  /* Mask for GPIO speed register 4 */
#define M_GPIO_OSPEEDR_OSPEEDR5_msk  0xFFFFF3FFUL  /* Mask for GPIO speed register 5 */
#define M_GPIO_OSPEEDR_OSPEEDR6_msk  0xFFFFCFFFUL  /* Mask for GPIO speed register 6 */
#define M_GPIO_OSPEEDR_OSPEEDR7_msk  0xFFFF3FFFUL  /* Mask for GPIO speed register 7 */
#define M_GPIO_OSPEEDR_OSPEEDR8_msk  0xFFFCFFFFUL  /* Mask for GPIO speed register 8 */
#define M_GPIO_OSPEEDR_OSPEEDR9_msk  0xFFF3FFFFUL  /* Mask for GPIO speed register 9 */
#define M_GPIO_OSPEEDR_OSPEEDR10_msk 0xFFCFFFFFUL  /* Mask for GPIO speed register 10 */
#define M_GPIO_OSPEEDR_OSPEEDR11_msk 0xFF3FFFFFUL  /* Mask for GPIO speed register 11 */
#define M_GPIO_OSPEEDR_OSPEEDR12_msk 0xFCFFFFFFUL  /* Mask for GPIO speed register 12 */
#define M_GPIO_OSPEEDR_OSPEEDR13_msk 0xF3FFFFFFUL  /* Mask for GPIO speed register 13 */
#define M_GPIO_OSPEEDR_OSPEEDR14_msk 0xCFFFFFFFUL  /* Mask for GPIO speed register 14 */
#define M_GPIO_OSPEEDR_OSPEEDR15_msk 0x3FFFFFFFUL  /* Mask for GPIO speed register 15 */

/* Masks for GPIO pull-up/pull-down register */
#define M_GPIO_PUPDR_PUPDR0_msk      0xFFFFFFFCUL  /* Mask for GPIO pull-up/pull-down register 0 */
#define M_GPIO_PUPDR_PUPDR1_msk      0xFFFFFFF3UL  /* Mask for GPIO pull-up/pull-down register 1 */
#define M_GPIO_PUPDR_PUPDR2_msk      0xFFFFFFCFUL  /* Mask for GPIO pull-up/pull-down register 2 */
#define M_GPIO_PUPDR_PUPDR3_msk      0xFFFFFF3FUL  /* Mask for GPIO pull-up/pull-down register 3 */
#define M_GPIO_PUPDR_PUPDR4_msk      0xFFFFFCFFUL  /* Mask for GPIO pull-up/pull-down register 4 */
#define M_GPIO_PUPDR_PUPDR5_msk      0xFFFFF3FFUL  /* Mask for GPIO pull-up/pull-down register 5 */
#define M_GPIO_PUPDR_PUPDR6_msk      0xFFFFCFFFUL  /* Mask for GPIO pull-up/pull-down register 6 */
#define M_GPIO_PUPDR_PUPDR7_msk      0xFFFF3FFFUL  /* Mask for GPIO pull-up/pull-down register 7 */
#define M_GPIO_PUPDR_PUPDR8_msk      0xFFFCFFFFUL  /* Mask for GPIO pull-up/pull-down register 8 */
#define M_GPIO_PUPDR_PUPDR9_msk      0xFFF3FFFFUL  /* Mask for GPIO pull-up/pull-down register 9 */
#define M_GPIO_PUPDR_PUPDR10_msk     0xFFCFFFFFUL  /* Mask for GPIO pull-up/pull-down register 10 */
#define M_GPIO_PUPDR_PUPDR11_msk     0xFF3FFFFFUL  /* Mask for GPIO pull-up/pull-down register 11 */
#define M_GPIO_PUPDR_PUPDR12_msk     0xFCFFFFFFUL  /* Mask for GPIO pull-up/pull-down register 12 */
#define M_GPIO_PUPDR_PUPDR13_msk     0xF3FFFFFFUL  /* Mask for GPIO pull-up/pull-down register 13 */
#define M_GPIO_PUPDR_PUPDR14_msk     0xCFFFFFFFUL  /* Mask for GPIO pull-up/pull-down register 14 */
#define M_GPIO_PUPDR_PUPDR15_msk     0x3FFFFFFFUL  /* Mask for GPIO pull-up/pull-down register 15 */


/* Masks for GPIO alternate function low register */
#define M_GPIO_AFL_AFL0_msk      0xFFFFFFF0UL  /* Mask for GPIO alternate function low register 0 */
#define M_GPIO_AFL_AFL1_msk      0xFFFFFF0FUL  /* Mask for GPIO alternate function low register 1 */
#define M_GPIO_AFL_AFL2_msk      0xFFFFF0FFUL  /* Mask for GPIO alternate function low register 2 */
#define M_GPIO_AFL_AFL3_msk      0xFFFF0FFFUL  /* Mask for GPIO alternate function low register 3 */
#define M_GPIO_AFL_AFL4_msk      0xFFF0FFFFUL  /* Mask for GPIO alternate function low register 4 */
#define M_GPIO_AFL_AFL5_msk      0xFF0FFFFFUL  /* Mask for GPIO alternate function low register 5 */
#define M_GPIO_AFL_AFL6_msk      0xF0FFFFFFUL  /* Mask for GPIO alternate function low register 6 */
#define M_GPIO_AFL_AFL7_msk      0x0FFFFFFFUL  /* Mask for GPIO alternate function low register 7 */

/* Masks for GPIO alternate function high register */
#define M_GPIO_AFH_AFH8_msk      0xFFFFFFF0UL  /* Mask for GPIO alternate function high register 8 */
#define M_GPIO_AFH_AFH9_msk      0xFFFFFF0FUL  /* Mask for GPIO alternate function high register 9 */
#define M_GPIO_AFH_AFH10_msk     0xFFFFF0FFUL  /* Mask for GPIO alternate function high register 10 */
#define M_GPIO_AFH_AFH11_msk     0xFFFF0FFFUL  /* Mask for GPIO alternate function high register 11 */
#define M_GPIO_AFH_AFH12_msk     0xFFF0FFFFUL  /* Mask for GPIO alternate function high register 12 */
#define M_GPIO_AFH_AFH13_msk     0xFF0FFFFFUL  /* Mask for GPIO alternate function high register 13 */
#define M_GPIO_AFH_AFH14_msk     0xF0FFFFFFUL  /* Mask for GPIO alternate function high register 14 */
#define M_GPIO_AFH_AFH15_msk     0x0FFFFFFFUL  /* Mask for GPIO alternate function high register 15 */

/* Mask for GPIO output data register */
#define M_GPIO_ODR_msk           0x0000FFFEUL  /* Mask for GPIO output data register */


/* Array of GPIO mode masks */
u32 Local_u32ArrMode[]=
{  
   M_GPIO_MODER_MODER0_msk,  /* Mask for GPIO mode register 0 */
   M_GPIO_MODER_MODER1_msk,  /* Mask for GPIO mode register 1 */
   M_GPIO_MODER_MODER2_msk,  /* Mask for GPIO mode register 2 */
   M_GPIO_MODER_MODER3_msk,  /* Mask for GPIO mode register 3 */
   M_GPIO_MODER_MODER4_msk,  /* Mask for GPIO mode register 4 */
   M_GPIO_MODER_MODER5_msk,  /* Mask for GPIO mode register 5 */
   M_GPIO_MODER_MODER6_msk,  /* Mask for GPIO mode register 6 */
   M_GPIO_MODER_MODER7_msk,  /* Mask for GPIO mode register 7 */
   M_GPIO_MODER_MODER8_msk,  /* Mask for GPIO mode register 8 */
   M_GPIO_MODER_MODER9_msk,  /* Mask for GPIO mode register 9 */
   M_GPIO_MODER_MODER10_msk, /* Mask for GPIO mode register 10 */
   M_GPIO_MODER_MODER11_msk, /* Mask for GPIO mode register 11 */
   M_GPIO_MODER_MODER12_msk, /* Mask for GPIO mode register 12 */
   M_GPIO_MODER_MODER13_msk, /* Mask for GPIO mode register 13 */
   M_GPIO_MODER_MODER14_msk, /* Mask for GPIO mode register 14 */
   M_GPIO_MODER_MODER15_msk  /* Mask for GPIO mode register 15 */
};

/* Array of GPIO output type masks */
u32 Local_u32ArrOutputType[]=
{  
   M_GPIO_OTYPER_OT0_msk,  /* Mask for GPIO output type register 0 */
   M_GPIO_OTYPER_OT1_msk,  /* Mask for GPIO output type register 1 */
   M_GPIO_OTYPER_OT2_msk,  /* Mask for GPIO output type register 2 */
   M_GPIO_OTYPER_OT3_msk,  /* Mask for GPIO output type register 3 */
   M_GPIO_OTYPER_OT4_msk,  /* Mask for GPIO output type register 4 */
   M_GPIO_OTYPER_OT5_msk,  /* Mask for GPIO output type register 5 */
   M_GPIO_OTYPER_OT6_msk,  /* Mask for GPIO output type register 6 */
   M_GPIO_OTYPER_OT7_msk,  /* Mask for GPIO output type register 7 */
   M_GPIO_OTYPER_OT8_msk,  /* Mask for GPIO output type register 8 */
   M_GPIO_OTYPER_OT9_msk,  /* Mask for GPIO output type register 9 */
   M_GPIO_OTYPER_OT10_msk, /* Mask for GPIO output type register 10 */
   M_GPIO_OTYPER_OT11_msk, /* Mask for GPIO output type register 11 */
   M_GPIO_OTYPER_OT12_msk, /* Mask for GPIO output type register 12 */
   M_GPIO_OTYPER_OT13_msk, /* Mask for GPIO output type register 13 */
   M_GPIO_OTYPER_OT14_msk, /* Mask for GPIO output type register 14 */
   M_GPIO_OTYPER_OT15_msk  /* Mask for GPIO output type register 15 */
};

/* Array of GPIO speed masks */
u32 Local_u32ArrSpeed[]=
{  
   M_GPIO_OSPEEDR_OSPEEDR0_msk,  /* Mask for GPIO speed register 0 */
   M_GPIO_OSPEEDR_OSPEEDR1_msk,  /* Mask for GPIO speed register 1 */
   M_GPIO_OSPEEDR_OSPEEDR2_msk,  /* Mask for GPIO speed register 2 */
   M_GPIO_OSPEEDR_OSPEEDR3_msk,  /* Mask for GPIO speed register 3 */
   M_GPIO_OSPEEDR_OSPEEDR4_msk,  /* Mask for GPIO speed register 4 */
   M_GPIO_OSPEEDR_OSPEEDR5_msk,  /* Mask for GPIO speed register 5 */
   M_GPIO_OSPEEDR_OSPEEDR6_msk,  /* Mask for GPIO speed register 6 */
   M_GPIO_OSPEEDR_OSPEEDR7_msk,  /* Mask for GPIO speed register 7 */
   M_GPIO_OSPEEDR_OSPEEDR8_msk,  /* Mask for GPIO speed register 8 */
   M_GPIO_OSPEEDR_OSPEEDR9_msk,  /* Mask for GPIO speed register 9 */
   M_GPIO_OSPEEDR_OSPEEDR10_msk, /* Mask for GPIO speed register 10 */
   M_GPIO_OSPEEDR_OSPEEDR11_msk, /* Mask for GPIO speed register 11 */
   M_GPIO_OSPEEDR_OSPEEDR12_msk, /* Mask for GPIO speed register 12 */
   M_GPIO_OSPEEDR_OSPEEDR13_msk, /* Mask for GPIO speed register 13 */
   M_GPIO_OSPEEDR_OSPEEDR14_msk, /* Mask for GPIO speed register 14 */
   M_GPIO_OSPEEDR_OSPEEDR15_msk  /* Mask for GPIO speed register 15 */
};

/* Array of GPIO pull-up/pull-down masks */
u32 Local_u32ArrPUPDR[]=
{  
   M_GPIO_PUPDR_PUPDR0_msk,  /* Mask for GPIO pull-up/pull-down register 0 */
   M_GPIO_PUPDR_PUPDR1_msk,  /* Mask for GPIO pull-up/pull-down register 1 */
   M_GPIO_PUPDR_PUPDR2_msk,  /* Mask for GPIO pull-up/pull-down register 2 */
   M_GPIO_PUPDR_PUPDR3_msk,  /* Mask for GPIO pull-up/pull-down register 3 */
   M_GPIO_PUPDR_PUPDR4_msk,  /* Mask for GPIO pull-up/pull-down register 4 */
   M_GPIO_PUPDR_PUPDR5_msk,  /* Mask for GPIO pull-up/pull-down register 5 */
   M_GPIO_PUPDR_PUPDR6_msk,  /* Mask for GPIO pull-up/pull-down register 6 */
   M_GPIO_PUPDR_PUPDR7_msk,  /* Mask for GPIO pull-up/pull-down register 7 */
   M_GPIO_PUPDR_PUPDR8_msk,  /* Mask for GPIO pull-up/pull-down register 8 */
   M_GPIO_PUPDR_PUPDR9_msk,  /* Mask for GPIO pull-up/pull-down register 9 */
   M_GPIO_PUPDR_PUPDR10_msk, /* Mask for GPIO pull-up/pull-down register 10 */
   M_GPIO_PUPDR_PUPDR11_msk, /* Mask for GPIO pull-up/pull-down register 11 */
   M_GPIO_PUPDR_PUPDR12_msk, /* Mask for GPIO pull-up/pull-down register 12 */
   M_GPIO_PUPDR_PUPDR13_msk, /* Mask for GPIO pull-up/pull-down register 13 */
   M_GPIO_PUPDR_PUPDR14_msk, /* Mask for GPIO pull-up/pull-down register 14 */
   M_GPIO_PUPDR_PUPDR15_msk  /* Mask for GPIO pull-up/pull-down register 15 */
};

/* Array of GPIO alternate function masks */
u32 Local_u32ArrAF[]=
{  
   M_GPIO_AFL_AFL0_msk,  /* Mask for GPIO alternate function low register 0 */
   M_GPIO_AFL_AFL1_msk,  /* Mask for GPIO alternate function low register 1 */
   M_GPIO_AFL_AFL2_msk,  /* Mask for GPIO alternate function low register 2 */
   M_GPIO_AFL_AFL3_msk,  /* Mask for GPIO alternate function low register 3 */
   M_GPIO_AFL_AFL4_msk,  /* Mask for GPIO alternate function low register 4 */
   M_GPIO_AFL_AFL5_msk,  /* Mask for GPIO alternate function low register 5 */
   M_GPIO_AFL_AFL6_msk,  /* Mask for GPIO alternate function low register 6 */
   M_GPIO_AFL_AFL7_msk,  /* Mask for GPIO alternate function low register 7 */
   M_GPIO_AFH_AFH8_msk,  /* Mask for GPIO alternate function high register 8 */
   M_GPIO_AFH_AFH9_msk,  /* Mask for GPIO alternate function high register 9 */
   M_GPIO_AFH_AFH10_msk, /* Mask for GPIO alternate function high register 10 */
   M_GPIO_AFH_AFH11_msk, /* Mask for GPIO alternate function high register 11 */
   M_GPIO_AFH_AFH12_msk, /* Mask for GPIO alternate function high register 12 */
   M_GPIO_AFH_AFH13_msk, /* Mask for GPIO alternate function high register 13 */
   M_GPIO_AFH_AFH14_msk, /* Mask for GPIO alternate function high register 14 */
   M_GPIO_AFH_AFH15_msk  /* Mask for GPIO alternate function high register 15 */
};




#endif