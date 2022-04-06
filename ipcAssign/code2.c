// write a program that uses msgctl() and prints number of messages,number of bytes in
// message queue and also get Maximum number of bytes in queue for already existing
// message queue and also remove message queue at the end.

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
    long type;
    char messageData[100];
}message, message1;

struct msqid_ds structure;

int main()
{
    key_t key = 78;

    message.type = 2;
    strcpy(message.messageData, "Hello Dhruv Prajapati");

    message1.type = 3;
    strcpy(message1.messageData, "Linux Internals");

    int messageQueueId;
    messageQueueId = msgget(key, IPC_CREAT | 0644);

    if(messageQueueId < 0)
    {
        perror("msg");
        return 0;
    }
    else 
    {
        printf("Mesage Queue id: %d\n", messageQueueId);
    }

    size_t size;
    size = sizeof(message);

    int ret = msgsnd(messageQueueId, &message, size, 0);       // Send message to message queue.
    int ret1 = msgsnd(messageQueueId, &message1, sizeof(message1), 0);       // Send message to message queue.

    if(ret == 0)
        printf("Message1 send Successfully\n");

    if(ret1 == 0)
        printf("Message2 send Successfully\n");

    msgctl(messageQueueId, IPC_STAT, &structure);

    printf("Number of message in message Queue: %ld\n", structure.msg_qnum);
    printf("Number of bytes in message Queue: %ld\n", structure.__msg_cbytes);
    printf("Maximum Number of bytes in message Queue: %ld\n", structure.msg_qbytes);

    if(msgctl(messageQueueId, IPC_RMID, &structure) == 0)
    {
        printf("\nMessage Queue is deleted\n");
    }


    return 0;
}