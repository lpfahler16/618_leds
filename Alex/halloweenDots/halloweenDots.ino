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

void std_dots() {
  dots(1, 150, 5, 255, 2);
}

void fast_dots() {
  dots(8, 10, 10, 255, 2);
}

void slow_dots() {
  dots(4, 35, 2, 255, 2);
}

void dots(int sections, int len, int sped, int brightness, int fade) {
  // Changable
  int NUM_SECTIONS = sections;
  int SECTION_LENGTH = len;
  int SPEED = sped;
  int BRIGHTNESS = brightness;
  int FADE = fade; // KEEP BETWEEN 0 and 2
  
  int TRACK_LENGTH = (NUM_LEDS - SECTION_LENGTH)*2;
  int SECTION_OFFSET = TRACK_LENGTH / NUM_SECTIONS;
  
  FastLED.clear();

  // Iterate to make sections
  for (int sec = 0; sec < NUM_SECTIONS; sec++) {
    int offset = sec * SECTION_OFFSET;
    int pos = (int) ((clock + offset) * (SPEED / 5.0)) % TRACK_LENGTH;

    // Switch directions
    if (pos >= TRACK_LENGTH/2) {
      pos = TRACK_LENGTH - 1 - pos;
    }

    // Light up leds
    for (int l = 0; l < SECTION_LENGTH; l++) {
      int brightness = BRIGHTNESS - abs(SECTION_LENGTH/2 - l) * (BRIGHTNESS/SECTION_LENGTH) * FADE;
      leds[pos + l] = CHSV(24, 255, brightness);
    }
  }
  FastLED.show();
}

void loop() {
  if (Serial.available() > 0) {
    FastLED.clear();
    in = Serial.read();
    clock = 0;
  }
  if (in == 'a') {
    std_dots();
  }
  else if (in =='b') {
     std_dots();
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
