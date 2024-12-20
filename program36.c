// 4.Write a program to convert a single-digit number (0-9) into its word representation (e.g., 1 to "One", 2 to "Two") using a switch-case statement.

#include <stdio.h>

int main(){

    int a;

    printf("Enter the single digit number : ");
    scanf("%d",&a);

    switch(a){

        case 0:
        printf("Zero");
        break;
        case 1:
        printf("One");
        break;
        case 2:
        printf("Two");
        break;
        case 3:
        printf("Three");
        break;
        case 4:
        printf("Four");
        break;
        case 5:
        printf("Five");
        break;
        case 6:
        printf("Six");
        break;
        case 7:
        printf("Seven");
        break;
        case 8:
        printf("Eight");
        break;
        case 9:
        printf("Nine");
        break;
        default:
        printf("Please enter single digit number");
        break;
    }

    return 0;

}