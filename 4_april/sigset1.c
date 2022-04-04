// #include <stdio.h>
// #include <signal.h>

// void sighand(int no)
// {
//     printf("I am in sighandlar\n");
// }

// int main()
// {
//     sigset_t s_set;
//     signal(2, sighand);
//     sigemptyset(&s_set);
//     sigaddset(&s_set, 2);
//     perror("sig2");
//     sigaddset(&s_set, 4);
//     perror("sigmask");
//     sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
//     printf("Send me signal one and see the effect now\n");
//     getchar();
//     getchar();
//     sigprocmask(SIG_UNBLOCK, &s_set, NULL);
//     printf("Now signal are unblocked \n");
//     while(1);

//     return 0;
// }

#include <stdio.h>
#include <signal.h>

void sighnad(int no)
{
    printf("I am the sighandler\n");
}

int main()
{
    sigset_t s_set;       // grp of signals
    signal(2, sighnad);   // sig handler
    sigemptyset(&s_set);  // initialize signal set
    sigaddset(&s_set, 2); // add signal 2 in grp of signals
    perror("sig2");
    sigaddset(&s_set, 4);
    perror("sig4");
    sigprocmask(SIG_BLOCK | SIG_SETMASK, &s_set, NULL);
    perror("sigmask");
    printf("Send me signal one and see the effect now\n");
    getchar();
    getchar();
    sigprocmask(SIG_UNBLOCK, &s_set, NULL);
    printf("Now signals are unblocked\n");
    while (1);
    return 0;
}