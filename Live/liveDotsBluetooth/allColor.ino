void allColor(CRGB color) {
   if(clock == 0) {
      setLeds(0, NUM_LEDS, color);
      FastLED.show();
   }
}
