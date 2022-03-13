#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid;

void* threadFun(void *args)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();   // print calling thread id
    printf("Pid: %u tid: %u\n", (unsigned int)pid, (unsigned int)tid);

    return NULL;
}

void main()
{
    int err;
    err = pthread_create(&tid, NULL, threadFun, NULL);
    if(err != 0)
    {
        printf("Can not create thread: %d\n", strerror(err));
    }

    while(1);       // ps -elf
    // sleep(3);
    exit(0);
}