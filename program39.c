// 7.Write a menu-driven program that offers the user options for basic mathematical operations (addition, subtraction, etc.). Based on the user’s choice, perform the corresponding operation using a switch-case.


#include <stdio.h>

int main() {
    
    int choice;
    double a, b, result;

    printf("Enter the two number : ");
    scanf("%lf \n%lf",&a,&b);

    printf("\n--- Menu ---\n");
    printf("1. Addition\t 2. Subtraction\t 3. Multiplication\t 4. Division\n");
    // printf("2. Subtraction\t");
    // printf("3. Multiplication\n");
    // printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        result = a + b;
        printf("Result: %.2lf", result);
        break;

        case 2: 
        result = a - b;
        printf("Result: %.2lf", result);
        break;

        case 3: 
        result = a * b;
        printf("Result: %.2lf", result);
        break;

        case 4: 
        if (b == 0) {
        printf("Error: Division by zero is not allowed.");
        }else{
        result = a / b;
        printf("Result: %.2lf", result);
        }
        break;

        default:
        printf("Invalid choice! Please try again.\n");
        }
    

    return 0;
}
