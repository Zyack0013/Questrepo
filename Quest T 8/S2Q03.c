// 3.Implement a program that declares a constant pointer to a constant integer. Show that neither the address stored in the pointer nor the value it points to can be changed.


#include <stdio.h>

int main() {

    int a = 10,b = 20;
    int const *const ptr = &a;

    printf("Address of a : %p\n",&a);
    printf("Address of b : %p\n",&b);
    
    printf("001 Value at ptr : %d\n",*ptr);
    printf("001Value of ptr : %p\n",ptr);

    // ptr = &b; //error: assignment of read-only variable ‘ptr’
    // *ptr = b; //error: assignment of read-only location ‘*(const int *)ptr’

    printf("002 Value at ptr : %d\n",*ptr);
    printf("002 Value of ptr : %p\n",ptr);

    return 0;
}