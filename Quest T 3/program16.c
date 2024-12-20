// 6.Write a program to set the bit at a given position p in an integer n to 1 using the OR operator.

#include <stdio.h>

int main(){

    int n,p,result;

    printf("Enter the integer : ");
    scanf("%d",&n);

    printf("Enter the position : ");
    scanf("%d",&p);

    result = n | (1<<p);

    printf("The result : %d",result);

    return 0;
}