#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    printf("max fds: %d\n", getdtablesize());   // will get fd size table
}