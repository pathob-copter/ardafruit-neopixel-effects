#include <Adafruit_NeoPixel.h>

class AbstractLedEffect {

  public:

    static const uint8_t Red   = 0;
    static const uint8_t Green = 1;
    static const uint8_t Blue  = 2;

    static const uint8_t NumPrimColors = 3;

    AbstractLedEffect(Adafruit_NeoPixel stripe);
    ~AbstractLedEffect(){};

    virtual void run() = 0;
  
  protected:

    void logColors(uint8_t red, uint8_t green, uint8_t blue);
  
    Adafruit_NeoPixel _stripe;
    uint16_t _numLEDs;

    uint32_t _primaryColors[NumPrimColors];
    uint8_t _activePrimaryColor;

};

