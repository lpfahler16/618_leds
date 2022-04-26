#include <Lamp.h>

Lamp lamp;

float GAP = 0.015;
float pos_r = 0;
float pos_b = 0;

float velocity_r;
float velocity_b;
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
  lamp.SetLamp(CRGB(100, 100, 100));
  bounce_r();
  bounce_b();
  lamp.Show();
  delay(del);
}

void bounce_r() {
  if ((pos_r == 0 && abs(velocity_r) < 0.75)) {
    velocity_r = randomVelocity();
  }
  draw_r();
  pos_r += (velocity_r*del/1000)/GAP;
  velocity_r -= gravity*del/1000;

  if (pos_r < 0) {
    velocity_r = -1*velocity_r*cons_energy;
    pos_r = 0;
  }
}
void bounce_b() {
  if ((pos_b == 0 && abs(velocity_b) < 0.75)) {
    velocity_b = randomVelocity();
  }
  draw_b();
  pos_b += (velocity_b*del/1000)/GAP;
  velocity_b -= gravity*del/1000;

  if (pos_b < 0) {
    velocity_b = -1*velocity_b*cons_energy;
    pos_b = 0;
  }
}

void draw_r() {
  float p_d = pos_r - floor(pos_r);
  lamp.SetRing(pos_r - 1, CHSV(255*(1 - p_d),0,0));
  lamp.SetRings(pos_r, pos_r + 2, CRGB(255,0,0));
  lamp.SetRing(pos_r + 2, CRGB(255*(p_d),0,0));
}

void draw_b() {
  float p_d = pos_b - floor(pos_b);
  lamp.SetRing(pos_b - 1, CHSV(0,0,255*(1 - p_d)));
  lamp.SetRings(pos_b, pos_b + 2, CRGB(0,0,255));
  lamp.SetRing(pos_b + 2, CRGB(0,0,255*(p_d)));
}

float randomVelocity() {
  float v = (rand() % int((vmax - vmin) * 10) + (vmin * 10)) / 10.0;
  Serial.println(v);
  return v;
}
