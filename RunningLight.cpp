#pragme once
#include "RunningLight.h"

RunningLight::RunningLight(Adafruit_NeoPixel stripe) :
  AbstractLedEffect(stripe)
{
  _activeStep = 0;
  _primaryColors[Red]   = 255;
  _primaryColors[Green] = 0;
  _primaryColors[Blue]  = 0;
}

void RunningLight::setIsReverted(bool reverted)
{
  _reverted = reverted;
}

void RunningLight::run()
{
  for(int i = _numLEDs; i > 0; i--) {
    _stripe.setPixelColor(i, _stripe.getPixelColor(i - 1));
  }
  
  _stripe.setPixelColor(0, getEffectColor());
  
  _activeStep = (_activeStep + 1) % sizeof(_divisor);
  
  _stripe.show();
  logColors(newRed, newGreen, newBlue);
}

