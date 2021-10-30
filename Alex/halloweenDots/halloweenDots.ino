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
  slide(3, 50, 10, 255, 2);
  delay(5);
  clock += 1;
  if (clock == 1000000) {
    clock = 0;
  }
}
