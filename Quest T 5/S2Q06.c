// 6. Static Variable for Step Count in Loops
// Problem Statement: Create a program with a loop that increments by a variable step size. Use a static variable to count and retain the total number of steps taken across multiple runs of the loop.


#include <stdio.h>

static int scount;

void loop(int a, int b);

int main(){

    loop(20,2);

    loop(50,5);

    loop(5,1);

    loop(30,10);

    printf("Total number of steps : %d \n",scount);


    return 0;

}


void loop(int a, int b){

    int steps=0;

    for(int i=1;i<=a;i+=b){

        steps++;

    }

    printf("Count --> iteration - %d  steps - %d : %d \n",a,b,steps);

    scount += steps;

}