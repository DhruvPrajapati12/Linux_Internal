#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char s[20];
    int fd;

    mkfifo("newfifo11", 0644);       // newfifo11 is an pipe , file named pipe

    perror("mkfifo");

    printf("Before open() ...\n");
    fd = open("newfifo11", O_WRONLY);   // open a file for write only
    printf("After open()...\n");

    printf("Enter data...\n");  
    scanf("%s", s);
    write(fd, s, strlen(s)+1);      // std wt(); internally filewrite data 
  return 0;
}