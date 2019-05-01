#include "leds.h"

CRGB ledStrip[NUM_LEDS];
float brightnessMultiplier = .9;

void init_leds()
{
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(ledStrip, NUM_LEDS);
}

void StripOFF()
{
  for(int j = 0; j < NUM_LEDS; j++)
  {
    ledStrip[j].setRGB(0, 0, 0);
  }  
}

void LEDfade(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b)
{
  if(tRepeat < mclock)
  {
    mclock = mclock % tRepeat;
  }
  if(mclock >= tStart && mclock < tStart + tLength)
  {
    int rPercent = r - ((mclock-tStart)*r/tLength);
    int gPercent = g - ((mclock-tStart)*g/tLength);
    int bPercent = b - ((mclock-tStart)*b/tLength);
    for(int j = lStart; j < lStart+lLength; j++)
    {
      ledStrip[j].setRGB(rPercent*brightnessMultiplier, gPercent*brightnessMultiplier, bPercent*brightnessMultiplier);
    }
  }
}

void LEDset(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b)
{
  if(tRepeat < mclock)
  {
    mclock = mclock % tRepeat;
  }
  if(mclock >= tStart && mclock < tStart + tLength)
  {
    for(int j = lStart; j < lStart+lLength; j++)
    {
      ledStrip[j].setRGB(r*brightnessMultiplier, g*brightnessMultiplier, b*brightnessMultiplier);
    }
  } 
}

void LEDstrobe(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b)
{
  if(tRepeat < mclock)
  {
    mclock = mclock % tRepeat;
  }
  if(mclock >= tStart && mclock < tStart + tLength)
  {
    if(mclock % 6 > 2)
    {
      for(int j = lStart; j < lStart+lLength; j++)
      {
        ledStrip[j].setRGB(r*brightnessMultiplier, g*brightnessMultiplier, b*brightnessMultiplier);
      }
    }
    else
    {
      for(int j = lStart; j < lStart+lLength; j++)
      {
        ledStrip[j].setRGB(0, 0, 0);
      }
    }
  }
}

void LEDchase(int mclock, int lStart, int lLength, int tStart, int tLength, int tRepeat, int r, int g, int b, int direction, int width)
{
  if(tRepeat < mclock)
  {
    mclock = mclock % tRepeat;
  }
  if(mclock >= tStart && mclock < tStart + tLength)
  {
    int forwardConst = 0;
    int currentStart = (((mclock-tStart)*(lStart+lLength-width))/tLength);
    if(direction == BACKWARD)
    {
      forwardConst = lStart + lLength - width; 
      currentStart = forwardConst - (((mclock-tStart)*(lStart+lLength-width))/tLength);
    }
    
    for(int j = currentStart; j < currentStart+width; j++)
    {
      ledStrip[j].setRGB(r*brightnessMultiplier, g*brightnessMultiplier, b*brightnessMultiplier);
    }
  }
}


