// 7.Write a program to calculate the sum of squares of the first nnn natural numbers using a for loop.

#include <stdio.h>

int main(){

    int n,sum=0;

    printf("Enter the value of n : ");
    scanf("%d",&n);

    for(int i=0;i<=n;i++){
        sum += i*i;
    }

    printf("The sum of square of %d natural number is %d",n,sum);


    return 0;
}