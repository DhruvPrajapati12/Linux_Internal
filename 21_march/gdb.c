#include <stdio.h>
#include <string.h>

void print(char *msg)
{
    if (msg != NULL)
    {
        printf("msg: %s\n", msg);
    }
    
}

int main()
{
    char buff[] = "Linux";
    print(NULL);

  return 0;
}