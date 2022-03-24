#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int sharedVar = 5; // shared variable(critical section)

sem_t my_sem;           // create semaphore

void* thread_inc(void *arg)
{
    sem_wait(&my_sem);  // take semaphore
    sharedVar++;
    // sharedVar++;
    sem_post(&my_sem);  // release semaphore
    printf("After inc = %d\n", sharedVar);
}

void* thread_dec(void *arg)
{
    sem_wait(&my_sem);  // take semaphore
    sharedVar--;
    sem_post(&my_sem);    // realease semaphore

    printf("After dec = %d\n", sharedVar);
}

void main()
{
    pthread_t t1, t2;

    sem_init(&my_sem, 0, 1);    // initialize semaphore
    // 3rd arg: 0 -> making semaphore object to be shared between thread of same process]
    // If it is non zero then it is shared between processed
    pthread_create(&t1, NULL, thread_inc, NULL);
    pthread_create(&t2, NULL, thread_dec, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("shared var = %d\n", sharedVar);
}