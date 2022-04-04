#include <stdio.h>
#include<signal.h>

void sighand(int signum)
{
    printf("I have to wake up my boss now.\n");
}

int main()
{
    signal(SIGALRM, sighand);
    alarm(2);
    while(1)
    {}

}