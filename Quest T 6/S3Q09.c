// 4. Count Positive, Negative, and Zero Elements in a 3D Array
// Problem Statement: Write a program to count the number of positive, negative, and zero elements in a three-dimensional matrix. The program should:
// Take a matrix of size X x Y x Z as input, where X, Y, and Z are defined using const variables.
// Use three static variables to store the counts of positive, negative, and zero elements, respectively.
// Use nested for loops to traverse the matrix.
// Use if-else statements to classify each element.
// Requirements:
// Print the counts of positive, negative, and zero elements.
// Ensure edge cases (e.g., all zeros or all negatives) are handled correctly.


#include <stdio.h>

int main() {
    
    int const X = 2; 
    int const Y = 2; 
    int const Z = 2; 


    int matrix[X][Y][Z];

    
    static int pCount = 0;
    static int nCount = 0;
    static int zCount = 0;

    
    printf("Enter elements for the 3D Matrix (%dx%dx%d):\n", X, Y, Z);

    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                printf("Element matrix[%d][%d][%d]: ", i + 1, j + 1, k + 1);
                scanf("%d", &matrix[i][j][k]);

            }
        }
    }

    
    for (int i = 0; i < X; i++) {

        for (int j = 0; j < Y; j++) {

            for (int k = 0; k < Z; k++) {

                if (matrix[i][j][k] > 0) {

                    pCount++;

                } else if (matrix[i][j][k] < 0) {

                    nCount++;

                } else {

                    zCount++;

                }
            }
        }
    }

    
    printf("\nCount of Positive Elements: %d\n", pCount);
    printf("Count of Negative Elements: %d\n", nCount);
    printf("Count of Zero Elements: %d\n", zCount);

    return 0;
}
