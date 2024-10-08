// STM32L432KC_DELAY.c
// source code for delay timer funcitons on timer 15

#include "STM32L432KC_DELAY.h"

void initDelay() {
    TIM15_PSC |= (0b11111010000 << 0); // set PSC to 2000 
    TIM15_CR1 |= (1 << 0); // enable counter
}

void Delay(float delay) {
    // generates a delay in ms
    
    //setup timer
    TIM15_CCR1 &= ~(0xFFFF << 0); //clear CCR1
    float T_CNT_CLK = 0.5;
    uint16_t CNT_MAX = (uint16_t)(delay/T_CNT_CLK); // set CCR to number of counter clock cycles for delay
    //TIM15_CCR1 |= (CNT_MAX << 0); //set CCR1 to CCR
    //TIM15_ARR |= (CNT_MAX << 0);
    TIM15_CNT &= ~(0xFFFF << 0); // clear CNT
    TIM15_SR &= ~(1 << 1); // reset SR bit 1
    
    // run delay
    while (TIM15_CNT < CNT_MAX);  // while CNT < CCR (1st bit of SR goes high on this condition)
}