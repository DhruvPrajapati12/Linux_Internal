#include <stdio.h>
#include <string.h>

int main()
{
    const char str[] = "linuxkernal.com";
    char ch = '.';
    char *ret;

    printf("String before char/scan: %s\n", str);

    ret = memchr(str, ch, strlen(str));

    printf("String after *%c* is -- *%s*", ch, ret+1);

  return 0;
}