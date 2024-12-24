// 3. Local Variable Initialization
// Problem Statement: Write a program with a function that declares a local variable and initializes it to a specific value. Call the function multiple times and observe how the local variable behaves with each call.


#include <stdio.h>

void fun(void);

int main(){

    printf("First call : ");
    fun();

    printf("Second call : ");
    fun();

    printf("Third call : ");
    fun();

    printf("Fourth call : ");
    fun();

    return 0;

}


void fun(void){

    int a=10;
    printf("Local variable = %d \n",a);
    a++;

}

/*

// 3. Local Variable Initialization (Static )
// Problem Statement: Write a program with a function that declares a local variable and initializes it to a specific value. Call the function multiple times and observe how the local variable behaves with each call.


#include <stdio.h>

void fun(void);

int main(){

    printf("First call : ");
    fun();

    printf("Second call : ");
    fun();

    printf("Third call : ");
    fun();

    printf("Fourth call : ");
    fun();

    return 0;

}


void fun(void){

    static int a=10;
    printf("Local variable = %d \n",a);
    a++;

}


*/