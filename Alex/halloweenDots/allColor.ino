void allColor(CRGB color) {
   if(clock == 0) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color;
    }
    FastLED.show();
   }
}
