#include <NewPing.h>
#include <Servo.h>

#define tp 10
#define ep 13
#define maxd 400

NewPing sonar(tp, ep, maxd);
Servo myServo;
float distance;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  distance = sonar.ping_cm();
  int angle = map(distance, 400, 2, 0, 180);
  myServo.write(angle);
  delay(1000);
   Serial.print("Distance = ");
   if(distance >= 400 || distance <= 2){
      Serial.println("Out of range");
    }
   else {
      Serial.print(distance);
      Serial.print(" cm");
      delay(1000);
    }
  delay(1000);
}
