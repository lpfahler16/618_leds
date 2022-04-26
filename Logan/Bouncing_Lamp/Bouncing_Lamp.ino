#include <Lamp.h>

Lamp lamp;

float GAP = 0.015;
float pos = 0;

float velocity;
float gravity;
float del;
float cons_energy;
float vmin;
float vmax;
float TOP_POS;

void setup() {

  TOP_POS = Lamp::LENGTH*GAP;
  
  vmin = 2;
  vmax = 7;
  gravity = 9.81;
  del = 10;
  cons_energy = 0.8;
  Serial.begin(9600);
}

void loop() {
  velocity = randomVelocity();
  bounce();
}

void spring() {
  velocity = randomVelocity();
  for (int i = Lamp::LENGTH - 1; i >= 0; i -= Lamp::LENGTH/5) {
    lamp.SetRings(i + 4, Lamp::LENGTH, CRGB(0,0,0));
    lamp.SetRings(i, i + 4, CRGB(255,0,0));
    lamp.SetRings(0, i, CRGB(100,100,100));
    lamp.Show();
    lamp.Delay(1000);
//    delay(1000);
  }
}

void launch() {
  while (pos < TOP_POS) {
    lamp.SetRings(0, pos, CRGB(100, 100, 100));
    draw();
    pos += (velocity*del/1000)/GAP;
    lamp.Delay(1000);
//    delay(1000);
  }
}

void bounce() {
  while (!(pos == 0 && abs(velocity) < 0.75)) {
    lamp.SetLamp(CRGB(100, 100, 100));
    draw();
    lamp.Delay(del);
//    delay(del);
    pos += (velocity*del/1000)/GAP;
    velocity -= gravity*del/1000;
  
    if (pos < 0) {
      velocity = -1*velocity*cons_energy;
      pos = 0;
    }
  }
}

void draw() {
  float p_d = pos - floor(pos);
  lamp.SetRing(pos - 1, CHSV(255*(1 - p_d),0,0));
  lamp.SetRings(pos, pos + 2, CRGB(255,0,0));
  lamp.SetRing(pos + 2, CRGB(255*(p_d),0,0));
  lamp.Show();
}

float randomVelocity() {
  float v = (rand() % int((vmax - vmin) * 10) + (vmin * 10)) / 10.0;
  Serial.println(v);
  return v;
}
