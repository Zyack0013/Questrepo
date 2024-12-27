// 1. Find Maximum and Minimum in an Array
// Problem Statement: Write a program to find the maximum and minimum values in a single-dimensional array of integers. Use:
// A const variable for the array size.
// A static variable to keep track of the maximum difference between the maximum and minimum values.
// if statements within a for loop to determine the maximum and minimum values.


#include <stdio.h>

int main(){

    int const mSize = 5;
    static int diff = 0;

    int arr[mSize];

    for(int i=0;i< mSize; i++){

        printf("Enter the arr[%d] element : ",i);
        scanf("%d",&arr[i]);
    }
    
    int maxE = arr[0], minE = arr[0];


    

        for(int i=1; i< mSize; i++){

            if(arr[i]>maxE){
                maxE= arr[i];
            }
            if(arr[i]<minE){
                minE= arr[i];
            }
        }
    

    diff = maxE-minE;

    printf("The maximum value is %d\n",maxE);
    printf("The minimum value is %d\n",minE);
    printf("The difference between Maximum and Minimum value is %d\n",diff);



    return 0;
}