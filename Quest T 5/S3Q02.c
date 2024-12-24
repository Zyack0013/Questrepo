// 2. const Variable as a Loop Limit
// Problem Statement: Declare a const integer variable as the upper limit of a loop. Write a loop that runs from 0 to the value of the const variable and prints the iteration count.


#include <stdio.h>

int main(){

    int const limit=10;
    int count;


    for(int i=0;i<=limit;i++){

        printf("%d ",i);
        count++;
    }
    printf("\n");

    printf("Total no of iteration : %d",count);

    

    return 0;
}