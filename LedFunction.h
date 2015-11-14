#include <Adafruit_NeoPixel.h>

class LedFunction {

  public:

    LedFunction(Adafruit_NeoPixel stripe);
    ~LedFunction();
  
  private:
  
    Adafruit_NeoPixel _stripe;

}
