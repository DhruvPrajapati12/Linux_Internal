#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct msg_buffer
{
    long msg_type;      // not use int
    char msg_text[100];
}message;

int main()
{
    key_t key;
    int msg_id;
    char text[100];

    // key = ftok("progfile", 65);     // ftok to generate unique key

    msg_id = msgget(45, IPC_CREAT | 0777);

    message.msg_type = 1;

    printf("Enter the data: ");
    scanf("%s", text);
    strcpy(message.msg_text, text);
    printf("Message to be send: %s\n", message.msg_text);
    msgsnd(msg_id, &message, sizeof(message), 0);


    message.msg_type = 2;

    printf("Enter the data: ");
    scanf("%s", text);
    strcpy(message.msg_text, text);
    printf("Message to be send: %s\n", message.msg_text);
    msgsnd(msg_id, &message, sizeof(message), 0);
    return 0;
}


// When we push(send function) data into Message Queue. the data is stored in the message
// queue. When we use msgrcv function data with given type is pulled from messge queue
