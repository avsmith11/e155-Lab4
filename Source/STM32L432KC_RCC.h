// STM32L432KC_RCC.h
// Header for RCC configuration in lab 4

#ifndef STM32L4_RCC_H
#define STM32L4_RCC_H

#include <stdint.h>


// RCC base addresses
#define RCC_BASE (0x40021000UL)
// define RCC refister pointers (only those necessary)
#define RCC_CR (*((volatile uint32_t *) (RCC_BASE + 0x00)))
#define RCC_AHB2ENR (*((volatile uint32_t *) (RCC_BASE + 0x4C)))
#define RCC_APB2ENR (*((volatile uint32_t *) (RCC_BASE + 0x60)))

// prototype functions
void configureClock();

#endif
