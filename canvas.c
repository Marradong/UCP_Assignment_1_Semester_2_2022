#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canvas.h"

void initArray(int* usrIns, char*** canvas)
{
    *canvas = createCanvas(usrIns);
    clearCanvas(usrIns, *canvas);

    (*canvas)[usrIns[PLAYER_ROW] + 1][usrIns[PLAYER_COL] + 1] = PLAYER_SYM;
    (*canvas)[usrIns[GOAL_ROW] + 1][usrIns[GOAL_COL] + 1] = GOAL_SYM;
}


void clearCanvas(int* usrIns, char** canvas)
{
    int i;
    int rows = usrIns[ROWS] + 2;
    int cols = usrIns[COLS] + 2;

    for (i=0;i<rows;i++)
    {
        
        if(i == 0 || i == (rows - 1))
        {
            memset(canvas[i], BORDER_SYM, cols);
        }
        else
        {
            memset(canvas[i], BORDER_SYM, 1);
            memset(canvas[i] + 1, SPACE_SYM, cols - 2);
            memset(canvas[i] + cols - 1, BORDER_SYM, 1);
        }
    }
}

char** createCanvas(int* usrIns)
{
    int i;
    int rows = usrIns[ROWS] + 2;
    int cols = usrIns[COLS] + 2;
    
    char** canvas = (char**)malloc(rows * sizeof(char*));

    for (i=0;i<rows;i++)
    {
        canvas[i] = (char*)malloc(cols * sizeof(char));
    }
    return canvas;
}

void printCanvas(int* usrIns, char** canvas)
{
    int rows = usrIns[ROWS] + 2;
    int cols = usrIns[COLS] + 2;
    int i, j;

    system("clear");

    for (i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
    printf("Press w to go up\n");
    printf("Press s to go down\n");
    printf("Press a to go left\n");
    printf("Press d to go up\n");
}

