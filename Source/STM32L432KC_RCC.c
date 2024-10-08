// STM32L432KC_RCC.c
// Source code for RCC configuration in lab 4

#include "STM32L432KC_RCC.h"

void configureClock() {
// USING DEFAULT 4MHz CLK, SO NO NEED TO USE CCR

    RCC_AHB2ENR |= (1<<0); // enable clk to GPIOA
    RCC_APB2ENR |= (1<<16); // enable clk to TIM15
    RCC_APB2ENR |= (1<<17); // enable clk to TIM16

}