#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
  private:
    int x;
    int y;

  public:
    Coordinate(int x, int y);
    int getX();
    int getY();
    bool setX(int x);
    bool setY(int y);
};

#endif