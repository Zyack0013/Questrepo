// 6. Using Function Pointers for Sorting
// Write a function void sort(int *arr, int size, int (*compare)(int, int)) that uses a function pointer to compare elements, allowing for both ascending and descending order sorting.

#include <stdio.h>

int ascending(int a, int b);
int descending(int a, int b);

void sort(int *arr, int size, int (*compare)(int, int));
void printArray(int *arr, int size);

int main() {

    int arr[] = {5, 2, 9, 1, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array :\n");
    printArray(arr, size);

    printf("\nSorting in ascending order :\n");
    sort(arr, size, ascending);
    printArray(arr, size);

    printf("\nSorting in descending order :\n");
    sort(arr, size, descending);
    printArray(arr, size);

    return 0;
}

int ascending(int a, int b) {

    return a > b; 
}

int descending(int a, int b) {

    return a < b; 
}

void sort(int *arr, int size, int (*compare)(int, int)) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {

            if (compare(arr[j], arr[j + 1])) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int *arr, int size) {

    for (int i = 0; i < size; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}
