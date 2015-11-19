#pragma once
#include "AbstractLedEffect.h"

class FlashLight
  : AbstractLedEffect {

  public:

    FlashLight(Adafruit_NeoPixel stripe);
    ~FlashLight(){};

    uint32_t getEffectColor() override;
    void setEffectFunction(uint8_t brightness[16]);
    void run() override;

    using AbstractLedEffect::setColor;

};
