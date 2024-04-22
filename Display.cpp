#include "Display.h"
#include "Gyro.h"
#include "Coordinate.h"
#include "Line.h"
#include "Wall.h"
#include "Hole.h"
#include "Maze.h"
#include "Level.h"

//Touchscreen Libraries:
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin

#define TS_MINX 130
#define TS_MAXX 905

#define TS_MINY 75
#define TS_MAXY 930

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;


#define MINPRESSURE 10
#define MAXPRESSURE 1000

#define BOXSIZE 40
#define PENRADIUS 2
int oldcolor, currentcolor;

void Display::initialize() {
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());
  tft.setRotation(1);
  tft.fillScreen(WHITE);
}

void Display::getTouchInput() {
  // ... read Touchscreen input
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    
    if (p.y < (TS_MINY-5)) {
      Serial.println("erase");
      // press the bottom of the screen to erase 
      tft.fillRect(0, BOXSIZE, tft.width(), tft.height()-BOXSIZE, BLACK);
    }
    p.x = p.x + p.y;       
    p.y = p.x - p.y;            
    p.x = p.x - p.y;   
    
    // scale from 0->1023 to tft.width
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    //p.y = (tft.height()-map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    p.y = tft.height()-(map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
     //p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);

    if (p.y < BOXSIZE) {
       oldcolor = currentcolor;

       if (p.x < BOXSIZE) { 
         currentcolor = RED; 
         tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
       } else if (p.x < BOXSIZE*2) {
         currentcolor = YELLOW;
         tft.drawRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, WHITE);
       } else if (p.x < BOXSIZE*3) {
         currentcolor = GREEN;
         tft.drawRect(BOXSIZE*2, 0, BOXSIZE, BOXSIZE, WHITE);
       } else if (p.x < BOXSIZE*4) {
         currentcolor = CYAN;
         tft.drawRect(BOXSIZE*3, 0, BOXSIZE, BOXSIZE, WHITE);
       } else if (p.x < BOXSIZE*5) {
         currentcolor = BLUE;
         tft.drawRect(BOXSIZE*4, 0, BOXSIZE, BOXSIZE, WHITE);
       } else if (p.x < BOXSIZE*6) {
         currentcolor = MAGENTA;
         tft.drawRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, WHITE);
       }

       if (oldcolor != currentcolor) {
          if (oldcolor == RED) tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
          if (oldcolor == YELLOW) tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, YELLOW);
          if (oldcolor == GREEN) tft.fillRect(BOXSIZE*2, 0, BOXSIZE, BOXSIZE, GREEN);
          if (oldcolor == CYAN) tft.fillRect(BOXSIZE*3, 0, BOXSIZE, BOXSIZE, CYAN);
          if (oldcolor == BLUE) tft.fillRect(BOXSIZE*4, 0, BOXSIZE, BOXSIZE, BLUE);
          if (oldcolor == MAGENTA) tft.fillRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, MAGENTA);
       }
    }
    if (((p.y-PENRADIUS) > BOXSIZE) && ((p.y+PENRADIUS) < tft.height())) {
      tft.fillCircle(p.x, p.y, PENRADIUS, currentcolor);
    }
  }
}

void Display::draw() {
  tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
  tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, YELLOW);
  tft.fillRect(BOXSIZE*2, 0, BOXSIZE, BOXSIZE, GREEN);
  tft.fillRect(BOXSIZE*3, 0, BOXSIZE, BOXSIZE, CYAN);
  tft.fillRect(BOXSIZE*4, 0, BOXSIZE, BOXSIZE, BLUE);
  tft.fillRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, MAGENTA);
  // tft.fillRect(BOXSIZE*6, 0, BOXSIZE, BOXSIZE, WHITE);
 
  tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
  currentcolor = RED;
}

int Display::getSizeX() {
  return tft.width();
}

int Display::getSizeY() {
  return tft.height();
}


void Display::drawLine(int x1, int y1, int x2, int y2, uint16_t color) {
  tft.drawLine(x1, y1, x2, y2, color);
}

void Display::drawLine(Line *l, uint16_t color) {
  drawLine(l->getStart().getX(), l->getStart().getY(), l->getEnd().getX(), l->getEnd().getY(), color);
}

void Display::drawLine(Line *l) {
  drawLine(l, BLUE);
}

void Display::fillRect(int x1, int y1, int x2, int y2, uint16_t color) {
  tft.fillRect(x1, y1, x2, y2, color);
}

void Display::fillRect(Coordinate *start, Coordinate *end, uint16_t color) {
  fillRect(start->getX(), start->getY(), end->getX(), end->getY(), color);
}

/*void Display::drawWall(Wall *w) {
  if(w->getLine().getStart().getX() == w->getLine().getEnd().getX()) {
    //vertical line
    fillRect(w->getLine().getStart().getX(), w->getLine().getStart().getY(), w->getLine().getEnd().getX()+w->getThickness(), w->getLine().getEnd().getY(), BLUE);
  } else {
    //horizontal line
    fillRect(w->getLine().getStart().getX(), w->getLine().getStart().getY(), w->getLine().getEnd().getX(), w->getLine().getEnd().getY()+w->getThickness(), BLUE);    
  }
}*/

void Display::drawWall(Line *l) {
  if(l->getStart().getX() == l->getEnd().getX()) {
    //vertical line
    fillRect(l->getStart().getX(), l->getStart().getY(), (l->getEnd().getX())+10, l->getEnd().getY(), BLUE);
  } else {
    //horizontal line
    fillRect(l->getStart().getX(), l->getStart().getY(), l->getEnd().getX(), (l->getEnd().getY())+10, BLUE);
  }
}

#define HOLE_SIZE 40
#define BALL_SIZE 30

void Display::drawCircle(int x, int y, int radius, uint16_t color) {
  tft.drawCircle(x, y, radius, color);
}

void Display::drawCircle(Coordinate *c, int radius, uint16_t color) {
  drawCircle(c->getX(), c->getY(), radius, color);
}

void Display::fillCircle(int x, int y, int radius, uint16_t color) {
  tft.fillCircle(x, y, radius, color);
}

void Display::fillCircle(Coordinate *c, int radius, uint16_t color) {
  fillCircle(c->getX(), c->getY(), radius, color);
}

void Display::drawHole(Coordinate *c) {
  fillCircle(c->getX(), c->getY(), HOLE_SIZE/2, BLACK);
}

void Display::drawBall(Coordinate *c) {
  fillCircle(c->getX(), c->getY(), BALL_SIZE/2, BLUE);
}

void Display::printText(int x, int y, String txt) {
  tft.setTextSize(1);
  tft.setTextColor(WHITE, BLACK);
  tft.setCursor(x, y);
  tft.print(txt);
}

void Display::printText(Coordinate *c, String txt) {
  printText(c->getX(), c->getY(), txt);
}
