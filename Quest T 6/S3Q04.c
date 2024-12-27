// 4. Matrix Multiplication
// Problem Statement: Write a program to multiply two matrices. The program should:
// Take two matrices as input:
// Matrix A of size M x N
// Matrix B of size N x P
// Use const variables to define the dimensions M, N, and P.
// Use nested for loops to calculate the product of the matrices.
// Use a static two-dimensional array to store the resulting matrix.
// Use if statements to validate that the matrices can be multiplied (N in Matrix A must equal M in Matrix B).



#include <stdio.h>

int main(){
    
    int const M = 3; 
    int const N = 2; 
    int const P = 4; 

    int A[M][N], B[N][P], C[M][P];  

    
    printf("Enter elements for Matrix A (%dx%d):\n", M, N);

    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            printf("Element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);

        }
    }


    printf("Enter elements for Matrix B (%dx%d):\n", N, P);

    for (int i = 0; i < N; i++){

        for (int j = 0; j < P; j++){

            printf("Element B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);

        }
    }


    if (N != N) {

        printf("Error!!! coloums are not equal.\n");
        return 1; 
    }


    for (int i = 0; i < M; i++){

        for (int j = 0; j < P; j++){

            C[i][j] = 0;

        }
    }

    
    for (int i = 0; i < M; i++){

        for (int j = 0; j < P; j++){

            for (int k = 0; k < N; k++) {

                C[i][j] += A[i][k] * B[k][j]; 

            }
        }
    }


    printf("\nMatrix A (%dx%d):\n", M, N);

    for (int i = 0; i < M; i++){

        for (int j = 0; j < N; j++){

            printf("%d ", A[i][j]);

        }
        printf("\n");
    }

    
    printf("\nMatrix B (%dx%d):\n", N, P);

    for (int i = 0; i < N; i++){

        for (int j = 0; j < P; j++){

            printf("%d ", B[i][j]);

        }
        printf("\n");
    }


    printf("\nMatrix C (%dx%d):\n", M, P);

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < P; j++) {

            printf("%d ", C[i][j]);

        }
        printf("\n");
    }

    return 0;
}
