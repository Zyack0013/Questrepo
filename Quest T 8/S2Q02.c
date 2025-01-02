// 2.Create a program that defines a pointer to a constant integer. Attempt to modify the value pointed to by this pointer and observe the compiler's response.



#include <stdio.h>


int main() {

    int a = 10,b = 20;

    int const *ptr = &a;

    printf("Address of a : %p\n",&a);
    printf("Address of b : %p\n",&b);
    
    printf("001 Value at ptr : %d\n",*ptr);
    printf("001Value of ptr : %p\n",ptr);

    ptr = &b; 
    // *ptr = 30; //error: assignment of read-only location ‘*ptr’

    printf("002 Value at ptr : %d\n",*ptr);
    printf("002 Value of ptr : %p\n",ptr);


    return 0;
}