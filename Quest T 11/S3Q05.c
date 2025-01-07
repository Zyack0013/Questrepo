// 5. 2D Array Using Double Pointer
// Write a function int** create2DArray(int rows, int cols) that dynamically allocates memory for a 2D array of integers using a double pointer and returns the pointer to the array.


#include <stdio.h>
#include <stdlib.h>

int** create2DArray(int rows, int cols);
void free2DArray(int **arr, int rows);

int main() {

    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **matrix = create2DArray(rows, cols);
    
    if (matrix == NULL) {
        
        return -1;  
    }
    
    printf("\nEnter the elements for the 2D array:\n");

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);

        }
    }

    printf("\nThe 2D array is:\n");

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            printf("%d ", matrix[i][j]);

        }
        printf("\n");
    }

    free2DArray(matrix, rows);

    return 0;
}



int** create2DArray(int rows, int cols) {

    int **arr = (int **)malloc(rows * sizeof(int *));
    
    if (arr == NULL) {

        printf("Memory allocation failed for row pointers.\n");
        return NULL;
    }

    
    for (int i = 0; i < rows; i++) {

        arr[i] = (int *)malloc(cols * sizeof(int));

        if (arr[i] == NULL) {

            printf("Memory allocation failed for column pointers at row %d.\n", i);
            return NULL;
            
        }
    }

    return arr;
}


void free2DArray(int **arr, int rows) {

    for (int i = 0; i < rows; i++) {

        free(arr[i]);  
    }
    free(arr); 
}
