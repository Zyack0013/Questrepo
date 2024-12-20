// 2.Write a program to check if a number is divisible by 3 using an if statement.

#include <stdio.h>

int main(){

    int a;

    printf("Enter the number : ");
    scanf("%d",&a);

    if(a%3==0){
        printf("%d is divisible by 3",a);
    }else{
        printf("%d is not divisible by 3",a);
    }


    return 0;
}