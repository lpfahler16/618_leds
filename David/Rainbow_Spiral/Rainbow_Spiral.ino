//Lamp Rainbow Spiral Program

#include <FastLED.h>
#include <Lamp.h>

Lamp lamp;
int i = 0;
int x = 0;
uint32_t color[8] = {0xFF0000, 0xFFA500, 0xFFFF00, 0x00FF00, 0x40E0D0, 0x0000FF, 0x800080, 0x800000};
bool goUp = true;
  
void setup() {
  
}

void loop() {
  if(goUp)
    UpwardSpiral();
  else
    DownwardSpiral();
  lamp.Show();

}

void UpwardSpiral() {
  lamp.Clear();
  lamp.SetLED(0, i, color[x]);
  lamp.SetLED(1, i+1, color[x]);
  lamp.SetLED(2, i+2, color[x]);
  lamp.Delay(50);

  i = i+3;
  x = x+1;
  x = x % 8;
  if(i > lamp.LENGTH-2) 
    goUp = false;
}

void DownwardSpiral() {
  lamp.Clear();
  lamp.SetLED(0, i, color[x]);
  lamp.SetLED(1, i-1, color[x]);
  lamp.SetLED(2, i-2, color[x]);
  lamp.Delay(50);

  i = i-3;
  x = x+1;
  x = x % 8;
  if(i < 2) 
    goUp = true;
}
