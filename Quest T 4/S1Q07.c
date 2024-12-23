// 7.Check Palindrome Number:
// Write a program to check if a number is a palindrome using a while loop.

#include <stdio.h>

int main(){

     int n,temp,rn = 0,r;

   
    printf("Enter the number : ");
    scanf("%d", &n);

    
    temp = n;

    while(n != 0){
        r = n % 10;               
        rn = rn * 10 + r; 
        n /= 10;                          
    }

    
    if(temp == rn){
        printf("%d is a palindrome",temp);
    }else{
        printf("%d is not a palindrome",temp);
    }

    return 0;   
}