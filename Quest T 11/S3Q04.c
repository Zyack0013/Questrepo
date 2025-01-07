// 4. Pointer to Pointer Example
// Create a simple program that demonstrates how to use a pointer to a pointer to access and modify the value of an integer.


#include <stdio.h>
#include <stdlib.h>

int main() {

    int num = 10;               
    int *ptr = &num;             
    int **ptrToPtr = &ptr;       

    printf("Value of num: %d\n", num);        
    printf("Value using ptr: %d\n", *ptr);    
    printf("Value using ptrToPtr: %d\n", **ptrToPtr); 

    
    **ptrToPtr = 20; 

    printf("\nAfter modification:\n");
    printf("Value of num: %d\n", num);         
    printf("Value using ptr: %d\n", *ptr);     
    printf("Value using ptrToPtr: %d\n", **ptrToPtr); 

    return 0;


}