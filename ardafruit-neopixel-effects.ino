#include <Adafruit_NeoPixel.h>
#include "RunningLight.h"
#include "FlashLight.h"
#include "DurableLight.h"
#include "ColorGenerator.h"
#include "List.h"

List<String> list;

void setup()
{
  Serial.begin(115200);
  
  list.add("Hello");
  list.add("big");
  list.add("world");
  
  Serial.println("");
}

void loop()
{
  //Serial.println((String) list.first());
  //Serial.println((String) list.last());
  Serial.println((String) list.get(3));
  //Serial.println((String) list.get(1));
  //Serial.println((String) list.get(2));
  
  Serial.println("");
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

