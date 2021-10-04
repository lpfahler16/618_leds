#include <FastLED.h>
#define LED_PIN 7
#define LED_PIN_2 8
#define NUM_LEDS 300
char in = 'a';

CRGB leds[NUM_LEDS];
long clock;

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.addLeds<WS2812, LED_PIN_2, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.show();
    Serial.begin(9600);
    clock = 0;
}

void loop() {
  if (Serial.available() > 0) {
    FastLED.clear();
    in = Serial.read();
    clock = 0;
  }
  if (in == 'a') {
    sectionFade(1);
  }
  else if (in =='b') {
     pats();
  }
  else if (in == 'r') {
     allColor(CRGB(255, 0, 0));
  }
  else if (in == 'g') {
     allColor(CRGB(0, 255, 0));
  }
  else if (in == 'v') {
     allColor(CRGB(0, 0, 255));
  }
  else if (in == 'y') {
     allColor(CRGB(255, 255, 0));
  }
  else if (in == 'w') {
     allColor(CHSV(255, 0, 200));
  }
  else {
     allColor(CRGB(255, 0, 255));
  }
  delay(5);
  clock += 1;
  if (clock == 1000000) {
    clock = 0;
  }
}
