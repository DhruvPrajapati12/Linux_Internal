#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd;

    mkfifo("newfifo", 0666);

    char arr1[100], arr2[100];
    while (1)
    {
        fd = open("newfifo", O_WRONLY);

        fgets(arr2, 100, stdin);

        write(fd, arr2, strlen(arr2) + 1);
        close(fd);

        // write the input arr2 string from user
        fd = open("newfifo", O_RDONLY);

        // open fifo for read only
        read(fd, arr1, sizeof(arr1));

        // print the read message
        printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}

// fiford//