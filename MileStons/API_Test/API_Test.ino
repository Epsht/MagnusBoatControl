String incomingString = " ";
String IncomingCommand = " ";
int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingString = Serial.readString();
                Serial.println(incomingString);
                IncomingCommand = incomingString.substring(0,3);
                if (IncomingCommand=="M1T"){ //Toggle Motor 1
                  Serial.println("Toggle Motor 1");
                }
                else if (IncomingCommand=="M2T") { //Toggle Motor 2
                  Serial.println("Toggle Motor 2");
                }

                else if (IncomingCommand=="M3F") { //Motor 3 Forward Step
                  Serial.println("Motor 3 Forward Step");
                }

                else if (IncomingCommand=="M3B") { //Motor 3 Backward Step
                  Serial.println("Motor 3 Backward Step");
               }

                else if (IncomingCommand=="M1S") { //Set Speed for Motor 1
                  incomingByte = incomingString.substring(4).toInt(); //pull out the number from the sting

                  Serial.print("Motor 1 new Speed: ");
                  Serial.println(incomingByte, DEC);
                }
                  
               else if (IncomingCommand=="M2S") { //Set Speed for Motor 2
                  incomingByte = incomingString.substring(4).toInt(); //pull out the number from the sting
                  
                  Serial.print("Motor 2 new Speed: ");
                  Serial.println(incomingByte, DEC);
                }
                else  Serial.println("Error");
  
                }
}




