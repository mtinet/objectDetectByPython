#include <SoftwareSerial.h>

#define in1 9
#define in2 10

SoftwareSerial mySerial(2, 3);

const int buttonPinR = 4;
const int buttonPinL = 5;
const int LED = 13;

int buttonStateR = 0;
int buttonStateL = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  pinMode(buttonPinR, INPUT_PULLUP);
  pinMode(buttonPinL, INPUT_PULLUP);

  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
  //mySerial.write("Hello, world?");
}

void loop() {
  buttonStateR = digitalRead(buttonPinR);
  buttonStateL = digitalRead(buttonPinL);
  digitalWrite(13, LOW);
  
  if (buttonStateR == 1) {
    analogWrite(in1, 0);
    analogWrite(in2, 255);
    delay(100);
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    
    //Serial.println("Right end");
    digitalWrite(LED, HIGH);
  }
  if (buttonStateL == 1) {
    analogWrite(in1, 255);
    analogWrite(in2, 0);
    delay(100);
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    
    //Serial.println("Left end");
    digitalWrite(LED, HIGH);
  }
  
  if (Serial.available()) {
    char input; 
    input = Serial.read();
    
    mySerial.write(input);

    if (input == 'a') {
      analogWrite(in1, 0);
      analogWrite(in2, 255);
    }
    if (input == 'b') {
      analogWrite(in1, 255);
      analogWrite(in2, 0);
    }
    if (input == 'n') {
      analogWrite(in1, 0);
      analogWrite(in2, 0);
    }
  }
}
