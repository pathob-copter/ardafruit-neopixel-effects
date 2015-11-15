#pragma once
#include "AbstractLedEffect.h"

class DurableLight
  : AbstractLedEffect {

  public:

    DurableLight(Adafruit_NeoPixel stripe);
    ~DurableLight(){};

    using AbstractLedEffect::run;
    void run() override;
    void setRange(uint16_t indexStart, uint16_t indexEnd);

};

