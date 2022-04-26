#include <Lamp.h>
Lamp lamp;
int i;
int set;
int os;

void setup() {
  i = 0;
  set = 200;
  os = 50;
}

void loop() {
  if (i < set/2) {
    lamp.SetLamp(CRGB(i + os, i + os, i + os));
  } else {
    lamp.SetLamp(CRGB(set - i + os, set - i + os, set - i + os));
  }
  lamp.Show();
  lamp.Delay(40);
  i = i % set;
  i++;
}
