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
#include "Maze.h"
#include "Level.h"

void setup(void) {  
  Serial.begin(9600);
  
  Gyro::initialize();
  Display::initialize();
  pinMode(13, OUTPUT);

  Display::startScreen();
  Gyro::getStartPositions();
  
  Level::lvl->load();
}

void loop()
{
  if(Level::gameFinished()) {
      Display::endScreen();
  } else if(Level::lvl->isAlive() && !(Level::lvl->isSolved()) ) {
    Display::getTouchInput();
    Gyro::checkMovement();
  } else if( !(Level::lvl->isAlive()) ) {
    Display::retryScreen();
  } else if(Level::lvl->isSolved()) {
      Display::nextLvlScreen();
  } 
}
