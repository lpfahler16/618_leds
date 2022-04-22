#include <Lamp.h>

Lamp lamp;

void setup() {
}

void loop() {
  int height = 20;
  while(true) {
    for(int i = 0; i < Lamp::LENGTH + height; i++) {
      lamp.Clear();
      lamp.SetRings(i - height, i, CRGB(255, 0, 255));
      lamp.Show();
      delay(20);
    }
  }
}
