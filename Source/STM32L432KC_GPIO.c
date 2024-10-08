// STM32L432KC_GPIO.c
// Source code to initialize GPIO for lab4

#include "STM32L432KC_GPIO.h"

void pinMode(int pin, int function) {
    switch(function) {
        case GPIO_INPUT:
            GPIO_MODER &= ~(0b11 << 2*pin);
            break;
        case GPIO_OUTPUT:
            GPIO_MODER |= (0b1 << 2*pin);
            GPIO_MODER &= ~(0b1 << (2*pin+1));
            break;
        case GPIO_ALT:
            GPIO_MODER &= ~(0b1 << 2*pin);
            GPIO_MODER |= (0b1 << (2*pin+1));
            break;
        case GPIO_ANALOG:
            GPIO_MODER |= (0b11 << 2*pin);
            break;
    }
}

void initGPIOA() {
    pinMode(6, GPIO_ALT); // set PA6 to Alt Func
    GPIO_AFRL &= ~(0b1111 << 24); //clear AFSEL6
    GPIO_AFRL |= (0b1110 << 24); //set PA6 to AF14 (TIM16_CH1)

}