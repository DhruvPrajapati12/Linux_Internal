// Write a program where a structure of information passed to pthread 
// task function, and display  structure of information.                 

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

struct student
{
    int rollNo;
    char name[50];
    char branch[50];
};

void* function(void *args)
{
    printf("Thread starts executing....\n");
    struct student *s = (struct student*)args;
    for(int i=0; i<2; i++)
    {
        printf("Rollno: %d\tName: %s\tBranch: %s\n", s[i].rollNo, s[i].name, s[i].branch);
        // s++;
    }
    printf("Thread execution ends here...\n");
    return NULL;
}

void main()
{
    pthread_t tid;

    struct student sd[2];

    sd[0].rollNo = 21;
    strcpy(sd[0].name, "Dhruv Prajapati");
    strcpy(sd[0].branch, "Computer");
    
    sd[1].rollNo = 22;
    strcpy(sd[1].name, "Satyam Prajapati");
    strcpy(sd[1].branch, "Electrical");


    printf("In Main program\n");

    pthread_create(&tid, NULL, function, sd);
    pthread_join(tid, NULL);

    printf("Main ends here...\n");
}