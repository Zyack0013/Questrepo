// 2. Dynamic Memory Allocation Using Double Pointer
// Implement a function void allocateArray(int **arr, int size) that dynamically allocates memory for an array of integers using a double pointer.

#include <stdio.h>
#include <stdlib.h>

void allocateArray(int **arr, int size);

int main() {

    int *arr = NULL;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
  
    allocateArray(&arr, size);

    if (arr != NULL) {

        printf("Allocated array elements:\n");

        for (int i = 0; i < size; i++) {

            printf("%d ", arr[i]);
        }

        printf("\n");

        free(arr);
    }

    return 0;
}

void allocateArray(int **arr, int size) {
    
    *arr = (int *)malloc(size * sizeof(int));
    
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    
    for (int i = 0; i < size; i++) {

        (*arr)[i] = i + 1;  
    }
}
