#include "animations.h"
#include "leds.h"

void testAnimation(int mclock)
{
  LEDchase(mclock, 0         , FOURTH_S,  0, HALF, WHOLE , 0, 0, 100, FORWARD, 5);
  LEDchase(mclock, FOURTH_S*2, FOURTH_S*2,  0, HALF, WHOLE , 0, 0, 100, BACKWARD, 5);
  LEDfade (mclock, FOURTH_S ,  FOURTH_S*2,  HALF, HALF, WHOLE, 0, 100, 0);
}

void testWhole1(int mclock)
{
  LEDfade(mclock, FOURTH_S, FOURTH_S*2, 0, WHOLE, WHOLE, 0, 0, 100);
}

void testHalf1(int mclock)
{
  LEDfade(mclock, FOURTH_S,   FOURTH_S,    0, HALF, WHOLE, 0, 100, 0);
  LEDfade(mclock, FOURTH_S*2, FOURTH_S, HALF, HALF, WHOLE, 100, 0, 0);
}

void testQuarter1(int mclock)
{
  LEDfade(mclock, 0          , FOURTH_S, 0        , QUARTER, WHOLE, 0  , 0  , 100 );
  LEDfade(mclock, FOURTH_S   , FOURTH_S, QUARTER  , QUARTER, WHOLE, 0  , 100 , 0  );
  LEDfade(mclock, FOURTH_S*2 , FOURTH_S, QUARTER*2, QUARTER, WHOLE, 0  , 100 , 100 );
  LEDfade(mclock, FOURTH_S*3 , FOURTH_S, QUARTER*3, QUARTER, WHOLE, 100 , 0  , 0  );
}

void testEighth1(int mclock)
{
  LEDfade(mclock, 0          , FOURTH_S, 0       , EIGHTH, HALF, 0  , 0  , 100 );
  LEDfade(mclock, FOURTH_S   , FOURTH_S, EIGHTH  , EIGHTH, HALF, 0  , 100 , 0  );
  LEDfade(mclock, FOURTH_S*2 , FOURTH_S, EIGHTH*2, EIGHTH, HALF, 0  , 100 , 100 );
  LEDfade(mclock, FOURTH_S*3 , FOURTH_S, EIGHTH*3, EIGHTH, HALF, 100 , 0  , 0  );
}