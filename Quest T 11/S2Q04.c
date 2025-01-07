// 4. Matrix Allocation
// Create a function that dynamically allocates memory for a 2D array (matrix) of size m x n, fills it with values, and then deallocates the memory.

#include <stdio.h>
#include <stdlib.h>

void dynamicMatrix(int rows,int cols);

int main() {

    int rows,cols;

    printf("Enter the number of rows : ");
    scanf("%d",&rows);

    printf("Enter the number of cols : ");
    scanf("%d",&cols);

    dynamicMatrix(rows,cols);



    return 0;
}

void dynamicMatrix(int rows,int cols) {

    int *matrix = (int *)malloc(rows * cols * sizeof(int));

    if (matrix == NULL) {

        printf("Memory allocation failed.\n");
        return;

    }

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            matrix[i * cols + j] = (2*i + 1) * (j + 1); 

        }
    }
    
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < cols; j++) {
        
            printf("%d ", matrix[i * cols + j]);
        
        }
        
        printf("\n");
    }

    free(matrix);


}