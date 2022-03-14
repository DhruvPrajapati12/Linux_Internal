#include <stdio.h>
#include <stdlib.h>

void buggy()
{
    int *intptr;
    intptr = (int *)malloc(sizeof(int)*5);

    printf("Malloc checking: Add=%08x and size %d\n", intptr, sizeof(int)*5);

    for(int i=0; i<5; i++)
    {
        *intptr = 100;
        printf("value at ptr intptr = %d\n", (*intptr));
        intptr++;
    }
}

int main()
{
    buggy();
    return 0;
}