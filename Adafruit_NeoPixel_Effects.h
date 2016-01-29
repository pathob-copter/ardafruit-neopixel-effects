#include "List.h"
#include "Color.h"

#ifdef DEBUG 
#include "debug/Serial.h"
#include "debug/Adafruit_NeoPixel.h"
#else
#include <Adafruit_NeoPixel.h>
#endif

#ifndef ADAFRUITNEOPIXELEFFECTS_ADAFRUIT_NEIPIXEL_EFFECTS_H
#define ADAFRUITNEOPIXELEFFECTS_ADAFRUIT_NEIPIXEL_EFFECTS_H

namespace AdafruitNeopixelEffects
{

  // Debugging

  #ifdef DEBUG
  typedef int int8_t;
  typedef int int16_t;
  typedef int int32_t;
  
  typedef int uint8_t;
  typedef int uint16_t;
  typedef int uint32_t;

  typedef bool boolean;

  _Serial Serial;
  #endif

  // Base classes
  
  template<typename N>
  class _Node;
  
  template<typename T>
  class _List;

  typedef _List<uint8_t>* Uint8List;
  typedef _List<uint32_t>* Uint32List;
  
  class _Color;
  typedef _Color* Color;
  typedef _List<_Color> _ColorList;
  typedef _List<_Color>* ColorList;
}

#endif