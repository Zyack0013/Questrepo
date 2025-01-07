// 1. Swap Two Numbers Using Double Pointers
// Write a function void swap(int **a, int **b) that swaps the values of two integer pointers using double pointers.

#include <stdio.h>

void swap(int **a, int **b);

int main() {

    int a,b;

    printf("Enter the 1st integer : ");
    scanf("%d",&a);
    
    printf("Enter the 1st integer : ");
    scanf("%d",&b);

    int *ptr1 = &a;
    int *ptr2 = &b;

    printf("Before swap : a = %d  b = %d \n",a,b);

    swap(&ptr1,&ptr2);

    printf("After swap : a = %d  b = %d \n",a,b);


    return 0;
}

void swap(int **a, int **b) {

    int temp = **a;
    **a =**b;
    **b = temp;

}