#include <stdio.h>
#include <unistd.h>

void main()
{
    printf("Can you see me [one]\n");

    execl("/home/dhruv/Desktop/Linux_Internal/10_march/exectest","./exectest_cmd_line", "hello", "dhru", "prajapati", NULL );
}