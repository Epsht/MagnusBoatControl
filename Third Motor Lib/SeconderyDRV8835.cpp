#include "SeconderyDRV8835.h"
const unsigned char SeconderyDRV8835::_M1DIR = 4;
const unsigned char SeconderyDRV8835::_M1PWM = 6;
const unsigned int SeconderyDRV8835::_StepTime = 200; // in miliseconds
const unsigned int SeconderyDRV8835::_StepSpeed = 300; // bitween 0 to 400

void SeconderyDRV8835::initAll()
{
  // Initialize the pin states used by the motor driver shield
  // digitalWrite is called before and after setting pinMode.
  // It called before pinMode to handle the case where the board
  // is using an ATmega AVR to avoid ever driving the pin high, 
  // even for a short time.
  // It is called after pinMode to handle the case where the board
  // is based on the Atmel SAM3X8E ARM Cortex-M3 CPU, like the Arduino
  // Due. This is necessary because when pinMode is called for the Due
  // it sets the output to high (or 3.3V) regardless of previous
  // digitalWrite calls.
  digitalWrite(_M1PWM, LOW);
  pinMode(_M1PWM, OUTPUT);
  digitalWrite(_M1PWM, LOW);
  digitalWrite(_M1DIR, LOW);
  pinMode(_M1DIR, OUTPUT);
  digitalWrite(_M1DIR, LOW);
#ifdef SeconderyDRV8835_USE_20KHZ_PWM
  // timer 1 configuration
  // prescaler: clockI/O / 1
  // outputs enabled
  // phase-correct PWM
  // top of 400
  //
  // PWM frequency calculation
  // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
  TCCR1A = 0b10100000;
  TCCR1B = 0b00010001;
  ICR1 = 400;
#endif
}

// speed should be a number between -400 and 400
void SeconderyDRV8835::doStep(bool reverse)
{
  init(); // initialize if necessary
    
#ifdef DRV8835MOTORSHIELD_USE_20KHZ_PWM
  OCR1A = _StepSpeed;
#else
  analogWrite(_M1PWM, _StepSpeed * 51 / 80 ); // default to using analogWrite, mapping 400 to 255
#endif 

  if (reverse) // flip if speed was negative or _flipM1 setting is active, but not both
    digitalWrite(_M1DIR, HIGH);
  else
    digitalWrite(_M1DIR, LOW);
/*
//delay(_StepTime);

#ifdef DRV8835MOTORSHIELD_USE_20KHZ_PWM
  OCR1A = 0;
#else
  analogWrite(_M1PWM, 0); 
#endif */
}