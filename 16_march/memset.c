#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "linuxkernal.com";
    char ch = '#';

    printf("String before initialization: %s\n", str);

    memset(str, ch, strlen(str));   // fun & array name itself is address

    // memset(str, ch, 4);     // ####xkernal.com

    printf("String after set is %s\n", str);

  return 0;
}
