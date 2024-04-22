/**
 * Micro:Bit - Project: Labyrinth Game 
 * Autors: Niko RUDOLF, Tobias WÖSENBÖCK
 * Date: 22.04.2024
 * Hardware: 
    * Arduino Mega 2560
    * Elegoo 3.5" TFT Touchscreen Shield (320x480 px)
    * GY-521 Sensor (Gyro)
*/

#include "Display.h"
#include "Gyro.h"
#include "Coordinate.h"
#include "Line.h"
#include "Wall.h"
#include "Hole.h"
#include "Maze.h"
#include "Level.h"

int currLvl;

void setup(void) {  
  Serial.begin(9600);
  
  Gyro::initialize();
  Display::initialize();
  //Display::draw();

  pinMode(13, OUTPUT);

  currLvl = 1;
  leadLevel(currLvl);
}

void loop()
{
  Display::getTouchInput();
  Gyro::getPos();
}

void leadLevel(int lvl) {
  switch(lvl) {
    case 1: 
      Maze *m1 = new Maze();
      
      m1->addWall(new Wall(new Line(new Coordinate(0, 50), new Coordinate(Display::getSizeX(), 50))));
      //m1->addWall(new Wall(new Line(new Coordinate(50, 0), new Coordinate(50, Display::getSizeY()))));
      m1->addHole(new Hole(new Coordinate(50, 50)));
      m1->addHole(new Hole(new Coordinate(150, 150)));
  
      Level *l1 = new Level(1, m1, EASY);
      l1->load();
      break;
      
    default:
      /*Line *line = new Line(new Coordinate(0, 0), new Coordinate(120, 0));
      Display::drawLine(line);
      Display::drawHole(new Coordinate(50, 50));
      Display::drawBall(new Coordinate(50, 50));*/
      break;
  }
}
