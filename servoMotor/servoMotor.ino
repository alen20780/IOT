#include <Servo.h> // Include the Servo library

Servo myServo;  // Create a Servo object to control the MG90S

void setup() {
  myServo.attach(9); // Attach the servo to pin 9
}

void loop() {
  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle); // Set servo to the current angle
    delay(15);            // Wait for 15ms for the servo to reach the angle
  }

  // Sweep back from 180° to 0°
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle); // Set servo to the current angle
    delay(15);            // Wait for 15ms for the servo to reach the angle
  }
}
