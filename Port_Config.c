#include "TM4C123GH6PM.h"
#include "Port_Config.h"

void PortF_Config(void){

      SYSCTL_RCGCGPIO_R |= 0x20;        // Open the clock of PORTF
      GPIO_PORTF_LOCK_R = 0x4C4F434B;   // Unlock PORTF
      GPIO_PORTF_CR_R = 0x11;
      GPIO_PORTF_DEN_R |= 0x1F;         // Enable pins (PF0->PF4) as Digital
      GPIO_PORTF_DIR_R |=  0x0E;
      GPIO_PORTF_PUR_R |=  0x11;
}