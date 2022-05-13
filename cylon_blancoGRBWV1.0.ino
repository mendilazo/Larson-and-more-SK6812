
#include "BluetoothSerial.h"
#include <WS2812FX.h>
#include "FastLED.h"

// How many leds in your strip?
#define LED_COUNT 16
#define LED_PIN 25


#define BT_WAITTIME 30
#define BT_STARTFLAG 18
#define BT_ACK 19
#define BT_ABORD 27

BluetoothSerial BT;

// Define the array of leds
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
bool gReverseDirection = false;

void setup()
{
   // set up serial out
  Serial.begin(115200);
  delay(20);

  ws2812fx.init();
  ws2812fx.setBrightness(255);
  ws2812fx.setSpeed(2000);
  ws2812fx.setColor(0x000000);
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.start();

  BT.begin("CYLON");
  
  }

void loop() {
// if (BT.available())
{
  int incoming = BT.read();
   
 if (incoming == 48) { 
   ws2812fx.setColor(0x00000000);
   ws2812fx.setBrightness(00);
   ws2812fx.setMode(FX_MODE_STATIC);
    }
  
 if (incoming == 49) {
   ws2812fx.setBrightness(50);
   ws2812fx.setColor(0xFFFFFFFF);
   ws2812fx.setMode(FX_MODE_STATIC);
    }
  
 if (incoming == 50) {
   ws2812fx.setBrightness(150);
   ws2812fx.setSpeed(2000);
   ws2812fx.setColor(0x00FF0000);
   ws2812fx.setMode(FX_MODE_LARSON_SCANNER);
    }
  
 if (incoming == 51) {
    ws2812fx.setColor(0xFFFFFFFF);
    ws2812fx.setBrightness(255);
    ws2812fx.setMode(FX_MODE_STATIC);
    }
    
 if (incoming == 52) {
    ws2812fx.setSpeed(1000);
    ws2812fx.setColor(0x003399FF);
    ws2812fx.setBrightness(200);
    ws2812fx.setMode(FX_MODE_BREATH);
    }
    
 if (incoming == 53) {
    ws2812fx.setColor(0xFF3399FF);
    ws2812fx.setBrightness(30);
    ws2812fx.setMode(FX_MODE_COLOR_WIPE_RANDOM);
    }

// Segunda Columna

    if (incoming == 54) { 
   ws2812fx.service();
   ws2812fx.setColor(RED,ORANGE);//
   ws2812fx.setBrightness(255);
   ws2812fx.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
    }
  
 if (incoming == 55) {
   ws2812fx.service();
   ws2812fx.setSpeed(500);
   ws2812fx.setBrightness(200);
   ws2812fx.setColor(0X00FF7800);
   ws2812fx.setMode(FX_MODE_BLINK);
    }

    ws2812fx.service();      
   }
     delay(10);
   }
  
 
