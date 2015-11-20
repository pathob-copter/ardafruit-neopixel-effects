#pragma once
#include "AbstractLedEffect.h"

class DurableLight
  : AbstractLedEffect
{

  public:

    DurableLight(Adafruit_NeoPixel stripe)
      : AbstractLedEffect(stripe)
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

    using AbstractLedEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

