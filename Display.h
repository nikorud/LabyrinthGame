#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

#include "Gyro.h"
#include "Coordinate.h"
#include "Line.h"
#include "Wall.h"
#include "Hole.h"
#include "Maze.h"
#include "Level.h"

class Display {  
  public:
    static void initialize();
    static void getTouchInput();
    static void draw();
    static int getSizeX();
    static int getSizeY();

    static void drawLine(int x1, int y1, int x2, int y2, uint16_t color);
    static void drawLine(Line *l, uint16_t color);
    static void drawLine(Line *l);

    static void fillRect(int x1, int y1, int x2, int y2, uint16_t color);
    static void fillRect(Coordinate *start, Coordinate *end, uint16_t color);
    //static void drawWall(Wall *w);
    static void drawWall(Line *l);
    
    static void fillCircle(int x, int y, int radius, uint16_t color);
    static void fillCircle(Coordinate *c, int radius, uint16_t color);
    static void drawCircle(int x, int y, int radius, uint16_t color);
    static void drawCircle(Coordinate *c, int radius, uint16_t color);
    static void drawHole(Coordinate *c);
    static void drawBall(Coordinate *c);

    static void printText(int x, int y, String txt);
    static void printText(Coordinate *c, String txt);
};

#endif
