#ifndef LED_H
#define LED_H

#include <FastLED.h>

#define NUM_LEDS 150
#define DATA_PIN 6

#define FORWARD 770
#define BACKWARD 771


void init_leds();
void StripOFF();
void LEDset(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b);
void LEDfade(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b);
void LEDstrobe(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b);
void LEDchase(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b, int direction, int width);



#endif