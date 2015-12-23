#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_LIGHTEFFECT_H
#define ADAFRUITNEOPIXELEFFECTS_LIGHTEFFECT_H

#include "ColorGenerator.h"

namespace AdafruitNeopixelEffects
{

  class _LightEffect
  {
  
    public:
  
      _LightEffect(Adafruit_NeoPixel stripe)
      {
        _stripe = stripe;
        _ledIndexStart = 0;
        _ledIndexEnd = stripe.numPixels() - 1;
        // FIXME
        // _brightness;
        _colorGenerator = _ColorGenerator();
      };
  
      _LightEffect(Adafruit_NeoPixel stripe, const _Color& color)
        : _LightEffect(stripe)
      {
        _colorGenerator = _ColorGenerator(color);
      };
  
      _LightEffect(Adafruit_NeoPixel stripe, _ColorGenerator const& colorGenerator)
        : _LightEffect(stripe)
      {
        _colorGenerator = colorGenerator;
      };
  
      ~_LightEffect(){};
      
      void setColor(const _Color& color)
      {
        Serial.print("setColor: ");
        Serial.println(color.toInt());
        _colorGenerator = _ColorGenerator(color);
      };
  
      void addColor(_Color color)
      {
        _colorGenerator.addColor(color);
      }
      
      void setRange(uint16_t indexStart, uint16_t indexEnd)
      {
        if (indexStart <= indexEnd) {
          _ledIndexStart = indexStart;
          _ledIndexEnd = indexEnd;
        }
      }
  
      void addBrightnessElement(uint8_t brightness)
      {
        // _brightness->add(brightness);
      }
      
      virtual void run() = 0;
      
      // light effect attributes
      _ColorGenerator _colorGenerator;
      // Uint8List _brightness;
      
    protected:
  
      virtual void init() = 0;
      
      // stripe attributes
      Adafruit_NeoPixel _stripe;
      uint16_t _ledIndexStart;
      uint16_t _ledIndexEnd;
  
  };
  
  typedef _LightEffect* LightEffect;

}

#endif
