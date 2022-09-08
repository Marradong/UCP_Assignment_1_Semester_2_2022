#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"
#include "gameplay.h"
#include "random.h"

int main(int argc, char *argv[])
{
    int usrIns[6], playerCoords[2];
    int winStatus = 0;
    char **canvas;
    char usrKey;

    if (vArgs(&argc))
    {
        charToInt(argv, usrIns, &argc);
        playerCoords[0] = usrIns[PLAYER_ROW];
        playerCoords[1] = usrIns[PLAYER_COL];

        if (vMapSize(usrIns) && vStartLocation(usrIns))
        {
            initRandom();
            initArray(usrIns, &canvas);
            printCanvas(usrIns, canvas);
            while (!winStatus)
            {
                usrKey = readMove();
                movePlayer(canvas, &usrKey, playerCoords, usrIns);
                winStatus = vWin(usrIns, playerCoords);
            }
            printf("You Win!\n");
            free(canvas);
        }
    }

    return 0;
}