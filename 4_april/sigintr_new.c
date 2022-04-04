// #include <stdio.h>
// #include <signal.h>

// void sighand(int signal)
// {
//     printf("Interrupt signal rec'd.. but no termination on ctrl + c\n");

//     if(signal == SIGINT)
//         printf("Received a SIGINT signal\n");
//     exit(0);
// }

// int main()
// {
//     signal(SIGINT, sighand);    // register singal handlar

//     for(int i=0; ; i++)
//     {
//         printf("%d\n", i);
//         sleep(1);
//     }

//   return 0;
// }

    /*catch signals*/ 
#include<signal.h>
#include <stdio.h> //1st option
    // void sighand(int signum)
    // {
    // printf("I have to wakeup my boss now\n");
    // //alarm(5);
    // //printf("%d\n",signum);
    // if(signum==2)
    // {
    // printf("Signal is: SIGINT\n");
    // }
    // }// 2nd option
    void sighand(signal)
{
    if (signal == SIGINT)
    {
        printf("\nSIGINT signal is received\n");
    }
}
int main()
{
    signal(SIGINT, sighand);
    while (1)
        ;
    return 0;
}
