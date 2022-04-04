#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void toggleCase(char *buf, int cnt);

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    // struct sembuf smop;
    struct seminfo *__buf;
};

union semun sem_union;

int main()
{
    int semId, shmId;
    char *pShm;
    struct sembuf smop;

    // create a semaphore set, containing two semaphores

    semId = semget(MY_KEY, 1, 0660 | IPC_CREAT);

    if(semId < 0)
    {
        printf("Could not create semaphore\n");
        return(1);
    }
    else
    {
        printf("Opended a semaphore ID is %d\n", semId);
    }

    // set initial token count of both semaphores to zeros

    semctl(semId, 0, SETVAL, 0);

    // create a shared memory segment
    shmId = shmget(MY_KEY, SHM_SIZE, 0660 | IPC_CREAT);

    if(shmId < 0)
    {
        printf("Could not create shared segment\n");
        return(2);
    }
    
    // attach a shared mem segment to process address space

    pShm = shmat(shmId, NULL, 0);
    if(!pShm)
    {
        printf("Could not attach shared mem segment\n");
        return(3);
    }

    while(1)
    {
        // server initiated i am waiting for a client connection until client conntected to the server
        // server is set to be blocking call and therefor while(1)
        
        // wait for a token from semaphore

        smop.sem_num = 0;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);

        // process the message available in shared mem
        printf("Got the semaphore\n");
        stpcpy(pShm+256, pShm);
        toggleCase(pShm+256, strlen(pShm+256));
        printf("Process the request message and placed response\n");

        // send token to semaphore 1

        smop.sem_num = 1;
        smop.sem_op = 1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);
    }
    return 0;
}

void toggleCase(char *buf, int cnt)
{
    int li;

    for(li=0; li<cnt; li++)
    {
        if(buf[li] >= 'A' && buf[li] <= 'Z')
            buf[li] += 0x20;
        else if(buf[li] >= 'a' && buf[li] <= 'z')
            buf[li] -= 0x20;
    }
}