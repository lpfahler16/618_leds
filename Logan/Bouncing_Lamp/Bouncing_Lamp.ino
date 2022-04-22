#include <Lamp.h>

Lamp lamp;

float velocity;
float gravity;
float gap;
float pos;
float del;
float VI = 5;
float bounce = 0.85;

void setup() {
  velocity = VI;
  gravity = 9.81;
  gap = 0.015;
  del = 10;
  pos = 0;
  Serial.begin(9600);
}

void loop() {

  for (int i = Lamp::LENGTH - 1; i >= 0; i -= Lamp::LENGTH/5) {
    lamp.SetRings(i + 4, Lamp::LENGTH, CRGB(0,0,0));
    lamp.SetRings(i, i + 4, CRGB(255,0,0));
    lamp.SetRings(0, i, CRGB(100,100,100));
    lamp.Show();
    delay(1000);
  }

  while (velocity > 0) {
    lamp.SetRings(0, pos, CRGB(100, 100, 100));
    draw();
  }

  while (!(pos == 0 && abs(velocity) < 1)) {
    lamp.SetLamp(CRGB(100, 100, 100));
    draw();
  
    if (pos < 0) {
      velocity = -velocity*bounce;
      pos = 0;
    }
  }
  velocity = VI;
  
}

void draw() {
  float p_d = pos - floor(pos);
  Serial.println(p_d);
  lamp.SetRing(pos - 1, CRGB(255*(1 - p_d),0,0));
  lamp.SetRings(pos, pos + 2, CRGB(255,0,0));
  lamp.SetRing(pos + 2, CRGB(255*(p_d),0,0));
  lamp.Show();
  delay(del);
  pos += (velocity*del/1000)/gap;
  velocity -= gravity*del/1000;
}
