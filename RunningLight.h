#pragma once
#include "LightEffect.h"

class RunningLight
  : LightEffect {

  public:

    RunningLight(Adafruit_NeoPixel stripe)
      : LightEffect(stripe)
    {
      _activeStep = 0;
      _primaryColors[Red]   = 255;
      _primaryColors[Green] = 0;
      _primaryColors[Blue]  = 0;
    }

    ~RunningLight(){};

    void setIsReverted(bool reverted)
    {
      _reverted = reverted;
    }
	
    void run() override
    {
      for(int i = _numLEDs; i > 0; i--) {
        _stripe.setPixelColor(i, _stripe.getPixelColor(i - 1));
      }
  
      _stripe.setPixelColor(0, getEffectColor());
      
      _activeStep = (_activeStep + 1) % _brightness->size();
    }
  
  private:

    bool _reverted;

};

