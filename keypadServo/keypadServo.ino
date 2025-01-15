#include <Servo.h>
#include <Adafruit_Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo myServo;

String inputAngle = ""; 

void setup() {
  Serial.begin(9600);       
  myServo.attach(13);        
  customKeypad.begin();    
  Serial.println("Enter an angle (0-180) followed by # to set the servo.");
}

void loop() {
  customKeypad.tick();
  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      char pressedKey = (char)e.bit.KEY;

      if (pressedKey >= '0' && pressedKey <= '9') {
        inputAngle += pressedKey;
        Serial.print("Current Input: ");
        Serial.println(inputAngle);
      } else if (pressedKey == '#') {
        int angle = inputAngle.toInt();
        if (angle >= 0 && angle <= 180) {
          myServo.write(angle);
          Serial.print("Servo angle set to: ");
          Serial.println(angle);
        } else {
          Serial.println("Error: Angle out of range (0-180).");
        }
        inputAngle = "";
      } else if (pressedKey == '*') {
        inputAngle = "";
        Serial.println("Input cleared.");
      } else {
        Serial.println("Invalid key. Use 0-9, * to clear, or # to confirm.");
      }
    }
  }

  delay(300); 
}
