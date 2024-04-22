#include "Difficulty.h"

const char* DifficultyNames[] = {"Easy", "Medium", "Hard"};

const char* getName(Difficulty difficulty) {
  return DifficultyNames[difficulty];
}
