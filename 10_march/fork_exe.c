#include <stdio.h>
#include <unistd.h>

void main()
{
    pid_t pid;
    pid = fork();

    if(pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
    }
}