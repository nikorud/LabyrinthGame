#include "Ball.h"
#include "Coordinate.h"
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

int Ball::x = 0;
int Ball::y = 0;
int Ball::ballSize = 9;

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


/*Ball::Ball() {
  c = new Coordinate(0,0);
}*/

/*void Ball::setCoordinate(Coordinate* c) {
  curr_c = c;
}

Coordinate Ball::getCoordinate() {
  return *curr_c;
}

void Ball::draw(){
  Display::drawBall(curr_c->getX(), curr_c->getY(), ballSize);
}

void Ball::moveBall(int dir) {
  switch(dir) {
    case L:
      Serial.println("Left");
      if(Level::validBallPos(curr_c->getX()-BALL_MOVEMENT, curr_c->getY())) {
        Serial.println("Moved Left");
        curr_c->setX(curr_c->getX()-BALL_MOVEMENT);
        
        draw();
        Level::refreshLvl();
      }
      break;
    case R:
      Serial.println("Ball: Right");
      if(Level::validBallPos(curr_c->getX()+BALL_MOVEMENT, curr_c->getY())) {
        Serial.println("Moved Right");
        curr_c->setX(curr_c->getX()+BALL_MOVEMENT);
        
        draw();
        Level::refreshLvl();
      }
      break;
    case U:
      Serial.println("Ball: Up");
      if(Level::validBallPos(curr_c->getX(), curr_c->getY()-BALL_MOVEMENT)) {
        Serial.println("Moved Up");
        curr_c->setY(curr_c->getY()+BALL_MOVEMENT);
        
        draw();
        Level::refreshLvl();
      }
      break;
    case D: 
      Serial.println("Ball: Down");
      if(Level::validBallPos(curr_c->getX(), curr_c->getY()+BALL_MOVEMENT)) {
        Serial.println("Moved Down");
        curr_c->setY(curr_c->getY()+BALL_MOVEMENT);
        
        draw();
        Level::refreshLvl();
      }
      break;
    default:
      // ... do nothing ...
      break;
  }
}*/
