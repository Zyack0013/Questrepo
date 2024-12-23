// 3.Write a program to calculate the factorial of a given number using a for loop.

#include <stdio.h>

int main(){

    int n,fac=1;

    printf("Enter the number : ");
    scanf("%d",&n);

    if(n<0){
        printf("There is no factorial for negitive numbers");
    }else{
        for(int i=1;i<=n;i++){

            fac *=i;
        }
        printf("The factorial of %d is %d",n,fac);
    }


    return 0;
}