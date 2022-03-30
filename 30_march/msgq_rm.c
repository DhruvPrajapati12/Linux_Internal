/*msg_snd*/

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

int main()
{
    int qid;
    struct msqid_ds buf;
    qid = msgget(49, IPC_CREAT|0644);
    printf("qid: %d\n", qid);

    msgctl(qid, IPC_RMID, NULL);
    // printf("Here are the details of the queue\n");
    // printf("no of msg in q %li\n", buf.msg_qnum);

    // printf("max no of bytes in q %li\n", buf.msg_qbytes);
    
    return 0;
}