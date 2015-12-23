#pragma once

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>

#include "Color.h"
#include "RunningLight.h"
#include "FlashLight.h"
#include "DurableLight.h"

#define LED_01_PIN      2
#define LED_01_NUM      2

using namespace AdafruitNeopixelEffects;

Adafruit_NeoPixel ledF = Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);

_Color orange(255,200,10);
_Color red(255,0,0);
_Color blue(0,0,255);
_FlashLight beagleF(ledF);

void setup()
{
  Serial.begin(115200);
  ledF.begin();
  delay(1000);
  
  Serial.print("Setup: ");
  Serial.println(blue.toInt());

  beagleF.setColor(blue);
  beagleF.setRange(0, 1);

  beagleF.run();
  ledF.show();

  // _Node<_Color>* node = (_Node<_Color>*) 928;
  // Serial.print("Test: ");
  // Serial.print(node->_item.toInt());
}

void loop()
{
  Serial.print("Loop: ");
  Serial.println(orange.toInt());
  
  beagleF.run();
  // ledF.setPixelColor(0, ledF.Color(0,150,0));
  ledF.show();

  delay(6000);
}

/*
#define LED_01_PIN      3
#define LED_01_NUM      13

Adafruit_NeoPixel led_01 = Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);
FlashLight beagle = FlashLight(led_01);
FlashLight flashLight = FlashLight(led_01);
DurableLight durableLight = DurableLight(led_01);

int delayTime = 60;

void setup() {
  Serial.begin(9600);
  
  led_01.begin();

  beagle.setRange(0, 7);
  beagle.setColor(255,200,0);
  uint8_t beagleFunction[16] = {0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 0 ,0};
  beagle.setEffectFunction(beagleFunction);
  
  durableLight.setRange(9, 12);
  durableLight.setColor(255,0,0);
  //durableLight.setColor(0,255,0);
}

void loop() {
  beagle.run();
  durableLight.run();
  led_01.show();
  delay(delayTime);
}
*/

