// 6. Shadowing Global Variables
// Problem Statement: Write a program where a local variable in a function shadows a global variable with the same name. Use the global scope operator to access the global variable and print both values.

#include <stdio.h>

int a=10;

void fun(void);

int main(){


    fun();

    return 0;

}

void fun(void){

    int a=30;

    printf("Local variable is %d\n",a);

    {
        extern int a;      
        printf("Global variable is %d\n",a);
    }

}
