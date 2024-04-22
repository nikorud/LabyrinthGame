#include "Wall.h"
#include "Line.h"
#include "Display.h"

#define WALL_THICKNESS 10
#define COLOR 0x0000 // black

Wall::Wall(Line *l) {
  this -> l = l;
  thickness = WALL_THICKNESS;
}

Line Wall::getLine() {
  return *l;
}

int Wall::getThickness() {
  return thickness;
}

void Wall::draw() {
  //Display::drawWall(this);
  Display::drawWall(l);
}
