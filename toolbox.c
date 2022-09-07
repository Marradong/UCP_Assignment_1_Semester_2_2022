#include <stdio.h>
#include <stdlib.h>

void charToInt(char** cArr, int iArr[6], int len)
{
    int i;
    for (i=1; i<len; i++)
    {
        iArr[i-1] = atoi(cArr[i]);
    }
}