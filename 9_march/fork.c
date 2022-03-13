#include <stdio.h>
#include <unistd.h>


void main()
{
    printf("Statement 1\n");        //Total process n = 2 ^ number of fork 
    fork();
    fork();
    fork();
    printf("Statement 2\n");

    while(1);
}
