// write a program, which get and set pthread scheduling policy and priority.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void main()
{
    int policy;
    struct sched_param parameters;

    pthread_getschedparam(pthread_self(), &policy, &parameters);

    printf("Default policy: %d and default priority: %d\n", policy, parameters.sched_priority);

    policy = SCHED_RR;
    parameters.sched_priority = 23;

    pthread_setschedparam(pthread_self(), policy, &parameters);

    pthread_getschedparam(pthread_self(), &policy, &parameters);

    printf("New policy: %d and default priority: %d\n", policy, parameters.sched_priority);
}