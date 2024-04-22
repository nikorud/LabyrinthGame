#include "Difficulty.h"
#include "Maze.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level {
  private:
    int nr;
    Maze *maze;
    Difficulty difficulty;
    int nAttempts;
    bool finished;
    void drawInfoBar();

  public:
    Level(int nr, Maze *maze, Difficulty difficulty);
    int getNr();
    Difficulty getDifficulty();    
    int getNAttempts();
    bool isFinished();
    void load();
};

#endif
