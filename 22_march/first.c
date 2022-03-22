#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[40], gender;
    float height;
}first;




int main()
{

    struct student second;  // declaring structure
    struct student third = {103, "Dhruv", 'M', 5.11};   // declaring and initializing structure variables

    printf("\n Roll\tname\t\t\t\t\t\tGender\tHeight\n");
    first.roll = 101;
    strcpy(first.name, "Om Patel");
    first.gender = 'F';
    first.height = 5.6;

    printf("\n %3d\t%-40s\t%c\t%1.2f", first.roll,first.name, first.gender, first.height);
    printf("\n %3d\t%-40s\t%c\t%1.2f", third.roll,third.name, third.gender, third.height);
    printf("\n");
    return 0;
}