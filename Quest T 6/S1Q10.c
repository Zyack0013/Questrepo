// 10. Cyclically Shift Array Elements
// Problem Statement: Shift all elements of a single-dimensional array cyclically to the right by one position. Use:
// A const variable for the array size.
// A static variable to temporarily store the last element during shifting.
// A for loop for the shifting operation.

#include <stdio.h>

int main(){

    int const SIZE = 10; 
    int arr[SIZE];
    static int lE; 

    
    printf("Enter %d elements for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    lE = arr[SIZE - 1];

    for (int i = SIZE - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = lE;

    
    printf("Array after cyclic right shift:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
