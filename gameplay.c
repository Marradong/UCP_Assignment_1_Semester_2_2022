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