/******************************************************************************

Function Pointer 2

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int add(int a,int b);


int main()
{
    int(*fptr)(int,int); //declaration of function pointer
    
    fptr = &add; // Initialize the function pointer
    
    printf("%d\n",fptr(10,20)); // call the function using function pointer
    
    return 0;
}

int add(int a,int b){
    return a+b;
}


/******************************************************************************

Function Pointer 2

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void add1(int a,int b);


int main()
{
    void(*fptr)(int,int); //declaration of function pointer
    
    fptr = &add; // Initialize the function pointer
    
    fptr(10,20); // call the function using function pointer
    
    return 0;
}

void add1(int a,int b){
    
    int sum = a+b;
    printf("Sum = %d \n",sum);
}
