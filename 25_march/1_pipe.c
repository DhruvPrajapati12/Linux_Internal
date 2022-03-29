#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int p[2]; // p[0], p[1] indexes of subscriber of array p

    pipe(0);    // fd0 ---p[0]rd end and fd1---p[1] wt end
    printf("read end of pipe = %d \t write end of pipe = %d\n", p[0], p[1]);

    if(fork())  // parent
    {
        char s[20];
        printf("In parent Enter data: \n");
        scanf("%s", s);     // wait user enter "15+1"
        write(p[1], s, strlen(s)+1);
    }
    else 
    {       // child
        char buf[20];
        printf("In child...\n");
        read(p[0], buf, sizeof(buf));
        printf("child pro printing.. Data of the parent process.. %s\n", buf);
    }

  return 0;
}