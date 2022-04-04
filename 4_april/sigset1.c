#include <stdio.h>
#include <signal.h>

void sighand(int no)
{
    printf("I am in sighandlar\n");
}

int main()
{
    sigset_t s_set;
    signal(2, sighand);
    sigemptyset(&s_set);
    sigaddset(&s_set, 2);
    perror("sig2");
    sigaddset(&s_set, 4);
    perror("sigmask");
    printf("Send me signal one and see the effect now\n");
    getchar();
    getchar();
    sigprocmask(SIG_UNBLOCK, &s_set, NULL);
    printf("Now signal are unblocked \n");
    while(1);

    return 0;
}