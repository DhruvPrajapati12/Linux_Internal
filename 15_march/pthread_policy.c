#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *my(void *i)
{
    printf("\n I am in %d thread \n", (int *)i);
}

void main()
{
    pthread_t tid;
    struct sched_param param;
    int priority, policy, ret;

    // Schedling parameters to target thread

    ret = pthread_getschedparam(pthread_self(), &policy, &param);   //pthread_self() means, current process is working as thread.so there is no need to use pthread_create().

    if (ret != 0)
    {
        perror("getschedparam\n");
    }

    printf("\n --------------Main thread \n Policy: %d \t priority: %d\n", policy, param.sched_priority);

    policy = SCHED_FIFO;
    param.sched_priority = 3;

    ret = pthread_setschedparam(pthread_self(), policy, &param);

    if (ret != 0)
        perror("getschedparam");

    ret = pthread_getschedparam(pthread_self(), &policy, &param);

    if (ret != 0)
        perror("getschedparam");

    printf("\n---------------------------------Main Thread------------------\nPolicy : %d \tPriority :%d\n", policy, param.sched_priority);

    return 0;

}