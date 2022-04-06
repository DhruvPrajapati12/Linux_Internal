#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/* handler for SIGINT and SIGTERM */
static void signal_handler(int signo)
{
    if (signo == SIGINT)
        printf("Caught SIGINT!\n");
    else if (signo == SIGALRM)
        printf("Caught SIGALRM! \n");
    else
    {
        printf("Caught SIGABRT!\n"); /* this should never happen */
        fprintf(stderr, "Unexpected signal!\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
int main(void)
{
    // *Register signal_handler as our signal handler for SIGINT.
    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGINT!\n");
        exit(EXIT_FAILURE);
    }
    alarm(4);
    /* Reset SIGPROF's behavior to the default. */
    if (signal(SIGABRT, SIG_DFL) == SIG_ERR)
    {
        fprintf(stderr, "Cannot reset SIGPROF!\n");
        exit(EXIT_FAILURE);
    }

    /* Ignore SIGHUP. */
    // abort();
    if (signal(SIGABRT, SIG_IGN) == SIG_ERR)
    {
        fprintf(stderr, "Cannot ignore SIGHUP!\n");
        exit(EXIT_FAILURE);
    }
    for (;;)
        pause();
    return 0;
}