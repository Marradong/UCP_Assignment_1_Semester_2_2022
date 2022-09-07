#include <stdio.h>
#include "gameplay.h"
#include "terminal.h"
#include "verify.h"

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

void movePlayer(char** canvas, char* usrKey, int playerCoords[])
{

    if((*usrKey) == UP_KEY)
    {

    }
    else if((*usrKey) == DOWN_KEY)
    {

    }
    else if((*usrKey) == LEFT_KEY)
    {

    }
    else if((*usrKey) == RIGHT_KEY)
    {

    }
}