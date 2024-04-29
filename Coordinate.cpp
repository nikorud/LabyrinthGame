#include "Coordinate.h"
#include "Display.h"
#include <string.h>

#define INFO_BAR_SIZE 15

Coordinate::Coordinate(int x, int y) {
  // default value is 0 if value is unvalid
  if(x < Display::getSizeX()) {
    this -> x = x;
  } else {
    this -> x = 0;
  }

  if(y < Display::getSizeY()-INFO_BAR_SIZE) {
    this -> y = y;
  } else {
    this -> y = 0;
  }
}

int Coordinate::getX() {
  return x;
}

int Coordinate::getY() {
  // this will return the y-position starting with y=15 (under the Info-Bar ["Level (Difficulty), Attempts: x"])
  return y; // + INFO_BAR_SIZE;
}

bool Coordinate::setX(int x) {
  if(x < Display::getSizeX()) {
    this -> x = x;
    return true;
  }
  return false;
}

bool Coordinate::setY(int y) {
  if(y < Display::getSizeY()) {
    this -> y = y;
    return true;
  }
  return false;
}
