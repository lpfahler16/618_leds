#include <FastLED.h>
#define LED_PIN 7
#define LED_PIN_2 8
#define NUM_LEDS 300

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

void loop() {
  delay(5);
  sectionFade(3);
  clock += 1;
  if (clock == 1000000) {
    clock = 0;
  }
}
