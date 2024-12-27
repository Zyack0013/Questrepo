// 6. Count Frequency of Each Element
// Problem Statement: Count the frequency of each unique element in a single-dimensional array. Use:
// A const variable for the size of the array.
// A nested for loop to compare each element with the rest. 
// A static array to store the frequency count.



#include <stdio.h>

int const size = 10; 

void getArray(int arr[]);

int main() {
    int arr[size];
    int freq[size];  
    int visited[size] ; 

    getArray(arr);


    for (int i = 0; i < size; i++) {
        if (visited[i] == 1) {
            continue; 
        }

        int count = 1; 

        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;        
                visited[j] = 1; 
            }
        }

        freq[i] = count; 
    }

    
    printf("Element\tFrequency\n");
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) { 
            printf("%d\t%d\n", arr[i], freq[i]);
        }
    }

    return 0;
}

void getArray(int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
