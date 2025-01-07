// 1. Allocate and Free Integer Array
// Write a program that dynamically allocates memory for an array of integers, fills it with values from 1 to n, and then frees the allocated memory.

#include <stdio.h>
#include <stdlib.h>

int main() { 

    int N;
    printf("Enter the N value : ");
    scanf("%d",&N);

    int *pNumber = (int *)malloc(N*sizeof(int));

    if (pNumber == NULL) {

        printf("Memory allocation failed.\n");
        
        return;
    }

    for(int i = 0; i < N;i++) {

        *(pNumber + i) = i+1;

    }

    for(int i = 0; i < N;i++) {

        printf("The elements are : \n%d",*(pNumber+i));
    }

    free(pNumber);
    return 0;

}