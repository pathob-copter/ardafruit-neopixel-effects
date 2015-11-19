#pragma once
#include "AbstractLedEffect.h"

class RunningLight
  : AbstractLedEffect {

  public:

    RunningLight(Adafruit_NeoPixel stripe);
    ~RunningLight(){};

	void setIsReverted(bool reverted);
	
    void run() override;
  
  private:

	bool _reverted;

    const uint8_t _divisor[7] = {20, 1, 3, 8, 20, 100, 255};

};

