#pragma once
#include <Adafruit_NeoPixel.h>

class AbstractLedEffect {

  public:

    static const uint8_t Red   = 0;
    static const uint8_t Green = 1;
    static const uint8_t Blue  = 2;
    static const uint8_t NumPrimColors = 3;

    AbstractLedEffect(Adafruit_NeoPixel stripe)
      : _stripe(stripe)
      , _color(0)
    {
      _ledIndexStart = 0;
      _ledIndexEnd = stripe.numPixels() - 1;
      _activeStep = 0;
      
      _primaryColors[AbstractLedEffect::Red]   = 255;
      _primaryColors[AbstractLedEffect::Green] = 0;
      _primaryColors[AbstractLedEffect::Blue]  = 0;
    };

    ~AbstractLedEffect(){};

    void setColor(uint8_t r, uint8_t g, uint8_t b)
    {
      // Todo: Should not use a (specific) neopixel instance to get color from it
      _color = _stripe.Color(r,g,b);
    };
    
    void setColor(uint32_t color)
    {
      _color = color;
    };
    
    void setRange(uint16_t indexStart, uint16_t indexEnd)
    {
      if (indexStart <= indexEnd) {
        _ledIndexStart = indexStart;
        _ledIndexEnd = indexEnd;
      }
    };

    virtual uint32_t getEffectColor() = 0;
    virtual void run() = 0;

    uint32_t colorGenerator();
  
  protected:

    void logColors(uint8_t red, uint8_t green, uint8_t blue)
    {
      // Todo: Dumb function - modify or remove
      Serial.print("Color - R:G:B");
      Serial.print(red);
      Serial.print(":");
      Serial.print(green);
      Serial.print(":");
      Serial.print(blue);
      Serial.print("\r\n\r\n");
    };
  
    Adafruit_NeoPixel _stripe;
    uint32_t _color;
    uint16_t _numLEDs;
    
    // must be set
    uint16_t _ledIndexStart;
    uint16_t _ledIndexEnd;
    
    uint8_t _numSteps;
    uint8_t _activeStep;

    uint32_t _primaryColors[NumPrimColors];
    uint8_t  _activePrimaryColor;
    
    uint8_t  _brightness[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

    // deprecated
    uint8_t  _divisor[7] = {1, 1, 1, 1, 1, 1, 1};

};

