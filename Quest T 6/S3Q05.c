// 5. Count Zeros in a Sparse Matrix
// Problem Statement: Write a program to determine if a given matrix is sparse. A matrix is sparse if most of its elements are zero. The program should:
// Take a matrix of size M x N as input, with dimensions defined using const variables.
// Use nested for loops to count the number of zero elements.
// Use if statements to compare the count of zeros with the total number of elements.
// Use a static variable to store the count of zeros.
// Requirements:
// Print whether the matrix is sparse or not.
// Use decision-making statements to handle matrices with no zero elements.
// Validate matrix dimensions before processing.


#include <stdio.h>

int main(){
    
    int const M = 3; 
    int const N = 4; 

    int A[M][N];  
    static int zCount = 0; 

    
    printf("Enter elements for Matrix A (%dx%d):\n", M, N);

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < N; j++) {

            printf("Element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
            
            if (A[i][j] == 0) {
                
                zCount++;
            }
        }
    }

    if (M <= 0 || N <= 0) {

        printf("Invalid matrix dimensions.\n");
        return 1;

    }


    printf("\nMatrix A (%dx%d):\n", M, N);

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < N; j++) {

            printf("%d ", A[i][j]);

        }
        printf("\n");
    }

    
    int eTotal = M * N;
    if (zCount > eTotal / 2) {
        printf("\nThe matrix is sparse.\n");
    } else {
        printf("\nThe matrix is not sparse.\n");
    }

    return 0;
}
