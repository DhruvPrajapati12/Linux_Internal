// Demo code of read() system call

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    ssize_t len;
    char buf[1000]; // buf empty loct/memory
    fd = open("writefd.c", O_CREAT | O_RDWR, 777);
    len = read(fd, buf, 1000);
    printf("fd: %d\n", fd); // 3
    printf("bytes: %ld\n", len);
    if (fd < 0)
    {
        printf("file is not opened or created\n");
    }
    
    printf("read data from buffer: \n %s", buf);
    close(fd);
}