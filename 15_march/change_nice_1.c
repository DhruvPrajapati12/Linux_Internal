#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int ret, cnt=0;

    errno = 0;

    ret = nice(1);
    if(ret == -1 && errno != 0)
    {
        perror("nice");
    }
    else 
    {
        printf("nice value is now %d\n", ret);
    }

    while(1)
    {
        printf("Process with nice value %d count = %d\n", ret, cnt);
        for(int i=0; i<1000000; i++)
        {
            cnt++;
        }
    }
}

// duel core ====> make use of only one cpu... on one cpu I execute 2 process...
// Nice value same ...each process 50% slice time