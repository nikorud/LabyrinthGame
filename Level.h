#include "Difficulty.h"
#include "Maze.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level {
  private:
    int nr;
    bool alive;
    bool solved;
    //char** maze;
    Difficulty difficulty;
    int nAttempts;
    bool finished;
    void drawInfoBar();
    void drawMaze(int lvl);

  public:
    static int curr_lvl;
    static Level *lvl;
    Level(int nr);
    int getNr();
    Difficulty getDifficulty();    
    int getNAttempts();
    bool isFinished();
    void load();
    static void refreshLvl();
    bool validBallPos(int x, int y);
    bool isAlive();
    bool isSolved();
    static bool gameFinished();
    void loadNextLvl();
};

#endif
