// 1.Write a program that takes an integer (1-7) as input and uses a switch-case to print the corresponding day of the week (e.g., 1 for Monday, 2 for Tuesday, etc.).
#include <stdio.h>

int main(){

    int a;

    printf("Enter the number : ");
    scanf("%d",&a);

    switch(a){

        case 1:
         printf("Monday");
         break;
         case 2:
         printf("Tuesday");
         break;
         case 3:
         printf("wednesday");
         break;
         case 4:
         printf("Thursday");
         break;
         case 5:
         printf("Friday");
         break;
         case 6:
         printf("Saturday");
         break;
         case 7:
         printf("Sunday");
         break;
         default :
         printf("Invalid!");
         break;
    }

    return 0;
}