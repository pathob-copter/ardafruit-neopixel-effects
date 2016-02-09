#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_RUNNINGLIGHT_H
#define ADAFRUITNEOPIXELEFFECTS_RUNNINGLIGHT_H

#include "Lighteffect.h"

namespace AdafruitNeopixelEffects
{

  class _RunningLight
    : public _LightEffect {
  
    public:
  
      using _LightEffect::_LightEffect;
      ~_RunningLight(){};
  
      void setIsReverted(bool reverted)
      {
        _reverted = reverted;
      }
  	
      void run() override
      {
        _Color color = _colorGenerator.getColor();
        Serial.println(color.toInt());
        color.applyBrightness(_brightness.iterate());
        
        for(int i = _ledIndexEnd; i > _ledIndexStart; i--) {
          _stripe.setPixelColor(i, _stripe.getPixelColor(i - 1));
        }
    
        _stripe.setPixelColor(0, color.toInt());
      }
    
    private:
  	  
      bool _reverted;
  
  };
  
  typedef _RunningLight* RunningLight;

}

#endif
