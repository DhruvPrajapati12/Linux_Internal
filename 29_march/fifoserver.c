#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    printf("Server - listening\n");

    // create fifo
    int code = mkfifo("cli_ser_fifo", 0764);
    if(code == -1)
        perror("mkfifo returned an error - file may already exist");
    
    // open read end

    int fd = open("cli_ser_fifo", O_RDONLY);
    if(fd == -1)
    {
        perror("Cannot open FIFO for read\n");
        return 0;
    }

    printf("FIFO Open\n");

    // Read string(upto 100 characters)

    char serverrcv[100];        // sttring buffer
    memset(serverrcv, 0, 100);  // set ser buff with zeros      // DOUBT

    int res;
    char len;

    while(1)        // DOUBT
    {
        res = read(fd, &len, 1);
        if(res == 0)
        {
            break;  
        }
        read(fd, serverrcv, len);       // read string characters
        printf("Server received: %s\n", serverrcv);
    }

    printf("EOF reached\n");
    close(fd);
    printf("FIFO closed\n");

    return 0;
}