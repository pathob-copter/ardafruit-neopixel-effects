#pragma once
#include <Adafruit_NeoPixel.h>

class AbstractLedEffect {

  public:

    static const uint8_t Red   = 0;
    static const uint8_t Green = 1;
    static const uint8_t Blue  = 2;
    static const uint8_t NumPrimColors = 3;

    AbstractLedEffect(Adafruit_NeoPixel stripe);
    ~AbstractLedEffect(){};

    void run(uint32_t color);
    virtual void run() = 0;

    uint32_t colorGenerator();
  
  protected:

    void logColors(uint8_t red, uint8_t green, uint8_t blue);
  
    Adafruit_NeoPixel _stripe;
    uint32_t _color;
    uint16_t _numLEDs;
    
    uint16_t _ledIndexStart;
    uint16_t _ledIndexEnd;
    
    uint8_t _numSteps;
    uint8_t _activeStep;

    uint32_t _primaryColors[NumPrimColors];
    uint8_t  _activePrimaryColor;
    
    uint8_t  _divisor[7] = {1, 1, 1, 1, 1, 1, 1};

};

