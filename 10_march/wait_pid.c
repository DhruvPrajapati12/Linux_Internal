#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int pid;
    int status;

    printf("Parent: %d\n", getpid());

    pid = fork();

    if(pid == 0)
    {
        printf("child %d\n",getpid());
        sleep(2);
        exit(0);
    }
    printf("Parent reporting exit of child whose pid= %d\n",waitpid(pid, &status, 0));
}

