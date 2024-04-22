#ifndef MAZE_H
#define MAZE_H

#include "Wall.h"
#include "Hole.h"
#include <LinkedList.h>

class Maze {
  private:
    LinkedList<Wall*> walls = LinkedList<Wall*>();
    LinkedList<Hole*> holes = LinkedList<Hole*>();

  public:
    Maze();
    void draw();
    bool addWall(Wall *w);
    bool addHole(Hole *h);
};

#endif
