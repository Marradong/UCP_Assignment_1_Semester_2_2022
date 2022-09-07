#ifndef CANVAS_H
#define CANVAS_H

#define ROWS_INDEX 1
#define COLS_INDEX 2
#define PLAYER_ROW_INDEX 3
#define PLAYER_COL_INDEX 4
#define GOAL_ROW_INDEX 5
#define GOAL_COL_INDEX 6

void initArray(int userInputs[], char** canvas);
void printCanvas(int* userInputs, char** canvas);

#endif