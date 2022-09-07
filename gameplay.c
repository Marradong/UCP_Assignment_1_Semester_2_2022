#include <stdio.h>
#include "gameplay.h"
#include "terminal.h"

char readMove()
{
    char move;
    disableBuffer();
    scanf(" %c", &move);
    if(vMove(&move))
    {

    }  
    return move;
}