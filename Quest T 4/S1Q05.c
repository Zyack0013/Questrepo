// 5.Count Digits in a Number:
// Write a program to count the number of digits in an integer using a while loop.


#include <stdio.h>

int main(){

    int a,count,temp;

    printf("Enter the number : ");
    scanf("%d",&a);

    temp=a;

    if(a==0){
        count = 1;
    }else{

        while(a!=0){
            a /= 10;
            count++;
        }

    }
    

    printf("The number of digit in %d is %d",temp,count);

    return 0;
}