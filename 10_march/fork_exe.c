#include <stdio.h>
#include <unistd.h>

void main()
{
    pid_t pid;
    pid = fork();

    if(pid < 0)     // error occurred
    {
        printf("Fork failed\n");
        exit(-1);
    }
    else if(pid == 0)   // child process
    {
        execl("/bin/ls", "ls", NULL);
        exit(0);
    }
    else    // parent process
    {
        wait(0);    // parent wait until the child executed successfully
        printf("\nChild completed\n");
    }

}