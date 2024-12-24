// 3. Static Variable in Nested Loops
// Problem Statement: Use a static variable in a nested loop structure to count the total number of times the inner loop has executed across multiple runs of the program.

#include <stdio.h>

static int count=0;

void loop(void);

int main(){

    loop();

    loop();

    loop();

    loop();

    printf("Total count = %d \n",count);

    return 0;
}

void loop(void){

    for(int i=1;i<=10;i++){

        for(int j=1; j<=i;j++){

            count++;

        }
    }

}