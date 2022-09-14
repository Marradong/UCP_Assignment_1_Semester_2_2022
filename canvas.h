#ifndef CANVAS_H
#define CANVAS_H

#define MAP_MINIMUM 5

#define ROWS 0
#define COLS 1
#define PLAYER_ROW 2
#define PLAYER_COL 3
#define GOAL_ROW 4
#define GOAL_COL 5

#define BORDER_SYM '*'
#define SPACE_SYM ' '
#define PLAYER_SYM 'P'
#define GOAL_SYM 'G'
#define FLOOR_SYM 'X'

void initArray(int* usrIns, char*** canvas);
void printCanvas(int* usrIns, char*** canvas);
void clearCanvas(int* usrIns, char*** canvas);
void createCanvas(int* usrIns, char*** canvas);
void placeSym(int* coords, char*** canvas, char sym);
void freeCanvas(int* usrIns, char*** canvas);

#endif