#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void main()
{
    printf("Can you see me [one]\n");

    execl("/home/dhruv/Desktop/Linux_Internal/10_march/exectest","./exectest", "hello", "dhruv", "prajapati", NULL );
}