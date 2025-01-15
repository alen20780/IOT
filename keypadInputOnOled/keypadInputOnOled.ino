#include <GyverOLED.h>
#include <Adafruit_Keypad.h>
GyverOLED<SSH1106_128x64> oled;
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

void setup() {
  delay(500);
  initDisplay();
  printUI();
  oled.setScale(2);  
  customKeypad.begin();
}

void loop()
 {  
  oled.setCursorXY(45, 28);
  oled.update();
  customKeypad.tick();
  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) { 
      oled.print((char)e.bit.KEY);
    }
  }
  delay(200);
}

void initDisplay()
{
  oled.init();  
  oled.clear();   
  oled.update(); 
}

void printUI()
{
  oled.home();   
  oled.rect(0,0,127,63,OLED_STROKE);
  oled.setCursorXY(30, 15);
  oled.setScale(1);
  oled.print("KEYPAD INPUT:");
  oled.update();
}
