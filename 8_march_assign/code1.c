// 1.Write a program using file operations that demonstrates copying of data from input file
// and write into output file, untill reaches end of file data.

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    int fd1, fd2;       // creating fds for files

    char write_buffer[50] = "Hello dhruv how are you";
    char read_buffer[50];

    fd1 = open("input.txt", O_RDWR | O_TRUNC | O_CREAT , 777);
    fd2 = open("output.txt", O_RDWR | O_TRUNC | O_CREAT , 777);

    write(fd1, write_buffer, 50);

    lseek(fd1, 0, SEEK_SET);

    read(fd1, read_buffer, 50);
    printf("data: %s\n", read_buffer);

    write(fd2, read_buffer, 50);


}