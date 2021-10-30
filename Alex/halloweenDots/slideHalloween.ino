void slide(int sections, int len, int sped, int brightness, int fade) {
  // Changable
  int NUM_SECTIONS = sections;
  int SECTION_LENGTH = len;
  int SPEED = sped;
  int BRIGHTNESS = brightness;
  int FADE = fade; // KEEP BETWEEN 0 and 2
  int TRACK_LENGTH = NUM_LEDS;
  int SECTION_OFFSET = TRACK_LENGTH / NUM_SECTIONS;
  
  FastLED.clear();

  // Iterate to make sections
  for (int sec = 0; sec < NUM_SECTIONS; sec++) {
    int offset = sec * SECTION_OFFSET;
    int pos = ((int) (clock + offset) * (SPEED / 5.0));

    // Light up leds
    for (int l = 0; l < SECTION_LENGTH; l++) {
      int brightness = BRIGHTNESS - abs(SECTION_LENGTH/2 - l) * (BRIGHTNESS/SECTION_LENGTH) * FADE;
      setLed((pos + l) % NUM_LEDS, CHSV(21, 255, brightness));
    }
  }
  FastLED.show();
}
