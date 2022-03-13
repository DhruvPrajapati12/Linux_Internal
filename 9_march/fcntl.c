#include <stdio.h>
#include <fcntl.h>

void main()
{
    int fd1, fd2, fd3;

    fd1 = open("linux1.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);

    fd3 = fcntl(fd1, F_DUPFD);  //dup()
    // fd3 = fcntl(fd1, F_DUPFD, 55);   Here 55 is own fd       //dup1();
    // syntax -> fcntl(int fd, int cmd, optional value);
    // Duplicate file using fcntl

    printf("Duplicate using fcntl using fd1: %d\n", fd3);

    close(fd1);
    close(fd3);
}