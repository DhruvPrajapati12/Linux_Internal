#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;

// Thread function

void* foo(void *arg)
{
    char* str = (char *)arg;

    printf("Thread task called by = %s\n", str);

    //acquire lock

    pthread_mutex_lock(&lock);

    if(done == 1)
    {
        // lets wait on condition variable cond1
            // done = 2;
        printf("Waiting on condition variable cond1\n");
        pthread_cond_wait(&cond1, &lock);
    }
    else 
    {
        // lets signal condition variable cond1
        printf("Signaling condition variable cond1\n");
        pthread_cond_signal(&cond1);
    }

    // release lock
    pthread_mutex_unlock(&lock);

    printf("Returning thread\n");

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, foo, "THDone");

    // sleep for 1 sec so that thread1
    // would get a chance to run first
    sleep(1);

    // lets wait on condition variable cond1

    done = 2;

    // create thread2

    pthread_create(&t2, NULL, foo, "THDtwo");

    // wait for the completion of thread2
    pthread_join(t2, NULL);

    return 0;
}