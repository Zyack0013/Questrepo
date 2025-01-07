// 9. String Array Manipulation Using Double Pointer
// Implement a function void modifyStringArray(char **arr, int n) that modifies each string in an array of strings using a double pointer.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifyStringArray(char **arr, int n);

int main() {

    char **arr;
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); 


    arr = (char **)malloc(n * sizeof(char *));
    
    if (arr == NULL) {

        printf("Memory allocation failed!\n");
        return -1;
    }

   
    for (int i = 0; i < n; i++) {

        arr[i] = (char *)malloc(100 * sizeof(char)); 
        
        
        if (arr[i] == NULL) {

            printf("Memory allocation for string %d failed!\n", i);
            return -1;
        }

        printf("Enter string %d: ", i + 1);
        fgets(arr[i], 100, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; 
    }

    
    modifyStringArray(arr, n);

    
    printf("\nModified strings:\n");

    for (int i = 0; i < n; i++) {

        printf("String %d: %s\n", i + 1, arr[i]);
    }


    for (int i = 0; i < n; i++) {

        free(arr[i]); 
    }

    free(arr); 

    return 0;
}

void modifyStringArray(char **arr, int n) {

    for (int i = 0; i < n; i++) {

        strcat(arr[i], "_modified");
    }
}