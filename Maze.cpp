#include "Maze.h"
#include "Display.h"
#include "Coordinate.h"
#include "Line.h"
#include "Wall.h"
#include "Line.h"

#include <LinkedList.h>

Maze::Maze() {
  addWall(new Wall(new Line(new Coordinate(0, 0), new Coordinate(Display::getSizeX(), 0)))); //top
  addWall(new Wall(new Line(new Coordinate(0, 0), new Coordinate(0, Display::getSizeY())))); //left
  addWall(new Wall(new Line(new Coordinate(Display::getSizeX(), 0), new Coordinate(Display::getSizeX(), Display::getSizeY())))); //right
  addWall(new Wall(new Line(new Coordinate(0, Display::getSizeY()), new Coordinate(Display::getSizeX(), Display::getSizeY())))); //bottom
}

bool Maze::addWall(Wall *w) {
    walls.add(w);
}

bool Maze::addHole(Hole *h) {
    holes.add(h);
}

void Maze::draw() {
  //TODO

  //draw walls
  int current = 0;
	Wall *wall;
	for(int i = 0; i < walls.size(); i++){
		// Get wall from list
		wall = walls.get(i);
    wall->draw();
	}

 Hole *hole;
 for(int i = 0; i < holes.size(); i++){
    // Get hole from list
    hole = holes.get(i);
    hole->draw();
  }
}
