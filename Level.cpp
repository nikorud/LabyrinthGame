#include "Level.h"
#include "Maze.h"
#include "Difficulty.h"

Level::Level(int nr, Maze *maze, Difficulty difficulty) {
  this -> nr = nr;
  this -> maze = maze;
  this -> difficulty = difficulty;
}

int Level::getNr(){
    return nr;
}

Difficulty Level::getDifficulty() {
  return difficulty;
}
