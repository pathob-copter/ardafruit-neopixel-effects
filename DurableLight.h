#pragma once
#include "LightEffect.h"

class DurableLight
  : LightEffect
{

  public:

    using LightEffect::LightEffect;

    ~DurableLight(){};
    
    void run() override
    {
      Color color = _colorGenerator.getNextColor();
      
      for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
        _stripe.setPixelColor(i, color.toInt());
      }
    }

    using LightEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

