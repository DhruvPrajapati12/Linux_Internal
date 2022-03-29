#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    printf("Client process writing\n");

    char clientmsg[] = "Linux system kernal programming";

    // open fifo for writing

    int fd = open("cli_ser_fifo", O_WRONLY);

    if(fd == -1)
    {
        perror("Cannot open fifo");
        return EXIT_FAILURE;
    }

    write(fd, clientmsg, strlen(clientmsg));
    close(fd);
    return 0;
}