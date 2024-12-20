// 1.Number Properties Validation:
//  Write a program to check if a given integer is both a multiple of 5 (arithmetic operator) and greater than 50 (relational operator). Additionally, verify if its binary representation has its least significant bit set (bitwise AND operation).

#include <stdio.h>

int main(){

    int n;

    printf("Enter the integer : ");
    scanf("%d",&n);

    if(n%5==0 && n>50){

        printf("%d is both a multiple of 5 and greater than 50 \n",n);
        
    }else 
    if(n%5 != 0 && n>50){
        printf("%d is not a multiple of 5 but is greater than 50 \n",n);
    }else 
    if(n%5==0 && n<=50){
        printf("%d is a multiple of 5 but is less than or equal to 50 \n",n);
    }else{
        printf("%d is not a multiple of 5 and is less than 50 \n",n);
    }

    if(n&1){
        printf("The LSB of  %d is set",n);
    }else{
        printf("The LSB of %d is not set",n);
    }



    return 0;
}