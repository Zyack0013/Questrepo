/*

Write a C program to filter all prime numbers from a given array of integers and store them in a new array. A prime number is a number greater than 1 that is divisible only by 1 and itself. For example, 2, 3, 5, and 7 are prime numbers.
 
Detailed Requirements:
Input Constraints:
The program should accept an integer array from the user, with the size (N) specified at runtime.
The size of the array must be between 5 and 100, inclusive. If the size is invalid, prompt the user to re-enter it.
The array can contain both positive and negative integers. However, only positive numbers greater than 1 should be checked for primality.
Prime Number Identification:
Use a loop to iterate through the array and check each number for primality.
A number is prime if it is not divisible by any number from 2 to the square root of that number. Optimize the primality test to stop early if a divisor is found.
Storage Requirements:
Store all identified prime numbers in a new dynamically allocated array.
Track the number of prime numbers found, and ensure that the new array size is equal to the number of prime numbers.
Output Requirements:
Display the original array and the newly created array of prime numbers.
If no prime numbers are found, display an appropriate message.
Additional Constraints:
Use a separate function to check whether a number is prime. This function should accept a single integer as input and return a boolean indicating whether the number is prime.
Ensure the program handles duplicate prime numbers correctly by storing each occurrence.
Edge Case Handling:
If the input array contains no prime numbers, the program should output: "No prime numbers found in the given array."
Negative numbers, zero, and one should be ignored and not checked for primality.
Performance Considerations:
Optimize the program to handle large arrays efficiently by reducing unnecessary computations during the primality check.
Use modular arithmetic to skip even numbers after checking for 2 as a special case.
 
Example Execution:
Input 1:
Original Array: [11, 18, 2, -5, 7, 9, 12]
Output:
Prime Numbers Array: [11, 2, 7]
Input 2:
Original Array: [4, 6, 8, 9, 15, 16]
Output:
"No prime numbers found in the given array

*/


#include <stdio.h>



void getArray(int arr[],int size);
int isPrime(int N);
void printArray(int arr[],int size);




int main(){

    int const max_size =100, min_size=5;
    int size;


    do{
        printf("Enter the size of array(5-100) : \n");
        scanf("%d",&size);

        if(size<min_size || size>max_size){

           printf("Enter a valid size!!\n");
        }
    }while(size<min_size || size>max_size);

    int arr[size];
    int prime[size],count=0;

    getArray(arr,size);

    for(int i = 0; i < size; i++){

        if(isPrime(arr[i])&& arr[i] > 1){

            prime[count++]= arr[i];
            printf("%d",prime[i]);
        }
    }

    printf("The original array : \n");
    printArray(arr,size);

    if(count==0){

        printf("There is no prime number\n");
    }else

    if(count >0){

        printf("The Prime number array :\n");
        printArray(prime,count);
    }






    return 0;
}



void getArray(int arr[],int size){

    for(int i = 0; i< size; i++){

        printf("\nEnter the element at %d index : ",i);
        scanf("%d",&arr[i]);

    }

}

int isPrime(int N){

    if(N==1){
        
        return 0;
    }

   for(int i = 2; i*i <= N; i++){

    if(N % i == 0){

        return 0;

    }
   }
   return 1;


}

void printArray(int arr[],int size){

    for(int i = 0; i < size; i++){

        printf("\n Array elements at index %d : %d \n",i, arr[i]);
    }
}