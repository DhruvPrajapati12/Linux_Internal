#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    int sig_no;

    printf("Enter the pid of the process for which the signal need to be send: ");
    scanf("%d", &pid);

    printf("Enter the signal that need to be send: ");
    scanf("%d", &sig_no);

    kill(pid, sig_no);
    perror("Sig_res");
  return 0;
}