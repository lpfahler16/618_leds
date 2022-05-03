#include <Lamp.h>

Lamp lamp;
int i;

void setup() {
  i = 0;

}

void loop() {
  for(int j = 0; j < 255; j++) {
    int pos = 3*(j+i) % (255*3);
    lamp.SetRings(pos, pos + 2, CHSV(j, 255, 255));
  }
  lamp.Show();
  lamp.Delay(100);
  i++;
  i %= 255;
}
