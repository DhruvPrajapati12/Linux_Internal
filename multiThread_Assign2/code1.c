// Write a pthread application where main task terminated but pending pthreads
// task still execute.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *function(void *args)
{
    printf("Thread executing...\n");
    for(int i=1; i<=20; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

int main()
{
    pthread_t tid, tid1;

    printf("main program starts here\n");
    printf("Thread creating...\n");
    pthread_create(&tid, NULL, function, NULL);
    // pthread_create(&tid1, NULL, function, NULL);
    // sleep(1);
    // pthread_join(tid, NULL);
    printf("here, Main program ends but pending pthreads task still execute.\n");  // here main process treminated but pending pthreads task still execute.
    pthread_exit(NULL); // main ends, pending task will be done
}

// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>

// void *fun(void *arg)
// {
//     printf("This task is done by thread\n");
//     sleep(3);
//     printf("This part is executing after main process\n");
//     printf("Thread task ends here\n");
// }

// int main()
// {
//     pthread_t thd;

//     pthread_create(&thd, NULL, fun, NULL);
//     // pthread_detach(thd);
//     sleep(1);
//     printf("Main ends here\n");
//     pthread_exit(NULL);

//     // exit(0);
// }