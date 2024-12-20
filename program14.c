// 4.Write a program to find the bitwise complement of a given integer and print the result.

#include <stdio.h>

int main(){

    int a,result;

    printf("Enter the integer : ");
    scanf("%d",&a);

    result = ~a;

    printf("The result : %d",result);
    return 0;
}