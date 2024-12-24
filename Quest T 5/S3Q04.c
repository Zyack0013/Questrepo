// 4. const for Read-Only Pointer in Loops
// Problem Statement: Declare a const pointer to an integer and use it in a loop to traverse an array. Print each value the pointer points to.


#include <stdio.h>

int main(){

    int arr[]={1,20,3,40,5,60};
    int *const Ptr = arr;
    
    for(int i=0;i<6;i++){

        printf("Element at index %d : %d\n",i,*(Ptr + i));
        printf("Address of index %d : %p\n",i,Ptr + i);

    }
}