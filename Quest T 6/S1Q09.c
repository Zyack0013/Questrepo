// 9. Odd and Even Number Separation
// Problem Statement: Separate the odd and even numbers from a single-dimensional arr into two separate arrays. Use:
// A const variable for the size of the array.
// if-else statements to classify elements.
// A for loop for traversal and separation.



#include <stdio.h>

int main(){
    
    int const SIZE = 10; 
    int arr[SIZE], odd[SIZE], even[SIZE];
    int oddIndex = 0, evenIndex = 0;

    printf("Enter %d elements for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            even[evenIndex++] = arr[i]; 
        } else {
            odd[oddIndex++] = arr[i]; 
        }
    }


    printf("Even numbers:\n");
    for (int i = 0; i < evenIndex; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("Odd numbers:\n");
    for (int i = 0; i < oddIndex; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
