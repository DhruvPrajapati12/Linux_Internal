// This code is example of file management and memory management

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

int main()
{

    int fd;
    char *c;
    struct stat file_info;

    fd = open("kernal.txt", O_CREAT | O_RDWR, 777);
    write(fd, "linux kernal programming", 25);

    fstat(fd, &file_info);
    printf("File size is %d\n", file_info.st_size);

    c = mmap(0, file_info.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    perror("mmap");

    printf("%s\n", c);  // no need of accessing system call for file read write

    munmap(c, file_info.st_size);
    close(fd);
    return 0;
}