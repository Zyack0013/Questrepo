// 8. Find the Second Largest Element
// Problem Statement: Find the second largest element in a single-dimensional array. Use:
// A const variable for the array size.
// A static variable to store the second largest element.
// if statements and a single for loop to compare elements.


#include <stdio.h>

int main() {

    int const SIZE = 10;
    int arr[SIZE];
    static int sL = -1; 
    int largest = -1; 

    
    printf("Enter %d elements for the array:\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    for(int i = 0; i < SIZE; i++){
        if (arr[i] > largest) {
            sL = largest; 
            largest = arr[i];      
        } else if (arr[i] > sL && arr[i] != largest) {
            sL = arr[i]; 
        }
    }

    
    if (sL == -1) {
        printf("No second largest element exists.\n");
    } else {
        printf("The second largest element is: %d\n", sL);
    }

    return 0;
}
