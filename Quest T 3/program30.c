// 8.Write a program to classify an integer as positive, negative, or zero using an if-else-if ladder.


#include <stdio.h>

int main(){

    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    if (a > 0) {
        printf("The number is positive.");
    }else 
    if (a < 0) {
        printf("The number is negative.");
    }else {
        printf("The number is zero.");
    }
    return 0;
}