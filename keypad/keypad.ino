// Define the rows and columns
const int rows[] = {2, 3, 4, 5};  // Row pins
const int cols[] = {6, 7, 8, 9};  // Column pins

// Define the keymap
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup() {
  Serial.begin(9600);

  // Set row pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH); // Keep rows HIGH
  }

  // Set column pins as inputs with pull-up resistors
  for (int i = 0; i < 4; i++) {
    pinMode(cols[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int row = 0; row < 4; row++) {
    // Set the current row LOW
    digitalWrite(rows[row], LOW);

    // Check each column
    for (int col = 0; col < 4; col++) {
      if (digitalRead(cols[col]) == LOW) { // Key is pressed
        Serial.print("Key Pressed: ");
        Serial.println(keys[row][col]);
        delay(200); // Debounce delay
      }
    }

    // Set the row back to HIGH
    digitalWrite(rows[row], HIGH);
  }
}
