#include <stdio.h>
#include "header.h"

int main()
{

    double v1, v2, m1, m2;
    v1 = 5.2;
    v2 = 5.9;
    m1 = mean(v1, v2);
    m2 = sub(v1, v2);
    printf("The mean of %3.3f and %3.2f is %3.2f\n", v1, v2, m1);
    printf("The substraction of %3.3f and %3.2f is %3.3f\n", v1, v2, m2);
    printf("Hello Dhruv Prajapati\n");
  return 0;
}