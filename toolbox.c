#include <stdio.h>
#include <stdlib.h>
#include "toolbox.h"

void charToInt(char** cArr, int* iArr, int* len)
{
    int i;
    for (i=1; i<(*len); i++)
    {
        iArr[i-1] = atoi(cArr[i]);
    }
}