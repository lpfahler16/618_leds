#include <FastLED.h>

#define NUM_LEDS 300
CRGB leds[NUM_LEDS];
int brightness = 150;
boolean isGoingDown = true;

void setup() {
  // put your setup code here, to run once:
  FastLED.delay(300);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  breathingLeds();
  
  FastLED.show();
  FastLED.delay(100);
}

void breathingLeds() {
  CRGB ledColor = CHSV (CRGB (113, 0, 188), 0, brightness);
  setLeds(0, 300, ledColor);
  
  if (!goTime(100)) {
    return;
  }
  
  if (brightness <= 25 && !isGoingDown) {
    for (int i = 0; i < NUM_LEDS; i++) {
      setLed(i, CHSV (CRGB (113, 0, 188), 0, brightness));
      brightness += 1;
      isGoingDown = false;
    }
  }
  else {
    for (int i = 0; i < NUM_LEDS; i++) {
      setLed(i, CHSV (CRGB (113, 0, 188), 0, brightness));
      brightness -= 1;
      isGoingDown = true;
    }
  }
  
}
