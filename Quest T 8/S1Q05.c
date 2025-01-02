// 5.Create an example that illustrates what happens when you attempt to dereference a wild pointer (a pointer that has not been initialized). Document the output and explain why this leads to undefined behavior.


#include <stdio.h>


int main() {

    int *ptr;

    *ptr = *ptr + 10;

    printf("The value in pointer is %d",*ptr);


    return 0;
}