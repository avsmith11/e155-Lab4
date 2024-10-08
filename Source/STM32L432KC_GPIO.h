// STM32L432KC_GPIO.h
// Header for GPIO initialization for lab4

#ifndef STM32L4_GPIO_H
#define STM32L4_GPIO_H

#include <stdint.h>

// Values for GPIO pins ("val" arguments)
#define GPIO_LOW    0
#define GPIO_HIGH   1

// Base addresses for GPIO ports
#define GPIOA_BASE  (0x48000000UL)

// Arbitrary GPIO functions for pinMode()
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_ALT    2
#define GPIO_ANALOG 3


// define GPIO register pointers
#define GPIO_MODER (*((volatile uint32_t *) (GPIOA_BASE + 0x00)))
#define GPIO_AFRL (*((volatile uint32_t *) (GPIOA_BASE + 0x20)))
#define GPIO_AFRH (*((volatile uint32_t *) (GPIO_BASE + 0x24)))

void initGPIOA();

#endif