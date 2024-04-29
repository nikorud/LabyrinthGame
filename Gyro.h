#ifndef GYRO_H
#define GYRO_H

class Gyro {
  public:
    static void initialize();
    static void getStartPositions();
    static void getPos();
    static void checkMovement();
};

#endif
