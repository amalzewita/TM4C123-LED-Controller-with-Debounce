#include "tm4c123gh6pm.h"
#include <stdint.h>


#define Led 2
void Timer0A_Init (void){

  
  SYSCTL_RCGCTIMER_R = 0x1;      // Enable the clock of Timer0
  TIMER0_CTL_R  = 0;             // Disable Timer0 before Configuration
  TIMER0_CFG_R  = (1<<2) ;       // Configure Timer0 to be in 16-bits : (1<<2)
  TIMER0_TAMR_R = (1<<2);        // Periodic mode:(1<<2) 
  TIMER0_TAPR_R = 250;           // 16 MHz/ 250 = 64000 Hz
  TIMER0_TAILR_R = 64000;       // Load the interval load register by 64000 to get 1 Hz
  TIMER0_ICR_R = 1;              // clear the time-out flag of TimerA
  TIMER0_IMR_R = 1;              // Enable the time-out interrupt of TimerA
  NVIC_PRI4_R |=0x80000000;
  NVIC_EN0_R = 1<<19; 
  TIMER0_CTL_R  = 1;             // Enable Timer0 after Configuration

}

void Timer0A_Handler (void){

	uint32_t i;  
    
	TIMER0_ICR_R = 1;           // clear the time-out flag of TimerA
    i= TIMER0_ICR_R ;           // Reading the register to force the flag to be cleared

	GPIO_PORTF_DATA_R ^= (1<<led);


}
