// 2. Prime Number Finder
// Problem Statement: Write a program to find all prime numbers between 1 and a given number N. Use:
// A const variable for the upper limit N.
// A static variable to count the total number of prime numbers found.
// Nested for loops for the prime-checking logic.
// Key Concepts Covered: Type qualifiers (const), Storage classes (static), Looping (for).



#include <stdio.h>

void prime(int const N);


int main(){

    int const N=100;
    prime(N);

    return 0;

}

void prime(int const N){

    static int count = 0; 
    printf("Prime numbers between 1 and %d are : \n",N);

    for(int i=2;i<=N;i++){

        int isP = 1;

        for(int j=2;j*j<=i;j++){

            if(i%j==0){

                isP = 0;
                break;

            }
        }
        if(isP){

            printf("%d ",i);
            count++;

        }
    }
    printf("\n Total number of prime numbers : %d\n",count);
}

