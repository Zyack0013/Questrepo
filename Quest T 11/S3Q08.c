// 8. Dynamic Array of Strings
// Create a function void allocateStringArray(char ***arr, int n) that dynamically allocates memory for an array of n strings using a double pointer.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocateStringArray(char ***arr, int n);
void freeStringArray(char ***arr, int n);

int main() {
    char **arr;
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); 


    allocateStringArray(&arr, n);


    for (int i = 0; i < n; i++) {

        printf("Enter string %d: ", i + 1);
        fgets(arr[i], 100, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; 

    }


    printf("\nEntered strings:\n");

    for (int i = 0; i < n; i++) {

        printf("String %d: %s\n", i + 1, arr[i]);
    }

    freeStringArray(&arr, n);

    return 0;
}



void allocateStringArray(char ***arr, int n) {
    
    *arr = (char **)malloc(n * sizeof(char *));
    
 
    if (*arr == NULL) {
        
        printf("Memory allocation for string array failed!\n");
        return;
    }


    for (int i = 0; i < n; i++) {

        (*arr)[i] = (char *)malloc(100 * sizeof(char)); 
    
        if ((*arr)[i] == NULL) {
            
            printf("Memory allocation for string %d failed!\n", i);
            return;
        }
    }
}


void freeStringArray(char ***arr, int n) {

    for (int i = 0; i < n; i++) {

        free((*arr)[i]); 
    }
    free(*arr); 
}
