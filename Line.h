#ifndef LINE_H
#define LINE_H

#include "Coordinate.h"

class Line {
  private:
    Coordinate *start;
    Coordinate *end;

  public:
    Line(Coordinate *start, Coordinate *end);
    Coordinate getStart();
    Coordinate getEnd();
};

#endif
