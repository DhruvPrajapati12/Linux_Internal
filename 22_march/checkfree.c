#include <stdio.h>
#include <stdlib.h>
extern int EF_PROTECT_BELOW;

void buggy()
{
    int *intptr;
    intptr = (int *)malloc(sizeof(int));  // int data types: 4 bytes

    *intptr = 100;
    printf("value at ptr intptr = %d\n", (*intptr));
    free(intptr);   // we free here dynamic allocated ptr
    *intptr = 100;  // trying to derefer here..
}

int main()
{
    buggy();
    return 0;
}