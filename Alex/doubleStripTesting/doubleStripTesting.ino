#include <FastLED.h>
#define LED_PIN 7
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

void setup() {
    delay(3000);
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.show();
    Serial.begin(9600);
}

void blue(){
  for (int i=0;i<NUM_LEDS;i++){
    leds[i] = CRGB(0, 0, 255);
  }
}

void loop() {
  blue();
  delay(0);
}
