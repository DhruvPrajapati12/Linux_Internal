// 6.Write a program, where functions of the program are called in the reverse order of
// their function calls from main().

#include <stdio.h>
#include <stdlib.h>

void callback1()
{
    printf("Callback 1 func called\n");
}

void callback2()
{
    printf("Callback 2 func called\n");
}

void callback3()
{
    printf("Callback 3 func called\n");
}

int main()
{
    printf("Registring callback1\n");
    atexit(callback1);      //atexit() ...regs func callback1 with kernal

    printf("Registring callback2\n");
    atexit(callback2);

    printf("Registring callback3\n");
    atexit(callback3);

    printf("Function calling in reverse order.. now\n");
    // _exit(0);    // not calling registered function
    exit(0);  // main + registered fun in kernal exit kre
    // return 0;
}