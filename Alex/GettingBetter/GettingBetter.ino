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
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.clear();
    FastLED.show();
    Serial.begin(9600);
    clock = 0;
}

void end_to_end() {
    for (int i=0; i<NUM_LEDS; i++) {
        leds[0+i] = CRGB(100, 100-i, 200-2*i);
        leds[1+i] = CRGB(100, 100-i, 200-2*i);
        leds[2+i] = CRGB(100, 100-i, 200-2*i);
        leds[3+i] = CRGB(100, 100-i, 200-2*i);
        leds[4+i] = CRGB(100, 100-i, 200-2*i);
        leds[5+i] = CRGB(100, 100-i, 200-2*i);
        leds[6+i] = CRGB(100, 100-i, 200-2*i);
        leds[7+i] = CRGB(100, 100-i, 200-2*i);
        leds[8+i] = CRGB(100, 100-i, 200-2*i);
        leds[9+i] = CRGB(100, 100-i, 200-2*i);
        leds[10+i] = CRGB(100, 100-i, 200-2*i);
        leds[300-i] = CRGB(100, 100-i, 5+4*i);
        leds[299-i] = CRGB(100, 100-i, 5+4*i);
        leds[298-i] = CRGB(100, 100-i, 5+4*i);
        leds[297-i] = CRGB(100, 100-i, 5+4*i);
        leds[296-i] = CRGB(100, 100-i, 5+4*i);
        leds[295-i] = CRGB(100, 100-i, 5+4*i);
        leds[294-i] = CRGB(100, 100-i, 5+4*i);
        leds[293-i] = CRGB(100, 100-i, 5+4*i);
        leds[292-i] = CRGB(100, 100-i, 5+4*i);
        leds[291-i] = CRGB(100, 100-i, 5+4*i);
        leds[290-i] = CRGB(100, 100-i, 5+4*i);
        FastLED.show();
        delay(10);
        FastLED.clear();
    } 
}

void still() {
  for (int i=0; i<NUM_LEDS; i++) {
          leds[300-i] = CRGB(100, 100-i, 5+4*i);
          leds[299-i] = CRGB(100, 100-i, 5+4*i);
          leds[298-i] = CRGB(100, 100-i, 5+4*i);
          leds[297-i] = CRGB(100, 100-i, 5+4*i);
          leds[296-i] = CRGB(100, 100-i, 5+4*i);
          leds[295-i] = CRGB(100, 100-i, 5+4*i);
          leds[294-i] = CRGB(100, 100-i, 5+4*i);
          leds[293-i] = CRGB(100, 100-i, 5+4*i);
          leds[292-i] = CRGB(100, 100-i, 5+4*i);
          leds[291-i] = CRGB(100, 100-i, 5+4*i);
          leds[290-i] = CRGB(100, 100-i, 5+4*i);
          FastLED.show();
      } 
}

void rainbow_down_and_back() {
  for (int i = 0; i <= 290; i++) {
    leds[0+i] = CHSV(0+i, 255, 157);
    leds[1+i] = CHSV(1+i, 255, 157);
    leds[2+i] = CHSV(2+i, 255, 157);
    leds[3+i] = CHSV(3+i, 255, 157);
    leds[4+i] = CHSV(4+i, 255, 157);
    leds[5+i] = CHSV(5+i, 255, 157);
    leds[6+i] = CHSV(6+i, 255, 157);
    leds[7+i] = CHSV(7+i, 255, 157);
    leds[8+i] = CHSV(8+i, 255, 157);
    leds[9+i] = CHSV(9+i, 255, 157);
    leds[10+i] = CHSV(10+i, 255, 157);
    FastLED.show();
    delay(5);
    FastLED.clear();
    leds[random(300)] = CHSV(random(255), random(255), 110);
  }
  for (int i=300; i>=0; i--) {
     leds[i-1] = CHSV(0+i, 255, 157);
     leds[i-2] = CHSV(1+i, 255, 157);
     leds[i-3] = CHSV(2+i, 255, 157);
     leds[i-4] = CHSV(3+i, 255, 157);
     leds[i-5] = CHSV(4+i, 255, 157);
     leds[i-6] = CHSV(5+i, 255, 157);
     leds[i-7] = CHSV(6+i, 255, 157);
     leds[i-8] = CHSV(7+i, 255, 157);
     leds[i-9] = CHSV(8+i, 255, 157);
     leds[i-10] = CHSV(9+i, 255, 157);
     leds[i-11] = CHSV(10+i, 255, 157);
     FastLED.show();
     delay(5);
     FastLED.clear();
  }
}

void reset(){
  for (int i=0;i<NUM_LEDS;i++){
    leds[i] = CHSV( 0, 0, 0);
  }
  FastLED.show(); 
}


void crack2(){
   //turn everything white briefly
   int m = 125;
   int n = 175;
   while(m >= 0 && n <= 300){
    for(int i = m; i < n; i++){
      leds[i] = CHSV( random(0,255), 255, 185); 
    }
    FastLED.show();
    delay(0);
    m-= 5;
    n+= 5;
   }

   m = 0;
   n = 300;
   while(m <= 125 && n >= 175){
     FastLED.clear();
     for(int i = m; i < n; i++){
      leds[i] = CHSV( random(0,255), 255, 185); 
     }

    FastLED.show();
    
    delay(0);
    m+= 5;
    n-= 5;
   }
    fukl2();
}

void crack(){
   //turn everything white briefly
   for(int i=0;i<NUM_LEDS;i++) {
      leds[i] = CHSV( random(0,255), 255, 185); 
   }
   FastLED.show();
   delay(random(10,100));
   reset();
}

void crackhead(){
   //turn everything white briefly
   for(int i=0;i<NUM_LEDS;i++) {
      leds[165] = CHSV( random(0,255), 255, 185);
      leds[164] = CHSV( random(0,255), 255, 185);
      leds[163] = CHSV( random(0,255), 255, 185);
      leds[162] = CHSV( random(0,255), 255, 185);
      leds[161] = CHSV( random(0,255), 255, 185);
      leds[160] = CHSV( random(0,255), 255, 185);
      leds[159] = CHSV( random(0,255), 255, 185);
      leds[158] = CHSV( random(0,255), 255, 185);
      leds[157] = CHSV( random(0,255), 255, 185);
      leds[156] = CHSV( random(0,255), 255, 185);
      leds[155] = CHSV( random(0,255), 255, 185);
      leds[154] = CHSV( random(0,255), 255, 185);
      leds[153] = CHSV( random(0,255), 255, 185);
      leds[152] = CHSV( random(0,255), 255, 185);
      leds[151] = CHSV( random(0,255), 255, 185);
      leds[150] = CHSV( random(0,255), 255, 185);
      leds[149] = CHSV( random(0,255), 255, 185);
      leds[148] = CHSV( random(0,255), 255, 185); 
      leds[147] = CHSV( random(0,255), 255, 185); 
      leds[146] = CHSV( random(0,255), 255, 185); 
      leds[145] = CHSV( random(0,255), 255, 185); 
      leds[144] = CHSV( random(0,255), 255, 185); 
      leds[143] = CHSV( random(0,255), 255, 185); 
      leds[142] = CHSV( random(0,255), 255, 185); 
      leds[141] = CHSV( random(0,255), 255, 185); 
      leds[140] = CHSV( random(0,255), 255, 185); 
      leds[139] = CHSV( random(0,255), 255, 185);
      leds[138] = CHSV( random(0,255), 255, 185);
      leds[137] = CHSV( random(0,255), 255, 185);
      leds[136] = CHSV( random(0,255), 255, 185);
      leds[135] = CHSV( random(0,255), 255, 185);
   }
   FastLED.show();
   delay(1000);
}

void fukl() {
    Serial.println("here");
    for (int i=0; i<NUM_LEDS; i++) {
        leds[0+i] = CRGB(172+i, 0, 0);
        leds[1+i] = CRGB(172+i, 0, 0);
        leds[2+i] = CRGB(172+i, 0, 0);
        leds[3+i] = CRGB(172+i, 0, 0);
        leds[4+i] = CRGB(172+i, 0, 0);
        leds[5+i] = CRGB(172+i, 0, 0);
        leds[6+i] = CRGB(172+i, 0, 0);
        leds[7+i] = CRGB(172+i, 0, 0);
        leds[8+i] = CRGB(172+i, 0, 0);
        leds[9+i] = CRGB(172+i, 0, 0);
        leds[10+i] = CRGB(172+i, 0, 0);
        leds[300-i] = CRGB(0, 100-i, 5+4*i);
        leds[299-i] = CRGB(0, 100-i, 5+4*i);
        leds[298-i] = CRGB(0, 100-i, 5+4*i);
        leds[297-i] = CRGB(0, 100-i, 5+4*i);
        leds[296-i] = CRGB(0, 100-i, 5+4*i);
        leds[295-i] = CRGB(0, 100-i, 5+4*i);
        leds[294-i] = CRGB(0, 100-i, 5+4*i);
        leds[293-i] = CRGB(0, 100-i, 5+4*i);
        leds[292-i] = CRGB(0, 100-i, 5+4*i);
        leds[291-i] = CRGB(0, 100-i, 5+4*i);
        leds[290-i] = CRGB(0, 100-i, 5+4*i);
        if(i == 140){
          delay(100);
          crack2();
        }
        FastLED.show();
        delay(10);
        FastLED.clear();
    } 
    Serial.println("Check");
}

void fukl2() {
    Serial.println("here");
    for (int i=0; i<NUM_LEDS; i++) {
        leds[149-i] = CRGB(172+i, 0, 0);
        leds[148-i] = CRGB(172+i, 0, 0);
        leds[147-i] = CRGB(172+i, 0, 0);
        leds[146-i] = CRGB(172+i, 0, 0);
        leds[145-i] = CRGB(172+i, 0, 0);
        leds[144-i] = CRGB(172+i, 0, 0);
        leds[143-i] = CRGB(172+i, 0, 0);
        leds[142-i] = CRGB(172+i, 0, 0);
        leds[141-i] = CRGB(172+i, 0, 0);
        leds[140-i] = CRGB(172+i, 0, 0);
        leds[139-i] = CRGB(172+i, 0, 0);
        leds[151+i] = CRGB(0, 50, i+50);
        leds[152+i] = CRGB(0, 50, i+50);
        leds[153+i] = CRGB(0, 50, i+50);
        leds[154+i] = CRGB(0, 50, i+50);
        leds[155+i] = CRGB(0, 50, i+50);
        leds[156+i] = CRGB(0, 50, i+50);
        leds[157+i] = CRGB(0, 50, i+50);
        leds[158+i] = CRGB(0, 50, i+50);
        leds[159+i] = CRGB(0, 50, i+50);
        leds[160+i] = CRGB(0, 50, i+50);
        leds[161+i] = CRGB(0, 50, i+50);
        if(i == 150){
          fukl();
        }
        FastLED.show();
        delay(10);
        FastLED.clear();
    } 
}


void down_and_back_red_white() {
  for (int i = 0; i <= 290; i++) {
    leds[0+i] = CHSV(0, 255, 197);
    leds[1+i] = CHSV(0, 255, 197);
    leds[2+i] = CHSV(0, 255, 197);
    leds[3+i] = CHSV(0, 255, 197);
    leds[4+i] = CHSV(0, 255, 197);
    leds[5+i] = CHSV(0, 255, 197);
    leds[6+i] = CHSV(0, 255, 197);
    leds[7+i] = CHSV(0, 255, 197);
    leds[8+i] = CHSV(0, 255, 197);
    leds[9+i] = CHSV(0, 255, 197);
    leds[10+i] = CHSV(0, 255, 197);
    leds[300-i] = CRGB(255, 255, 197);
    leds[299-i] = CRGB(255, 255, 197);
    leds[298-i] = CRGB(255, 255, 197);
    leds[297-i] = CRGB(255, 255, 197);
    leds[296-i] = CRGB(255, 255, 197);
    leds[295-i] = CRGB(255, 255, 197);
    leds[294-i] = CRGB(255, 255, 197);
    leds[293-i] = CRGB(255, 255, 197);
    leds[292-i] = CRGB(255, 255, 197);
    leds[291-i] = CRGB(255, 255, 197);
    leds[290-i] = CRGB(255, 255, 197);
    FastLED.show();
    delay(15);
    FastLED.clear();
  }
  for (int i=300; i>=0; i--) {
     leds[i-1] = CRGB(255, 255, 255);
     leds[i-2] = CRGB(255, 255, 255);
     leds[i-3] = CRGB(255, 255, 255);
     leds[i-4] = CRGB(255, 255, 255);
     leds[i-5] = CRGB(255, 255, 255);
     leds[i-6] = CRGB(255, 255, 255);
     leds[i-7] = CRGB(255, 255, 255);
     leds[i-8] = CRGB(255, 255, 255);
     leds[i-9] = CRGB(255, 255, 255);
     leds[i-10] = CRGB(255, 255, 255);
     leds[i-11] = CRGB(255, 255, 255);
     FastLED.show();
     delay(15);
     FastLED.clear();
  }
}

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
    int pos = (int) ((clock + offset) * (SPEED / 5.0)) % TRACK_LENGTH;

    // Switch directions
    if (pos >= TRACK_LENGTH/2) {
      pos = TRACK_LENGTH - 1 - pos;
    }

    // Light up leds
    for (int l = 0; l < SECTION_LENGTH; l++) {
      int brightness = BRIGHTNESS - abs(SECTION_LENGTH/2 - l) * (BRIGHTNESS/SECTION_LENGTH) * FADE;
      leds[pos + l] = CHSV((((255 / NUM_SECTIONS) * sec) + pos) % 255, 255, brightness);
    }
  }
  FastLED.show();
}

void loop() {
  if (Serial.available() > 0) {
    FastLED.clear();
    in = Serial.read();
    clock = 0;
  }
  if (in == 'a') {
      std_dots();
  }
  else if (in =='b') {
      fast_dots();
  }
  else if (in == 'c') {
      slow_dots();
  } 
  else {
    still();
  }
  delay(5);
  clock += 1;
  if (clock == 1000000) {
    clock = 0;
  }
}
