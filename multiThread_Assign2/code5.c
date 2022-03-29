// Write a program that implements threads synchronization using pthread 
// spinlock techniques.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_spinlock_t lock;
int sharedVari=23;

void* function(void *args)
{
    int var = (void *)args;
    printf("Inside thread%d\n", var);

    pthread_spin_lock(&lock);
    printf("thread%d locked\n", var);

    sharedVari++;
    sleep(2);

    printf("thread%d unlocked\n", var);
    pthread_spin_unlock(&lock);
    
    printf("thread%d: var= %d\n", var, sharedVari);
    return NULL;
}

int main()
{

    pthread_t tid1, tid2;

    pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);

    pthread_create(&tid1, NULL, function, 1);
    pthread_create(&tid2, NULL, function, 2);

    pthread_join(tid1, NULL);
    sleep(3);
    // pthread_join(tid2, NULL);

    return 0;
}