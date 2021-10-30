#include <Wire.h>
#include "FastLED.h"

#define NUM_LEDS 300
#define DATA_PIN 7
#define DATA_PIN_2 8

CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds, NUM_LEDS);
}

void reset(){
  for (int i=0;i<NUM_LEDS;i++){
    leds[i] = CHSV( 0, 0, 0);
  }
  FastLED.show(); 
}

void rolling(){
  // a simple method where we go through every LED with 1/10 chance
  // of being turned on, up to 10 times, with a random delay wbetween each time
  for(int r=0;r<random(2,10);r++){
    //iterate through every LED
    for(int i=0;i<NUM_LEDS;i++){
      if(random(0,100)>90){
        leds[i] = CHSV(random(0,40), 0, 155); 

      }
      else{
        //dont need reset as we're blacking out other LEDs her 
        leds[i] = CHSV(0,0,0);
      }
    }
    FastLED.show();
    delay(random(5,100));
    reset();
    
  }
}

void crack(){
   //turn everything white briefly
   for(int i=0;i<NUM_LEDS;i++) {
      leds[i] = CHSV(21, 255, 185); 
   }
   FastLED.show();
   delay(random(10,100));
   reset();
}

void thunderburst(){

  // this thunder works by lighting two random lengths
  // of the strand from 10-20 pixels. 
  int rs1 = random(0,NUM_LEDS/2);
  int rl1 = random(10,20);
  int rs2 = random(rs1+rl1,NUM_LEDS);
  int rl2 = random(10,20);
  
  //repeat this chosen strands a few times, adds a bit of realism
  for(int r = 0;r<random(3,6);r++){
    
    for(int i=0;i< rl1; i++){
      leds[i+rs1] = CHSV(random(0,40), 0, 195);
    }
    
    if(rs2+rl2 < NUM_LEDS){
      for(int i=0;i< rl2; i++){
        leds[i+rs2] = CHSV(random(0,40) 0, 95);
      }
    }
    
    FastLED.show();
    //stay illuminated for a set time
    delay(random(10,50));
    
    reset();
    delay(random(10,50));
  }
  
}

void constant_lightning(){
  switch(random(1,20)){
   case 1:
        thunderburst();
        delay(random(400,500));
         Serial.println("Thunderburst");
        break;
       
      case 2:
        rolling();
        Serial.println("Rolling");
        break;
        
      case 3:
        crack();
        delay(random(200,250));
        Serial.println("Crack");
        break;


      case 4:
        thunderburst();
        delay(random(400,500));
        Serial.println("Thunderburst");
        break;
  }  
}

void loop() { 
    constant_lightning();
    delay(200);
}
