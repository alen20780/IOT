#include <TM1637Display.h>

// Define the pins for CLK and DIO
#define CLK 11
#define DIO 13

// Create an instance of TM1637Display
TM1637Display display(CLK, DIO);

void setup() {
  // Set brightness (0-7)
  display.setBrightness(5);

  // Display "1234" on the 7-segment
  display.showNumberDec(8888);
  delay(2000);
}

void loop() {
  // Count up from 0 to 9999
  for (int i = 0; i <= 9999; i++) {
    display.showNumberDec(i); // Display the number
    delay(500);               // Wait for 500ms
  }
}
