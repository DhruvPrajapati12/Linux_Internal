// write a program that creates a shared memory region and displays shared memory id
// and also print address at which shared area in this process starts from.

#include <stdio.h>
#include <sys/shm.h>

int main()
{
    key_t key = 37;
    size_t size = 200;
    int memoryId = shmget(key,size, IPC_CREAT | 0644 | SHM_RDONLY);     // create a shared memory segment in KS
    if(memoryId < 0)
    {
        perror("shmget");
        return 0;
    }
    else 
    {
        printf("Shared memory id: %d\n", memoryId);
    }

    void* address;
    address = shmat(memoryId, 0, SHM_RDONLY);   // Attach shared memory segment.

    printf("Successfully attached memory segment to Process address space\n");
    printf("Address: %p\n", address);
    
    int success = shmdt(address);   // Detach shared memory segment.

    if(success == 0)
    {
        printf("Successfully dettached memory segment from Process address space\n");
    }
    // printf("Address: %p\n", address);
    return 0;
}