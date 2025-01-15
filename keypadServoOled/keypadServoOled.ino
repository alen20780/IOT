#include <GyverOLED.h>
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
GyverOLED<SSH1106_128x64> oled;

String inputAngle = "";

void setup() {
  myServo.attach(13);
  initDisplay();
  printCentered("Enter Angle:");
  customKeypad.begin();
  delay(200);
}

void loop() {
  customKeypad.tick();
  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      char pressedKey = (char)e.bit.KEY;

      oled.clear(); // Clear the screen before updating the display

      if (pressedKey >= '0' && pressedKey <= '9') {
        inputAngle += pressedKey;
        printCentered("Input: " + inputAngle);
      } else if (pressedKey == '#') {
        int angle = inputAngle.toInt();
        if (angle >= 0 && angle <= 180) {
          myServo.write(angle);
          printCentered("Angle Set: " + String(angle));
        } else {
          printCentered("Error: Invalid Angle");
        }
        inputAngle = "";
      } else if (pressedKey == '*') {
        inputAngle = "";
        printCentered("Input Cleared");
      } else {
        printCentered("Invalid Key");
      }
      oled.update();
    }
  }
  delay(300); 
} 

void initDisplay() {
  oled.init();  
  oled.clear();   
  oled.update(); 
}

void printCentered(String message) {
  oled.clear(); 
  oled.setScale(2); 
  
  byte textWidth = message.length() * 6 * 2;
  byte x = (128 - textWidth) / 2; 
  byte y = 24; 

  oled.setCursorXY(x, y);
  oled.print(message);
  oled.update();
}
