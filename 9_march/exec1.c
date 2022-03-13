#include <stdio.h>
#include <unistd.h>

void main()
{
    printf("I am going to execute an ls program\n");

    execl("/bin/ls", "ls", "-lh", 0);   //execl is used to executed shell commands in bin directory

    // execl("/home/dhruv/Desktop/Linux_Internal/9_march", "./dup1", 0 );

    printf("i executed ls program\n");
    printf("i executed ls program\n");
    printf("i executed ls program\n");

    // int ret;
    // ret = execl("/usr/bin/vim", "vim", "info1.txt", 0);
    // if(ret == -1)
    //     printf("Execl returned error %d\n", ret);
}