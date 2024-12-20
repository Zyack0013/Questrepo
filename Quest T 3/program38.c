// 6.Write a program that takes a grade (A, B, C, D, F) as input and uses a switch-case to print the description of the grade (e.g., A: "Excellent", B: "Good", etc.).

#include <stdio.h>

int main() {

    char grade;

    printf("Enter the grade : ");
    scanf(" %c", &grade);

    switch (grade) {
        
        case 'A':
        printf("Excellent");
        break;
        case 'B':
        printf("Good");
        break;
        case 'C':
        printf("Average");
        break;
        case 'D':
        printf("Below Average");
        break;
        case 'F':
        printf("Fail");
        break;
        default:
        printf("Invalid grade! Please enter again");
    }

    return 0;
}