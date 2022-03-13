#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void main()
{
    pid_t pid;
    int option, start;

    while(1)
    {
        printf("Enter 1 to exec ls program in child process and 0 for exit\n");
        scanf("%d", &option);

        if(!option)
            exit(0);
        printf("\n");

        if(fork() == 0)
        {
            execl("/bin/ls", "ls", 0);
            exit(0);
        }
    }
}