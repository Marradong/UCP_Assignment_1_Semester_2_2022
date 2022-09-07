#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

void initArray(int userInputs[], char** canvas)
{
    int i, j;

    canvas = (char**)malloc(sizeof(char*)*(userInputs[ROWS_INDEX]));

    for (i=0;i<userInputs[ROWS_INDEX];i++)
    {
        for(j=0;i<userInputs[COLS_INDEX];j++)
        {
            if(i == 0 || i == (userInputs[ROWS_INDEX] - 1) || j == 0 || j == (userInputs[COLS_INDEX] - 1))
            {
                canvas[i][j] = '*';
            }
            else
            {
                canvas[i][j] = ' ';
            }
        }
    }

    canvas[userInputs[PLAYER_ROW_INDEX]][userInputs[PLAYER_COL_INDEX]] = 'P';

    canvas[userInputs[GOAL_ROW_INDEX]][userInputs[GOAL_COL_INDEX]] = 'G';
}

void printCanvas(int* userInputs, char** canvas)
{
    int rows = userInputs[ROWS_INDEX];
    int cols = userInputs[COLS_INDEX];
    int i, j;

    system("clear");

    for (i=0;i<rows;i++)
    {
        for(j=0;i<cols;j++)
        {
            printf(" %c", canvas[i][j]);
        }
        printf("\n");
    }
    printf("Press w to go up");
    printf("Press s to go down");
    printf("Press a to go left");
    printf("Press d to go up");
}

