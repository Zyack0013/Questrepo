// 5.Write a program that takes an integer (1-12) as input and uses a switch-case to print the name of the corresponding month (e.g., 1 for January, 2 for February, etc.).

#include <stdio.h>

int main(){

    int a;
    printf("Enter the integer : ");
    scanf("%d",&a);

    switch(a){

        case 1:
        printf("January");
        break;
        case 2:
        printf("February");
        break;
        case 3:
        printf("March");
        break;
        case 4:
        printf("April");
        break;
        case 5:
        printf("May");
        break;
        case 6:
        printf("June");
        break;
        case 7:
        printf("July");
        break;
        case 8:
        printf("August");
        break;
        case 9:
        printf("September");
        break;
        case 10:
        printf("October");
        break;
        case 11:
        printf("November");
        break;
        case 12:
        printf("December");
        break;
        default:
        printf("Not valid, Enter the integer in range(1-12)");
        break;
    }
    return 0;

}