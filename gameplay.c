#include <stdio.h>
#include "gameplay.h"
#include "terminal.h"
#include "verify.h"
#include "canvas.h"

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

void movePlayer(char** canvas, char* usrKey, int playerCoords[], int usrIns[])
{

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

    if(playerCoords[0] > usrIns[ROWS])
    {
        playerCoords[0] = usrIns[ROWS];
    }
    if(playerCoords[0] < 0)
    {
        playerCoords[0] = 0;
    }
    if(playerCoords[1] > usrIns[COLS])
    {
        playerCoords[1] = usrIns[COLS];
    }
    if(playerCoords[1] < 0)
    {
        playerCoords[1] = 0;
    }

    clearCanvas(usrIns, canvas);
    placePlayer(playerCoords, canvas);
}