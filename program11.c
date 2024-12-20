// 1.Write a program to compute the result of the bitwise AND operation between two integers provided by the user

#include <stdio.h>

int main(){

    int a,b,result;

    printf("Enter the two integers : ");
    scanf("%d \n %d",&a,&b);
    result = a & b;

    printf("The result : %d", result);

    return 0;

}