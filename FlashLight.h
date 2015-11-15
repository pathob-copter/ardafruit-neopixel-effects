#pragma once
#include "AbstractLedEffect.h"

class FlashLight
  : AbstractLedEffect {

  public:

    FlashLight(Adafruit_NeoPixel stripe);
    ~FlashLight(){};

    void run() override;
    void setRange(uint16_t indexStart, uint16_t indexEnd);
  
  private:

    uint8_t _numSteps;
    uint8_t _activeStep;
    
    uint16_t _ledIndexStart;
    uint16_t _ledIndexEnd;

    const uint8_t _divisor[7] = {1, 255, 1, 255, 255, 255, 255};

};

