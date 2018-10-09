#include <DRV8835MotorShield.h>
#include <C:\Users\user\Desktop\DoronProj\Third Motor Lib\SeconderyDRV8835.h>

/*
this version does not include motor number 3 because the lib cant work with 2 DRV boards

Motor 1 legs: EN  09
              Ph  07

Motor 2 legs: EN  10
              Ph  08

Motor 3 legs: EN  12
              Ph  11

todo
* add comments
* calibrate speed

*/

String incomingString = " ";
String IncomingCommand = " ";
int incomingByte = 0,   // for incoming serial data
    M1Speed = 0,
    M2Speed = 0;
boolean M1d = false,
        M2d = false;
        

DRV8835MotorShield motors;


void setup() {
        Serial.begin(19200);     // opens serial port, sets data rate to 9600 bps
        void initAll();
}

void loop() {
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingString = Serial.readString();
                Serial.println(incomingString);
                IncomingCommand = incomingString.substring(0,3);
                if (IncomingCommand=="M1T"){ //Toggle Motor 1
                  M1d=!(M1d);
                  motors.flipM1(M1d);
                  motors.setM1Speed(M1Speed);
                  if (M1d) Serial.println("Motor 1 Is in Reverse");
                  else Serial.println("Motor 1 Is in Foward");
                  
                }
                else if (IncomingCommand=="M2T") { //Toggle Motor 2
                  M2d=!(M2d);
                  motors.flipM2(M2d);
                  motors.setM2Speed(M2Speed);
                  if (M2d) Serial.println("Motor 2 Is in Reverse");
                  else Serial.println("Motor 2 Is in Foward");
                }

                else if (IncomingCommand=="M3F") { //Motor 3 Forward Step
                  doStep(false);
                  Serial.println("Motor 3 Forward Step");
                }

                else if (IncomingCommand=="M3B") { //Motor 3 Backward Step
                  doStep(true);
                  Serial.println("Motor 3 Backward Step");
               }

                else if (IncomingCommand=="M1S") { //Set Speed for Motor 1
                  M1Speed = incomingString.substring(4).toInt(); //pull out the number from the sting
                  motors.setM1Speed(M1Speed);
                  Serial.print("Motor 1 new Speed: ");
                  Serial.println(M1Speed, DEC);
                }
                  
               else if (IncomingCommand=="M2S") { //Set Speed for Motor 2
                  M2Speed = incomingString.substring(4).toInt(); //pull out the number from the sting
                  motors.setM2Speed(M2Speed);
                  Serial.print("Motor 2 new Speed: ");
                  Serial.println(M2Speed, DEC);
                }
                else  Serial.println("Error");
  
                }
}


