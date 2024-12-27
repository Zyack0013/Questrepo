// 1. Matrix Addition
// Problem Statement: Write a program to perform the addition of two matrices. The program should:
// Take two matrices as input, each of size M x N, where M and N are defined using const variables.
// Use a static two-dimensional array to store the resulting matrix.
// Use nested for loops to perform element-wise addition.
// Use if statements to validate that the matrices have the same dimensions before proceeding with the addition.
// Requirements:
// Declare matrix dimensions as const variables.
// Use decision-making constructs to handle invalid dimensions.
// Print the resulting matrix after addition.


#include <stdio.h>

#define MA 3
#define NA 3 

int main() {

    int const M = 3; 
    int const N = 3;
    int matrix1[M][N],matrix2[M][N];

    static int result[MA][NA];

    
    printf("Enter elements of the first matrix (%dx%d):\n", M, N);

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < N; j++) {

            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);

        }
    }

    printf("Enter elements of the second matrix (%dx%d) :\n", M, N);

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < N; j++) {

            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);

        }
    }

    if (M <= 0 || N <= 0){

        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    
    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            result[i][j] = matrix1[i][j] + matrix2[i][j];

        }
    }

    
    printf("Resultant matrix after addition:\n");

    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            printf("%d ", result[i][j]);

        }
        printf("\n");
    }

    return 0;
}
