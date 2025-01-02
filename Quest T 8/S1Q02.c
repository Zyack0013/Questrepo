// 2.Create a program where you declare a pointer to a float variable, assign a value to the variable, and then use the pointer to change the value of the float variable. Print both the original and modified values.

#include <stdio.h>

int main() {

    float a = 3.14;

    float *ptr = &a;

    printf("Orignal value = %.2f \nModified value = %.2f\n",a,*ptr+5);

}