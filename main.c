#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"
#include "gameplay.h"
#include "random.h"

int main(int argc, char *argv[])
{
    int usrIns[6], playerCoords[2], goalCoords[2];
    int winStatus = 0;
    int loseStatus = 0;
    char **canvas;
    char usrKey;

    if (vArgs(&argc))
    {
        charToInt(argv, usrIns, &argc);
        playerCoords[0] = usrIns[PLAYER_ROW];
        playerCoords[1] = usrIns[PLAYER_COL];
        goalCoords[0] = usrIns[GOAL_ROW];
        goalCoords[1] = usrIns[GOAL_COL];

        if (vMapSize(usrIns) && vStartLocation(usrIns))
        {
            initRandom();
            initArray(usrIns, &canvas);
            printCanvas(usrIns, canvas);
            while (!(winStatus || loseStatus))
            {
                usrKey = readMove();

                #ifndef BORDERLESS
                    movePlayer(canvas, &usrKey, playerCoords, usrIns);
                #endif

                #ifdef BORDERLESS
                    moveBorderless(canvas, &usrKey, playerCoords, usrIns);
                #endif

                winStatus = vWin(usrIns, playerCoords);
                loseStatus = (vLose(canvas, playerCoords) || vLose(canvas, goalCoords));
            }
            if(winStatus)
            {
                printf("You Win!\n");
            }
            else
            {
                printf("You Lose!\n");
            }
            free(canvas);
        }
    }

    return 0;
}