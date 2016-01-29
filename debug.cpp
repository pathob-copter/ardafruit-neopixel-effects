#define DEBUG

#include <iostream>
#include "Adafruit_NeoPixel_Effects.h"

using namespace std;
using namespace AdafruitNeopixelEffects;

int main()
{
    _ColorGenerator colorGenerator;

    colorGenerator.addColor(_Color(255,0,0));
    colorGenerator.addColor(_Color(0,255,0));
    colorGenerator.addColor(_Color(0,0,255));

    for (int i = 0; i < 6; i++) {
        cout << colorGenerator.getNextColor().toInt() << endl;
    }

    return 0;
}
