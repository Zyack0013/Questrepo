// 1. Using const for Read-Only Array
// Problem Statement: Declare an array of integers as const and use a loop to print each element of the array. Attempt to modify an element inside the loop and explain the result.


#include <stdio.h>

int main(){

    int const arr[]={1,2,3,4,5,6,7};

    for(int i=0;i<7;i++){

        printf("The %dth element is : %d\n",i+1,arr[i]);   
        
    }

    // arr[1] = 5; --> can not be modify


    return 0;
}