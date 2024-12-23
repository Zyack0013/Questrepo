// 9.Sum of Series:
// Write a program to calculate the sum of the series:
// S=1+2+3+…+n
// using a while loop.

#include <stdio.h>

int main(){

    
    int n,i=1,sum=0;

    printf("Enter the value of n : ");
    scanf("%d",&n);

    while(i<=n){
        sum += i;
        i++;     
    }

    printf("The sum of the series is : %d",sum);

    return 0;
}