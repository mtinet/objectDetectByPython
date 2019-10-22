#include <stdlib.h>
#define in1 9
#define in2 10

int SR = 0;
int SL = 0;

const int buttonPinR = 2;
const int buttonPinL = 3;
const int LED = 13;

int buttonStateR = 0;
int buttonStateL = 0;

int previousVal = 250;
int inputVal = 0;
int currentVal = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  pinMode(buttonPinR, INPUT_PULLUP);
  pinMode(buttonPinL, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  
  Serial.begin(115200);
  while (!Serial); 
  Serial.println("Input Steering Range : 0 to 500"); 
  Serial.print("previousVal = ");
  Serial.print(previousVal);
  Serial.print(", inputVal = ");
  Serial.print(inputVal);
  Serial.print(", currentVal = ");
  Serial.println(currentVal);
}

void loop() {
  buttonStateR = digitalRead(buttonPinR);
  buttonStateL = digitalRead(buttonPinL);
  digitalWrite(13, LOW);
  Serial.print(buttonStateR);
  Serial.print("  ");
  Serial.println(buttonStateL);
  
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
//    int inputVal = Serial.parseInt(); // str로 자료가 넘어올 때 사용
    int inputVal = Serial.read(); // byte로 자료가 넘어올 때 사용
    inputVal = constrain(inputVal, 0, 500);
    currentVal = previousVal - inputVal;
    currentVal *= 100;
    Serial.print("previousVal = ");
    Serial.print(previousVal);
    Serial.print(", inputVal = ");
    Serial.print(inputVal);
    Serial.print(", currentVal = ");
    Serial.print(currentVal);
    
    if (currentVal > 0) {
      steeringLeft(currentVal);
      previousVal = inputVal;
    } else if (currentVal < 0 ) {
      steeringRight(-currentVal);
      previousVal = inputVal;
    } else if(currentVal == 0) {
      steeringNeutral();
    }
  }    
}
  
  
void steeringRight(int SR) {
  Serial.print(", SR Val = ");
  Serial.println(SR);
  analogWrite(in1, 255);
  analogWrite(in2, 0);
  delay(SR);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
}

void steeringLeft(int SL) {
  Serial.print(", SL Val = ");
  Serial.println(SL);
  analogWrite(in1, 0);
  analogWrite(in2, 255);
  delay(SL);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
}

void steeringNeutral() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  Serial.println("");
}
