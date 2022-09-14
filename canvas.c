#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canvas.h"

void initArray(int* usrIns, char*** canvas)
{
    int playerCoords[2];
    playerCoords[0] = usrIns[PLAYER_ROW];
    playerCoords[1] = usrIns[PLAYER_COL];
    createCanvas(usrIns, canvas);
    clearCanvas(usrIns, canvas);   
    placeSym(playerCoords, canvas, PLAYER_SYM);
}

void placeSym(int* coords, char*** canvas, char sym)
{
    (*canvas)[coords[0] + 1][coords[1] + 1] = sym;
}

void clearCanvas(int* usrIns, char*** canvas)
{
    int i;
    int rows = usrIns[ROWS] + 2;
    int cols = usrIns[COLS] + 2;
    int goalCoords[2];

    for (i=0;i<rows;i++)
    {
        if(i == 0 || i == (rows - 1))
        {
            memset((*canvas)[i], BORDER_SYM, cols);
        }
        else
        {
            memset((*canvas)[i], BORDER_SYM, 1);
            memset((*canvas)[i] + 1, SPACE_SYM, cols - 2);
            memset((*canvas)[i] + cols - 1, BORDER_SYM, 1);
        }
    }
    goalCoords[0] = usrIns[GOAL_ROW];
    goalCoords[1] = usrIns[GOAL_COL];
    placeSym(goalCoords, canvas, GOAL_SYM);
}

void createCanvas(int* usrIns, char*** canvas)
{
    int i;
    int rows = usrIns[ROWS] + 2;
    int cols = usrIns[COLS] + 2;
    
    (*canvas) = (char**)malloc(rows * sizeof(char*));

    for (i=0;i<rows;i++)
    {
        (*canvas)[i] = (char*)malloc(cols * sizeof(char));
    }
}

void printCanvas(int* usrIns, char*** canvas)
{
    int rows = usrIns[ROWS] + 2;
    int cols = usrIns[COLS] + 2;
    int i, j;

    system("clear");

    for (i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%c", (*canvas)[i][j]);
        }
        printf("\n");
    }
    printf("Press w to go up\n");
    printf("Press s to go down\n");
    printf("Press a to go left\n");
    printf("Press d to go up\n");
}

void freeCanvas(int* usrIns, char*** canvas)
{
    int rows = usrIns[ROWS] + 2;
    int i;

    for (i=0;i<rows;i++)
    {
        free((*canvas)[i]);
        (*canvas)[i] = NULL;
    }
    free((*canvas));
    (*canvas) = NULL;
}

