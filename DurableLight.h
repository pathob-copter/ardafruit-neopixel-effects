#pragma once
#include "LightEffect.h"

class DurableLight
  : public LightEffect
{

  public:
  
    DurableLight(Adafruit_NeoPixel* stripe)
      : LightEffect(stripe)
    {
      // _brightness.add(255);
    };

    DurableLight(Adafruit_NeoPixel* stripe, Color* color)
      : LightEffect(stripe, color)
    {
      // _brightness.add(255);
    };

    DurableLight(Adafruit_NeoPixel* stripe, ColorGenerator* colorGenerator)
      : LightEffect(stripe, colorGenerator)
    {
      // _brightness.add(255);
    };

    ~DurableLight(){};
    
    void run() override
    {
      Color* color = _colorGenerator->getNextColor();
      
      for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
        _stripe->setPixelColor(i, color->toInt());
      }
    }

    using LightEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

