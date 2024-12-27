// 3. 3D Matrix Scalar Multiplication
// Problem Statement: Write a program to perform scalar multiplication on a three-dimensional matrix. The program should:
// Take a matrix of size X x Y x Z and a scalar value as input, where X, Y, and Z are declared as const variables.
// Use a static three-dimensional array to store the resulting matrix.
// Use nested for loops to multiply each element of the matrix by the scalar.
// Requirements:
// Print the original matrix and the resulting matrix after scalar multiplication.
// Use decision-making statements to handle invalid scalar values (e.g., zero or negative scalars) if necessary.


#include <stdio.h>

int main(){
    
    int const X = 2; 
    int const Y = 2; 
    int const Z = 2; 

    
    int matrix[X][Y][Z];
    int result[X][Y][Z]; 

    
    printf("Enter elements for the 3D Matrix (%dx%dx%d):\n", X, Y, Z);

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("Element matrix[%d][%d][%d]: ", i + 1, j + 1, k + 1);
                scanf("%d", &matrix[i][j][k]);

            }
        }
    }


    int scalar;
    printf("Enter the scalar value : ");
    scanf("%d", &scalar);

    
    if (scalar <= 0) {

        printf("Invalid scalar value.\n");
        return 1; 
    }

    
    printf("\nOriginal 3D Matrix:\n");

    for (int i = 0; i < X; i++){

        for (int j = 0; j < Y; j++){

            for (int k = 0; k < Z; k++){

                printf("%d ", matrix[i][j][k]);

            }
            printf("\n");
        }
        printf("\n");
    }

    
    for (int i = 0; i < X; i++){

        for (int j = 0; j < Y; j++){

            for (int k = 0; k < Z; k++){

                result[i][j][k] = matrix[i][j][k] * scalar;
            }
        }
    }

    
    printf("\nScalar multiplication result :\n");

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("%d ", result[i][j][k]);
                
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
