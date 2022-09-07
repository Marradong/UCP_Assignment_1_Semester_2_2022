#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "toolbox.h"

int main(int argc, char* argv[])
{   
    if(argc == 7)
    {
    int userInputs[6];
    char** canvas = NULL;

    charToInt(argv, userInputs, argc);
    initArray(userInputs, canvas);
    printCanvas(userInputs, canvas);
    }
    else
    {
        system("clear");
        printf("Invalid number of arguements please enter in the format below\n");
        printf("./escape <row_map> <col_map> <row_player> <col_player> <row_goal> <col_goal>\n");
    }
    return 0;
}