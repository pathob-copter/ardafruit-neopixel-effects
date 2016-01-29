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
  
      _FlashLight(Adafruit_NeoPixel stripe)
        : _LightEffect(stripe)
      {
        init();
      };
      
      _FlashLight(Adafruit_NeoPixel stripe, const _Color& color)
        : _LightEffect(stripe, color)
      {
        init();
      };
      
      _FlashLight(Adafruit_NeoPixel stripe, const _ColorGenerator& colorGenerator)
        : _LightEffect(stripe, colorGenerator)
      {
        init();
      };
  
      ~_FlashLight(){};
  
      void run() override
      {
        _Color color = _colorGenerator.getNextColor();
        Serial.print("getNextColor: ");
        Serial.println(color.toInt());
        //color.applyBrightness(_brightness->iterate());
        
        for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
          _stripe.setPixelColor(i, color.toInt());
        }
      }
  
      using _LightEffect::setColor;
  
    protected:
  
      void init() override
      {
        uint8_t b[2] = {255, 0};
        // _brightness = boost::make_shared<_List<uint8_t> >(b, 4);
      }
  
  };
  
  typedef _FlashLight* FlashLight;
  
}

#endif
