// 7. Sort Array in Descending Order
// Problem Statement: Sort a single-dimensional array in descending order using bubble sort. Use:
// A const variable for the size of the array.
// A nested for loop for sorting.
// if statements for comparing and swapping elements.


#include <stdio.h>

int main() {

    int const SIZE = 10; 
    int arr[SIZE];

    
    printf("Enter %d elements for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
            
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    
    printf("Array in descending order:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
