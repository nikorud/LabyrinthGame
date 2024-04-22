/**
 * Micro:Bit - Project: Labyrinth Game 
 * Autors: Niko RUDOLF, Tobias WÖSENBÖCK
 * Date: 22.04.2024
 * Hardware: 
    * Arduino Mega 2560
    * Elegoo 3.5" TFT Touchscreen Shield
    * GY-521 Sensor (Gyro)
*/

#include "Display.h"
#include "Gyro.h"
#include "Coordinate.h"
#include "Line.h"
#include "Wall.h"
#include "Hole.h"
#include "Maze.h"

#define HOLE_SIZE 10
#define BALL_SIZE 8
#define WALL_SIZE 2

void setup(void) {  
  Serial.begin(9600);
  
  Gyro::initialize();
  Display::initialize();
  Display::draw();

  pinMode(13, OUTPUT);
}

void loop()
{
  Display::getTouchInput();
  Gyro::getPos();
}
