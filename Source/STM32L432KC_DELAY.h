// STM32L432KC_PWM_TIM.h
// header for delay timer functions

#ifndef STM32L4_DELAY_H
#define STM32L4_DELAY_H

#include <stdint.h>

// timer 6 base address
#define TIM15_BASE (0x40014000UL)

// define pointers to TIM6 register
#define TIM15_CR1 (*((volatile uint32_t *) (TIM15_BASE + 0x00)))
#define TIM15_SR (*((volatile uint32_t *) (TIM15_BASE + 0x10)))
#define TIM15_CNT (*((volatile uint32_t *) (TIM15_BASE + 0x24)))
#define TIM15_PSC (*((volatile uint32_t *) (TIM15_BASE + 0x28)))
#define TIM15_ARR (*((volatile uint32_t *) (TIM15_BASE + 0x2C)))
#define TIM15_CCR1 (*((volatile uint32_t *) (TIM15_BASE + 0x34)))


// prototype functions

void initDelay();

void Delay(float delay);

#endif