#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
    int ret = execl("/home/dhruv/Desktop/Linux_Internal/process_assign/code1", "./code1", NULL);
    if (ret == -1)
    {
        printf("execl returned error %d\n", ret);
    }
    printf("\n");
}