// 4.Write a program that demonstrates the use of a null pointer. Declare a pointer, assign it a null value, and check if it is null before attempting to dereference it.


#include <stdio.h>


int main() {

    int *ptr = NULL;

    if(ptr == NULL) {

        printf("THe pointer is having a value of NULL");

    }else {
        printf("The value the pointer pointing  is %d",*ptr);
    }


    return 0;
}