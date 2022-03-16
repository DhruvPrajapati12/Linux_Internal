#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{

    char *c;

    c = mmap(0, 50, PROT_READ | PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);  //msg success
    perror("mmap");

    strcpy(c, "linuxkernal");   // kernel region in US
    printf("%s\n", c);

    // deallocate all resource
    munmap(c, 50);  //malloc after free

  return 0;
}