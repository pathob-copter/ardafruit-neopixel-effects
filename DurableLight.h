#pragma once
#include "LightEffect.h"

class DurableLight
  : LightEffect
{

  public:

    DurableLight(Adafruit_NeoPixel stripe)
      : LightEffect(stripe)
    {
      // ...
    }

    ~DurableLight(){};

    uint32_t getEffectColor() override
    {
      return _color;
    }
    
    void run() override
    {
      for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
        _stripe.setPixelColor(i, getEffectColor());
      }
    }

    using LightEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

