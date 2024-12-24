// 6. const Variable in Conditional Loops
// Problem Statement: Use a const variable as a termination condition for a while loop. The loop should terminate when the iteration count reaches the value of the const variable.


#include <stdio.h>

int main(){

    int const a=10;
    int i=0;

    while(i<=a){

        printf("Iteration = %d\n",i+1);
        i++;
    }

    printf("Loop stops!!!");

    return 0;
}