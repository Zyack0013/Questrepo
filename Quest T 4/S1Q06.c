// 6.Print Multiplication Table:
// Write a program to print the multiplication table of a given number using a while loop.

#include <stdio.h>

int main(){

    int a,i=1;

    printf("Enter the number : ");
    scanf("%d",&a);

    while (i<=a){

        printf("%d x %d = %d \n",a,i,a*i);
        i++;
    }

    return 0;
}