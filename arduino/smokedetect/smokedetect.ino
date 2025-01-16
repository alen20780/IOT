const int bp = 11;
const int sensorPin = A0;  // Pin where the MQ-2 sensor is connected (analog pin A0)
int sensorValue = 0;       // Variable to store the analog value from the sensor

void setup() {
  Serial.begin(9600);       // Start serial communication at 9600 baud rate
  pinMode(sensorPin, INPUT); // Set sensor pin as input
  pinMode(bp, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Read the analog value from MQ-2 sensor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);          // Print the sensor value to the Serial Monitor
  if (sensorValue > 820){
    Serial.print("Smoke Detected!");
    digitalWrite(bp, HIGH);
  }
  else{
    Serial.print(" ");
    digitalWrite(bp, LOW);  
  }
  delay(500);  // Delay for  second before reading again
}
