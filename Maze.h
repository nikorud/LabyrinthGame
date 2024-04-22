#ifndef MAZE_H
#define MAZE_H

#include "Wall.h"
#include "Hole.h"
#include <LinkedList.h>

class Maze {
  private:
    //LinkedList<Wall> walls = LinkedList<Wall>();
    //LinkedList<Hole> holes = LinkedList<Hole>();
    /*Wall *walls[100];
    Hole *holes[30];*/

  public:
    //Maze(Wall *walls[100] , Hole *holes[30]);
    Maze();//(LinkedList<Wall> walls, LinkedList<Hole> holes);
    void draw();
};

#endif
