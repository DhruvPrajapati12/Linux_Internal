#include <stdio.h>
#include <string.h>

void my_mam_cpy(char *src, char *dest, size_t nbytes)
{
    // strcpy(dest, src);
    for(int i=0; i<=nbytes; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}

int main()
{
    char str1[11] = "Goodmorning";
    char str2[11];

    // printf("Str1: %s Str2: \n", str1, str2);
    my_mam_cpy(str1, str2, strlen(str1));
    printf("Str1: %s Str2: %s\n", str1, str2);

  return 0;
}