#include <Wire.h>
#include "FastLED.h"

#define NUM_LEDS 300
#define DATA_PIN 7
#define DATA_PIN_2 8




int fade_h;
int fade_direction = 1;

CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds, NUM_LEDS);
}




void colour_fade(){
  //mood mood lamp that cycles through colours
  for (int i=0;i<NUM_LEDS;i++){
    leds[i] = CHSV( fade_h, 255, 255);
  }
  if(fade_h >254){
    fade_direction = -1; //reverse once we get to 254
  }
  else if(fade_h < 0){
    fade_direction = 1;
  }
    
  fade_h += fade_direction;
  FastLED.show();
  delay(100);
}




void loop() { 
    colour_fade();
    delay(0);
  }
