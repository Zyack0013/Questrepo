// 3.Write a program to determine if a number is odd or even using an if-else statement.

#include <stdio.h>

int main(){

    int a;

    printf("Enter the number : ");
    scanf("%d",&a);

    if(a==0){
        printf("The number is zero");
    }else if(a%2==0){
        printf("%d is even",a);
    }else{
        printf("%d is odd",a);
    }

    return 0;
}