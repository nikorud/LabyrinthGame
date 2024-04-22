
#include "Coordinate.h"

#ifndef HOLE_H
#define HOLE_H

class Hole {
  private:
    Coordinate *c;

  public:
    Hole(Coordinate *c);
    Coordinate getCoordinate();
    void draw();
};

#endif
