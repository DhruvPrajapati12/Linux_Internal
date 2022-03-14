#include <pthread.h>
#include <stdio.h>

void function(void)
{
    // pthread_detach(pthread_self());
    printf("This is thread function\n");
}

void main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, function, NULL);

    printf("Ths is main code\n");

    pthread_exit(NULL);    // OR We can write pthread_join(&thread, NULL);
    // pthread_exit terminates the main process, but it allows pending tasks to finish, Its not terminating task
}

// There may be pending request at this point 
// Just exit that main thread/process  - not the whole program - so that remaining
// request that may still be processed can continue 