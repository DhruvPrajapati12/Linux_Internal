// 2.Write a program such that parent process create two child processes,such that
// each child executes a separate task.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

void task1()    // task1 perform by child process 1
{
    printf("This is task1 to be performed by child process 1\n");
    printf("Task1:  ");
    for(int i=1; i<=10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void task2()    // task2 perform by child process 2
{
    printf("This is task2 to be performed by child process 2\n");
    printf("Task2:  ");
    for(int i=11; i<=20; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{   
    printf("main program starts here\n");

    if(fork() == 0)
    {
        printf("child process id: %d, my parent process id: %d\n", getpid(), getppid());
        task1();    // task done by child process 1
        exit(0);    // terminate child process 1
    }
    else 
    {
        wait(0);    // parent wait for child process to be terminate
    }

    if(fork() == 0)
    {
        printf("child process id: %d, my parent process id: %d\n", getpid(), getppid());
        task2();   // task done by child process 2 
        exit(0);    // terminate child process 2
    }
    else 
    {
        wait(0);    // parent wait for child process to be terminate
    }
    printf("main program ends here\n");

    return 0;
}

// |P
// |
// |
// |_________
// |P       |C
// |        |
// |        |
// |        |
// |________X
// |P       |C
// |        |
// |        |
// |        |
// X        X

// for(int i=0; i<2; i++)
// {
//     if(fork() == 0)
//     {
//         printf("child process id: %d, my parent process id: %d\n", getpid(), getppid());
//         exit(0);
//     }
//     wait(0);
// }