// 5. Transpose of a 3D Matrix Along a Specific Axis
// Problem Statement: Write a program to compute the transpose of a three-dimensional matrix along a specific axis (e.g., swap rows and columns for a specific depth). The program should:
// Take a matrix of size X x Y x Z as input, where X, Y, and Z are defined using const variables.
// Use a static three-dimensional array to store the transposed matrix.
// Use nested for loops to perform the transpose operation along the specified axis.
// Use if statements to validate the chosen axis for transposition.
// Requirements:
// Print the original matrix and the transposed matrix.
// Ensure invalid axis values are handled using decision-making constructs.



#include <stdio.h>

#define XA 2
#define YA 2
#define ZA 2


int main() {
    
    const int X = 2; 
    const int Y = 2; 
    const int Z = 2; 

    
    int matrix[X][Y][Z];

    
    static int trans[XA][ZA][YA];  


    printf("Enter elements for the 3D Matrix (%dx%dx%d):\n", X, Y, Z);

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("Element matrix[%d][%d][%d]: ", i + 1, j + 1, k + 1);
                scanf("%d", &matrix[i][j][k]);
            }
        }
    }

    
    printf("\nOriginal Matrix:\n");

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("matrix[%d][%d][%d] = %d\n", i + 1, j + 1, k + 1, matrix[i][j][k]);
            }
        }
    }

    
    int axis;
    printf("\nEnter the axis for transposition (0 for X-Y, 1 for X-Z, 2 for Y-Z): ");
    scanf("%d", &axis);

    
    if (axis == 0) {
        
        for (int i = 0; i < X; i++) {

            for (int j = 0; j < Y; j++) {

                for (int k = 0; k < Z; k++) {

                    trans[i][k][j] = matrix[i][j][k];
                }
            }
        }
    } else 
    if (axis == 1) {
        
        for (int i = 0; i < X; i++) {

            for (int j = 0; j < Y; j++) {

                for (int k = 0; k < Z; k++) {

                    trans[i][j][k] = matrix[i][k][j];
                }
            }
        }
    } else if (axis == 2) {
        
        for (int i = 0; i < X; i++) {

            for (int j = 0; j < Y; j++) {

                for (int k = 0; k < Z; k++) {

                    trans[j][i][k] = matrix[i][j][k];
                }
            }
        }
    } else {

        printf("Invalid axis for transposition!\n");
        return 1;  
    }

    
    printf("\nTransposed Matrix (along axis %d):\n", axis);

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Z; j++) {

            for (int k = 0; k < Y; k++) {

                printf("transposed[%d][%d][%d] = %d\n", i + 1, j + 1, k + 1, trans[i][j][k]);
            }
        }
    }

    return 0;
}
