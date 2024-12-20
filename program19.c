//2. Toggle and Evaluate Bit Status:
//  Given an integer n and a bit position p:
// Use bit masking and bitwise XOR to toggle the bit at position p.
// After toggling, check if the updated number is positive (arithmetic and relational operators) and divisible by 2 (logical operators).


#include <stdio.h>


int main(){

    int n,p,result;

    printf("Enter the integer : ");
    scanf("%d",&n);

    printf("Enter the position : ");
    scanf("%d",&p);

    result = n ^ (1<<p);

    if(result == 0){
        printf("The number is Zero");
    }else
    if(result>0 && result%2==0){
        printf("The updated number is positive and divisible by 2");
    }else 
    if(result<0 && result%2==0){
        printf("The updated number is not positive but divisible by 2");
    }else 
    if(result>0 && result%2 != 0){
        printf("The updated number is positive but not divisible by 2");
    }else{
        printf("The updated number is not positive and not divisible by 2");
    }


    return 0;
    
}