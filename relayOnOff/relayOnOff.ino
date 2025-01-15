#define relayPin 12  // Pin connected to the relay IN pin

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relayPin as output
  digitalWrite(relayPin, LOW);  // Initialize the relay to off
}

void loop() {
  digitalWrite(relayPin, HIGH);  // Turn relay on (close the NO and COM connection)
  delay(2000);  // Wait for 2 seconds

  digitalWrite(relayPin, LOW);  // Turn relay off (open the NO and COM connection)
  delay(2000);  // Wait for 2 seconds
}
