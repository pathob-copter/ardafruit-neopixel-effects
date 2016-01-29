#define DEBUG

#include <iostream>
#include "Adafruit_NeoPixel_Effects.h"

using namespace std;
using namespace AdafruitNeopixelEffects;

int main()
{

    _List<_Color> list;
    list.add(_Color(255,0,0));
    list.add(_Color(0,255,0));
    list.add(_Color(0,0,255));

    cout << list.size() << endl;

    /*
    for (int i = 0; i <= 50; i++) {
        cout << list.iterate() << endl;
    }


    cout << list.first() << endl;
    cout << list.last() << endl << endl;
    */

    for (int i = 0; i < list.size(); i++) {
        cout << list.get(i).toInt() << endl;
    }

    return 0;
}
