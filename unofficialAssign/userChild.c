#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Parent process id: %d\n", getpid());

    int id;
    int n;

    printf("Enter the how many child process do you want to create: ");
    scanf("%d", &n);

    for(int i = 0; i<=n-1; i++)
    {
        id = fork();

        if(id == 0)
        {
            printf("I am child process %d my child process id: %d and parent process id: %d\n", i+1, getpid(), getppid());
            return 0;
        }
        else 
        {
            sleep(0.1);
            continue;
        }
    }


    // if(id == 0)
    // {
    //     printf("I am child\n");
    // }
    // else 
    // {
    //     printf("I am parent\n");
    //     // sleep(1);
    // }

    // printf("Parent \n");

    return 0;
}