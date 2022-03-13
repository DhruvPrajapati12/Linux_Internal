#include <stdio.h>
#include <pthread.h>

pthread_t tid;
pthread_t tid2;

void *thread1(void *arg)
{
    printf("newly created thread 1 is executing \n");
    return NULL;
}
void *thread2(void *arg)
{
    printf("newly created thread 2 is executing \n");
    return NULL;
}
int main(void)
{
    int ret = pthread_create(&tid, NULL, thread1, NULL);
    int ret2 = pthread_create(&tid2, NULL, thread2, NULL);

    if (ret)
        printf("Thread1 is not created\n");
    else
        printf("Thread1 is created\n");

    if (ret2)
        printf("Thread2 is not created\n");
    else
        printf("Thread2 is created\n");

    // sleep(2);
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    return 0;
}