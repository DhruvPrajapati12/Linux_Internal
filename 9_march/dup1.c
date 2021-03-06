#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void main()
{
    int fd1, fd2, fd3, fd4;

    fd1 = open("linux.txt", O_WRONLY | O_CREAT | O_TRUNC, 777); //3
    fd2 = open("linuxnew.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);  //4
    printf("new file created with fd=%d\n", fd1);
    printf("new flle created with fd=%d\n", fd2);

    fd3 = dup(fd1); 
    fd4 = dup2(fd2, 44);    // generating fd of your own 44

    printf("fd3_dup of fd1=%d\n", fd3);
    printf("fd4_dup of fd2=%d\n", fd4);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
}