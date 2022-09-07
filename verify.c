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

int vStartLocation(int coordx, int coordy, int max)
{
    int verified = 1;
    if((coordx > max) || (coordx < 0))
    {
        verified = 0;
        system("clear");
        printf("Invalid Location! Please ensure parameters are within the map\n");
        /* TODO : End Program */
    }
    return verified;
}