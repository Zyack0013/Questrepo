// 6.Implement a C program that uses a pointer to a pointer. Initialize an integer variable, create a pointer that points to it, and then create another pointer that points to the first pointer. Print the value using both levels of indirection.


#include <stdio.h>


int main() {

    int a;

    int *ptr1 =&a;

    int **ptr2 = &ptr1;
    
    int ***ptr3 = &ptr2;

    printf("Adress of a = %p\n",&a);
    printf("Ptr1 = %p\n",ptr1);
    printf("Ptr2 = %p\n",ptr2);
    printf("Ptr3 = %p\n",ptr3);


    return 0;
}