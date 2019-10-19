#include <stdlib.h>


#define in1 9
#define in2 10

int SR = 0;
int SL = 0;
int inputVal = 0;
int potValue = 0;
int divideValue = 0;
float integralTime = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.begin(9600);
  while (!Serial); 
  Serial.println("Input Steering Angle : 0 to 500"); 
}
void loop() {
  if (Serial.available()) {
    int potValue = Serial.parseInt();   
    Serial.print("potValue = ");
    Serial.print(potValue);
    
    divideValue = potValue - 250;
    Serial.print(", divideValue = ");
    Serial.print(divideValue);
    
    Serial.print(", integralTime = ");
    Serial.print(integralTime);
    
    if (divideValue > 0) {
      steeringRight(divideValue);
    } else if (divideValue == 0) {
      steeringNeutral();
    } else {
      steeringLeft(divideValue);
    }
  }
}

void steeringRight(int SR) {
  SR = abs(SR);
  integralTime += divideValue;
  if (integralTime < 1000 && integralTime > 0) {
    Serial.print(", SR Val = ");
    Serial.println(SR);
    analogWrite(in1, SR);
    analogWrite(in2, 0);
  } else if (integralTime >= 1000) {
    integralTime = 1000;
    Serial.print(", integralTime = ");
    Serial.print(integralTime);
    Serial.println(", Right End Position"); 
    analogWrite(in1, 0);
    analogWrite(in2, 0);
  }
}

void steeringLeft(int SL) {
  SL = abs(SL);
  integralTime += divideValue;
  if (integralTime > -1000 && integralTime < 0) {
    Serial.print(", SL Val = ");
    Serial.println(SL);
    analogWrite(in1, 0);
    analogWrite(in2, SL);
  } else if (integralTime <= -1000) {
    integralTime = -1000;
    Serial.print(", integralTime = ");
    Serial.print(integralTime);
    Serial.println(", Left End Position");
    analogWrite(in1, 0);
    analogWrite(in2, 0);
  }
}

void steeringNeutral() {
  integralTime += divideValue;
  analogWrite(in1, 0);
  analogWrite(in2, 0);
}
