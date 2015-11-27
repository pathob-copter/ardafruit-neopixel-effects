#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_LIGHTEFFECT_H
#define ADAFRUITNEOPIXELEFFECTS_LIGHTEFFECT_H

#include "ColorGenerator.h"

namespace AdafruitNeopixelEffects
{

  class _LightEffect
  {
  
    public:
  
      _LightEffect(Adafruit_NeoPixel* stripe)
      {
        _stripe = stripe;
        _ledIndexStart = 0;
        _ledIndexEnd = stripe->numPixels() - 1;
        // FIXME
        _brightness; // = boost::make_shared<List<uint8_t>(_List<uint8_t>());
        _colorGenerator = boost::make_shared<_ColorGenerator>();
      };
  
      _LightEffect(Adafruit_NeoPixel* stripe, Color color)
        : _LightEffect(stripe)
      {
        _colorGenerator = boost::make_shared<_ColorGenerator>(color);
      };
  
      _LightEffect(Adafruit_NeoPixel* stripe, ColorGenerator colorGenerator)
        : _LightEffect(stripe)
      {
        _colorGenerator = colorGenerator;
      };
  
      ~_LightEffect(){};
  
      void setColor(uint8_t r, uint8_t g, uint8_t b)
      {
        // Todo: Should not use a (specific) neopixel instance to get color from it
        // _color = _stripe->Color(r,g,b);
      };
      
      void setColor(uint32_t color)
      {
        //_color = color;
      };
  
      void addColor(Color color)
      {
        _colorGenerator->addColor(color);
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
        _brightness->add(brightness);
      }
      
      virtual void run() = 0;
      
      // light effect attributes
      ColorGenerator _colorGenerator;
      Uint8List _brightness;
      
    protected:
  
      virtual void init() = 0;
      
      // stripe attributes
      Adafruit_NeoPixel* _stripe;
      uint16_t _ledIndexStart;
      uint16_t _ledIndexEnd;
  
  };
  
  typedef boost::shared_ptr<_LightEffect> LightEffect;

}

#endif
