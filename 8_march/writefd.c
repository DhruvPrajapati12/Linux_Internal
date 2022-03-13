// Demo code of write() system call

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int x;
    ssize_t len;

    char write_buf[90] = "Linux kernal new program ?, wow? hello dhruv";
    //char read_buf[50];    

    fd = open("linuxabc.txt", O_CREAT | O_RDWR | O_TRUNC, 777);

    len = write(fd, write_buf, 90); //writing from write_buf to linuxabc.txt

    printf("return value = %ld\n", len);
    close(fd);
    return 0;
}