// STM32L432KC_PWM_TIM.h
// STM32L432KC_PWM_TIM.h
// header file for PWM timer funcs
#ifndef STM32L4_PWM_H
#define STM32L4_PWM_H

#include <stdint.h>
// define base address 
#define TIM16_BASE (0x40014400UL)
// define pointers to TIM16 registers
#define TIM16_CR1 (*((volatile uint32_t *) (TIM16_BASE + 0x00)))
#define TIM16_CR2 (*((volatile uint32_t *) (TIM16_BASE + 0x04)))
#define TIM16_EGR (*((volatile uint32_t *) (TIM16_BASE + 0x14)))
#define TIM16_CCMR1 (*((volatile uint32_t *) (TIM16_BASE + 0x18)))
#define TIM16_CCER (*((volatile uint32_t *) (TIM16_BASE + 0x20)))
#define TIM16_CNT (*((volatile uint32_t *) (TIM16_BASE + 0x24)))
#define TIM16_PSC (*((volatile uint32_t *) (TIM16_BASE + 0x28)))
#define TIM16_ARR (*((volatile uint32_t *) (TIM16_BASE + 0x2C)))
#define TIM16_CCR1 (*((volatile uint32_t *) (TIM16_BASE + 0x34)))
#define TIM16_BDTR (*((volatile uint32_t *) (TIM16_BASE + 0x44)))

void initPWM();
void setPWM(float freq);

#endif