//  2.Write a program to determine which of two numbers is greater using relational operators.

#include <stdio.h>

int main(){

    int a,b;

    printf("Enter two numbers : ");
    scanf("%d \n %d",&a,&b);

    if(a>b){
        printf("%d is greater than %d",a,b);
    }else{
        printf("%d is greater than %d",b,a);
    }

    return 0;
}