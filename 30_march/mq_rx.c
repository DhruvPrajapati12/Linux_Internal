/*msgrcv*/ 
#include<stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

typedef struct
{
    long mtype;
    char data[100];
}msg;

int main()
{
    int qid, i;
    msg m1, m2;
    qid = msgget(32, IPC_CREAT | 0644);
    i = msgrcv(qid, &m1, sizeof(msg), 10, 0);
    for (i = 0; i < 100; i++)
    {
        printf("%c", m1.data[i]);
    }
    i = msgrcv(qid, &m2, sizeof(msg), 20, 0);
    for (i = 0; i < 100; i++)
    {
        printf("%c", m2.data[i]);
    }
    printf("\n");
    return 0;
}
