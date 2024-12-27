// 2. Transpose of a Matrix
// Problem Statement: Write a program to compute the transpose of a matrix. The program should:
// Take a matrix of size M x N as input, where M and N are declared as const variables.
// Use a static two-dimensional array to store the transposed matrix.
// Use nested for loops to swap rows and columns.
// Validate the matrix size using if statements before transposing.
// Requirements:
// Print the original and transposed matrices.
// Use a type qualifier (const) to ensure the matrix size is not modified during execution.




#include <stdio.h>

#define MA 3
#define NA 4


int main() {

    int const M = 3; 
    int const N = 4; 
    int matrix[M][N];   
            
    static int transpose[NA][MA]; 

    printf("Enter elements of the %dx%d matrix:\n", M, N);

    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);

        }
    }

    
    if (M <= 0 || N <= 0){

        printf("Invalid dimensions.\n");
        return 1;
    }

    
    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            transpose[j][i] = matrix[i][j];

        }
    }


    printf("Original Matrix:\n");

    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            printf("%d ", matrix[i][j]);

        }
        printf("\n");
    }


    printf("Transposed Matrix:\n");

    for (int i = 0; i < N; i++){

        for (int j = 0; j < M; j++){

            printf("%d ", transpose[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}
