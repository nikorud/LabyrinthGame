#include "Hole.h"
#include "Coordinate.h"

Hole::Hole(Coordinate *c) {
  this -> c = c;
}

Coordinate Hole::getCoordinate() {
  return *c;
}

void Hole::draw(){
    
}
