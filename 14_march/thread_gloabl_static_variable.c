#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sharedVar = 5; // shared variable(critical section)

void* thread_inc(void *arg)
{
    sharedVar++;
    // sharedVar++;
    printf("After inc = %d\n", sharedVar);
}

void* thread_dec(void *arg)
{
    sharedVar--;

    printf("After dec = %d\n", sharedVar);
}

void main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_inc, NULL);
    pthread_create(&t2, NULL, thread_dec, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("shared var = %d\n", sharedVar);
}