// 9. Dynamic Function Selection
// Write a program where the user inputs an operation symbol (+, -, *, /) and the program uses a function pointer to call the corresponding function.

#include <stdio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {

    float (*operation)(float, float) = NULL;

    char symbol;
    float num1, num2, result;

    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &symbol); 
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (symbol) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            if (num2 == 0) {

                printf("Error: Division by zero is not allowed.\n");
                return 1;
                
            }
            operation = divide;
            break;
        default:
            printf("Error: Invalid operation.\n");
            return 1;
    }

    result = operation(num1, num2);
    printf("Result: %.2f\n", result);

    return 0;
}

float add(float a, float b) {

    return a + b;
}

float subtract(float a, float b) {

    return a - b;
}

float multiply(float a, float b) {

    return a * b;
}

float divide(float a, float b) {

    return a / b;
}
