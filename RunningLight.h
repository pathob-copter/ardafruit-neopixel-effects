#pragma once
#include "LightEffect.h"

class RunningLight
  : public LightEffect {

  public:

    using LightEffect::LightEffect;
    ~RunningLight(){};

    void setIsReverted(bool reverted)
    {
      _reverted = reverted;
    }
	
    void run() override
    {
      Color* color = _colorGenerator->getNextColor();
      color->applyBrightness(_brightness->iterate());
      
      for(int i = _ledIndexEnd; i > _ledIndexStart; i--) {
        _stripe->setPixelColor(i, _stripe->getPixelColor(i - 1));
      }
  
      _stripe->setPixelColor(0, color->toInt());
    }
  
  private:

    bool _reverted;

};

