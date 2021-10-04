#include <FastLED.h>
#define LED_PIN 7
#define LED_PIN_2 8
#define NUM_LEDS 300

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
  int clockRead = (clock / 500) % 2;
  if (clockRead == 0) {
    setLeds(0, NUM_LEDS/4, CRGB(0, 0, 255);
    setLeds(NUM_LEDS/4, NUM_LEDS/2, CRGB(255, 255, 255);
    setLeds(NUM_LEDS/2, 3*NUM_LEDS/4, CRGB(0, 0, 255);
    setLeds(3*NUM_LEDS/4, NUM_LEDS, CRGB(255, 255, 255);
  } else {
    setLeds(0, NUM_LEDS/4, CRGB(255, 0, 0);
    setLeds(NUM_LEDS/4, NUM_LEDS/2, CRGB(255, 255, 255);
    setLeds(NUM_LEDS/2, 3*NUM_LEDS/4, CRGB(255, 0, 0);
    setLeds(3*NUM_LEDS/4, NUM_LEDS, CRGB(255, 255, 255);
  }
  FastLED.show();
}
