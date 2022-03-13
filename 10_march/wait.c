#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main()
{
    pid_t pid1; // pid_t data types for process id(Internally interger)

    pid1 = fork();

    if(pid1 == 0)   //child process
    {
        sleep(5);
        printf("I am child with delay of 5 sec and my child pro pid: %d\n", getpid());
        exit(0);
    }
    else 
    {
        int pid2;
        printf("I am parent pro pid: %d\n", getpid());
        pid2 = wait(0); //on return pid of the terminated child...exit status of termnt child

        printf("Parent saying, child %d exited/terminated normally\n", pid2);
        printf("I am parent process pro pid: %d\n", getpid());
    }
}