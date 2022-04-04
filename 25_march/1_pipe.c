#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2]; // p[0], p[1] indexes of subscriber of array p

    pipe(fd);    // fd0 ---p[0]rd end and fd1---p[1] wt end
    printf("read end of pipe = %d \t write end of pipe = %d\n", fd[0], fd[1]);

    int id = fork();
    if(id == 0)  // child
    {
        char buf[20];
        printf("In child...\n");
        read(fd[0], buf, sizeof(buf));
        printf("child pro printing.. Data of the parent process.. %s\n", buf);
    }
    else 
    {       // parent
        char s[20];
        printf("In parent Enter data: \n");
        scanf("%s", s);     // wait user enter "15+1"
        write(fd[1], s, strlen(s)+1);
    }

  return 0;
}
