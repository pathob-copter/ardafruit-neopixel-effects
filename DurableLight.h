#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_DURABLELIGHT_H
#define ADAFRUITNEOPIXELEFFECTS_DURABLELIGHT_H

#include "LightEffect.h"

namespace AdafruitNeopixelEffects
{

  class _DurableLight
    : public _LightEffect
  {
  
    public:
    
      _DurableLight(Adafruit_NeoPixel* stripe)
        : _LightEffect(stripe)
      {
        // _brightness.add(255);
      };
  
      _DurableLight(Adafruit_NeoPixel* stripe, Color color)
        : _LightEffect(stripe, color)
      {
        // _brightness.add(255);
      };
  
      _DurableLight(Adafruit_NeoPixel* stripe, ColorGenerator colorGenerator)
        : _LightEffect(stripe, colorGenerator)
      {
        // _brightness.add(255);
      };
  
      ~_DurableLight(){};
      
      void run() override
      {
        Color color = _colorGenerator->getNextColor();
        
        for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
          _stripe->setPixelColor(i, color->toInt());
        }
      }
  
      using _LightEffect::setColor;
      
      void setRange(uint16_t indexStart, uint16_t indexEnd);
  
  };
  
  typedef boost::shared_ptr<_DurableLight> DurableLight;
  
}

#endif
