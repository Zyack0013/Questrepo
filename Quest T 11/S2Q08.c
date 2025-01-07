// 9. Dynamic Memory for Multidimensional Arrays
// Create a program that dynamically allocates memory for a 3D array of integers, fills it with values, and deallocates the memory.


#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int x, y, z;
    
    printf("Enter the dimensions for the 3D array (x, y, z): ");
    scanf("%d %d %d", &x, &y, &z);

    int ***array = (int ***)malloc(x * sizeof(int **));  

    if (array == NULL) {

        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < x; i++) {

        array[i] = (int **)malloc(y * sizeof(int *));  

        if (array[i] == NULL) {

            printf("Memory allocation failed for array[%d].\n", i);
            return 1;
        }

        
        for (int j = 0; j < y; j++) {
        
            array[i][j] = (int *)malloc(z * sizeof(int));  
        
            if (array[i][j] == NULL) {
        
                printf("Memory allocation failed for array[%d][%d].\n", i, j);
                return 1;
            }
        }
    }

    int counter = 1;

    for (int i = 0; i < x; i++) {

        for (int j = 0; j < y; j++) {

            for (int k = 0; k < z; k++) {

                array[i][j][k] = counter++;

            }
        }
    }

    printf("\n3D Array content:\n");

    for (int i = 0; i < x; i++) {

        printf("Layer %d:\n", i + 1);

        for (int j = 0; j < y; j++) {

            for (int k = 0; k < z; k++) {

                printf("%d ", array[i][j][k]);

            }

            printf("\n");

        }
    }


    for (int i = 0; i < x; i++) {

        for (int j = 0; j < y; j++) {

            free(array[i][j]);  

        }

        free(array[i]);  

    }

    free(array);  

    return 0;
}
