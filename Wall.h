#ifndef WALL_H
#define WALL_H

#include "Line.h"

class Wall {
  private:
    Line *l;
    int thickness;

  public:
    Wall(Line *l);
    Line getLine();
    int getThickness();
    void draw();
};

#endif
