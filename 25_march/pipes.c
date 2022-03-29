#include <stdio.h>
#include <unistd.h>

int main()
{
    int fds[2];
    int res;

    char *buf1 = "aaaaaaaaaaaaaaa";
    char *buf = "bbbbbbbbbbbbbbb";
    int len1 = strlen(buf1);
    int len2 = strlen(buf);
    char buf2[len1+len2];
    res = pipe(fds);

    // fd[0] for reading and fds[1] is for writing

    if(res == -1)
    {
        perror("pipe");
        exit(1);
    }

    write(fds[1], buf1, len1);
    write(fds[1], buf, len2);
    read(fds[0], buf2, len1+len2);

    for(int i=0; i<len1+len2; i++)
    {
        printf("%c", buf2[i]);
    }
    printf("\n");

    return 0;
}