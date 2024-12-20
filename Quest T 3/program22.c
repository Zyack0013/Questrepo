// 5.Custom Mathematical Condition with Bits:
//  Given two integers a and b, perform the following:
// Compute their sum and product (arithmetic operators).
// Verify if the sum is greater than 100 and the product is divisible by 4 (relational and logical operators).
// Check if the binary representation of a has its second bit set (bitwise AND with a mask).

#include <stdio.h>

int main(){

    int a,b,sum,prod,result;

    printf("Enter the number a : ");
    scanf("%d",&a);

    printf("Enter the number b: ");
    scanf("%d",&b);

    sum= a+b;
    prod=a*b;

    printf("The sum of %d and %d is : %d \n",a,b,sum);

    printf("The product of %d and %d is : %d \n",a,b,prod);

    if(a & 4){
        printf("The second position of %d is set \n",a);
    }else{
        printf("The second position of %d is not set \n",a);
    }

    if(sum>100 && prod%4==0){
        printf("The sum is greater than 100 and the product is divisible by 4");
    }else
      if(sum>100 && prod%4!=0){
        printf("The sum is greater than 100 but the product is not divisible by 4");
    }else
      if(sum<=100 && prod%4==0){
        printf("The sum is not greater than 100 but the product is divisible by 4");
    }else{
        printf("The sum is not greater than 100 and the product not divisible by 4");
    }

    return 0;
}