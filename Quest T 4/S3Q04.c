// 4.Write a program to read integers from the user and compute their sum. Stop when the user enters a negative number.

#include <stdio.h>

int main(){

    int n,sum=0;

    do{
        printf("Enter the integer : ");
        scanf("%d",&n);

        if(n>=0){
            sum += n;
        }
    }while(n>=0);

    printf("The sum = %d \n",sum);

    return 0;
}