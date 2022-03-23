#include <stdio.h>
#include <stdlib.h>

struct A
{
    int roll;
    char name[40], gender __attribute__((aligned(16)));
    float height;
}__attribute__((packed));

int main()
{
    struct A first;
    printf("Size of struct A: %ld\n", sizeof(first));

    return 0;
}