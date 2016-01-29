#ifndef ADAFRUITNEOPIXELEFFECTS_ADAFRUIT_NEIPIXEL_EFFECTS_H
#define ADAFRUITNEOPIXELEFFECTS_ADAFRUIT_NEIPIXEL_EFFECTS_H

#ifdef DEBUG 
typedef int int8_t;
typedef int int16_t;
typedef int int32_t;

typedef int uint8_t;
typedef int uint16_t;
typedef int uint32_t;

typedef bool boolean;

#include "debug/Serial.h"
#include "debug/Adafruit_NeoPixel.h"

namespace AdafruitNeopixelEffects
{
    _Serial Serial;
}

#else
#include <Adafruit_NeoPixel.h>
#endif

#include "List.h"
#include "Color.h"
#include "ColorGenerator.h"

#endif
