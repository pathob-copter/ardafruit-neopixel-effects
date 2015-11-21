#pragma once
#include "AbstractLightEffect.h"

class FlashLight
  : AbstractLightEffect {

  public:

    FlashLight(Adafruit_NeoPixel stripe)
      : AbstractLightEffect(stripe)
    {
      uint8_t brightness[16] = {255, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      _brightness = new List<uint8_t>(brightness, 16);
    }

    ~FlashLight(){};

    uint32_t getEffectColor() override
    {
      uint8_t r = (_color >> 16) & 0xFF;
      uint8_t g = (_color >> 8) & 0xFF;
      uint8_t b = (_color) & 0xFF;
    
      r = (r * _brightness->get(_activeStep)) >> 8;
      g = (g * _brightness->get(_activeStep)) >> 8;
      b = (b * _brightness->get(_activeStep)) >> 8;
      
      return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
    }

    void setEffectFunction(uint8_t brightness[16])
    {
      memcpy(_brightness, brightness, sizeof(_brightness));
    }

    void run() override
    {
      for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
        _stripe.setPixelColor(i, getEffectColor());
      }
      _activeStep = (_activeStep + 1) % sizeof(_brightness);
    }

    using AbstractLightEffect::setColor;

};
