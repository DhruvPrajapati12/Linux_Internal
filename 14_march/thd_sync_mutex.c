#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int sharedVar = 5; // shared variable(critical section)

pthread_mutex_t my_mutex;          

void* thread_inc(void *arg)
{
    pthread_mutex_lock(&my_mutex);          // take mutex
    sharedVar++;    
    // sharedVar++;
    pthread_mutex_unlock(&my_mutex);  // release mutex
    printf("After inc = %d\n", sharedVar);
}

void* thread_dec(void *arg)
{
    pthread_mutex_lock(&my_mutex);  // take mutex
    sharedVar--;
    pthread_mutex_unlock(&my_mutex);    // realease mutex

    printf("After dec = %d\n", sharedVar);
}

void main()
{
    pthread_t t1, t2;

   pthread_mutex_init(&my_mutex, NULL);    // initialize mutex

    pthread_create(&t1, NULL, thread_inc, NULL);
    pthread_create(&t2, NULL, thread_dec, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("shared var = %d\n", sharedVar);
}