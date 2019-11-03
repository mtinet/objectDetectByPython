#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.write("Hello, world?");
  
}

void loop() {
  if (mySerial.available()) {
    int c = mySerial.read();
    Serial.println(c);
  }
}
