void sectionFade(int numSections) {
  //mood mood lamp that cycles through colours

  int COLOR_OFFSET = 60;
  int SECTION_LENGTH = (NUM_LEDS / numSections);
  
  if (clock % 20 == 0) {
    for (int i=0;i<NUM_LEDS;i++){

      int finalOffset = (i / SECTION_LENGTH) * COLOR_OFFSET;
      
      int currColor = ((clock/20) + finalOffset) % 508;
      
      if(currColor > 254){
        currColor = 508 - currColor; //reverse once we get to 254
      }
      
      leds[i] = CHSV( currColor, 255, 255);
    }
    FastLED.show();
 }
}
