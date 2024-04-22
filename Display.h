#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

class Display {
  public:
    static void initialize();
    static void getTouchInput();
    static void draw();
};

#endif
