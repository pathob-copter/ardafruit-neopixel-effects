#pragma once
#include "AbstractBase.h"

class ColorGenerator
  : AbstractBase
{

  public:

    using AbstractBase::Red;
    using AbstractBase::Green;
    using AbstractBase::Blue;
    using AbstractBase::NumPrimColors;

    ColorGenerator(uint32_t color);
    ~ColorGenerator() {};

    uint32_t getNextColor();
  
  private:

    List<Color> _colors;

    
    uint32_t _primaryColors[NumPrimColors];

};

ColorGenerator::ColorGenerator(uint32_t color)
{
  Color c(color);
  _colors.add(c);
  /*
  _primaryColors[AbstractLightEffect::Red]   = 255;
  _primaryColors[AbstractLightEffect::Green] = 0;
  _primaryColors[AbstractLightEffect::Blue]  = 0;
  */
}

uint32_t ColorGenerator::getNextColor()
{
  /*
  _primaryColors[_activePrimaryColor]--;
  _primaryColors[(_activePrimaryColor + 1) % NumPrimColors]++;

  if (_primaryColors[_activePrimaryColor] == 0) {
    _activePrimaryColor = (_activePrimaryColor + 1) % NumPrimColors;
  }

  uint8_t newRed   = _primaryColors[Red]   / _divisor[_activeStep];
  uint8_t newGreen = _primaryColors[Green] / _divisor[_activeStep];
  uint8_t newBlue  = _primaryColors[Blue]  / _divisor[_activeStep];

  _activeStep = (_activeStep + 1) % sizeof(_divisor);

  _color = _stripe.Color(newRed, newGreen, newBlue);
  */

  return _colors.get(0).toInt();
}

