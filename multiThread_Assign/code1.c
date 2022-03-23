// 1.Write a multithreading program, where threads runs same shared golbal variable of
// the process between them.

#include <stdio.h>
#include <pthread.h>
// #include <stdlib.h>

int a = 15;

void* function1(void *args)
{
    char *str = (char *)args;
    // printf("%s\n", str);
    a = a + 5;
    printf("%s sleep now...then thread 2 will be activated and changes value of a\n", str);
    sleep(3);
    printf("%s resume now...\n", str);
    a = a - 4;
    // printf("Value of a: %d\n", a);
    return NULL;
}

void* function2(void *args)
{
    char *str = (char *)args;
    // printf("%s\n", str);
    a = a + 7;
    printf("thread 2 successfully changes value of a\n");
    // printf("Value of a: %d\n", --a);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    printf("Value of a: %d\n", a);

    pthread_create(&t1, NULL, function1, "Thread 1");
    sleep(2);
    pthread_create(&t2, NULL, function2, "Thread 2");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Value of a: %d\n", a);

    return 0;
}


