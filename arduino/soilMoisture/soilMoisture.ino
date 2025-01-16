const int dry = 490;
const int wet = 230;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A0);
  Serial.println("Sensor Value: " + String(sensorVal));
  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);
  Serial.print("HUMIDITY: " + String(percentageHumidity));
  Serial.println("%");
  delay(100);
}
