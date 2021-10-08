void std_dots() {
  dots(5, 15, 5, 255, 2);
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
    int pos = (int) ((long) ((clock + offset) * (SPEED / 5.0)) % TRACK_LENGTH);

    // Switch directions
    if (pos >= TRACK_LENGTH/2) {
      pos = TRACK_LENGTH - 1 - pos;
    }

    // Light up leds
    for (int l = 0; l < SECTION_LENGTH; l++) {
      int brightness = BRIGHTNESS - abs(SECTION_LENGTH/2 - l) * (BRIGHTNESS/SECTION_LENGTH) * FADE;
      setLed(pos + l, CHSV((((255 / NUM_SECTIONS) * sec) + pos) % 255, 255, brightness));
    }
  }
  FastLED.show();
}
