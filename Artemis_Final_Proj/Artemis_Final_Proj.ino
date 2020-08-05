/ ----------------------------------------------------------------------------
// sample 4-LED rhythm program
//----------------------------------------------------------------------------

#define NUM_LEDS 10
#define PIN A0

#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel s = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);


//
// flash one LED at specified color for specified time in ms
//
void flashColor(uint32_t c, uint16_t ms) {
  for (int i = 0; i < s.numPixels(); i++)
    s.setPixelColor( i, c);
  s.show();
  delay( ms);
  for (int i = 0; i < s.numPixels(); i++)
    s.setPixelColor( i, 0, 0, 0);
  s.show();
}

//void showLEDS () {
//  uint32_t temp;
//  uint32_t r, g, b;
//  for (int i=8; i<12; i++) {
//    temp = s.getPixelColor(i);
//    r = (temp >> 16) & 0xFF;
//    g = (temp >> 8) & 0xFF;
//    b = (temp) & 0xFF;
//    s.setPixelColor(i, g, r, b);
//  }
//  s.show();
//}

//
// set all pixels in string to the same color
//
void setAllPixelColor( uint8_t r, uint8_t g, uint8_t b) {
  for ( int i = 0; i < NUM_LEDS; i++) {
    s.setPixelColor( i, r, g, b);
  }
}

//
// setup routine:  initialize LED string, set brightness
//
void setup() {
  s.begin();
  s.setBrightness(100);
  s.show();
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < s.numPixels(); i++) {
      s.setPixelColor(i, Wheel(((i * 256 / s.numPixels()) + j) & 255));
    }
    s.show();
    delay(wait);
  }
}


uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return s.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return s.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return s.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void sweepMediumTorquiose(uint8_t stop, uint16_t ms) {
  int i;
  for (i = 0; i < stop; i++) {
    setAllPixelColor(72, 209, 204);
    s.show();
    delay(ms);
  }

  for ( ; i > 0; i--) {
    setAllPixelColor(72, 209, 204);
    s.show();
    delay(ms);
  }
}

void sweepSteelBlue(uint8_t stop, uint16_t ms) {
  int i;
  for (i = 0; i < stop; i++) {
    setAllPixelColor(70, 130, 180);
    s.show();
    delay(ms);
  }

  for ( ; i > 0; i--) {
    setAllPixelColor(70, 130, 180);
    s.show();
    delay(ms);
  }
}


void sweepDeepBlue(uint8_t stop, uint16_t ms) {
  int i;
  for (i = 0; i < stop; i++) {
    setAllPixelColor(0, 191, 255);
    s.show();
    delay(ms);
  }

  for ( ; i > 0; i--) {
    setAllPixelColor(0, 191, 255);
    s.show();
    delay(ms);
  }
}

void sweepMediumBlue(uint8_t stop, uint16_t ms) {
  int i;
  for (i = 0; i < stop; i++) {
    setAllPixelColor(0, 0, 205);
    s.show();
    delay(ms);
  }

  for ( ; i > 0; i--) {
    setAllPixelColor(0, 0, 205);
    s.show();
    delay(ms);
  }
}

void sweepMidnightBlue(uint8_t stop, uint16_t ms) {
  int i;
  for (i = 0; i < stop; i++) {
    setAllPixelColor(25, 25, 112);
    s.show();
    delay(ms);
  }

  for ( ; i > 0; i--) {
    setAllPixelColor(25, 25, 112);
    s.show();
    delay(ms);
  }
}


void loop() {
  delay(300);
  setAllPixelColor(0, 0, 0);

  for ( int i = 0; i < 7; i++ ) {
    for (int j = 0; j < s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(102, 205, 170));
      s.setPixelColor(j - 1, s.Color(0, 255, 127));
      s.setPixelColor(j - 2, s.Color(34, 139, 34));
      delay(340);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j - 1, s.Color(0, 0, 0));
      s.setPixelColor(j - 2, s.Color(0, 0, 0));
    }
  }

  setAllPixelColor(0, 0, 0);
  flashColor(s.Color(255, 105, 180), 2000);
  delay(300);
  flashColor(s.Color(255, 105, 180), 2000);
  delay(300);
  flashColor(s.Color(255, 105, 180), 2000);
  delay(500);
  rainbowCycle(2);
  flashColor(s.Color(0, 0, 0), 2000);

  for ( int i = 0; i < 4; i++ ) {
    for (int j = 0; j < s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(102, 51, 153));
      s.setPixelColor(j - 1, s.Color(139, 0, 139));
      s.setPixelColor(j - 2, s.Color(75, 0, 130));
      s.setPixelColor(j - 3, s.Color(72, 61, 139));
      s.setPixelColor(j - 4, s.Color(0, 0, 128));
      s.setPixelColor(j - 5, s.Color(215, 190, 215));
      s.setPixelColor(j - 6, s.Color(128, 0, 128));
      s.setPixelColor(j - 7, s.Color(186, 85, 211));
      s.setPixelColor(j - 8, s.Color(0, 0, 139));
      s.setPixelColor(j - 9, s.Color(25, 25, 112));
      delay(100);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j - 1, s.Color(0, 0, 0));
      s.setPixelColor(j - 2, s.Color(0, 0, 0));
      s.setPixelColor(j - 3, s.Color(0, 0, 0));
      s.setPixelColor(j - 4, s.Color(0, 0, 0));
      s.setPixelColor(j - 5, s.Color(0, 0, 0));
      s.setPixelColor(j - 6, s.Color(0, 0, 0));
      s.setPixelColor(j - 7, s.Color(0, 0, 0));
      s.setPixelColor(j - 8, s.Color(0, 0, 0));
      s.setPixelColor(j - 9, s.Color(0, 0, 0));
      delay(200);
    }
    flashColor(s.Color(255, 105, 180), 2000);
  }

  flashColor(s.Color(25, 25, 112), 2000);
  flashColor(s.Color(255, 220, 0), 1000);

  for ( int i = 0; i < 1; i++ ) {
    for (int j = 0; j < s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(255, 220, 0));
      s.setPixelColor(j - 1, s.Color(72, 61, 139));
      s.setPixelColor(j - 2, s.Color(106, 90, 205));
      delay(340);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j - 1, s.Color(0, 0, 0));
      s.setPixelColor(j - 2, s.Color(0, 0, 0));
    }
  }
  for ( int i = 0; i < 2; i++ ) {
    for (int j = 0; j < s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(255, 127, 80));
      s.setPixelColor(j - 1, s.Color(205, 92, 92));
      s.setPixelColor(j - 2, s.Color(220, 20, 60));
      s.setPixelColor(j - 3, s.Color(255, 0, 0));
      s.setPixelColor(j - 4, s.Color(178, 34, 34));
      s.setPixelColor(j - 5, s.Color(139, 0, 0));
      s.setPixelColor(j - 6, s.Color(165, 42, 42));
      s.setPixelColor(j - 7, s.Color(128, 0, 0));
      delay(100);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j - 1, s.Color(0, 0, 0));
      s.setPixelColor(j - 2, s.Color(0, 0, 0));
      s.setPixelColor(j - 3, s.Color(0, 0, 0));
      s.setPixelColor(j - 4, s.Color(0, 0, 0));
      s.setPixelColor(j - 5, s.Color(0, 0, 0));
      s.setPixelColor(j - 6, s.Color(0, 0, 0));
      s.setPixelColor(j - 7, s.Color(0, 0, 0));
      delay(250);
    }
    flashColor(s.Color(255, 160, 122), 2000);
  }

  flashColor(s.Color(72, 61, 139), 500);
  delay(250);
  flashColor(s.Color(173, 216, 230), 500);
  delay(250);
  flashColor(s.Color(123, 104, 238), 500);
  delay(250);
  flashColor(s.Color(72, 61, 139), 500);
  delay(250);
  flashColor(s.Color(173, 216, 230), 500);
  delay(250);
  flashColor(s.Color(123, 104, 238), 500);
  delay(250);
  flashColor(s.Color(72, 61, 139), 500);
  delay(250);
  flashColor(s.Color(173, 216, 230), 500);
  delay(250);
  flashColor(s.Color(123, 104, 238), 500);
  delay(250);
  flashColor(s.Color(255, 215, 0), 500);
  delay(250);
  flashColor(s.Color(0, 250, 154), 500);
  delay(250);
  flashColor(s.Color(30, 144, 255), 500);
  delay(250);
  flashColor(s.Color(0, 206, 209), 500);
  delay(250);


  for ( int i = 0; i < 7; i++ ) {
    for (int j = 0; j < s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(102, 205, 170));
      s.setPixelColor(j - 1, s.Color(0, 255, 127));
      s.setPixelColor(j - 2, s.Color(34, 139, 34));
      delay(340);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j - 1, s.Color(0, 0, 0));
      s.setPixelColor(j - 2, s.Color(0, 0, 0));
    }
  }
  for ( int i = 0; i < 3; i++ ) {
    for (int j = 0; j < s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(102, 51, 153));
      s.setPixelColor(j - 1, s.Color(139, 0, 139));
      s.setPixelColor(j - 2, s.Color(75, 0, 130));
      s.setPixelColor(j - 3, s.Color(72, 61, 139));
      s.setPixelColor(j - 4, s.Color(0, 0, 128));
      s.setPixelColor(j - 5, s.Color(215, 190, 215));
      s.setPixelColor(j - 6, s.Color(128, 0, 128));
      s.setPixelColor(j - 7, s.Color(186, 85, 211));
      s.setPixelColor(j - 8, s.Color(0, 0, 139));
      s.setPixelColor(j - 9, s.Color(25, 25, 112));
      delay(100);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j - 1, s.Color(0, 0, 0));
      s.setPixelColor(j - 2, s.Color(0, 0, 0));
      s.setPixelColor(j - 3, s.Color(0, 0, 0));
      s.setPixelColor(j - 4, s.Color(0, 0, 0));
      s.setPixelColor(j - 5, s.Color(0, 0, 0));
      s.setPixelColor(j - 6, s.Color(0, 0, 0));
      s.setPixelColor(j - 7, s.Color(0, 0, 0));
      s.setPixelColor(j - 8, s.Color(0, 0, 0));
      s.setPixelColor(j - 9, s.Color(0, 0, 0));
      delay(200);
    }
    flashColor(s.Color(255, 105, 180), 2000);
  }
  sweepMediumTorquiose(180, 50);
  sweepSteelBlue(180, 50);
  sweepDeepBlue(180, 40);
  sweepMediumBlue(180, 30);
  sweepMidnightBlue(180, 20);
  sweepMediumTorquiose(180, 20);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < s.numPixels(); j++) {
      s.setPixelColor(Color(random(0, 255), random(0, 255), random(0, 255)));
      delay(random(10, 100));
    }
  }
  rainbowCycle(2);

  for (int i = 0; i < 5) {
    flashColor(s.Color(220, 20, 60), 500);
    delay(10);
    flashColor(s.Color((255, 215, 0)), 500);
    delay(10);
    flashColor(s.Color(30, 144, 255)), 500);
    delay(10);
  }

}