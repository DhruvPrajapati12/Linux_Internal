//  5.Write a program that implements threads synchronization using mutex techniques.

#include <stdio.h>
#include <pthread.h>

int globleSharedVari = 25;
pthread_mutex_t mutex_lock;

void* increment(void)
{
    printf("Inside thread 1(Increment)\n");
    pthread_mutex_lock(&mutex_lock);
    globleSharedVari++;
    pthread_mutex_unlock(&mutex_lock);
    printf("Value of shared variable is increment by 1: %d\n", globleSharedVari);
    // return NULL;
}

void* decrement(void)
{
    printf("Inside thread 2(decrement)\n");
    pthread_mutex_lock(&mutex_lock);
    globleSharedVari--;
    pthread_mutex_unlock(&mutex_lock);
    printf("Value of shared variable is decrement by 1: %d\n", globleSharedVari);
    // return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex_lock, NULL);

    printf("Creating thread1 and thread2\n");

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // sleep(1);
    // printf("Global shared variable value: %d\n", globleSharedVari);

    return 0;
}