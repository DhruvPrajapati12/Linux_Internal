// 4.A processs using execl() system call should replace a new command line program.

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("main program\n");

    execl("/bin/ls", "ls", "-l", NULL);

    printf("This part should not be executed\n");
    return 0;
}