#include "Ball.h"
#include "Display.h"
#include "Level.h"

#define L 0
#define R 1
#define U 2
#define D 3
#define LU 4
#define LD 5
#define RU 6
#define RD 7

#define BALL_MOVEMENT 10

int Ball::ballSize = 9;
int Ball::x = 0;
int Ball::y = 0;

int Ball::getX() {
  return Ball::x;
}

int Ball::getY() {
  return Ball::y;
}

int Ball::getSize() {
  return Ball::ballSize;
}

bool Ball::setX(int newX) {
  if(newX < Display::getSizeX()) {
    Ball::x = newX;
    return true;
  }
  return false;
}

bool Ball::setY(int newY) {
  if(newY < Display::getSizeY()) {
    Ball::y = newY;
    return true;
  }
  return false;
}

bool Ball::setCoordinate(int newX, int newY) {
  setX(newX);
  setY(newY);
}

void Ball::draw(){
  Display::drawBall(Ball::x, Ball::y, Ball::ballSize);
}

void Ball::moveBall(int dir) {
  switch(dir) {
    case L:
    case LU:
    case LD:
      if(dir == LU && Level::lvl->validBallPos(Ball::x-BALL_MOVEMENT, Ball::y-BALL_MOVEMENT)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x-BALL_MOVEMENT, Ball::y-BALL_MOVEMENT, Ball::ballSize);
        setX(Ball::x-BALL_MOVEMENT);
        setY(Ball::y-BALL_MOVEMENT);
      } else if(dir == LD && Level::lvl->validBallPos(Ball::x-BALL_MOVEMENT, Ball::y+BALL_MOVEMENT)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x-BALL_MOVEMENT, Ball::y+BALL_MOVEMENT, Ball::ballSize);
        setX(Ball::x-BALL_MOVEMENT);
        setY(Ball::y+BALL_MOVEMENT);
      } else if(Level::lvl->validBallPos(Ball::x-BALL_MOVEMENT, Ball::y)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x-BALL_MOVEMENT, Ball::y, Ball::ballSize);
        setX(Ball::x-BALL_MOVEMENT);
      }
      break;
    case R:
    case RU:
    case RD:
      if(dir == RU && Level::lvl->validBallPos(Ball::x+BALL_MOVEMENT, Ball::y-BALL_MOVEMENT)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x+BALL_MOVEMENT, Ball::y-BALL_MOVEMENT, Ball::ballSize);
        setX(Ball::x+BALL_MOVEMENT);
        setY(Ball::y-BALL_MOVEMENT);
      } else if(dir == RD && Level::lvl->validBallPos(Ball::x+BALL_MOVEMENT, Ball::y+BALL_MOVEMENT)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x+BALL_MOVEMENT, Ball::y+BALL_MOVEMENT, Ball::ballSize);
        setX(Ball::x+BALL_MOVEMENT);
        setY(Ball::y+BALL_MOVEMENT);
      } else if(Level::lvl->validBallPos(Ball::x+BALL_MOVEMENT, Ball::y)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x+BALL_MOVEMENT, Ball::y, Ball::ballSize);
        setX(Ball::x+BALL_MOVEMENT);
      }
      break;
    case U:
      if(Level::lvl->validBallPos(Ball::x, Ball::y-BALL_MOVEMENT)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x, Ball::y-BALL_MOVEMENT, Ball::ballSize);
        setY(Ball::y-BALL_MOVEMENT);
      }
      break;
    case D: 
      if(Level::lvl->validBallPos(Ball::x, Ball::y+BALL_MOVEMENT)) {
        Display::drawBall(Ball::x, Ball::y, Ball::x, Ball::y+BALL_MOVEMENT, Ball::ballSize);
        setY(Ball::y+BALL_MOVEMENT);
      }
      break;
    default:
      // ... do nothing ...
      break;
  }
}