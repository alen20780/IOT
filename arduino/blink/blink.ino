const int bp = 11;
const int wp = 10;
const int gp = 9;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(bp, OUTPUT);
  pinMode(wp, OUTPUT);
  pinMode(gp, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //blue led with buzzer
  for (int freq = 100; freq <= 1000; freq += 100) { // Increase pitch
    tone(bp, freq, 20); // Play frequency for 200ms
    delay(200);
  }
  for (int freq = 1000; freq >= 100; freq -= 100) { // Decrease pitch
    tone(bp, freq, 20); // Play frequency for 200ms
    delay(200);                 // Pause before the next tone
  }
  //white led  
  for (int freq = 100; freq <= 1000; freq += 100) { // Increase pitch
    tone(wp, freq, 20); // Play frequency for 200ms
    delay(200);
  }
  for (int freq = 1000; freq >= 100; freq -= 100) { // Decrease pitch
    tone(wp, freq, 20); // Play frequency for 200ms
    delay(200);                 // Pause before the next tone
  }
  //green led
  for (int freq = 100; freq <= 1000; freq += 100) { // Increase pitch
    tone(gp, freq, 20); // Play frequency for 200ms
    delay(200);
  }
  for (int freq = 1000; freq >= 100; freq -= 100) { // Decrease pitch
    tone(gp, freq, 20); // Play frequency for 200ms
    delay(200);                 // Pause before the next tone
  }
} 
