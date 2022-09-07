#include <stdio.h>
#include <stdlib.h>
#include "verify.h"
#include "gameplay.h"
#include "canvas.h"

int vMapSize(int usrIns[])
{
    int verified = 1;
    /* Check within bounds else end program */
    if((usrIns[ROWS] <= MAP_MINIMUM) || (usrIns[COLS] <= MAP_MINIMUM))
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

int vStartLocation(int usrIns[])
{
    int verified = 1;

    int playerChecks = (usrIns[PLAYER_ROW] > usrIns[ROWS]) || (usrIns[PLAYER_ROW] < 0) 
        || (usrIns[PLAYER_COL] > usrIns[COLS]) || (usrIns[PLAYER_COL] < 0 
        || (usrIns[PLAYER_ROW] != usrIns[GOAL_ROW] && usrIns[PLAYER_COL] != usrIns[GOAL_COL]));

    int goalChecks = (usrIns[GOAL_ROW] > usrIns[ROWS]) || (usrIns[GOAL_ROW] < 0) 
        || (usrIns[GOAL_ROW] > usrIns[COLS]) || (usrIns[GOAL_ROW] < 0);

    if(playerChecks || goalChecks)
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
    if((*move) == UP_KEY || (*move) == DOWN_KEY || (*move) == LEFT_KEY || (*move) == RIGHT_KEY)
    {
        verified = 1;
    }
    return verified;
}