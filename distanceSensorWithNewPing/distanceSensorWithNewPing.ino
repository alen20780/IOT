#include <NewPing.h>

#define tp 10
#define ep 13
#define maxd 400

NewPing sonar(tp, ep, maxd);
float distance;
void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = sonar.ping_cm();

   Serial.print("Distance = ");
   if(distance >= 400 || distance <= 2){
      Serial.println("Out of range");
    }
   else {
      Serial.print(distance);
      Serial.print(" cm");
      delay(500);
    }
  delay(500);
}
