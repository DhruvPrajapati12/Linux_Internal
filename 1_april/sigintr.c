#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sighand(int signum)
{
    printf("Interrupt signal rec'd but no termination on ctrl + c\n");

    signal(SIGINT, SIG_DFL);        // Re registering signal handler for default action
}

int main()
{
    // signal(SIGINT, SIG_DFL);
    signal(SIGINT, sighand);    // register singal handlar

    for(int i=0; ; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

    // signal(SIGINT, SIG_DFL);

    return 0;
}