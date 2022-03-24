#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* Function(void *args)
{
    char *str = (char *)args;
    printf("Threadid: %lu, String: %s\n", pthread_self(), str);
    return NULL;
}

void main()
{
    pthread_t threadId;
    pthread_attr_t Attri;
    int ret;
    size_t size;
    void *ptr;

    pthread_attr_init(&Attri);
    // pthread_attr_getstack(&Attri,&ptr, &size);
    pthread_attr_getstacksize(&Attri, &size);
    pthread_attr_getstackaddr(&Attri, &ptr);

    printf("Initial(Deafult) address: %08x \nsize: %ld\n", ptr, size);

    size_t newSize = 1342177280;
    void* newAddress;

    newAddress = malloc(newSize);

    pthread_attr_setstack(&Attri, newAddress, newSize);

    pthread_create(&threadId, &Attri, Function, "Hello Dhruv");

    pthread_attr_getstack(&Attri, &ptr, &size);

    printf("After changing add and incresing stack size\nAddr= %08p and Size=%ld\n", ptr, size);
    // pthread_join(threadId, NULL);
    sleep(2);
}