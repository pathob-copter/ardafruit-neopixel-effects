#pragma once
#include "AbstractLedEffect.h"

class RunningLight
  : AbstractLedEffect {

  public:

    RunningLight(Adafruit_NeoPixel stripe)
      : AbstractLedEffect(stripe)
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
      
      _activeStep = (_activeStep + 1) % sizeof(_divisor);
    }
  
  private:

    bool _reverted;

    const uint8_t _divisor[7] = {20, 1, 3, 8, 20, 100, 255};

};

