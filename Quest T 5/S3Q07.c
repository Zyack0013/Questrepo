// 7. const and Immutable Loop Step Size
// Problem Statement: Declare a const variable as the step size of a for loop. Use this step size to iterate through a range of numbers and print only every nth number.

#include <stdio.h>

int main(){

    int const step =5;

    for(int i=0; i<= 50;i+=step){

        printf("%d\n",i);
    }

    return 0;

}