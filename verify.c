#include <stdio.h>
#include <stdlib.h>
#include "verify.h"

int vMapSize(int row, int col)
{
    int verified = 1;
    /* Check within bounds else end program */
    if((row <= MAP_MINIMUM) || (col <= MAP_MINIMUM))
    {
        verified = 0;
        system("clear");
        printf("Invalid Map Size! Please ensure both map rows and columns are greater than 5\n");
        /* TODO : End Program */
    }
    return verified;
}

int vArgs(int numArgs)
{
    int verified = 1;
    if(numArgs != 7)
    {
        verified = 0;
        system("clear");
        printf("Invalid number of arguements please enter in the format below\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
    }
    return verified;
}

int vStartLocation(int coordX, int coordY, int maxX, int maxY)
{
    int verified = 1;
    if((coordX > maxX) || (coordX < 0) || (coordY > maxY) || (coordY < 0))
    {
        verified = 0;
        system("clear");
        printf("Invalid Location! Please ensure parameters are within the map\n");
        /* TODO : End Program */
    }
    return verified;
}

int vMove(char* move)
{
    int verified = 0;
    if((*move) == 'w')
    {
        verified = 1;
    }
    else if((*move) == 's')
    {
        verified = 1;
    }
    else if((*move) == 'a')
    {
        verified = 1;
    }
    else if((*move) == 'd')
    {
        verified = 1;
    }
    return verified;
}