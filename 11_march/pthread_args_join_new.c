#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void* threadFun(void *args)
{
    char *s = (char *)args ;
    printf("%s\n", s);
    sleep(5);
    return (void*)strlen(s);
    return 0;
}

int main(int args, char *argv[])
{
    pthread_t t1;
    void *res;
    int s;

    s=pthread_create(&t1, NULL, &threadFun, "Hello world");

    printf("Messaged from main()\n");


    sleep(3);

    pthread_join(t1, &res);

    printf("Thread returned %d ld\n", (long)res);
    exit(0);
}