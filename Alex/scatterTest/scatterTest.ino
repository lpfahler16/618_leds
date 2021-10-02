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

void scatter() {
  int NUM_DOTS = 5;
  int SECTIONS = 1;
  int SPEED = 5;
  int BRIGHTNESS = 255;

  int TRACK_LENGTH = (NUM_LEDS - (SECTIONS*NUM_DOTS))*2;
  int SECTION_OFFSET = TRACK_LENGTH / SECTIONS;
  
  FastLED.clear();

  // Iterate to make sections
  for (int sec = 0; sec < NUM_DOTS; sec++) {
    int offset = sec * SECTION_OFFSET;
    int pos = (int) ((clock + offset) * (SPEED / 5.0)) % TRACK_LENGTH;

    // Switch directions
    if (pos >= TRACK_LENGTH/2) {
      pos = TRACK_LENGTH - 1 - pos;
    }

    // Scatter lights
    if (pos = TRACK_LENGTH/4) {
      //pos = //i have no idea what to do here to actually make the individual dots move at separate rates of speed 
    }

    // Light up leds
    setLeds(pos, pos + SECTIONS, CRGB(255, 255, brightness));
  }
  FastLED.show();
}

void loop() {
  scatter();
}
