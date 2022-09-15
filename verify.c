#include <stdio.h>
#include <stdlib.h>
#include "verify.h"
#include "gameplay.h"
#include "canvas.h"
#include "toolbox.h"

int vArgs(int* numArgs)
{
    int verified = TRUE;
    /* Check correct number of command line arguments else end program */
    if((*numArgs) != 7)
    {
        verified = FALSE;
        system("clear");
        printf("Invalid number of arguements please enter in the format below\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
    }
    return verified;
}

int vMapSize(int* usrIns)
{
    int verified = TRUE;
    /* Check within bounds else end program */
    if((usrIns[ROWS] < MAP_SIZE_MINIMUM) || (usrIns[COLS] < MAP_SIZE_MINIMUM))
    {
        verified = FALSE;
        system("clear");
        printf("Invalid Map Size! Please ensure map size is greater than or equal to 5\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
    }
    return verified;
}

int vStartLocation(int* usrIns)
{
    int verified = TRUE;

    /* Check player starts in map and not equal to the goal*/
    int playerChecks = (usrIns[PLAYER_ROW] >= usrIns[ROWS]) || (usrIns[PLAYER_ROW] < 0) 
        || (usrIns[PLAYER_COL] >= usrIns[COLS]) || (usrIns[PLAYER_COL] < 0 
        || (usrIns[PLAYER_ROW] == usrIns[GOAL_ROW] && usrIns[PLAYER_COL] == usrIns[GOAL_COL]));

    /* Check goal starts in map and not equal to the player*/
    int goalChecks = (usrIns[GOAL_ROW] >= usrIns[ROWS]) || (usrIns[GOAL_ROW] < 0) 
        || (usrIns[GOAL_ROW] >= usrIns[COLS]) || (usrIns[GOAL_ROW] < 0);

    if(playerChecks || goalChecks)
    {
        verified = FALSE;
        system("clear");
        printf("Invalid Location! Ensure locations are not equal and reside within the map\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
    }
    return verified;
}

int vMove(char* move)
{
    int verified = FALSE;
    /*Check user enters a correct move key*/
    if((*move) == UP_KEY || (*move) == DOWN_KEY || (*move) == LEFT_KEY || (*move) == RIGHT_KEY)
    {
        verified = TRUE;
    }
    return verified;
}

int vFloor(int* usrIns, int* coords, char*** canvas, int checkGoal)
{
    int i, j;
    int verified = TRUE;
    for (i=0;i<=usrIns[ROWS];i++)
    {
        for(j=0;j<=usrIns[COLS];j++)
        {
            /*Check if there is an collapsed floor at the given coordinates*/
            if((*canvas)[i][j] == FLOOR_SYM && i == (coords[0]+1) && j == (coords[1]+1))
            {
                verified = FALSE;
            }
            /*Check if there is a player or goal at the given coordinates*/
            if(checkGoal && ((*canvas)[i][j] == GOAL_SYM || (*canvas)[i][j] == PLAYER_SYM) 
                && i == (coords[0]+1) && j == (coords[1]+1))
            {
                verified = FALSE;
            }
        }
    }
    return verified;
}

int vWin(int* usrIns, int* playerCoords)
{
    int won = FALSE;
    /*Check if the player coordinates are equal to the goal*/
    if(playerCoords[0] == usrIns[GOAL_ROW] && playerCoords[1] == usrIns[GOAL_COL])
    {
        won = TRUE;
    }
    return won;
}

int vLose(char*** canvas, int* coords, int* usrIns)
{
    int lose = FALSE;

    int sRow = coords[0] + 1;
    int sCol = coords[1] + 1;
    int chkUp, chkDown, chkLeft, chkRight;
    
    #ifndef BORDERLESS
        chkUp = ((*canvas)[sRow-1][sCol] == FLOOR_SYM) || ((*canvas)[sRow-1][sCol] == BORDER_SYM);
        chkDown = ((*canvas)[sRow+1][sCol] == FLOOR_SYM) || ((*canvas)[sRow+1][sCol] == BORDER_SYM);
        chkLeft = ((*canvas)[sRow][sCol-1] == FLOOR_SYM) || ((*canvas)[sRow][sCol-1] == BORDER_SYM);
        chkRight = ((*canvas)[sRow][sCol+1] == FLOOR_SYM) || ((*canvas)[sRow][sCol+1] == BORDER_SYM);
        if(chkLeft && chkRight && chkUp && chkDown)
        {
            lose = TRUE;
        }
    #else 
        int maxRow = usrIns[ROWS];
        int maxCol = usrIns[COLS]; 
        chkUp = ((*canvas)[sRow-1][sCol] == FLOOR_SYM) || (((*canvas)[sRow-1][sCol] == BORDER_SYM) && ((*canvas)[maxRow][sCol] == FLOOR_SYM));
        chkDown = ((*canvas)[sRow+1][sCol] == FLOOR_SYM) || (((*canvas)[sRow+1][sCol] == BORDER_SYM) && ((*canvas)[1][sCol] == FLOOR_SYM));
        chkLeft = ((*canvas)[sRow][sCol-1] == FLOOR_SYM) || (((*canvas)[sRow][sCol-1] == BORDER_SYM) && ((*canvas)[sRow][maxCol] == FLOOR_SYM));
        chkRight = ((*canvas)[sRow][sCol+1] == FLOOR_SYM) || (((*canvas)[sRow][sCol+1] == BORDER_SYM) && ((*canvas)[sRow][1] == FLOOR_SYM));
        if(chkLeft && chkRight && chkUp && chkDown)
        {
            lose = TRUE;
        }
    #endif

    return lose;
}