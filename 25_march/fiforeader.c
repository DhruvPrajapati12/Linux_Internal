#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// DOUBT Not working

int main()
{
    char s[20];
    int fd;

    mkfifo("newfifo11", 0644);       // newfifo11 is an pipe , file named pipe

    perror("mkfifo");

    printf("Before open() ...\n");
    fd = open("newfifo11", O_RDONLY);   // open a file for read only
    printf("After open()...\n");

    read(fd, s, sizeof(s));      // read data from fifo 
    printf("Data: %s\n", s);
  return 0;
}