#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("File name: %s\n", argv[0]);
    printf("Total number of arguments: %d\n", argc);
    printf("Arguments passed: ");
    for(i = 0; i<argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}