#include <FastLED.h>
#define LED_PIN 7
#define LED_PIN_2 8
#define LED_PIN_3 9
#define NUM_LEDS 53
char in = 'a';
int brightness = 150;
boolean isGoingDown = true;

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
long clock;

void SetRing(int ring, CRGB color) {
  leds1[ring] = color;
  leds2[ring] = color;
  leds3[ring] = color;
}

void SetLamp(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    SetRing(i, color);
  }
}

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN_2, GRB>(leds2, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN_3, GRB>(leds3, NUM_LEDS);
  FastLED.clear();
  for (int i = 0; i < 256; i++) {
    SetLamp(CRGB(i,i,i));
    FastLED.show();
    delay(5);
  }
}

void loop() {
  SetLamp(CRGB(255, 0, 0));
  FastLED.show();
  
  delay(500);
  SetLamp(CRGB(0, 0, 255));
  FastLED.show();
  delay(500);
}
