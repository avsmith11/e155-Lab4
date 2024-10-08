// STM32L432KC_PWM_TIM.c
// source code for for PWM timer function on timer 16

#include "STM32L432KC_PWM.h"

void initPWM() {
    TIM16_CR1 |= (1 << 7); // enable ARR buffer
    TIM16_CCMR1 &= ~(0b111 << 4); // reset OC1M bits 2:0
    TIM16_CCMR1 |= (0b110 << 4); // set PWM mode 1
    TIM16_CCMR1 |= (1 << 3); // enable output compare preload register
    TIM16_EGR |= (1 << 0); // update generation
    TIM16_CCER |= (1 << 0); // enable capture/compare output
    TIM16_BDTR |= (1 << 15); // main output enable

    // configure timing
    // sys_clk = 4MHz
    // PSC = 0x0000 default on reset
}

const float sys_clk = 4000000.0;

void setPWM(float freq){
    // CNT = sys_clk / freq
    if (freq == 0) TIM16_CR1 &= ~(1 << 0);
    else {
      TIM16_CR1 |= (1 << 0); // enable couner
      uint16_t ARR = (uint16_t)(sys_clk/freq); // set ARR to nearest integer
      TIM16_ARR &= ~(0xFFFF << 0);
      TIM16_ARR |= (ARR << 0); // set ARR[15:0] to ARR value
      uint16_t CRR = ARR/2; // set CRR[15:0] to half ARR for 50% duty cycle
      TIM16_CCR1 &= ~(0xFFFF <<0);
      TIM16_CCR1 |= (CRR <<0);
    }

}