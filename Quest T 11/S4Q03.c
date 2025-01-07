// 3. Function Pointer Returning Pointer
// Write a program with a function int* max(int *a, int *b) that returns a pointer to the larger of two integers, and use a function pointer to call this function.


#include <stdio.h>


int* max(int *a, int *b);

int main() {
    int x = 10, y = 20;


    int* (*findMax)(int*, int*) = max;

    int *larger = findMax(&x, &y);

    printf("Larger value: %d\n", *larger);

    return 0;
}

int* max(int *a, int *b) {

    return (*a > *b) ? a : b;

}
