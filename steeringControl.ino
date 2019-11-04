#include <SoftwareSerial.h>

#define in1 9
#define in2 10

SoftwareSerial mySerial(2, 3);

int previousVal = 127;
int inputVal = 0;
int currentVal = 0;

int SR = 0;
int SL = 0;

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
  mySerial.write("Hello, world?");
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
    
    Serial.println("Right end");
    digitalWrite(LED, HIGH);
  }
  if (buttonStateL == 1) {
    analogWrite(in1, 255);
    analogWrite(in2, 0);
    delay(100);
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    
    Serial.println("Left end");
    digitalWrite(LED, HIGH);
  }
  
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

void steeringRight(int SR) {
  //Serial.print(", SR Val = ");
  //Serial.println(SR);
  analogWrite(in1, 100);
  analogWrite(in2, 0);
  delay(SR);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
}

void steeringLeft(int SL) {
  //Serial.print(", SL Val = ");
  //Serial.println(SL);
  analogWrite(in1, 0);
  analogWrite(in2, 100);
  delay(SL);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
}

void steeringNeutral() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  //Serial.println("");
}
