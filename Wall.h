#ifndef WALL_H
#define WALL_H

#include "Line.h"

class Wall {
  private:
    Line *l;

  public:
    Wall(Line *l);
    void draw();
};

#endif
