#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

union semnum
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};

int get_release(void);
int get_semaphore(void);
int sem_id;

struct sembuf sem_op;
union semnum sem_union;

int main()
{
    int i, j;
    sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);

    for (i = 0; i <= 10; i++)
    {
        get_semaphore();
        printf("\nSEM2 : %d : got the semafore\n", getpid());
        for (j = 0; j <= 3; j++)
        {
            sleep(1);
            printf("\a");
        }

        printf("\nSEM2 : %d : release the semaphore\n", getpid());
        get_release();
        sleep(2);
    }
    if (semctl(sem_id, 0, IPC_RMID, sem_union) < 0)
        printf("Unable to delete semaphore\n");
    else
        printf("Semaphore deleted\n");
}

int get_semaphore(void)
{
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_op, 1) < 0)
    {
        printf("Failed to get the semaphore\n");
        return -1;
    }
    return 0;
}

int get_release(void)
{
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_op, 1) < 0)
    {
        printf("Failed to release the semaphore\n");
        return -1;
    }
    return 0;
}