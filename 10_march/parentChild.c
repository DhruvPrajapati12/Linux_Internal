#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main()
{
    pid_t pid;
    int option, stat;

    while(1)
    {
        printf("Enter 1 to exec ls program in child process and 0 for exit\n");
        scanf("%d", &option);

        if(option == 0)
            exit(0);
        printf("\n");

        if(fork() == 0)
        {
            execl("/bin/ls", "ls", 0);
            exit(0);
        }
        pid = wait(0);
        printf("child with pid %d is terminated\n", pid);
    }
}

// wait and wait_pid system calls are force and repair a process to wait until child process completes and terminates
