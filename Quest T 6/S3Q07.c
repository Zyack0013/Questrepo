// 2. Find the Maximum Element in a 3D Array
// Problem Statement: Write a program to find the maximum element in a three-dimensional matrix. The program should:
// Take a matrix of size X x Y x Z as input, where X, Y, and Z are declared as const variables.
// Use a static variable to store the maximum value found.
// Use nested for loops to traverse all elements of the matrix.
// Use if statements to compare and update the maximum value.
// Requirements:
// Print the maximum value found in the matrix.
// Handle edge cases where the matrix might contain all negative numbers or zeros using decision-making statements.



#include <stdio.h>

int main(){
    
    int const X = 2; 
    int const Y = 2; 
    int const Z = 2; 

    
    int matrix[X][Y][Z];

    
    printf("Enter elements for the 3D Matrix (%dx%dx%d):\n", X, Y, Z);

    for (int i = 0; i < X; i++){

        for (int j = 0; j < Y; j++){

            for (int k = 0; k < Z; k++){

                printf("Element matrix[%d][%d][%d]: ", i + 1, j + 1, k + 1);
                scanf("%d", &matrix[i][j][k]);

            }
        }
    }

    
    static int max = -10000;  

    
    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++){

            for (int k = 0; k < Z; k++){
                
                if (matrix[i][j][k] > max) {

                    max = matrix[i][j][k]; 
                }
            }
        }
    }

    
    printf("The maximum value in the 3D matrix is: %d\n", max);

    return 0;
}
