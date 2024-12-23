// 10.Write a program to count the n of digits in a n entered by the user using a do-while loop.


#include <stdio.h>

int main(){

    int n, count = 0;

    printf("Enter a number : ");
    scanf("%d",&n);
    
    if(n==0){

        count = 1;

    }else{
        
        while(n!=0){
            n /= 10;  
            count++;      
        }
    }

    printf("The number has %d digit(s).",count);

    return 0;
}
