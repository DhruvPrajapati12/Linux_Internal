#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buff_comm[9];
    stpcpy(buff_comm, "ls -l");

    printf("system() library function uses fork() to create a child process\n");
    printf("child process executes execl() which loads and run new program provided by system() argument\n");
    printf("%d\n", system(buff_comm));  // shell busy che
    printf("%d\n", system(NULL));   // shell navro che
    return 0;
}