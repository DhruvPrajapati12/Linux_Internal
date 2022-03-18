// 3. A program that replaces old program with new program data and is expected to display
// the currently running processes in a hierarchical tree format.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main()
{

    printf("main program starts here\n");   // this part should be executed

    execl("/usr/bin/pstree", "pstree", NULL);

    printf("This part should not be executed\n");

  return 0;
}