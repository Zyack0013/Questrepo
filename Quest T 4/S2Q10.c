// 10.Write a program to count the divisors of a given number using a for loop.


#include <stdio.h>

int main(){

    int n, count=0;

    printf("Enter a number : ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        if(n%i == 0){  
            count++;  
        }
    }

    printf("The number of divisors of %d is : %d",n,count);

    return 0;
}
