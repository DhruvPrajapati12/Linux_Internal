// 4. Write a program where pthread task displays the thread id and also prints the calling
// process pid.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* Function(void* args)
{
    printf("Thread id: %lu\n", pthread_self());
    printf("Process pid: %d\n", getpid());
}

int main()
{
    pthread_t threadId;

    printf("Main program starts\n");
    printf("Thread is created\n");

    pthread_create(&threadId, NULL, Function, NULL);

    pthread_join(threadId, NULL);

    printf("Main end\n");

    return 0;
}