// 7.Write a program to ensure that the user enters a n between 1 and 10. Prompt until a valid n is provided.

#include <stdio.h>

int main(){

    int n;

    do{
    
        printf("Enter a number between 1 and 10 : ");
        scanf("%d",&n);
        
        if (n<1 || n>10) {
            printf("Invalid input.Try again.\n");
        }
    } while(n<1 || n>10);
    printf("You entered a valid number: %d\n",n);

    return 0;
}
