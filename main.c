#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"
#include "verify.h"

int main(int argc, char *argv[])
{
    if (vArgs(argc))
    {
        int userInputs[6];
        char **canvas;

        charToInt(argv, userInputs, argc);
        
        initArray(userInputs, &canvas);
        printCanvas(userInputs, canvas);

        free(canvas);
    }
    return 0;
}