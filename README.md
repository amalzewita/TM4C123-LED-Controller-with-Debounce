# LED State Control for TM4C123GH6PM

This repository provides a simple example demonstrating how to control the state of an RGB LED on the TM4C123GH6PM microcontroller using onboard buttons. The LED can display four colors: white, red, green, and blue.

## Table of Contents
- [Introduction](#led-state-control-for-tm4c123gh6pm)
- [Features](#features)
    * [LED State Enumeration](#led-state-enumeration)
    * [Button Debounce](#button-debounce)
    * [State Control Logic](#state-control-logic)
- [Setup and Usage](#setup-and-usage)
    * [Setup](#setup)
    * [Main Loop](#main-loop)
    * [Debounce](#debounce)
- [Code Structure](#code-structure)
    * [`setup()` Function](#setup-function)
    * [`debounceDelay()` Function](#debouncedelay-function)
    * [`main()` Function](#main-function)
- [Dependencies](#dependencies)
    * [`TM4C123GH6PM.h` Header](#tm4c123gh6pmh-header)
    * [`Port_Config.h` Header](#port_configh-header)
    * [`SysTick.h` Header](#systickh-header)
    * [`scheduler.h` Header](#schedulerh-header)
- [Notes](#notes)
- [Contribution](#contribution)

## Features

- **LED State Enumeration**: Uses a well-defined enumeration (`LEDState`) for maintaining the states of the LED: WHITE, RED, GREEN, BLUE.
  
- **Button Debounce**: Implements a simple button debounce mechanism to avoid erratic LED state changes due to noise or rapid button pressing.
  
- **State Control Logic**: Pressing one button cycles through LED states, while pressing the other button switches between specific states or returns the LED to a white state.

## Setup and Usage

1. **Setup**: Initialize GPIO ports to set LED pins as outputs and button pins as inputs with pull-ups enabled.
  
2. **Main Loop**: Continuously checks the state of the buttons to determine the LED state.
  
3. **Debounce**: After recognizing a button press and changing the LED state, the program pauses for a brief period to debounce the button input.

## Code Structure

- `setup()`: This function initializes the required GPIO ports for LED and buttons.
  
- `debounceDelay()`: Implements a simple delay loop for button debouncing.
  
- `main()`: The primary function that initializes the setup and contains the main loop. The main loop checks the button inputs, updates the LED state accordingly, and then applies a debounce delay.

## Dependencies

- `TM4C123GH6PM.h`: Header file for the TM4C123GH6PM microcontroller specific definitions.
  
- `Port_Config.h`: Header file (presumably) containing configurations for various GPIO ports.
  
- `SysTick.h`: Header file (presumably) for the system tick timer functions.
  
- `scheduler.h`: Header file (presumably) for task scheduling functions.

## Notes

1. The code assumes that the RGB LED is connected to specific pins on GPIO port F of the TM4C123GH6PM microcontroller.

2. The button debounce time is set for roughly 20ms, but this may vary depending on the system clock setting.

3. For optimal performance, ensure that the system clock settings match the intended microcontroller configuration.

## Contribution

Feel free to fork this repository and make any changes or improvements. Pull requests are welcome!
