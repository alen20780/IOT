#include <DHT.h>

// Define the pin where the DHT11 is connected
#define DHTPIN 2  // Pin connected to the Data pin of DHT11
#define DHTTYPE DHT11  // Define the type of DHT sensor (DHT11)

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Start serial communication
  Serial.println("DHT11 sensor example");
  dht.begin();  // Initialize the DHT sensor
  delay(1000);
}

void loop() {
  delay(2000);  // Wait a few seconds between measurements

  // Reading temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any readings failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
