#ifndef CANVAS_H
#define CANVAS_H

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
void printCanvas(int* usrIns, char** canvas);
void clearCanvas(int* usrIns, char** canvas);
char** createCanvas(int* usrIns);
void placePlayer(int coords[], char** canvas);

#endif