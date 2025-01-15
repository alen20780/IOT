#include <Adafruit_Keypad.h>

// Define the rows and columns for the keypad
const byte ROWS = 4;  // Number of rows
const byte COLS = 4;  // Number of columns

// Define the keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the row and column pins
byte rowPins[ROWS] = {2, 3, 4, 5};  // Row pins connected to the Arduino
byte colPins[COLS] = {6, 7, 8, 9};  // Column pins connected to the Arduino

// Create an instance of the keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Start serial communication
  customKeypad.begin(); // Initialize the keypad
}

void loop() {
  // Check for key events
  customKeypad.tick();

  while (customKeypad.available()) {
    // Get the pressed key
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) { // When a key is pressed
      Serial.print("Key Pressed: ");
      Serial.println((char)e.bit.KEY);
    }
  }
}
