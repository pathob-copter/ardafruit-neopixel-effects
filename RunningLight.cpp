#include "RunningLight.h"

RunningLight::RunningLight(Adafruit_NeoPixel stripe) :
  AbstractLedEffect(stripe)
{
  _activeStep = 0;
  _primaryColors[Red]   = 255;
  _primaryColors[Green] = 0;
  _primaryColors[Blue]  = 0;
}

void RunningLight::run()
{
  for(int i = _numLEDs; i > 0; i--) {
    _stripe.setPixelColor(i, _stripe.getPixelColor(i - 1));
  }

  _primaryColors[_activePrimaryColor]--;
  _primaryColors[(_activePrimaryColor + 1) % NumPrimColors]++;
  
  if (_primaryColors[_activePrimaryColor] == 0) {
    _activePrimaryColor = (_activePrimaryColor + 1) % NumPrimColors;
  }

  uint8_t newRed   = _primaryColors[Red]   / _divisor[_activeStep];
  uint8_t newGreen = _primaryColors[Green] / _divisor[_activeStep];
  uint8_t newBlue  = _primaryColors[Blue]  / _divisor[_activeStep];
  
  uint32_t newColor = _stripe.Color(newRed, newGreen, newBlue);
  _stripe.setPixelColor(0, newColor);
  
  _activeStep = (_activeStep + 1) % sizeof(_divisor);
  
  _stripe.show();
  logColors(newRed, newGreen, newBlue);
}

