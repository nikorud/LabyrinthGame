#include "Coordinate.h"

#ifndef BALL_H
#define BALL_H

class Ball {
  private:
    static int ballSize;
    //static Coordinate* curr_c;
    static int x;
    static int y;
    static bool setX(int x);
    static bool setY(int y);

  public:
    //static Ball();
    /*static void setCoordinate(Coordinate *c);
    static Coordinate getCoordinate();*/
    static int getX();
    static int getY();
    static int getSize();
    static bool setCoordinate(int x, int y);
    static void draw();
    static void moveBall(int dir);
};

#endif
