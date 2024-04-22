#include "Wall.h"
#include "Line.h"

#define WIDTH 2
#define COLOR 0x0000 // black

Wall::Wall(Line *l) {
  this -> l = l;
}

void Wall::draw() {
  //TODO
}
