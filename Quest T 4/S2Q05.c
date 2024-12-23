// 5.Write a program to check if a given number is prime using a for loop.

#include <stdio.h>

int main(){

    int n,p=0;

    printf("Enter the number : ");
    scanf("%d",&n);

    if(n<=1){
        printf("%d is not a prime number",n);
    }else{

        for(int i=2;i<=n;i++){

            if(n%i==0){
                p++;
            }
        }
        if(p>=2){
            printf("%d is not a prime number",n);
        }else{
            printf("%d is  a prime number",n);
        }
    }

    return 0;
}