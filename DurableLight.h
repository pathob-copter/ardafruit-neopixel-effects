#pragma once
#include "AbstractLedEffect.h"

class DurableLight
  : AbstractLedEffect {

  public:

    DurableLight(Adafruit_NeoPixel stripe);
    ~DurableLight(){};

    uint32_t getEffectColor() override;
    void run() override;

    using AbstractLedEffect::setColor;
    
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

