/*
 * SCHED_CFG.h
 *
 * Created: 1/13/2025
 *  Author: Omar Alaa
 */ 


#ifndef SCHED_CFG_H_
#define SCHED_CFG_H_

#include "STD_TYPES.h"


#define HSCHED_Max_Runnable 10

typedef struct 
{
   void (*CBF_t)(void);      
   u32 Priority;       
   u32 First_Delay;
   u32 Cyclic_Time; 

}HSCHED_sSCHEDRunnableCfg_t;



#endif /* SCHED_CFG_H_ */