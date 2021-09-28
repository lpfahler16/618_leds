#include <FastLED.h>
#define LED_PIN 7
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.show();
    Serial.begin(9600);
}

void dots() {
  for (int i = 90; i < NUM_LEDS; i++) {
    FastLED.clear();
    leds[90+i] = CRGB(255, 0, 0);
    leds[91+i] = CRGB(255, 0, 0);
    leds[92+i] = CRGB(255, 0, 0);
    delay(100);
  }
}

void loop() {
  if (leds[100] = 1) {
    FastLED.clear();
    FastLED.show();
    leds[200] = CRGB(0, 0, 255);
  }
  dots();
}
