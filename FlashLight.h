#pragma once
#include "LightEffect.h"

class FlashLight
  : public LightEffect {

  public:

    FlashLight(Adafruit_NeoPixel* stripe)
      : LightEffect(stripe)
    {
      init();
    };
    
    FlashLight(Adafruit_NeoPixel* stripe, Color* color)
      : LightEffect(stripe, color)
    {
      init();
    };
    
    FlashLight(Adafruit_NeoPixel* stripe, ColorGenerator* colorGenerator)
      : LightEffect(stripe, colorGenerator)
    {
      init();
    };

    ~FlashLight(){};

    void run() override
    {
      Color* color = _colorGenerator->getNextColor();
      color->applyBrightness(_brightness->iterate());
      
      for(int i = _ledIndexStart; i <= _ledIndexEnd; i++) {
        _stripe->setPixelColor(i, color->toInt());
      }
    }

    using LightEffect::setColor;

  protected:

    void init() override
    {
      uint8_t b[4] = {255, 0, 255, 0};
      _brightness = new List<uint8_t>(b, 4);
    }

};
