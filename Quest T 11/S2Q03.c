// 3. Resize an Array
// Write a program that dynamically allocates memory for an array of n integers, fills it with values, resizes the array to 2n using realloc(), and fills the new elements with values.


#include <stdio.h>
#include <stdlib.h>


int main() {

    int N;
    
    printf("Enter the size : ");
    scanf("%d",&N);

    int *pNumber = (int *)malloc(N * sizeof(int));

    if (pNumber == NULL) {

        printf("Memory allocation failed.\n");
        
        return 1;
    }

    for(int i = 0; i < N;i++) {

        *(pNumber + i) = i+1;

    }

    printf("The array before resized :\n");

    for(int i = 0; i < N;i++) {

        printf("%d ",*(pNumber+i));
    }

    printf("\n");
    // Resizing 

    int newN = 2*N;

    pNumber = (int *)realloc(pNumber,newN * sizeof(int));

    if (pNumber == NULL) {

        printf("Memory allocation failed.\n");
        
        return 1;
    }

    for(int i = 0; i < newN;i++) {

        *(pNumber + i) = i+1;

    }

    printf("The array after resized : \n");

    for(int i = 0; i < newN;i++) {

        printf("%d ",*(pNumber+i));
    }

    printf("\n");

    free(pNumber);



    return 0;
}