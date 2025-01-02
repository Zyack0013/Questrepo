// 1.Write a program that declares a constant pointer to an integer. Initialize it with the address of an integer variable and demonstrate that you can change the value of the integer but cannot reassign the pointer to point to another variable.


#include <stdio.h>

int main() {

    int a = 20,b=30;
    int *const ptr = &a;
    
    printf("Address of a : %p\n",&a);
    printf("Address of b : %p\n",&b);

    printf("001Value of ptr : %p\n",ptr);
    printf("001 Value at ptr : %d\n",*ptr);

    //ptr = &b; //error: assignment of read-only variable ‘ptr’
    *ptr = b;

    printf("002Value of ptr : %p\n",ptr);
    printf("002 Value at ptr : %d\n",*ptr);
    


    return 0;
}