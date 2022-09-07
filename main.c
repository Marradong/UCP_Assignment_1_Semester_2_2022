#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"
#include "gameplay.h"

int main(int argc, char *argv[])
{
    int usrIns[6];
    
    char **canvas;
    if (vArgs(argc))
    {
        charToInt(argv, usrIns, argc);
    }

    if(vMapSize(usrIns) && vStartLocation(usrIns))
    {
        initArray(usrIns, &canvas);
        printCanvas(usrIns, canvas);
        readMove();
        free(canvas);
    }        
    return 0;
}