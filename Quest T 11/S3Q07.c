// 7. Pass a Double Pointer to a Function
// Write a function void setPointer(int **ptr) that sets the pointer passed to it to point to a dynamically allocated integer.

#include <stdio.h>
#include <stdlib.h>

void setPointer(int **ptr);

int main() {

    int *p = NULL;  

    setPointer(&p);

    if (p != NULL) {

        printf("Value of dynamically allocated integer: %d\n", *p);
    }

    free(p);

    return 0;
}

void setPointer(int **ptr) {
    
    *ptr = (int *)malloc(sizeof(int));

    
    if (*ptr == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

   
    **ptr = 100; 
}