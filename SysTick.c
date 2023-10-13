#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "SysTick.h"
#include "Port_Config.h"

int counter=0;
int flag=0;

//************************************************************
//*
//*Configuring delays using SysTick timer without interrupts
//*
//************************************************************

void SysTick_Init (void){
	//Initialize the SysTick Timer
	NVIC_ST_RELOAD_R = 16000 -1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x7;
	while((NVIC_ST_CTRL_R & (1<<16))== 0){}
}

void Delay_ms(uint32_t delay){
	volatile int i=0;
	for(i=0;i<delay;i++){
		SysTick_Init ();
	}
}

//************************************************************
//*
//*Configuring delays using SysTick timer without interrupts
//*
//************************************************************

void 
SysTick_Setup_Second (void){
	//Initialize the SysTick Timer
        NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 1600000 -1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x7;
}

void 
SysTick_Handler (void){
  counter++;
  flag=0;

        //GPIO_PORTF_DATA_R ^= RedLed;
}
