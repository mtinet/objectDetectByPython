// 아두이노에서 파이썬으로 문자열을 보내는 예시

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  Serial.println("Hello");
  delay(500);
}
