#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd;
    ssize_t len;

    char write_buf[50] = "hello dhruv prajapati qwertyuiop..!";
    char read_buf[50];

    fd = open("linux_kernal.txt", O_CREAT | O_RDWR | O_TRUNC, 777);
    len=write(fd, write_buf, 50);
    printf("Written value from write optn= %ld\n", len);

    // lseek(fd, 4, SEEK_SET);
    // lseek(fd, -50, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    read(fd, read_buf, len);
    printf("data from buffer(read optn) = %s\n", read_buf);
    close(fd);
}