#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"

int main(int argc, char *argv[])
{
    int userInputs[6];
    char **canvas;
    if (vArgs(argc))
    {
        charToInt(argv, userInputs, argc);
    }

    if(vMapSize(userInputs[ROWS_INDEX], userInputs[COLS_INDEX]) 
    && vStartLocation(userInputs[PLAYER_ROW_INDEX], 
    userInputs[PLAYER_COL_INDEX], userInputs[ROWS_INDEX], userInputs[COLS_INDEX])
    && vStartLocation(userInputs[GOAL_COL_INDEX], userInputs[GOAL_ROW_INDEX], 
    userInputs[ROWS_INDEX], userInputs[COLS_INDEX]))
    {
        initArray(userInputs, &canvas);
        printCanvas(userInputs, canvas);
        
        free(canvas);
    }        
    return 0;
}