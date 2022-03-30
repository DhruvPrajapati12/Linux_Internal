/*msg_snd*/

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

//# define KEY 8979

typedef struct
{
    long mtype;
    char data[100];
} msg;

int main(int argc, char *argv[])
{
    int qid, i;
    msg m1, m2;

    qid = msgget(32, IPC_CREAT | 0644);

    m1.mtype = 10;
    for (i = 0; i < 100; i++)
    {
        m1.data[i] = 'a';
        m2.mtype = 20;
    }
    for (i = 0; i < 100; i++)
    {
        m2.data[i] = 'b';
    }

    i = msgsnd(qid, &m1, sizeof(msg), 0);
    printf("Return value of msgsnd of As = %d\n", i);
    i = msgsnd(qid, &m2, sizeof(msg), 0);
    printf("Return value of msgsnd of Bs = %d\n", i);

    return 0;
}