// Demo code of command line arguments

// Command line argument is the arguments that are passed to the main function(./a.out hello dhruv)

#include <stdio.h>

int main(int argc, char *argv[])        //argc = total no of args, argv stores all parameters
{
    printf("File name: %s\n", argv[0]); //a.out
    printf("Tital no of args: %d\n", argc);

    printf("Args passed: \n");
    for(int i=0; i<argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    printf("\n");
}