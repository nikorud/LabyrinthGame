#include "Hole.h"
#include "Coordinate.h"
#include "Display.h"

Hole::Hole(Coordinate *c) {
  this -> c = c;
}

Coordinate Hole::getCoordinate() {
  return *c;
}

void Hole::draw(){
    Display::drawHole(c);
}
