#include "FastLED.h"
#define NUM_LEDS 9
CRGB leds[NUM_LEDS];
int lum = 15;
#define DATA_PIN 4


int capteur_lum = A2; // capteur branché sur le port 0
int analog_lum; // valeur analogique envoyé par le capteur


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // démarrer la liaison série
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  analog_lum = analogRead(capteur_lum); // lecture de la valeur analogique, qu'on enregistre dans analog_lum
  Serial.print("Valeur luminosité = ");
  Serial.print(analog_lum); 
  Serial.println("");
  delay(1000);
  
if (analog_lum <=512) {
  leds[0] = CRGB(0,0,0);
  leds[1] = CRGB(0,0,0);
  leds[2] = CRGB(0,0,0);
  leds[3] = CRGB(0,0,0);
  leds[4] = CRGB(120,0,200);
  leds[5] = CRGB(0,0,0);
  leds[6] = CRGB(0,0,0);
  leds[7] = CRGB(0,0,0);
  leds[8] = CRGB(0,0,0);
  FastLED.show();
  }
else {
  leds[0] = CRGB(lum,0,0);
  leds[1] = CRGB(0,lum,0);
  leds[2] = CRGB(0,lum,lum);
  leds[3] = CRGB(lum,0,lum);
  leds[4] = CRGB(lum,lum,lum);
  leds[5] = CRGB(lum,lum,0);
  leds[6] = CRGB(0,lum,0);
  leds[7] = CRGB(0,0,lum);
  leds[8] = CRGB(0,lum,lum);
  FastLED.show();
  }







}
