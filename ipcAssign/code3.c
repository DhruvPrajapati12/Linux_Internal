// Write a program parent process writing to pipe and child reading toggled data from pipe,
// and also analyse the data flow order from write end to read end.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

char* toggle(char str[])
{
    char* temp=str;
    int i;
    for(i=0; i<strlen(str); i++)
    {
        if(temp[i]>='A' && temp[i]<='Z')
            temp[i]=temp[i]+32;
        else if(temp[i]>='a' &&  temp[i]<='z')
            temp[i]=temp[i]-32;
    }
    temp[i] = '\0';
    return temp;
}

int main()
{
    pid_t id;
    int fds[2];     // fds[0] --> read, fds[1] --> write
    char readStr[100];

    id = getpid();
    printf("Parent process pid: %d\n", id);
    pipe(fds);

    printf("Enter the string do you want to toggle: ");
    // scanf("%s", readStr);
    gets(readStr);
    
    char str[100];

    if(fork() == 0)         // child
    {
        close(fds[1]);
        read(fds[0], str, strlen(readStr));
        printf("Toggle string is: %s\n", toggle(str));
        return 0;
    }
    else                    // parent
    {
        close(fds[0]);
        write(fds[1], readStr, strlen(readStr));
        wait();
    }

    
  return 0;
}