#pragma once
#include "LightEffect.h"

class FlashLight
  : LightEffect {

  public:

    FlashLight(Adafruit_NeoPixel stripe)
      : LightEffect(stripe)
    {
      uint8_t brightness[16] = {255, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      _brightness = new List<uint8_t>(brightness, 16);
    }

    ~FlashLight(){};

    void run() override
    {
      Color color = _colorGenerator.getNextColor();
      color.applyBrightness(_brightness->iterate());
      
      for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
        _stripe.setPixelColor(i, color.toInt());
      }
    }

    using LightEffect::setColor;

};
