// Write a pthread program that implements simple initialization code. 

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void initFun()     // this function only executes once
{
    printf("Inside initialization function..\n");
    printf("This is initialization code that only executes for first thread\n");
}

void* function(void *args)
{
    char *s = (char *)args;
    printf("%s executing here...\n",s);

    pthread_once(&once, initFun);
    return NULL;
}

void main()
{
    pthread_t tid1, tid2, tid3;     // declared 3 threadid
    
    printf("Main program starts here...\n");

    pthread_create(&tid1, NULL, function, "Thread 1");
    pthread_create(&tid2, NULL, function, "Thread 2");
    pthread_create(&tid3, NULL, function, "Thread 3");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    printf("Main program ends here...\n");
}

// Initialisation code: code that only exexutes once. next time it will only executes after shutdown
// pthread_once_t--------------datatype provided in pthread library

// macro is used to initialize an object/ variable of type pthread_once_t.

// pthread_once_t once= PTHREAD_ONCE_INIT

// initialization to initial value(either 0 or 1)

// pthread_once(&once,(void)(*fun ptr)(void));

// once pthread_once execute, verify the object "once" of type pthread_once_t.

// If the variable is set, going to schedule and exexute function provided by 2nd argument.............2nd argument is function pointer.

// it schedules a function having no argument and returns nothing.

// After execution of initialization code, the value of variable is changed from its initial value.

// So next thread/process will not be able to point to function pointer.

// purpose of pthread_once is to only execute initializatin code(code that only exexutes once)
