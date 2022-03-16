#include <stdio.h>
#include <string.h>

int main()
{
    char buf1[10];
    char buf2[10];
    int ret;

    memcpy(buf1, "madam", 5);   // madam-----97---108
    memcpy(buf2, "mad", 5); //mad------65----76

    ret = memcmp(buf1, buf2, 7);

    if(ret > 0)
    {
        printf("buf greter than buf2\n");
    }
    else if(ret < 0)
    {
        printf("buf1 is less than buf2\n");
    }
    else 
    {
        printf("buf1 is equal to buf2\n");
    }
  return 0;
}