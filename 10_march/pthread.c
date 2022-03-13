#include <stdio.h>
#include <pthread.h>

pthread_t tid;

void* thread1(void *arg)
{
    printf("newly created thread is executing \n");
    return NULL;
}

void main()
{
    int ret = pthread_create(&tid, NULL, thread1, NULL);

    if (ret)
        printf("THread is not created\n");
    else
        printf("THread is created\n");

    pthread_join(tid, NULL);
    // sleep(2);
    return 0;
}