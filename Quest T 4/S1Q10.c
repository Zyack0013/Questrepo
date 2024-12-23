// 10.Find GCD of Two Numbers:
// Write a program to compute the GCD of two numbers using a while loop.


#include <stdio.h>

int main(){


    int a,b,r;

    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);

    if(a<0){
        a=-a;
    } 
    if(b<0){
         b=-b;
    }

    while(b!=0) {
        r = a%b;
        a = b;
        b = r;
    }

    printf("The GCD is: %d",a);

    return 0;
}
