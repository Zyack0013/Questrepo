// 10. Combining Local and Global Variables in Loops
// Problem Statement: Write a program that uses a global variable to track the total sum and a local variable to store the sum of elements in an array. Use a loop to calculate the local sum, then add it to the global total.


#include <stdio.h>

int tsum = 0;

void sum(int arr[], int size);

int main(){

    int array[]={1,2,3,4,5};

    sum(array,5);
    return 0;

}

void sum(int arr[],int size){

    int sum =0;

    for(int i=0; i<size;i++){

        sum += arr[i];
    }

    tsum += sum;

    printf("The total sum in Global variable = %d\n",tsum);


}