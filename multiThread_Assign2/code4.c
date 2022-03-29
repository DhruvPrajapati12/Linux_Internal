// write a program, which get and set pthread scheduling policy and priority.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Root power needed

void main()
{
    int policy;
    struct sched_param parameters;

    printf("Main program starts here...\n");

    pthread_getschedparam(pthread_self(), &policy, &parameters);

    printf("Default policy: %d and default priority: %d\n", policy, parameters.sched_priority);

    printf("Changing the priority and policy of process\n");

    policy = SCHED_RR;      //2
    parameters.sched_priority = 23;

    pthread_setschedparam(pthread_self(), policy, &parameters);

    pthread_getschedparam(pthread_self(), &policy, &parameters);

    printf("New policy: %d and default priority: %d\n", policy, parameters.sched_priority);

    printf("main program ends here...\n");
}