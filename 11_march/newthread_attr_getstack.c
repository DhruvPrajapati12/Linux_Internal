#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

void* Proc(void* param)
{
    sleep(2);
    return 0;
}

int main()              // Doubt
{
    pthread_attr_t Attr;    //1
    pthread_t Id; 
    void *stk;
    size_t siz; // size_t int
    int err;

    size_t my_stksize = 0X30000000;
    void *my_stack;

    pthread_attr_getstacksize(&Attr, &siz);
    pthread_attr_getstackaddr(&Attr, &stk);

    printf("Default: Addr=%08x default size=%u\n", stk, siz);

    my_stack = (void *)malloc(my_stksize);

    pthread_attr_setstack(&Attr, my_stack, my_stksize);

    pthread_create(&Id, &Attr, Proc, NULL);

    pthread_attr_getstack(&Attr, &stk, &siz);

    printf("newly defined stack: Addr= %08x and Size=%u\n", stk, siz);

    sleep(3);

}

// PTHREAD ATTRIBUTES::

// pthread attributes talk about properties of threads. They talks about how thread should behave once thread created.

// Attributes are classified into 5 diffrent categories.
// 1--Stack management  	(pthread library functionalities)

// 2--thread synchronization	(pthread library functionalities)

// 3--thread scheduling policy  and priority	(pthread library functionalities)

// 4--thread specific data	(pthread library functionalities)

// 5--thread signals (pthread library functionalities)


// PTHREAD LIBRARY PROVIDES FUNCTIONALITIES FOR ALL ABOVE 5 CATEGORIES.



// when a thread is created, virtual memory of size 8 MB is alloacted to each thread to stack size.------ It is allocated by pthread library.



// whenever I want to change default attributes of thread , use pthread_attribute object.

// 1--declare an object of type 
// 	pthread_attr_t;	------Internaly structures with lots of members.

// 2-- Initialize pthread attribute object (because there will be garbage)


// pthread_attr_init(pthread_attr_t , *attr);

// 3--- call appropriate pthread attribute functions. (e.g.  call stack management functionalities)

// 4---- create pthread-----  pthread_create(__,&attr,___,__);	--previously we were putting NULL inplace of &attr.


// 5---At the end of pthread_create function, if fetch the attributes object will get our defined values.

// 6---pthread attributes destroyed
// 	pthread_attr_destroy(pthread_attr_t *attr);


// before creating new thread, destroy current thread attributes to avoid bugs..




// pthread_attr_getstack(pthread_attr_t *attr,void *addr,int size);

// pthread_attr_setstack(pthread_attr_t *attr, void *my_add,int mysize);
