#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void* threadFun(void *args)
{
    char *s = (char *)args ;
    printf("%s\n", s);

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

    exit(0);
}