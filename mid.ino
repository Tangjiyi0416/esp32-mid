#include <Servo.h>
Servo myservo;
const int servoPin = 13;
int state = 0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  //Serial.begin(115200);
}
const int inputPin = 12;
void loop() {
  // put your main code here, to run repeatedly:
  int p_time = 0;
  int dist_cm = 0;
  pinMode(inputPin, OUTPUT);
  digitalWrite(inputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(inputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(inputPin, LOW);
  pinMode(inputPin, INPUT);
  p_time = pulseIn(inputPin, HIGH); //unit: us
  dist_cm = (float)((p_time / 2) / 29.41);
  delay(250);
  if (dist_cm <= 20 && state != 1) {
    myservo.write(180);
    delay(20);
    state = 1;
  }
  else if (dist_cm > 30 && state != 0) {
    myservo.write(90);
    delay(20);
    state = 0;
  }
  //  myservo.write(180);
}
