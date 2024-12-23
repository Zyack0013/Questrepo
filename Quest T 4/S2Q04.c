// 4.Write a program to generate the first nnn terms of the Fibonacci series using a for loop.

#include <stdio.h>

int main(){

    int n,fib,a=0,b=1;

    printf("Enter the value of n : ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        if(i==1){
            printf("%d \n",a);
        }else
        if(i==2){
            printf("%d \n",b);
        }else{
            fib=a+b;
            a=b;
            b=fib;
            printf("%d \n",fib);
        }

    }
    return 0;

}