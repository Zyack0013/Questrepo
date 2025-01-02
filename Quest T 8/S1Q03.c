// 3.Given an array of integers, write a function that takes a pointer to the array and its size as arguments. Use pointer arithmetic to calculate and return the sum of all elements in the array.


#include <stdio.h>

int sum(int *arr,int size);

int main() {

    int arr[5]={1,2,3,4,5};

    int size = sizeof(arr)/ sizeof(arr[0]);

    int sum1 = sum(arr,size);

    printf("The sum is %d\n",sum1);


    return 0;

}


int sum(int *arr,int size){

    int sum2 = 0;

    for(int i=0; i < size; i++) {

        sum2 += *(arr + i);
    }

    return sum2;
}