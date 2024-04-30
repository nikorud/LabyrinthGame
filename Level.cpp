#include "Level.h"
#include "Difficulty.h"
#include "Display.h"
#include "Ball.h"

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


#define DISPLAY_SIZE_X 480
#define DISPLAY_SIZE_Y 320

#define MAZE_SIZE_X 48
#define MAZE_SIZE_Y 32

int Level::curr_lvl = 1;
Level* Level::lvl = new Level(1);
int nLevels = 4;

char lvl1[MAZE_SIZE_Y][MAZE_SIZE_X] = {
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','s','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','x','x','x','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','h','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','x','x','x','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','e','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}
 };
 
char lvl2[MAZE_SIZE_Y][MAZE_SIZE_X] = {
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','s','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','x','x','x','x','x','x','x','x','x','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','h','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','h','x','x','x','x','x','x','x','o','x','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','x','x','o','o','o','o','o','x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','x','x','o','x','x','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','h','o','h','h','h','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','h','h','h','o','h','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','o','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','o','e','o','o','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','h','h','h','h','h','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','x','x','x','x','x','x','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}
 };
 
 char lvl3[MAZE_SIZE_Y][MAZE_SIZE_X] = {
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','s','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','x','x','x','x','x','x','x','x','x','x','x','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','h','x','o','o','h','o','o','o','o','o','o','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','o','o','o','h','o','o','h','o','o','o','o','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','h','x','o','o','o','h','o','o','o','o','o','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','x','x','x','x','x','x','x','x','x','x','o','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','o','x','o','o','o','o','o','h','h','h','h','o','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','h','x','o','o','o','o','o','h','o','o','o','o','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','x','x','x','o','o','o','o','o','h','o','h','h','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','o','e','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','h','h','h','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}
 };
 
 char lvl4[MAZE_SIZE_Y][MAZE_SIZE_X] = {
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','h','h','h','h','h','h','h','h','h','h','h','h','h','h','h','h','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','s','h','h','h','o','o','h','o','h','o','o','h','o','o','o','h','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','o','h','o','o','o','o','h','o','h','h','h','h','o','h','e','h','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','o','h','o','h','h','o','h','o','o','o','h','h','o','o','h','h','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','o','h','o','h','h','o','h','o','h','o','h','h','h','o','h','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','o','o','o','h','h','o','o','o','h','o','o','o','o','o','h','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','h','h','h','h','h','h','h','h','h','h','h','h','h','h','h','h','h','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','x'},
        {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}
 };

char* levels[] = { *lvl1, *lvl2, *lvl3, *lvl4 };  // Array von Zeigern auf die Level

Level::Level(int nr) {
  this -> nr = nr;
  alive = true;
  solved = false;
  difficulty = EASY;
  nAttempts = 0;
}

int Level::getNr(){
    return nr;
}

Difficulty Level::getDifficulty() {
  return difficulty;
}

int Level::getNAttempts() {
  return nAttempts;
}

void drawMaze(int lvl) {
  
}

void Level::load() {
  Display::fillScreen(WHITE);
  alive = true;
  solved = false;

  // ... draw lvl from array ...
  int size_multiplier = DISPLAY_SIZE_X/MAZE_SIZE_X;
  
  for(int y = 0; y < MAZE_SIZE_Y; y++) {
    for(int x = 0; x < MAZE_SIZE_X; x++) {
      //switch(lvl1[y][x]){
      switch(levels[(Level::curr_lvl)-1][y * MAZE_SIZE_X + x]) {
        case 'x':
          // wall
          Display::drawWall(x*size_multiplier, y*size_multiplier, size_multiplier);
          break;
        case 's':
          // starting point
          Display::drawBall(x*size_multiplier, y*size_multiplier, size_multiplier-1);
          Ball::setCoordinate(x*size_multiplier, y*size_multiplier);
          break;
        case 'o':
          // path -> nothing to draw
          break;
        case 'h':
          // hole
          Display::drawHole(x*size_multiplier, y*size_multiplier, size_multiplier);
          break;
        case 'e':
          // hole
          Display::drawExit(x*size_multiplier, y*size_multiplier, size_multiplier);
          break;
        default:
          // unvalid 
          break;
      }
    }
  }

  drawInfoBar();
  
  nAttempts++;
}

void Level::refreshLvl() {
  // ... redraw all compontents that could be covered by ball ...
  int size_multiplier = DISPLAY_SIZE_X/MAZE_SIZE_X;
  
  for(int y = 0; y < MAZE_SIZE_Y; y++) {
    for(int x = 0; x < MAZE_SIZE_X; x++) {
      //switch(lvl1[y][x]){
      switch(levels[(Level::curr_lvl)-1][y * MAZE_SIZE_X + x]) {
        case 'o':
          // path -> nothing to draw
          break;
        case 'h':
          // hole
          Display::drawHole(x*size_multiplier, y*size_multiplier, size_multiplier);
          break;
        case 'e':
          // exit
          Display::drawExit(x*size_multiplier, y*size_multiplier, size_multiplier);
          break;
        default:
          // unvalid 
          break;
      }
    }
  }
}

void Level::drawInfoBar() {
  // this area must be substracted from maze!
  Display::fillRect(0, 0, Display::getSizeX(), 15, BLACK);
  Display::printText(5, 5, ("Level " + String(nr) + " (" + String(getName(difficulty)) + "), Attempts: " + String(nAttempts)));
}

boolean Level::validBallPos(int x, int y) {
  int ball_size = Ball::getSize();
  int size_multiplier = DISPLAY_SIZE_X/MAZE_SIZE_X;

  // ... round x up if necessary ...
  if (x % size_multiplier != 0) {
    x = (x / size_multiplier) + 1;
  } else {
    x/=size_multiplier;
  }

  // ... round y up if necessary ...
  if (y % size_multiplier != 0) {
    y = (y / size_multiplier) + 1;
  } else {
    y/=size_multiplier;
  }

  if(x >= 0 && x <= DISPLAY_SIZE_X && y >= 0 && y <= DISPLAY_SIZE_Y) {
    // ... ball can be moved to all places that are not a wall ...

    if(levels[(Level::curr_lvl)-1][y * MAZE_SIZE_X + x] == 'h') {
      alive = false;
    } else if(levels[(Level::curr_lvl)-1][y * MAZE_SIZE_X + x] == 'e') {
      solved = true;
    } 
    
    return levels[(Level::curr_lvl)-1][y * MAZE_SIZE_X + x] != 'x';
  }
  return false;
}

bool Level::isAlive() {
  return alive;
}

bool Level::isSolved() {
  return solved;
}

bool Level::gameFinished() {
  if(curr_lvl <= nLevels) {
    return false;
  }
  return true;
}

void Level::loadNextLvl() {
  if(!gameFinished()) {
    // ... there is still a level to play ...
    curr_lvl++;
    lvl = new Level(curr_lvl);
    lvl->load();
  }  
}
