// 1.Write a program to check if a number entered by the user is positive using an if statement.


#include <stdio.h>

int main(){

    int a;
    printf("Enter the number : ");
    scanf("%d",&a);

    if(a>0){
        printf("%d is a positive number",a);
    }
    else{
        printf("%d is not a positive number",a);
    }
    return 0;
}