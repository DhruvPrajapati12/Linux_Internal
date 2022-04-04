#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    int id;

    union semun
    {
        // data 

        int val;
        struct semid_ds *buf;
        ushort *array;
    };
    

    return 0;
}