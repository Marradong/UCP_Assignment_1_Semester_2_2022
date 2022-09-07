#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"
#include "gameplay.h"

int main(int argc, char *argv[])
{
    int usrIns[6], playerCoords[2];
    char **canvas;
    char usrKey;

    if (vArgs(argc))
    {
        charToInt(argv, usrIns, argc);
        playerCoords[0] = usrIns[PLAYER_ROW];
        playerCoords[1] = usrIns[PLAYER_COL];

        if (vMapSize(usrIns) && vStartLocation(usrIns))
        {
            initArray(usrIns, &canvas);
            printCanvas(usrIns, canvas);
            usrKey = readMove();
            movePlayer(canvas, &usrKey, playerCoords, usrIns);
            printCanvas(usrIns, canvas);
            free(canvas);
        }
    }

    return 0;
}