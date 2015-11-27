#pragma once

#include <Adafruit_NeoPixel.h>
#include <StandardCplusplus.h>
#include <boost_1_51_0.h>

#include "Color.h"
#include "RunningLight.h"
#include "FlashLight.h"
#include "DurableLight.h"

#define LED_01_PIN      3
#define LED_01_NUM      13

using namespace AdafruitNeopixelEffects;

Adafruit_NeoPixel* led_01 = new Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);

Color orange = boost::make_shared<_Color>(255,200,10);
FlashLight beagle = boost::make_shared<_FlashLight>(led_01, orange);

void setup()
{
  Serial.begin(115200);
  delay(1000);

  //led_01->begin();
  //beagle->setRange(0, 0);
}

void loop()
{
  Serial.println(orange->toInt());
  //beagle->run();
  //led_01->show();

  delay(1000);
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

