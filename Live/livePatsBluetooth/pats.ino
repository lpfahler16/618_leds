void pats() {
  if (!goTime(100)) {
    return;
  }
  int off_clock = (clock/20) % 510;
  if (off_clock < 255) {
    setLeds(0, NUM_LEDS/4, CRGB(255 - off_clock, 0, off_clock));
    setLeds(NUM_LEDS/4, NUM_LEDS/2, CRGB(255, 255, 255));
    setLeds(NUM_LEDS/2, 3*NUM_LEDS/4, CRGB(255 - off_clock, 0, off_clock));
    setLeds(3*NUM_LEDS/4, NUM_LEDS, CRGB(255, 255, 255));
  } else {
    setLeds(0, NUM_LEDS/4, CRGB(off_clock - 255, 0, 510 - off_clock));
    setLeds(NUM_LEDS/4, NUM_LEDS/2, CRGB(255, 255, 255));
    setLeds(NUM_LEDS/2, 3*NUM_LEDS/4, CRGB(off_clock - 255, 0, 510 - off_clock));
    setLeds(3*NUM_LEDS/4, NUM_LEDS, CRGB(255, 255, 255));
  }
  FastLED.show();
}
