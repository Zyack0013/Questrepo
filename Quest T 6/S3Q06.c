// 1. 3D Matrix Addition
// Problem Statement: Write a program to perform element-wise addition of two three-dimensional matrices. The program should:
// Take two matrices as input, each of size X x Y x Z, where X, Y, and Z are defined using const variables.
// Use a static three-dimensional array to store the resulting matrix.
// Use nested for loops to iterate through the elements of the matrices.
// Use if statements to validate that the dimensions of both matrices are the same before performing addition.
// Requirements:
// Declare matrix dimensions as const variables.
// Use decision-making statements to handle mismatched dimensions.
// Print the resulting matrix after addition.




#include <stdio.h>

int main() {
    
    int const X = 2; 
    int const Y = 2; 
    int const Z = 2; 

    
    int A[X][Y][Z], B[X][Y][Z], result[X][Y][Z];

    printf("Enter elements for Matrix A (%dx%dx%d):\n", X, Y, Z);

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("Element A[%d][%d][%d]: ", i + 1, j + 1, k + 1);
                scanf("%d", &A[i][j][k]);
            }
        }
    }

    
    printf("Enter elements for Matrix B (%dx%dx%d):\n", X, Y, Z);

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("Element B[%d][%d][%d]: ", i + 1, j + 1, k + 1);
                scanf("%d", &B[i][j][k]);
            }
        }
    }

    
    if (sizeof(A) != sizeof(B)) {

        printf("Dimensions do not matching.\n");
        return 1; 
    }

    
    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                result[i][j][k] = A[i][j][k] + B[i][j][k];

            }
        }
    }

    // 
    printf("\nAddition Result:\n");

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("Result[%d][%d][%d] = %d\n", i + 1, j + 1, k + 1, result[i][j][k]);

            }
        }
    }

    return 0;
}
