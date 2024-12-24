//  Global Variable for Shared State
// Problem Statement: Write a program that uses a global variable as a counter. Multiple functions should increment the counter and print its value. Demonstrate how global variables retain their state across function calls.

#include <stdio.h>

int count = 0;

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);

int main(){


    fun1();
    fun2();
    fun3();
    fun4();


    return 0;

}


void fun1(void){

    count++;
    printf("Current value of GV is %d \n",count);
}

void fun2(void){

    count++;
    printf("Current value of GV is %d \n",count);
}
void fun3(void){

    count++;
    printf("Current value of GV is %d \n",count);
}
void fun4(void){

    count++;
    printf("Current value of GV is %d \n",count);
}