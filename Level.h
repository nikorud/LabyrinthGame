#include "Difficulty.h"
#include "Maze.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level {
  private:
    int nr;
    Maze *maze;
    Difficulty difficulty;

  public:
    Level(int nr, Maze *maze, Difficulty difficulty);
    int getNr();
    Difficulty getDifficulty();
};

#endif
