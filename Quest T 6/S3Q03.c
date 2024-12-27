// 3. Find the Maximum Element in Each Row
// Problem Statement: Write a program to find the maximum element in each row of a two-dimensional array. The program should:
// Take a matrix of size M x N as input, with dimensions defined using const variables.
// Use a static array to store the maximum value of each row.
// Use nested for loops to traverse each row and find the maximum element.
// Use if statements to compare and update the maximum value.
// Requirements:
// Print the maximum value of each row after processing the matrix.
// Handle edge cases where rows might be empty using decision-making statements.


#include <stdio.h>

#define MA 3

int main(){

    int const M = 3; 
    int const N = 4; 
    int matrix[M][N];  

    static int maxrow[MA];  

    
    printf("Enter elements of the %dx%d matrix:\n", M, N);

    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);

        }
    }

    
    for (int i = 0; i < M; i++) {
        
        maxrow[i] = matrix[i][0];
        
        for (int j = 1; j < N; j++){

            if (matrix[i][j] > maxrow[i]){

                maxrow[i] = matrix[i][j];  

            }
        }
    }


    printf("Maximum values in each row are:\n");

    for (int i = 0; i < M; i++){

        printf("Row %d: %d\n", i + 1, maxrow[i]);
    }

    return 0;
}
