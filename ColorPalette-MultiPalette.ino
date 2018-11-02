#include <FastLED.h>
#include <elapsedMillis.h>
elapsedMillis timer1;

#define LED_PIN     3
#define NUM_LEDS    60
#define BRIGHTNESS  64
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

int UPDATES_PER_SECOND;

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.



CRGBPalette16 currentPalette, girlPalette, rainPalette, cityPalette, puddlePalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
   
    currentBlending = LINEARBLEND;
}


void loop()
{
 
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */

  if (timer1 < 10000) {
    FillLEDsFromPaletteColors_scene1(startIndex);
  }
  else if ((timer1 > 10000) && (timer1 < 20000)) {
    FillLEDsFromPaletteColors_scene2(startIndex); 
  }
  else if ((timer1 > 20000) && (timer1 < 40000)) {
    FillLEDsFromPaletteColors_scene3(startIndex); 
  }
  else {
    timer1 = 0;
  }

   
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors_scene1( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    UPDATES_PER_SECOND = 10;
    girlPalette = solidpurpleColors_p;
    rainPalette = OceanColors_p;
    cityPalette = CityColors_p;
    puddlePalette = ForestColors_p;
    
     for( int i = 1; i < 11; i++) {
        leds[i] = ColorFromPalette( rainPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    
    for( int i = 17; i < 21; i++) {
        leds[i] = ColorFromPalette( girlPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    for( int i = 29; i < 44; i++) {
        leds[i] = ColorFromPalette( puddlePalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    for( int i = 44; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( cityPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void FillLEDsFromPaletteColors_scene2( uint8_t colorIndex)
{
    uint8_t brightness = 10;
    UPDATES_PER_SECOND = 100;
    girlPalette = LavaColors_p;
    rainPalette = PartyColors_p;
    cityPalette = RainbowStripeColors_p;
    puddlePalette = RainbowStripeColors_p; 
    
     for( int i = 1; i < 11; i++) {
        leds[i] = ColorFromPalette( rainPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    
    for( int i = 17; i < 21; i++) {
        leds[i] = ColorFromPalette( girlPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    for( int i = 29; i < 44; i++) {
        leds[i] = ColorFromPalette( puddlePalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    for( int i = 44; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( cityPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void FillLEDsFromPaletteColors_scene3( uint8_t colorIndex)
{
    uint8_t brightness = 100;
    uint8_t brightness_girl = 255;
    UPDATES_PER_SECOND = 25;
    girlPalette = ForestColors_p;
    rainPalette = CloudColors_p;
    cityPalette = OceanColors_p;
    puddlePalette = solidpurpleColors_p; 
    
     for( int i = 1; i < 11; i++) {
        leds[i] = ColorFromPalette( rainPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    
    for( int i = 17; i < 21; i++) {
        leds[i] = ColorFromPalette( girlPalette, colorIndex, brightness_girl, currentBlending);
        colorIndex += 3;
    }
    for( int i = 29; i < 44; i++) {
        leds[i] = ColorFromPalette( puddlePalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    for( int i = 44; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( cityPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}
// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.

