#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"
#include "gameplay.h"
#include "random.h"

int main(int argc, char *argv[])
{
    if (vArgs(&argc))
    {
        int usrIns[6], playerCoords[2], goalCoords[2];

        charToInt(argv, usrIns, &argc);

        playerCoords[ROWS] = usrIns[PLAYER_ROW];
        playerCoords[COLS] = usrIns[PLAYER_COL];

        goalCoords[ROWS] = usrIns[GOAL_ROW];
        goalCoords[COLS] = usrIns[GOAL_COL];

        if (vMapSize(usrIns) && vStartLocation(usrIns))
        {
            int winStatus = FALSE;
            int loseStatus = FALSE;
            char **canvas = NULL;
            char usrKey = ' ';

            initRandom();
            initCanvas(usrIns, playerCoords, &canvas);

            while (!(winStatus || loseStatus))
            {
                readMove(&usrKey);

                #ifndef BORDERLESS
                    movePlayer(&canvas, &usrKey, playerCoords, usrIns);
                #endif

                #ifdef BORDERLESS
                    moveBorderless(&canvas, &usrKey, playerCoords, usrIns);
                #endif

                winStatus = vWin(usrIns, playerCoords);
                loseStatus = (vLose(&canvas, playerCoords, usrIns) || vLose(&canvas, goalCoords, usrIns));
            }
            if(winStatus)
            {
                printf("You Win!\n");
            }
            else
            {
                printf("You Lose!\n");
            }
            freeCanvas(usrIns, &canvas);
        }
    }
    return 0;
}