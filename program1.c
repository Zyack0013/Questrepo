// 1. Write a program to check if two integers provided by the user are equal or not.

#include <stdio.h>

int main(){

    int a,b;

    printf("Enter the first integer : ");
    scanf("%d",&a);

    printf("enter the second integer : ");
    scanf("%d",&b);

    if(a==b){
        printf("The two integers are equal");
    }else{
        printf("The two integers are not equal");
    }

    return 0;
}