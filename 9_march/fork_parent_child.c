#include <stdio.h>
#include <unistd.h>

void main()
{
    int pid1;

    printf("Current process id: %d\n", getpid());

    pid1 = fork(); //child id sent parent
                    //0 return child pro

    if(pid1 == 0)
    {
        // sleep(5);
        printf("New child process pid: %d\n", getpid());
        printf("New  child parent process pid: %d\n", getppid());
    }
    else 
    {
        // sleep(3);
        printf("Parent process pid: %d\n", getpid());
        printf("Parents process pid: %d\n", getppid()); //bash
    }
    // while(1);

}