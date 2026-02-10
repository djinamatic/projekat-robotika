#include <Servo.h>
Servo myServo;
const int ldrPin = A1;  

const int servoPin = A0;

int threshold = 280;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(90);
}
void loop() {

  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue > threshold) {

    // servo "pritisne space"
    myServo.write(45);   // ako ne dodiruje space, probaj 50 ili 60
    delay(120);
    // vrati servo nazad

    myServo.write(90);
    // pauza da ne skače 2x
    delay(50);

  }
  else {
    myServo.write(90);
    delay(30);
  }

  delay(10);

}
