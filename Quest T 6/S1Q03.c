// 3. Cumulative Sum of Array Elements
// Problem Statement: Calculate the cumulative sum of elements in a single-dimensional array. Use:
// A static variable to hold the running total.
// A for loop to iterate through the array and update the cumulative sum.
// A const variable to set the array size.


#include <stdio.h>

int const size = 5 ;

void sum(int arr[]);

int main(){

    int arr[size];

    for(int i = 0; i < size; i++){

        printf("Enter the %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    sum(arr);

    return 0;
}


void sum(int arr[]){

    static int total=0;

    printf("\nCumulative sum of elements : \n");

    for(int i = 0; i < size; i++){

        total += arr[i];
        printf("sum after %d element is %d \n",i+1,total);
    }

}