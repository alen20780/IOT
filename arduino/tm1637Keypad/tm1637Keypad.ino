#include <Adafruit_Keypad.h>
#include <TM1637Display.h>

// Define the pins for CLK and DIO
#define CLK 11
#define DIO 13

// Create an instance of TM1637Display
TM1637Display display(CLK, DIO);

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
  Serial.begin(9600);         // Start serial communication
  customKeypad.begin();       // Initialize the keypad
  display.setBrightness(5);   // Set display brightness
  display.showNumberDec(8888); // Display "8888" initially
  delay(2000);
}

void loop() {
  // Check for key events
  customKeypad.tick();

  while (customKeypad.available()) {
    // Get the pressed key
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) { // When a key is pressed
      char pressedKey = (char)e.bit.KEY; // Get the character of the pressed key
      Serial.print("Key Pressed: ");
      Serial.println(pressedKey);

      if (pressedKey >= '0' && pressedKey <= '9') {
        // If the key is a number, display it
        int num = pressedKey - '0'; // Convert ASCII to numeric value
        display.showNumberDec(num);
      } else {
        // If it's a non-numeric key, display "----"
        uint8_t customSegments[] = {0x40, 0x40, 0x40, 0x40}; // Four dashes
        display.setSegments(customSegments);
      }
    }
  }
}
