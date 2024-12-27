// 4. Check Prime Numbers in an Array
// Problem Statement: Identify which elements in a single-dimensional array are prime numbers. Use:
// A for loop to iterate through the array and check each element.
// A nested for loop to determine if a number is prime.
// if statements for decision-making.
// A const variable to define the size of the array.

#include <stdio.h>

int const size = 5;


void getArray(int arr[]);

int main(){

    int arr[size];

    getArray(arr);

    printf("Prime numbers in the array are:\n");
    for (int i = 0; i < size; i++) {

        int num = arr[i];
        int isPrime = 1; 

        if (num <= 1){

            isPrime = 0; 
        } else{
            for(int j = 2; j * j <= num; j++){

                if(num % j == 0){
                    isPrime = 0; 
                    break;
                }
            }
        }

        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");


    return 0;
}


void getArray(int arr[]){

    for(int i = 0; i < size; i++){

        printf("Enter the %d element : ",i+1);
        scanf("%d",&arr[i]);

    }

}