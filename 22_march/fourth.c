#include <stdio.h>
#include <stdlib.h>

struct A
{
    int roll;
    char name[40], gender;
    float height;
};

int main()
{
    struct A first;
    printf("\n size of struct A %ld\n", sizeof(first));
    return 0;
}