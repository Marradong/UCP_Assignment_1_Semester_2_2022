#ifndef CANVAS_H
#define CANVAS_H

#define ROWS_INDEX 0
#define COLS_INDEX 1
#define PLAYER_ROW_INDEX 2
#define PLAYER_COL_INDEX 3
#define GOAL_ROW_INDEX 4
#define GOAL_COL_INDEX 5

#define BORDER_SYM '*'
#define SPACE_SYM ' '
#define PLAYER_SYM 'P'
#define GOAL_SYM 'G'
#define FLOOR_SYM 'X'

void initArray(int* userInputs, char*** canvas);
void printCanvas(int* userInputs, char** canvas);
void clearCanvas(int* userInputs, char** canvas);
char** createCanvas(int* userInputs);

#endif