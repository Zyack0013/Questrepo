// 4.Reverse a Number:
// Write a program to reverse a given number using a while loop.

#include <stdio.h>

int main(){

    int a,r,rev=0,temp;

    printf("Enter the number : ");
    scanf("%d",&a);

    temp=a;
    while(a!=0){

        r=a%10;
        rev= rev*10+r;
        a /= 10;
    }

    printf("The reverse of %d is %d",temp,rev);

    return 0;

}
