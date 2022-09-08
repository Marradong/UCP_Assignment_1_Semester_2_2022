#include <stdio.h>
#include <stdlib.h>
#include "verify.h"
#include "gameplay.h"
#include "canvas.h"
#include "toolbox.h"

int vArgs(int* numArgs)
{
    int verified = 1;
    if((*numArgs) != 7)
    {
        verified = 0;
        system("clear");
        printf("Invalid number of arguements please enter in the format below\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
    }
    return verified;
}

int vMapSize(int* usrIns)
{
    int verified = 1;
    /* Check within bounds else end program */
    if((usrIns[ROWS] < MAP_MINIMUM) || (usrIns[COLS] < MAP_MINIMUM))
    {
        verified = 0;
        system("clear");
        printf("Invalid Map Size! Please ensure map size is greater than or equal to 5\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
        /* TODO : End Program */
    }
    return verified;
}

int vStartLocation(int* usrIns)
{
    int verified = 1;

    int playerChecks = (usrIns[PLAYER_ROW] >= usrIns[ROWS]) || (usrIns[PLAYER_ROW] < 0) 
        || (usrIns[PLAYER_COL] >= usrIns[COLS]) || (usrIns[PLAYER_COL] < 0 
        || (usrIns[PLAYER_ROW] == usrIns[GOAL_ROW] && usrIns[PLAYER_COL] == usrIns[GOAL_COL]));

    int goalChecks = (usrIns[GOAL_ROW] >= usrIns[ROWS]) || (usrIns[GOAL_ROW] < 0) 
        || (usrIns[GOAL_ROW] >= usrIns[COLS]) || (usrIns[GOAL_ROW] < 0);

    if(playerChecks || goalChecks)
    {
        verified = 0;
        system("clear");
        printf("Invalid Location! Ensure locations are not equal and reside within the map\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
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

int vFloor(int* usrIns, int* coords, char** canvas, int checkGoal)
{
    int i, j;
    int verified = 1;
    for (i=0;i<=usrIns[ROWS];i++)
    {
        for(j=0;j<=usrIns[COLS];j++)
        {
            if(canvas[i][j] == FLOOR_SYM && i == (coords[0]+1) && j == (coords[1]+1))
            {
                verified = 0;
            }
            
            if(checkGoal && (canvas[i][j] == GOAL_SYM || canvas[i][j] == PLAYER_SYM) 
                && i == (coords[0]+1) && j == (coords[1]+1))
            {
                verified = 0;
            }
        }
    }
    return verified;
}

int vWin(int* usrIns, int* playerCoords)
{
    int won = 0;
    if(playerCoords[0] == usrIns[GOAL_ROW] && playerCoords[1] == usrIns[GOAL_COL])
    {
        won = 1;
    }
    return won;
}

int vLose(char** canvas, int* coords)
{
    int lose = 0;
    if(((canvas[coords[0]][coords[1]+1] == FLOOR_SYM) || (canvas[coords[0]][coords[1] + 1] == BORDER_SYM)) 
        && ((canvas[coords[0]+2][coords[1]+1] == FLOOR_SYM) || (canvas[coords[0] + 2][coords[1] + 1] == BORDER_SYM))
        && ((canvas[coords[0]+1][coords[1]] == FLOOR_SYM) || (canvas[coords[0] + 1][coords[1]] == BORDER_SYM))
        && ((canvas[coords[0]+1][coords[1]+2] == FLOOR_SYM) || (canvas[coords[0] + 1][coords[1] + 2] == BORDER_SYM)))
    {
        lose = 1;
    }
    return lose;
}