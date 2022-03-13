#include <stdio.h>
#include <fcntl.h>

void main()
{
    int fd1, fd2, fd3;

    fd1 = open("linux.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);

    fd3 = fcntl(fd1, F_DUPFD);
    // Duplicate file using fcntl

    printf("Duplicate using fcntl using fd1: %d\n", fd3);
}