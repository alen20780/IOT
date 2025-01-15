#include <GyverOLED.h>
#include "DHT.h"

#define DHTPIN 2    // Pin the DHT11 is connected to
#define DHTTYPE DHT11   // DHT sensor type (can also be DHT22)

GyverOLED<SSH1106_128x64> oled;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  delay(1000);
  initDisplay();
  printUI();
  oled.setScale(1);  
}

void loop() {  
  float temperature = readTemperature();  // Get temperature
  float humidity = readHumidity();        // Get humidity

  // Print temperature
  oled.setCursorXY(28, 38);
  oled.print(String(temperature, 1) + "C");

  // Print humidity
  oled.setCursorXY(28, 48);
  oled.print(String(humidity, 1) + "%");

  oled.update();  // Update display
  delay(2000);    // Wait for 2 seconds
}

float readTemperature() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    oled.clear();
    oled.setCursorXY(10, 28);
    oled.print("Error reading temperature!");
  }
  return temperature;
}

float readHumidity() {
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    oled.clear();
    oled.setCursorXY(10, 48);
    oled.print("Error reading humidity!");
  }
  return humidity;
}

void initDisplay() {
  oled.init();  
  oled.clear();   
  oled.update(); 
}

void printUI() {
  oled.home();   
  oled.rect(0,0,127,63,OLED_STROKE);
  oled.setCursorXY(30, 8);
  oled.setScale(1);
  oled.print("Temperature &");
  oled.setCursorXY(30, 20);
  oled.setScale(1);
  oled.print("Humidity");
  oled.setScale(1);
  oled.setCursorXY(85, 32);
  oled.print("o");
  oled.setScale(1);
  oled.setCursorXY(92, 38);
  oled.print("C");
  oled.setCursorXY(85, 45);
  oled.print("%");
  oled.update();
}
