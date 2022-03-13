#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("my process id = %d\n", getgid());

    printf("my parent pid = %d\n", getppid());

    printf("Linux kernal\n");
    while(1);
    return 0;
}