// 1.Write a C program that declares an integer pointer, initializes it to point to an integer variable, and prints the value of the variable using the pointer.

#include <stdio.h>

int main(){

    int a= 10;
    int * ptr = &a;

    printf("The value of a = %d",*ptr);

    return 0;
}