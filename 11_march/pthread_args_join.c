#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* threadFun(void *args)
{
    char *s = (char *)args ;
    printf("%s\n", s);

    return NULL;
}

void* threadFun1(void *args)
{
    char *s = (char *)args;
    printf("%s\n", s);
    return NULL;
}

int main()
{
    pthread_t t1;
    pthread_t t2;
    void *res;
    int s;
    int s2;

    s=pthread_create(&t1, NULL, threadFun, "Hello world");
    s2=pthread_create(&t2, NULL, threadFun1, "Hello dhruv");

    if(s != 0)
        printf("pthread_create error\n");

    if(s2 != 0)
        printf("pthread_create2 error\n");

    printf("Messaged from main()\n");

    // sleep(3);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    exit(0);
}