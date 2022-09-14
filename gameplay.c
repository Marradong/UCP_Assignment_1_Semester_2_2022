#include <stdio.h>
#include "gameplay.h"
#include "terminal.h"
#include "verify.h"
#include "canvas.h"
#include "random.h"
#include "toolbox.h"

char readMove(void)
{
    char move;
    disableBuffer();

    while(!vMove(&move))
    {
        scanf(" %c", &move);
    }  

    enableBuffer();
    return move;
}

void collapseFloor(int* usrIns, char*** canvas)
{
    int clpseCoords[2];
    int check = 0;
    while(!check)
    {
        clpseCoords[0] = random(0, (usrIns[ROWS] - 1));
        clpseCoords[1] = random(0, (usrIns[COLS] - 1));
        check = vFloor(usrIns, clpseCoords, canvas, 1);
    }
    placeSym(clpseCoords, canvas, FLOOR_SYM);
}

void movePlayer(char*** canvas, char* usrKey, int* playerCoords, int* usrIns)
{
    int tempCoords[2];
    tempCoords[0] = playerCoords[0];
    tempCoords[1] = playerCoords[1];

    if((*usrKey) == UP_KEY)
    {
        playerCoords[0] = playerCoords[0] - 1;
    }
    else if((*usrKey) == DOWN_KEY)
    {
        playerCoords[0] = playerCoords[0] + 1;
    }
    else if((*usrKey) == LEFT_KEY)
    {
        playerCoords[1] = playerCoords[1] - 1;
    }
    else if((*usrKey) == RIGHT_KEY)
    {
        playerCoords[1] = playerCoords[1] + 1;
    }

    if((playerCoords[0] > usrIns[ROWS] - 1) || (playerCoords[0] < 0) 
        || (playerCoords[1] > usrIns[COLS] - 1) || (playerCoords[1] < 0) 
        || !vFloor(usrIns, playerCoords, canvas, 0)) 
    {
        playerCoords[0] = tempCoords[0];
        playerCoords[1] = tempCoords[1];
    }
    else
    {
        /*remove last player*/
        placeSym(tempCoords, canvas, SPACE_SYM);
        placeSym(playerCoords, canvas, PLAYER_SYM);
        collapseFloor(usrIns, canvas);
        printCanvas(usrIns, canvas);
    }
}

void moveBorderless(char*** canvas, char* usrKey, int* playerCoords, int* usrIns)
{
    int tempCoords[2];
    tempCoords[0] = playerCoords[0];
    tempCoords[1] = playerCoords[1];

    if((*usrKey) == UP_KEY)
    {
        playerCoords[0] = playerCoords[0] - 1;
    }
    else if((*usrKey) == DOWN_KEY)
    {
        playerCoords[0] = playerCoords[0] + 1;
    }
    else if((*usrKey) == LEFT_KEY)
    {
        playerCoords[1] = playerCoords[1] - 1;
    }
    else if((*usrKey) == RIGHT_KEY)
    {
        playerCoords[1] = playerCoords[1] + 1;
    }

    if(playerCoords[0] > usrIns[ROWS] - 1)
    {
        playerCoords[0] = 0;
    }
    else if(playerCoords[0] < 0)
    {
        playerCoords[0] = usrIns[ROWS] - 1;
    }
    else if(playerCoords[1] > usrIns[COLS] - 1)
    {
        playerCoords[1] = 0;
    }
    else if(playerCoords[1] < 0)
    {
        playerCoords[1] = usrIns[COLS] - 1;
    }

    if(vFloor(usrIns, playerCoords, canvas, 0))
    {
        /*remove last player*/
        placeSym(tempCoords, canvas, SPACE_SYM);
        placeSym(playerCoords, canvas, PLAYER_SYM);
        collapseFloor(usrIns, canvas);
        printCanvas(usrIns, canvas);
    }
    else
    {
        playerCoords[0] = tempCoords[0];
        playerCoords[1] = tempCoords[1];
    }
}