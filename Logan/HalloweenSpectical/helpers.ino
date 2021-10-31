void setLed(int num, CRGB color) {
  leds[num] = color;
}

void setLed(int num, CHSV color) {
  leds[num] = color;
}

// Sets leds, not inclusive at last
void setLeds(int first, int last, CRGB color) {
  for (int i = first; i < last; i++) {
    setLed(i, color);
  }
}

// Sets leds, not inclusive at last
void setLeds(int first, int last, CHSV color) {
  for (int i = first; i < last; i++) {
    setLed(i, color);
  }
}


// Sets leds from array
void setLeds(int lights[], int numLeds, CRGB color) {
  for (int i = 0; i < numLeds; i++) {
    setLed(lights[i], color);
  }
}

// Sets leds from array
void setLeds(int lights[], int numLeds, CHSV color) {
  for (int i = 0; i < numLeds; i++) {
    setLed(lights[i], color);
  }
}

// Returns a boolean to say whether it should run based on the clock
boolean goTime(int t) {
  return (clock % (t / 5)) == 0;
}
