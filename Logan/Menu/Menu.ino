#include <Lamp.h>

Lamp lamp;
int val = 0;

void setup() {
  lamp.SetLamp(CRGB(255,255,255));
  lamp.Show();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int temp = Serial.parseInt();
    if (temp != 0) {
      val = temp;
    }
  }
  lamp.Clear();
  lamp.SetRings(val, val + Lamp::LENGTH/8, CRGB(255,255,255));
  lamp.Show();
}
