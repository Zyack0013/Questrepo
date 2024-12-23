// 3.Write a program to keep accepting numbers from the user and print them until the user enters zero.


#include <stdio.h>

int main(){

    int n;
    do{
        printf("Enter the number : ");
        scanf("%d",&n);
        printf("The entered number is %d\n",n);
    }while(n!=0);

    return 0;
}