// Demo code of creating, opening and closing file using creat(), open(), close() system call.

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
    // int fd1, fd2, fd3;

    // fd1 = creat("one.txt", 777);
    // fd2 = creat("two.txt", 777);
    // fd3 = creat("three.txt", 777);

    // printf("file 1 fd: %d\n", fd1);
    // printf("file 2 fd: %d\n", fd2);
    // printf("file 3 fd: %d\n", fd3);

    printf("fd return bye open: %d ", open("one.txt", O_RDWR | O_CREAT | O_TRUNC, 777));
    printf("fd return bye open: %d ", open("two.txt", O_RDWR | O_CREAT | O_TRUNC, 777));
    printf("fd return bye open: %d ", open("three.txt", O_RDWR | O_CREAT | O_TRUNC, 777));

    // close(fd1);
    // close(fd2);
    // close(fd3);
}