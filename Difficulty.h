#ifndef ENUM_H
#define ENUM_H

enum Difficulty {
  EASY = 1,
  MEDIUM = 2,
  HARD = 3
};

const char* getName(Difficulty difficulty);

#endif
