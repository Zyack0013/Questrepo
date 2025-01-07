// 2. Function Pointer as Argument
// Implement a function void performOperation(int (*operation)(int, int), int a, int b) that takes a function pointer as an argument and applies it to two integers, printing the result.


#include <stdio.h>


int add(int a, int b);
int sub(int a, int b);

void performOperation(int (*operation)(int, int), int a, int b);

int main() {

    int a = 10, b = 5;

    printf("Addition:\n");
    performOperation(add, a, b);


    printf("Subtraction:\n");
    performOperation(sub, a, b);

    return 0;
}


int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}


void performOperation(int (*operation)(int, int), int a, int b) {

    int result = operation(a, b);  
    printf("Result: %d\n", result);

}
