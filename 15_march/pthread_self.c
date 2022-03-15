#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct my_thread
{
    int thread_id;
    char mesg[300];
};

void *PrintHello(void *threadobj)
{
    pthread_t thread_ID;
    struct my_thread *t1;
    t1 = (struct my_thread *) threadobj;
    thread_ID = pthread_self();
    printf("\n Thread ID: %u", thread_ID);
    printf("\n %d Thread Messaage: %s\n", t1->thread_id, t1-> mesg);
}

int main()
{
    pthread_t thread2, thread_ID;
    int rc;
    struct my_thread t2;
    t2.thread_id = 2;
    strcpy(t2.mesg, "I am second thread\n");

    thread_ID = pthread_self();

    printf("\n Main Thread id: %u", thread_ID);

    pthread_create(&thread2, NULL, PrintHello, (void *)&t2);

    printf("\nExit from main function\n");
    pthread_exit(NULL);

  return 0;
}