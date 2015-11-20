#pragma once

class ColorGenerator {

  public:

    ColorGenerator(uint32_t color)
    : _color(color)
    {
        // Todo...
    };
    
    ~ColorGenerator() {};

    uint32_t getNextColor()
    {
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

      return _color;
    };
  
  private:

    // should be a list
    uint32_t _color;

};
