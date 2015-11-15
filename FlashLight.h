#pragma once
#include "AbstractLedEffect.h"

class FlashLight
  : AbstractLedEffect {

  public:

    FlashLight(Adafruit_NeoPixel stripe);
    ~FlashLight(){};

    uint32_t getEffectColor() override;
    void run() override;

    using AbstractLedEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

