// 1. Static Variable in a Loop
// Problem Statement: Write a program that uses a static variable inside a loop to keep track of the cumulative sum of numbers from 1 to 10. The loop should run multiple times, and the variable should retain its value between iterations.


#include <stdio.h>

void sum(void);

int main(){

    printf("First call : \n");
    sum();

    printf("Second call : \n");
    sum();

    printf("Third call : \n");
    sum();

    printf("Fourth call : \n");
    sum();
    

    return 0;
}

void sum(void){

    static int tsum=0;

    for(int i=1; i<=10;i++){

        tsum += i;

    }

    printf("Sum = %d \n",tsum);

}