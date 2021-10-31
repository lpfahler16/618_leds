#include <FastLED.h>
#define LED_PIN 7
#define LED_PIN_2 8
#define NUM_LEDS 300
char in = 'a';

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

void loop() {
  switch(random(1,500)){
    case 1:
      thunderburst();
      Serial.println("thunder 1");
      break;
     
    case 2:
      rolling();
      Serial.println("rolling 1");
      break;
      
    case 3:
      crack();
      Serial.println("crack 1");
      break;
  
  
    case 4:
      thunderburst();
      Serial.println("thunder 2");
      break;

    default:
      slide(3, 70, 10, 255, 2);
      clock += 1;
      if (clock == 1000000) {
        clock = 0;
      }
  }
  delay(5);
}
