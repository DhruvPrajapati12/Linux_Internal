// 7. Write a program child executes(exec()) a new program , while parent waits for
// child task to get complete.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
    printf("main program\n");

    if(fork() == 0)     // creating a child process
    {
        printf("child process id: %d, my parent process id: %d\n", getpid(), getppid());
        execl("/bin/ls", "ls", "-l", NULL);
        exit(0);    // terminating child process
    }
    else 
    {
        wait(0);
    }

  return 0;
}