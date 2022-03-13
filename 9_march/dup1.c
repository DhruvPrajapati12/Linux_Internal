#include <stdio.h>
#include <fcntl.h>

void main()
{
    int fd1, fd2, fd3, fd4;

    fd1 = open("linux.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    fd2 = open("linuxnew.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    printf("fd1=%d\n", fd1);
    printf("fd2=%d\n", fd2);

    fd3 = dup(fd1); 
    fd4 = dup2(fd1, 44);

    printf("fd3_dup of fd1=%d\n", fd3);
    printf("fd4_dup of fd1=%d\n", fd4);

    close(fd1);
    close(fd2);
    close(fd3);
}