#ifndef ENUM_H
#define ENUM_H

enum Difficulty {
  EASY = 0,
  MEDIUM = 1,
  HARD = 2
};

const char* getName(Difficulty difficulty);

#endif
