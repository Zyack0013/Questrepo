// 4. Function Pointer with Different Functions
// Create a program that defines two functions int add(int, int) and int multiply(int, int) and uses a function pointer to dynamically switch between these functions based on user input.

#include <stdio.h>

int add(int a, int b);
int multiply(int a, int b);

int main() {

    int choice, num1, num2, result;

    int (*operation)(int, int);

    printf("Select an operation:\n");
    printf("1. Add\n");
    printf("2. Multiply\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (choice == 1) {

        operation = add;

    } else 
    if (choice == 2) {

        operation = multiply;

    } else {

        printf("Invalid choice.\n");
        return 1; 
    }

    result = operation(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
