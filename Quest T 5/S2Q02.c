// 2. Static Variable to Count Iterations
// Problem Statement: Use a static variable inside a loop to count the total number of iterations executed across multiple runs of the loop. Print the count after each run.


#include <stdio.h>

static int count=0;

void loop(void);

int main(){

    loop();
    loop();
    loop();
    loop();
    loop();

    printf("Total count of iterations = %d \n",count);

    return 0;
}


void loop(void){

    for(int i =1; i<=10;i++){

        count++;
    }

    
}