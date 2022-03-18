#include <stdio.h>
#include "cal_mean.h"

int main()
{

    double v1, v2, m1, m2;
    v1 = 5.2;
    v2 = 5.9;
    m1 = mean(v1, v2);
    m2 = sub(v1, v2);
    printf("The mean of %3.3f and %3.2f is %3.2f\n", v1, v2, m1);
    printf("The substraction of %3.3f and %3.2f is %3.3f\n", v1, v2, m2);
  return 0;
}

// AR is archived tool , a linux command unitilty tool that is 
// used to generrate shared library

// RCS is stands for replace create and symbol

// .a is for static library extention
// symbol is nothing but combination of variables and function and its a standard to 
