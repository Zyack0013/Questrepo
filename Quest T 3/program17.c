// 7.Write a program to clear (set to 0) the bit at a given position p in an integer n using the AND and NOT operators.

#include <stdio.h>

int main(){

    int n,p,result;

    printf("Enter the integer : ");
    scanf("%d",&n);

    printf("Enter the position : ");
    scanf("%d",&p);

    result = n & ~(1<<p);

    printf("The result : %d", result);

    return 0;
}