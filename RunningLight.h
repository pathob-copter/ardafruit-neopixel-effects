#pragma once
#include "AbstractLedEffect.h"

class RunningLight
  : AbstractLedEffect {

  public:

    RunningLight(Adafruit_NeoPixel stripe);
    ~RunningLight(){};

    void run() override;
  
  private:

    uint8_t _numSteps;
    uint8_t _activeStep;

    const uint8_t _divisor[7] = {20, 1, 3, 8, 20, 100, 255};

};

