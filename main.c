#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "Port_Config.h"
#include "SysTick.h"
#include "scheduler.h"
#include "TM4C123GH6PM.h"

// Define a constant for button debounce duration.
#define BUTTON_DEBOUNCE_TIME 500000  // Roughly 20ms, depends on system clock setting

// Enumeration to represent the different LED states
typedef enum {
    WHITE,
    RED,
    GREEN,
    BLUE
} LEDState;

// Variable to store the current LED state, initialized to WHITE
LEDState currentState = WHITE;

// Function to set up GPIO ports for LED and buttons
void setup() {
    // Enable clock for GPIOF (LEDs and switches are on Port F)
    SYSCTL_RCGCGPIO_R |= 0x20;

    // Configure LED pins as outputs (Red, Green, Blue)
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DEN_R |= 0x0E;

    // Configure button pins as inputs and enable pull-ups (Switch1 and Switch2)
    GPIO_PORTF_DIR_R &= ~(0x11);
    GPIO_PORTF_DEN_R |= 0x11;
    GPIO_PORTF_PUR_R |= 0x11;
}

// Function for button debounce delay
void debounceDelay() {
    for(int i = 0; i < BUTTON_DEBOUNCE_TIME; i++);  // Delay loop for debouncing
}

// Main function
int main(void) {
    // Initialize the setup
    setup();

    // Main loop
    while(1) {
        // Update LED based on the current state
        switch (currentState) {
            case WHITE:
                GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & ~0x0E) | 0x0E;
                break;
            case RED:
                GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & ~0x0E) | 0x02;
                break;
            case GREEN:
                GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & ~0x0E) | 0x08;
                break;
            case BLUE:
                GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & ~0x0E) | 0x04;
                break;
        }

        // Button logic to change LED state
        if (!(GPIO_PORTF_DATA_R & 0x10) && (GPIO_PORTF_DATA_R & 0x01)) {  // Both buttons pressed
            currentState = WHITE;
        } else if (!(GPIO_PORTF_DATA_R & 0x10)) {  // Btn1 pressed
            currentState = (currentState + 1) % 4;  // Cycle to next state
        } else if ((GPIO_PORTF_DATA_R & 0x01)) {  // Btn2 pressed
            currentState = (currentState == WHITE) ? BLUE : currentState - 1;  // Cycle to previous state or jump to BLUE
        }
        
        // Apply debounce delay to avoid erratic changes due to noise or rapid pressing
        debounceDelay();
    }
}
