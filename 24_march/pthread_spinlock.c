#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


static pthread_spinlock_t spinlock;
volatile int slock;


void *spinlockThread(void *i)
{
    int rc;
    int count = 0;

    printf("Entered thread %d, getting spin lock\n", (int *)i);

    rc = pthread_spin_lock(&slock);

    printf("%d Thread unlock the spin lock\n", (int *)i);
    rc = pthread_spin_unlock(&slock);

    printf("%d thread complete\n", (int *)i);
    return NULL;
}

void main()
{
    int rc;
    // int count=0;

    pthread_t thread;

    if(pthread_spin_init(&slock, PTHREAD_PROCESS_PRIVATE) != 0)
        perror("init\n");
    printf("Main, get spin lock\n");
    rc = pthread_spin_lock(&slock);

    printf("main, create the spin lock thread\n");
    rc = pthread_create(&thread, NULL, spinlockThread, (int *)1);

    printf("Main, wait a bit holding the spin lock\n");
    sleep(4);

    printf("Main, now unlock the spin lock\n");
    rc = pthread_spin_unlock(&slock);

    if(rc == 0)
        printf("\n Main thread successfully unlocked\n");
    else 
        printf("\n Main thread unsuccessfully unlocked\n");

    printf("Main, wait for the thread to end\n");
    rc = pthread_join(thread, NULL);

    // rc = pthread_spin_destroy(&slock);

    printf("Main completed\n");
}