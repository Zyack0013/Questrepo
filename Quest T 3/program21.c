// 4.Set, Clear, and Check Specific Bit:
//  Write a program to:
// Use bit masking and bitwise OR to set a specific bit in a number.
// Use bitwise AND and NOT to clear another specific bit.
// Check if the resulting number is odd (arithmetic and relational operators) and lies within a range (logical operators).

#include <stdio.h>

int main(){

    int n,p1,p2,result;

    printf("Enter the integer : ");
    scanf("%d",&n);

    printf("Enter the specific bit position to set : ");
    scanf("%d",&p1);

    printf("Enter the specific bit position to clear : ");
    scanf("%d",&p2);

    result= n | (1<<p1);

    result = result & ~(1<<p2);

    if(result%2!=0 && 0<result<=100 ){
        printf("%d is a odd number and lies in between 1 and 100",result);
    }else 
    if(result%2==0 && 0<result<=100){
        printf("%d is even number and lies in between 1 and 100",result);
    }

    return 0;
}