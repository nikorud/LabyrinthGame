#include "Display.h"
#include "Gyro.h"
#include "Level.h"
#include "Ball.h"

#include <Adafruit_GFX.h>    // Touchscreen - Core graphics library
#include <Adafruit_TFTLCD.h> // Touchscreen - Hardware-specific library
#include <TouchScreen.h>

#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

#define YP A2 
#define XM A3 
#define YM 8
#define XP 9

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

#define DISPLAY_SIZE_X 480
#define DISPLAY_SIZE_Y 320

#define BOXSIZE 40
#define PENRADIUS 2
int oldcolor, currentcolor;

TSPoint p;

void Display::initialize() {
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
}

void Display::getTouchInput() {
  // ... read Touchscreen input
  digitalWrite(13, HIGH);
  p = ts.getPoint();
  digitalWrite(13, LOW);

  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    p.y = p.y + p.x;       
    p.x = p.y - p.x;            
    p.y = p.y - p.x;   
    
    // scale from 0->1023 to tft.width
    p.y = map(p.y, TS_MINX, TS_MAXX, tft.width(), 0);
    p.x = tft.height()-(map(p.x, TS_MINY, TS_MAXY, tft.height(), 0));
  }
}

int Display::getSizeX() {
  return tft.width();
}

int Display::getSizeY() {
  return tft.height();
}

void Display::fillScreen(uint16_t color) {
  tft.fillScreen(color);
}


void Display::startScreen() {
  tft.fillScreen(BLACK);
  printText(40, 40, "Micro:Bit Project", 4, BLUE);
  printText(125, 100, "Tobias WOESENBOECK", 2);
  printText(170, 130, "Niko RUDOLF", 2);

  tft.drawRect(40, 180, 400, 100, WHITE);
  printText(110, 218, "START MAZE GAME", 3);

  boolean buttonPressed = false;
  while(!buttonPressed) {
    getTouchInput();
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      if (p.y > 218) {
        buttonPressed = true;
      }
    }
  }
  tft.fillScreen(WHITE);
}

void Display::retryScreen() {
  fillRect(80, 80, DISPLAY_SIZE_X-160, DISPLAY_SIZE_Y-160, BLACK);
  tft.drawRect(82, 82, DISPLAY_SIZE_X-164, DISPLAY_SIZE_Y-164, WHITE);
  printText(160, 120, "You failed! :(", 2, RED);

  tft.drawRect(90, 170, 300, 60, WHITE);
  printText(175, 192, "RETRY LEVEL", 2);

  boolean buttonPressed = false;
  while(!buttonPressed) {
    getTouchInput();
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      if (p.y > 100 && p.y < 320) {
        buttonPressed = true;
        Level::lvl->load();
      }
    }
  }
}

void Display::nextLvlScreen() {
  fillRect(80, 80, DISPLAY_SIZE_X-160, DISPLAY_SIZE_Y-160, BLACK);
  tft.drawRect(82, 82, DISPLAY_SIZE_X-164, DISPLAY_SIZE_Y-164, WHITE);
  printText(130, 120, "Level finished! :D", 2, GREEN);

  tft.drawRect(90, 170, 300, 60, WHITE);
  printText(178, 192, "NEXT LEVEL", 2);

  boolean buttonPressed = false;
  while(!buttonPressed) {
    getTouchInput();
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      if (p.y > 100 && p.y < 320) {
        buttonPressed = true;
        Level::lvl->loadNextLvl();
      }
    }
  }
}

void Display::endScreen() {
  tft.fillScreen(BLACK);
  printText(40, 40, "Micro:Bit Project", 4, BLUE);
  printText(125, 100, "Tobias WOESENBOECK", 2);
  printText(170, 130, "Niko RUDOLF", 2);  
  printText(70, 200, "YOU FINISHED THE GAME", 3, GREEN);
  printText(60, 240, "THANK TOU FOR PLAYING!", 3, MAGENTA);

  while(1) {
    // ... final endless loop, all levels completed ...
  }
}


void Display::printText(int x, int y, String txt, int txtSize, uint16_t color) {
  tft.setTextSize(txtSize);
  tft.setTextColor(color, BLACK); // ... background is black ...
  tft.setCursor(x, y);
  tft.print(txt);
}

void Display::printText(int x, int y, String txt, int txtSize) {
  printText(x, y, txt, txtSize, WHITE);
}

void Display::printText(int x, int y, String txt) {
  printText(x, y, txt, 1);
}


void Display::drawLine(int x1, int y1, int x2, int y2, uint16_t color) {
  tft.drawLine(x1, y1, x2, y2, color);
}

void Display::fillRect(int x1, int y1, int x2, int y2, uint16_t color) {
  tft.fillRect(x1, y1, x2, y2, color);
}

void Display::drawCircle(int x, int y, int radius, uint16_t color) {
  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y && radius > 0) {
    tft.drawCircle(x, y, radius, color);
  }
}

void Display::fillCircle(int x, int y, int radius, uint16_t color) {
  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y && radius > 0) {
    tft.fillCircle(x, y, radius, color);
  }
}


void Display::drawWall(int x, int y, int wSize) {
  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y && wSize > 0) {
    fillRect(x, y, wSize, wSize, BLACK);
  }
}

void Display::drawExit(int x, int y, int eSize) {
  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y && eSize > 0) {
    fillRect(x, y, eSize, eSize, MAGENTA);
  }
}

void Display::drawHole(int x, int y, int hSize) {
  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y && hSize > 0) {
    fillCircle(x+(hSize/2), y+(hSize/2), hSize/2, YELLOW);
  }
}

void Display::drawBall(int old_x, int old_y, int new_x, int new_y, int bSize) {
  if(new_x >= 0 && new_x <= DISPLAY_SIZE_X && new_y >= 0 && new_y <= DISPLAY_SIZE_Y && bSize > 0) {
    fillCircle(old_x+(bSize/2), old_y+(bSize/2), bSize/2, WHITE);
    Level::refreshLvl();
    fillCircle(new_x+(bSize/2), new_y+(bSize/2), bSize/2, BLUE);
  }
}

void Display::drawBall(int x, int y, int bSize) {
  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y && bSize > 0) {
    fillCircle(x+(bSize/2), y+(bSize/2), bSize/2, BLUE);
  }
}