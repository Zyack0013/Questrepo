// 4. Combining Global and Local Variables
// Problem Statement: Write a program that calculates the sum of a global variable and a local variable inside a function. Print the result and explain the variable scope in comments.


#include <stdio.h>

int a=10; //GV

void sum(void);

int main(){

    sum();

    return 0;

}

void sum(void){

    int b=20,sum; //LV having a scope within the function

    sum= a+b; // 'a' is gv and 'b' & 'sum' are LV, where 'a' having a scope till the end of the program execution

    printf("Sum = %d \n",sum);

}