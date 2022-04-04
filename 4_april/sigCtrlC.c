#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sighand(int signum)
{
    printf("ctrl + c\n");
}

int main()
{
    // signal(SIGINT, SIG_DFL);
    signal(SIGINT, sighand);    // register singal handlar

    // for(int i=0; ; i++)
    // {
    //     printf("%d\n", i);
    //     sleep(1);
    // }
    sleep(6);

    // signal(SIGINT, SIG_DFL);

    return 0;
}