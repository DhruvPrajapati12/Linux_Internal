// 4.Write a program that implements all file operations(open/creat/write/read/
// lseek/close).

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd1, fd2;

    char write_buf[50] = "Hello this is dhruv prajapati....";
    char read_buf[50];

    // fd1 = creat("creat.txt", 777);
    fd1 = open("creat.txt", O_RDWR | O_CREAT, 777);
    printf("File created with %d\n", fd1);

    fd2 = open("creat_new.txt", O_RDWR | O_CREAT | O_TRUNC, 777);
    printf("Opening a file with %d fd\n", fd2);

    write(fd1, write_buf, 50);

    lseek(fd1, 0, SEEK_SET);

    read(fd1, read_buf, 50);

    printf("Data: %s\n", read_buf);

    write(fd2, read_buf, 50);

    close(fd1);
    close(fd2);
    return 0;
}