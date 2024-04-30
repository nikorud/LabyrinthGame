#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

class Display {  
  public:
    static void initialize();
    static void getTouchInput();
    static int getSizeX();
    static int getSizeY();
    static void fillScreen(uint16_t color);

    static void startScreen();
    static void retryScreen();
    static void nextLvlScreen();
    static void endScreen();

    static void printText(int x, int y, String txt, int txtSize, uint16_t color);
    static void printText(int x, int y, String txt, int txtSize);
    static void printText(int x, int y, String txt);

    static void drawLine(int x1, int y1, int x2, int y2, uint16_t color);
    static void fillRect(int x1, int y1, int x2, int y2, uint16_t color);    
    static void fillCircle(int x, int y, int radius, uint16_t color);
    static void drawCircle(int x, int y, int radius, uint16_t color);
    
    static void drawWall(int x, int y, int wSize);
    static void drawExit(int x, int y, int gSize);
    static void drawHole(int x, int y, int hSize);
    static void drawBall(int old_x, int old_y, int new_x, int new_y, int bSize);
    static void drawBall(int x, int y, int bSize);    
};

#endif
