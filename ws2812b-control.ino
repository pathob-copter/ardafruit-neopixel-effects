#include <Adafruit_NeoPixel.h>

#define LED_01_PIN      3
#define LED_01_NUM      13

#define RED   0
#define GREEN 1
#define BLUE  2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_01_NUM, LED_01_PIN, NEO_GRB + NEO_KHZ800);

int delayval = 40; // delay for half a second

bool increase = true;
int index = 0;

int color[3];
int offset;

void setup() {
  Serial.begin(9600);
  
  pixels.begin();
  pixels.setBrightness(255);
  pixels.show();
  
  offset = 0;
  
  color[RED]   = 255;
  color[GREEN] = 0;
  color[BLUE]  = 0;
}

void loop() {
  
  for(int i=0;i<LED_01_NUM;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  
  if (color[offset] == 0) {
    offset = (offset + 1) % 3;
  }
  
  color[offset]--;
  color[(offset+1)%3]++;
  
  Serial.print(color[RED]);
  Serial.print(" - ");
  Serial.print(color[GREEN]);
  Serial.print(" - ");
  Serial.println(color[BLUE]);
  
  pixels.setPixelColor(index, pixels.Color(color[RED],color[GREEN],color[BLUE]));
  
  index = (index + 1) % LED_01_NUM;
  
  pixels.show();
  delay(delayval);
}
