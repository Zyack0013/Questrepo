// 8. Dynamic Array of Pointers
// Write a program that dynamically allocates memory for an array of pointers to integers, fills each integer with values, and then frees all the allocated memory.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

   
    int **arr = (int **)malloc(n * sizeof(int *));
    if (arr == NULL) {
        
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    for (int i = 0; i < n; i++) {

        arr[i] = (int *)malloc(sizeof(int)); 

        if (arr[i] == NULL) {

            printf("Memory allocation for integer %d failed.\n", i);
            return 1;

        }

        *(arr[i]) = (i + 1) * 10;  
    }

    printf("\nValues in the array of pointers:\n");

    for (int i = 0; i < n; i++) {

        printf("arr[%d] = %d\n", i, *(arr[i]));
    }

    for (int i = 0; i < n; i++) {

        free(arr[i]);  
    }
    free(arr);  
    return 0;
}
