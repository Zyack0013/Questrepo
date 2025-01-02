// 6.Create a program that uses conditional statements to determine if a constant pointer is pointing to a specific value, printing messages based on whether it matches or not.


#include <stdio.h>

int main() {

    int a = 10, b = 20;
    int *const ptr = &a;

    if(*ptr == 10) {

        printf("The constant pointer is pointing to a value of %d",*ptr);
    }else 
    if(*ptr == 20) {
        
        printf("The constant pointer is pointing to a value of %d",*ptr);
    }

    *ptr = 30;

    printf("AM--The constant pointer is pointing to a value of %d",*ptr);


    return 0;
}