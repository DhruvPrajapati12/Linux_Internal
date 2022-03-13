#include <stdio.h>

void callback1(void)
{
    printf("Callback 1 func called\n");
}

void callback2(void)
{
    printf("Callback 2 func called\n");
}

void callback3(void)
{
    printf("Callback 3 func called\n");
}

void main()
{
    printf("Registring callback1\n");
    atexit(callback1);      //atexit() ...regs func callback1 with kernal

    printf("Registring callback2\n");
    atexit(callback2);

    printf("Registring callback3\n");
    atexit(callback3);

    printf("Main().. exiting now\n");
    // _exit(0);    // not calling registered function
    exit(0);    // main + registered fun in kernal exit kre
}

// Maximum 32 atexit() we can define 