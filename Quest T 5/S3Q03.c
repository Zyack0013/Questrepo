// 3. Nested Loops with const Limits
// Problem Statement: Use two const variables to define the limits of nested loops. Demonstrate how the values of the constants affect the total number of iterations.


#include <stdio.h>

int main(){

    int const ilimit=5,olimit=10;
    int count=0;

    for(int i=0;i<=olimit;i++){

        for(int j=0;j<=ilimit;j++){

            count++;
        }

    }

    printf("Total number of iteration = %d \n",count);
}