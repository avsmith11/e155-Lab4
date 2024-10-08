// main.c
// play frequencies for set durations via GPIO
// Avery Smith, avsmith@hmc.edu
// 9/30/24

# include <stdint.h>

//include header files
#include "STM32L432KC_DELAY.h"
#include "STM32L432KC_GPIO.h"
#include "STM32L432KC_PWM.h"
#include "STM32L432KC_RCC.h"


//define note values
#define A3	220
#define As3 233.1
#define Bb3	233.1
#define B3	246.9
#define C4	261.6
#define Cs4 277.2
#define Db4	277.2
#define D4	293.7
#define Ds4 311.1
#define Eb4	311.1
#define E4	329.6
#define F4	349.2
#define Fs4 370.0
#define Gb4 370.0
#define G4	392.0
#define Gs4 415.3
#define Ab4	415.3
#define A4	440
#define As4 466.2
#define Bb4	466.2
#define B4	493.9
#define C5	523.3
#define Cs5 554.4
#define Db5	554.4
#define D5	587.3
#define Ds5 622.2
#define Eb5	622.2
#define E5	659.2
#define F5	698.4
#define Fs5 740.9
#define Gb5	740.9
#define G5	784.0
#define Gs5 830.6
#define Ab5	830.6
#define A5	880

const float tempo = 133.0; // tempo in bpm
const float q = 60000 / tempo; // quarter note in ms
const float w = q*4; // whole note in ms
const float dh = q*3; // dotted half note in ms
const float h = q*2; // half note in ms
const float eigth = q/2; //eigth note in ms
const float triplet = q/3; //eigth note triplet in ms
const float sixteenth = q/4; //sixteenth notes in ms

const float Thunderstruck[][2] = {
{B3, sixteenth},
//m1
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
//m2
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
//m3
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
//m4
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
//m5
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
//m6
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
//m7
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
//m8
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{G4, sixteenth},
{B3, sixteenth},
//m9
{B4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
//m10
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
//m11
{B4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
//m12
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
//m13
{B4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
//m14
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
//m15
{B4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{A4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{Fs4, sixteenth},
{B3, sixteenth},
{Gs4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
//m16
{Fs4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth},
{Ds4, sixteenth},
{B3, sixteenth},
{E4, sixteenth},
{B3, sixteenth}};





// Pitch in Hz, duration in ms
//
const float fur_elise[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};


int main(void) {
    //configure peripherals
    configureClock();
    initDelay();
    initGPIOA();
    initPWM();

    volatile int x = 0;
     while (x < 400000) x += 1; // delay for some reason
    
    volatile int i = 0; // playhead i
    while (1) {
        float freq = fur_elise[i][0];
        float delay = fur_elise[i][1];
        if (delay == 0) {
          setPWM(0);
          break;
        }
        else {
            setPWM(freq);
            Delay(delay);
            i += 1;
        }
    }
}