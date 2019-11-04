#include <SoftwareSerial.h>

#define in1 9
#define in2 10

SoftwareSerial mySerial(2, 3);

int previousVal = 127;
int inputVal = 0;
int currentVal = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.write("Hello, world?");
}

void loop() {
  if (Serial.available()) {
    inputVal = Serial.read();
//    mySerial.write(inputVal);
    currentVal = previousVal - inputVal;
    previousVal = inputVal;
    mySerial.write(currentVal);

    if (currentVal > 0) {
      analogWrite(in1, 0);
      analogWrite(in2, 100);
    }
    if (currentVal < 0) {
      analogWrite(in1, 100);
      analogWrite(in2, 0);
    }
    if (currentVal == 0) {
      analogWrite(in1, 0);
      analogWrite(in2, 0);
    }
  }
    
}
