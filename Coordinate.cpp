#include "Coordinate.h"
#include <string.h>

// size of touchscreen in landscape mode
#define MAX_X 480
#define MAX_Y 320

Coordinate::Coordinate(int x, int y) {
  // default value is 0 if value is unvalid
  if(x < MAX_X) {
    this -> x = x;
  } else {
    this -> x = 0;
  }

  if(y < MAX_Y) {
    this -> y = y;
  } else {
    this -> y = 0;
  }
}

int Coordinate::getX() {
  return x;
}

int Coordinate::getY() {
  return x;
}

bool Coordinate::setX(int x) {
  if(x < MAX_X) {
    this -> x = x;
    return true;
  }
  return false;
}

bool Coordinate::setY(int y) {
  if(y < MAX_Y) {
    this -> y = y;
    return true;
  }
  return false;
}
