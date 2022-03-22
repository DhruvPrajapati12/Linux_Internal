#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(4);    // allocating 4 bytes
    ptr[0] = 12;
    free(ptr);
    // free(ptr);
    ptr[0] = 13;
  return 0;
}