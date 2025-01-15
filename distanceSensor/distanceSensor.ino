#define trigPin 10
#define echoPin 13

float duration, distance;
 
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //PULSE
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //RESPONSE
  duration = pulseIn(echoPin,HIGH);
  //determine distance from duration
  //use 343 mps as speed of sound
  distance = (duration / 2) * 0.0343;
  //results to serial monitor
  Serial.print("Distance: ");
  if (distance >= 400 || distance <=2){
     Serial.println("Out of range.");
  }
  else{
    Serial.print(distance);
    Serial.print(" cm");
    delay(500);
   }
   delay(500);
}
