// 5.Write a program that creates a file with a 4K bytes free space. 
// (Such files are called files with holes.)

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>


int main()
{
    char arr[4000];
    struct stat st;

    int fd;

    fd = open("hello.txt", O_CREAT | O_RDWR, 777);

    write(fd, arr, 4000);
    stat("hello.txt", &st);
    printf("size: %lu", st.st_size);

  return 0;
}