#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_FLASHLIGHT_H
#define ADAFRUITNEOPIXELEFFECTS_FLASHLIGHT_H

#include "LightEffect.h"
#include "List.h"

namespace AdafruitNeopixelEffects
{

  class _FlashLight
    : public _LightEffect
  {
  
    public:
  
      _FlashLight(Adafruit_NeoPixel* stripe)
        : _LightEffect(stripe)
      {
        init();
      };
      
      _FlashLight(Adafruit_NeoPixel* stripe, Color color)
        : _LightEffect(stripe, color)
      {
        init();
      };
      
      _FlashLight(Adafruit_NeoPixel* stripe, ColorGenerator colorGenerator)
        : _LightEffect(stripe, colorGenerator)
      {
        init();
      };
  
      ~_FlashLight(){};
  
      void run() override
      {
        Color color = _colorGenerator->getNextColor();
        color->applyBrightness(_brightness->iterate());
        
        for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
          _stripe->setPixelColor(i, color->toInt());
        }
      }
  
      using _LightEffect::setColor;
  
    protected:
  
      void init() override
      {
        // uint8_t b[4] = {255, 0, 255, 0};
        // _brightness = boost::make_shared<_List<uint8_t> >(b, 4);
      }
  
  };
  
  typedef boost::shared_ptr<_FlashLight> FlashLight;
  
}

#endif
