#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/msg.h>

struct msgbuf
{
    long mtype;
    char data[512];
};

int main(int argc, char **argv)
{
    int id;
    struct msgbuf v;

    if (argc != 2)
    {
        printf("usage: ./mq_rx type\n");
        printf("Example: mq_rx S\n");
        return 0;
    }

    id = msgget(55, IPC_CREAT | 0644);

    if (id < 0)
    {
        perror("msgget");
        return 0;
    }

    msgrcv(id, &v, sizeof(v), atoi(argv[1]), 0);
    printf("Data %s\n", v.data);
    return 0;
}