// 2.Sum of Digits:
// Write a program to calculate the sum of the digits of a given integer using a while loop.


#include <stdio.h>

int main(){

    int a,i,sum=0;

    printf("Entr the digit : ");
    scanf("%d",&a);

    if(a<00){
        a= -a;
    }

     while(a>0){
        i = a % 10;  
        sum += i;      
        a /= 10;         
    }

    printf("The sum of digit : %d",sum);

}