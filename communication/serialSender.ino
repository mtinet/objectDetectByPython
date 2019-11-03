#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  
}

void loop() {
  for(int i = 0; i<255; i++) {
    mySerial.write(i);
    Serial.println(i);
    i++;
    if(i == 255) {
      i = 0;
    }
  }
}
