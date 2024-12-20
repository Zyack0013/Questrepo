// 5.Given an integer n and a position p, write a program to toggle the bit at position p using the XOR operator.

#include <stdio.h>

int main(){

    int n,p,result;

    printf("Enter the integer : ");
    scanf("%d",&n);

    printf("Enter the position : ");
    scanf("%d",&p);

    result = n ^ (1 << p);

    printf("The result : %d ", result);

    return 0;
}