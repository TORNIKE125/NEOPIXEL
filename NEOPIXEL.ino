/*this code is for neopixel
speed controling with  potentiometer*/


#include <Adafruit_NeoPixel.h>

#define LED_PIN     6     
// define under this comment is abaut neopixel leds
/* ამ კომენტარის ქვემოთ დაწერილ დიფაინში არის ნეოპიქსელის
ნათურების რაოდენობა მოარგე ეს რიცხვი შენს ნეოპიქსელის ლედებს*/


#define LED_COUNT   24    
#define POT_PIN     A0    

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           
  strip.show();            
  strip.setBrightness(50); 
}

void loop() {
  int potValue = analogRead(POT_PIN);               
  int delayTime = map(potValue, 0, 1023, 10, 100);  

  
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0)); 
    strip.show();
    delay(delayTime);
    strip.setPixelColor(i, strip.Color(0, 0, 0));   
  }
}
/* გაითვალისწინე რომ ნეოპიქსელთა მონაცვლეობის 
სიჩქარე კონტროლდება პოტენციომეტრით */


