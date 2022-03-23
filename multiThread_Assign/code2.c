// 2.Write a program where thread cancel itself.(use pthread_cancel())

#include <stdio.h>
#include <pthread.h>

void* function(void* args)
{
    char *str = (char *)args;
    printf("%s executing\n",str);
    
    int t = pthread_cancel(pthread_self());     //Cancel THREAD immediately or at the next possibility.
    if(t == 0)
        printf("thread cancelld successfully\n\n\n");

    printf("This part is not executed\n");

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int ret;

    printf("main program starts\n");
    printf("creating thread\n\n");

    pthread_create(&t1, NULL, function, "Thread1");

    // Waiting for when thread is completed
    pthread_join(t1, NULL);

    printf("main program ends\n");

    return 0;
}

