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
  drawStaticUI();  // Draw static elements once
  customKeypad.begin();
}

void loop() {
  customKeypad.tick();
  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      char pressedKey = (char)e.bit.KEY;

      if (pressedKey >= '0' && pressedKey <= '9') {
        inputAngle += pressedKey;
        updateInputArea(inputAngle);  // Update input area dynamically
      } else if (pressedKey == '#') {
        int angle = inputAngle.toInt();
        if (angle >= 0 && angle <= 180) {
          myServo.write(angle);
          updateFeedback("Angle: " + String(angle));
        } else {
          updateFeedback("Error.");
        }
        inputAngle = "";  // Clear input after processing
        updateInputArea(inputAngle);
      } else if (pressedKey == '*') {
        inputAngle = "";  // Clear input
        updateInputArea(inputAngle);
        updateFeedback("Input Cleared");
        oled.clear();
        delay(200);
        drawStaticUI();
      } else {
        updateFeedback("Invalid Key");
        oled.clear();
        delay(200);
        drawStaticUI();
      }
    }
  }
  delay(100);
}

void initDisplay() {
  oled.init();  
  oled.clear();   
  oled.update(); 
}

void drawStaticUI() {
  oled.clear();
  oled.setScale(1);

  // Draw a border
  oled.rect(0, 0, 127, 63, OLED_STROKE);

  // Display the title
  oled.setCursorXY(10, 5);
  oled.print("ENTER ANGLE:");

  // Labels for input and feedback
  oled.setCursorXY(5, 30);
  oled.print("Input: ");
  
  oled.setCursorXY(5, 45);
  oled.print("Status: ");

  oled.update();
}

void updateInputArea(String input) {
  oled.setScale(1);
  oled.setCursorXY(50, 30);  // Position for the input area
  oled.print("          ");   // Clear previous input
  oled.setCursorXY(50, 30);  // Reset position
  oled.print(input);         // Display new input
  oled.update();
}

void updateFeedback(String message) {
  oled.setScale(1);
  oled.setCursorXY(50, 45);  // Position for the feedback area
  oled.print("          ");   // Clear previous feedback
  oled.setCursorXY(50, 45);  // Reset position
  oled.print(message);       // Display new feedback
  oled.update();
}
