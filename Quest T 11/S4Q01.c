// 1. Basic Function Pointer Declaration
// Write a program that declares a function pointer for a function int add(int, int) and uses it to call the function and print the result.


#include <stdio.h>

int add(int a, int b);

int main() {

    int (*funcPtr)(int, int);

    funcPtr = add;

    int result = funcPtr(5, 3);

    printf("Sum = %d\n",result);

    return 0;
}


int add(int a, int b) {

    return a + b;

}
