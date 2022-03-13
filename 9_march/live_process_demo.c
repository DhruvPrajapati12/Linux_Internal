#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("my process id = %d\n", getgid());   // get pid of calling process

    printf("my parent pid = %d\n", getppid());  // get pid of parent of calling process(Bash process)

    printf("Linux kernal\n");
    while(1);
    return 0;
}