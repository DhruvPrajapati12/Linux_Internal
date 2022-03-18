// 5.Write a program parent process wait untill ,while child process open a file and read file
// data into empty buffer.

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    printf("main program starts here\n");

    printf("Child process created\n");

    if(fork() == 0)     // create child process
    {
        int fd;
        char read_buffer[100];

        fd = open("data.txt", O_RDONLY, 777);

        if(fd == -1)
        {
            printf("something went wrong\n");
        }
        printf("Child process read the data\n");
        read(fd, read_buffer, 100);     // read data.txt file

        printf("Data in buffer: %s\n", read_buffer);
        close(fd);
        exit(0);
    }
    else 
    {
        wait(0);
    }

    printf("main program ends here\n");

  return 0;
}