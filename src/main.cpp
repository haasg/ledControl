#include "leds.h"
#include "animations.h"

int animationPhase = 0;
int animationType = 0;
int beatPhase = 0;
int mclock = 0;

char sBuffer[50];
int bufCount = 0;

void setup()
{
  Serial1.begin(115200);
  Serial.begin(9600);
  init_leds();
  //init_dmx();
  
}

void loop() 
{
  if(Serial1.available() > 0)
  {
    sBuffer[bufCount] = Serial1.read();
    Serial.write(sBuffer[bufCount]+50); 
    bufCount++;
    if(sBuffer[bufCount-1] == '$')
    {
      Serial.write('!');

      beatPhase = (int)sBuffer[0];
      animationPhase = (int)sBuffer[1];
      animationType = (int)sBuffer[2];
      mclock = beatPhase * 24 + animationPhase;

      Serial.println(mclock);
      if(animationType == 1)
      {
        testEighth1(mclock);
      }
      else if(animationType == 2)
      {
        testQuarter1(mclock);
      }
      else if(animationType == 3)
      {
        testHalf1(mclock);
      }
      else
      {
        //testAnimation(mclock);
        //testWhole1(mclock);
        //testHalf1(mclock);
        testQuarter1(mclock);
        //testEighth1(mclock);
      }

      FastLED.show();
      StripOFF();

      memset(sBuffer, '(', 50);
      bufCount = 0;

    }
  }
}






