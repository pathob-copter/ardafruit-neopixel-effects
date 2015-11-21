#pragma once
#include "AbstractLightEffect.h"

class DurableLight
  : AbstractLightEffect
{

  public:

    DurableLight(Adafruit_NeoPixel stripe)
      : AbstractLightEffect(stripe)
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

    using AbstractLightEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

