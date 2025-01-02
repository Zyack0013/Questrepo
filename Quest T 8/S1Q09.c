// 9.Create two examples: one demonstrating a constant pointer (where you cannot change what it points to) and another demonstrating a pointer to constant data (where you cannot change the data being pointed to). Document your findings.

#include <stdio.h>


int main() {

    int a =10;
    int b=15;

    int const *ptr1 = &a;  // pointer pointing to a constant data

    int *const ptr2 = &a;  // constant pointer to a integer variable

    ptr1 = &b;  // *ptr1 = 20;  --> not allowed  --> constant data
    
    // *ptr1 = 20; //error: assignment of read-only location ‘*ptr1’

    *ptr2 = 20;  // ptr2 = &b; --> not allowed -->constant pointer
    
    // ptr2 = &b; // error: assignment of read-only variable ‘ptr2’

    printf("Address of \na = %p\nb = %p\n",&a,&b);

    printf("Values at \na = %d\nb = %d\n",a,b);

    printf("Address of \nptr1 = %p\nptr2 = %p\n",ptr1,ptr2);

    printf("Values at \nptr1 = %d\nptr2 = %d\n",*ptr1,*ptr2);



    return 0;
}