// 5. Array of Function Pointers
// Implement a program that creates an array of function pointers for basic arithmetic operations (addition, subtraction, multiplication, division) and allows the user to select and execute one operation.


#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {

    int choice, num1, num2, result;

    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    printf("Select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {

        printf("Invalid choice.\n");
        return 1;

    }

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (choice == 4 && num2 == 0) {

        printf("Error: Division by zero is not allowed.\n");
        return 1;

    }

    result = operations[choice - 1](num1, num2);

    printf("Result: %d\n", result);

    return 0;
}

int add(int a, int b) {

    return a + b;
}

int subtract(int a, int b) {

    return a - b;
}

int multiply(int a, int b) {

    return a * b;
}

int divide(int a, int b) {

    return a / b;
}
