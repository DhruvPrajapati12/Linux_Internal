#include <stdio.h>
#include <stdlib.h>
extern int EF_PROTECT_BELOW;

void buggy()
{
    int *intptr;
    intptr = (int *)malloc(sizeof(int)*5);  // int data types: 4 bytes

    for(int i=0; i<3; i++)
    {
        *intptr = 100;
        printf("value at ptr intptr = %d\n", (*intptr));
        intptr--;
    }
}

int main()
{
    buggy();
    return 0;
}