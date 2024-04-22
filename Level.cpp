#include "Level.h"
#include "Maze.h"
#include "Difficulty.h"
#include "Display.h"

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Level::Level(int nr, Maze *maze, Difficulty difficulty) {
  this -> nr = nr;
  this -> maze = maze;
  this -> difficulty = difficulty;
  nAttempts = 0;
  finished = false;
}

int Level::getNr(){
    return nr;
}

Difficulty Level::getDifficulty() {
  return difficulty;
}

int Level::getNAttempts() {
  return nAttempts;
}

bool Level::isFinished(){
    return finished;
}

void Level::load() {
  nAttempts++;
  drawInfoBar();
  maze->draw();
}

void Level::drawInfoBar() {
  // this area must be substracted from maze!
  Display::fillRect(0, 0, Display::getSizeX(), 15, BLACK);
  Display::printText(5, 5, "Level " + String(nr) + " (" + String(getName(difficulty)) + "), Attempts: " + String(nAttempts));
}
