// 7.Write a program that declares two constant pointers pointing to different integer variables. Compare their addresses using relational operators and print whether one points to a higher or lower address than the other.


#include <stdio.h>


int main() {

    int a=10,b=20;

    int *const ptr1 = &a;
    int *const ptr2 = &b;

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