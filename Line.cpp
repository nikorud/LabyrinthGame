#include "Line.h"
#include "Coordinate.h"
#include "Display.h"

Line::Line(Coordinate *start, Coordinate *end) {
  this -> start = start;
  this -> end = end;
}

Coordinate Line::getStart() {
  return *start;
}

Coordinate Line::getEnd() {
  return *end;
}

void Line::draw() {
  Display::drawLine(this);
}
