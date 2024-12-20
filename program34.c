// 2.Write a program to perform basic arithmetic operations (addition, subtraction, multiplication, division) based on the operator input (+, -, *, /) using a switch-case statement.

#include <stdio.h>

int main(){

    int a,b;
    char op;
    printf("Enter the operator : ");
    scanf("%c",&op);
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    

    switch(op){
        case '+':
        printf("%d + %d : %d ",a,b,a+b);
        break;
        case '-':
        printf("%d - %d : %d ",a,b,a-b);
        break;
        case '*':
        printf("%d * %d : %d ",a,b,a*b);
        break;
        case '/':
        if(b!=0){
            printf("%d / %d : %d ",a,b,a/b);
        }else{
            printf("Can't divide by zero");
        }
        break;
        default:
        printf("Invalid operator");
        break;
    }
    return 0;

}