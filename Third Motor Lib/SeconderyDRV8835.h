#ifndef SeconderyDRV8835_h
#define SeconderyDRV8835_h

/*#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined (__AVR_ATmega32U4__)
  #define SeconderyDRV8835_USE_20KHZ_PWM
#endif*/

#include <Arduino.h>
#include "SeconderyDRV8835.c"

    void doStep(bool reverse);
    void initAll();

#endif