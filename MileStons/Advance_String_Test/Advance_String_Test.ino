String incomingString = " ";
int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingString = Serial.readString();
                Serial.println(incomingString);
                if (incomingString.substring(0,3) == "Num") {
                  incomingByte = incomingString.substring(4).toInt();
                  // say what you got:
                  Serial.print("I received: ");
                  Serial.println(incomingByte, DEC);
                  }
                else{
                  Serial.println("Not A Number!");
                  }
        }
}



