// write a program that uses msgctl() and prints number of messages,number of bytes in
// message queue and also get Maximum number of bytes in queue for already existing
// message queue

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
    long type;
    char messageData[100];
}message;


int main()
{
    key_t key = 78;

    int messageQueueId;
    messageQueueId = msgget(key, IPC_CREAT | 0644);

    size_t size;
    size = sizeof(message);
    ssize_t recMessage;

    recMessage = msgrcv(messageQueueId, &message, size,2 ,0);       // Send message to message queue.

    printf("Message received data: %s\n", message.messageData);

    return 0;
}