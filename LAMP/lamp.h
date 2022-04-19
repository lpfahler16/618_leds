//618 Lamp Header File
#ifndef Lamp_H
#define Lamp_H

#include <FastLED.h>

const unsigned int NUM_LEDS     = 53; 


class Lamp {

    private:
        CRGB strip1[NUM_LEDS]; 
        CRGB strip2[NUM_LEDS];
        CRGB strip3[NUM_LEDS];

    public:
        Lamp(); //Will take in inputs at somepoint
        ~Lamp();
        void SetRing(int ring, CRGB color);
        void SetRing(int ring, CHSV color);
        void SetRings(int[] rings, CRGB color);
        void SetRings(int[] rings, CHSV color);
        void SetRings(int from, int to, CRGB color);
        void SetRings(int from, int to, CHSV color);
        void SetLamp(CRGB color);
        void SetLamp(CHSV color);
        void SetLED(int strip, int led, CRGB color);
        void SetLED(int strip, int led, CHSV color);
        void SetLEDs(int strip, int[] rings, CRGB color);
        void SetLEDs(int strip, int[] rings, CHSV color);
        void SetLEDs(int strip, int from, int to, CRGB color);
        void SetLEDs(int strip, int from, int to, CHSV color);
        void SetStrip(int strip, CRGB color);
        void SetStrip(int strip, CHSV color);

}




#endif