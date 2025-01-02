// 10.Write a program that compares two pointers pointing to different variables of the same type. Use relational operators to determine if one pointer points to an address greater than or less than another and print the results.


#include <stdio.h>

int main() {

    int a=10,b=20;

    int *ptr1 = &a;
    int *ptr2 = &b;

    printf("value of ptr1 = %p\n",ptr1);
    printf("value of ptr2 = %p\n",ptr2);

    if(ptr1 < ptr2) {

        printf("ptr1 points to a lower memory address than ptr2.");
    }else
    if(ptr1 > ptr2) {

        printf("ptr2 points to a lower memory address than ptr1.");
    }else {

        printf("Both points to same address");
    }


    return 0;
}