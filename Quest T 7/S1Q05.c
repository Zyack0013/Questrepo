// Check Even or Odd
//  Write a program where a function determines whether a given integer is even or odd. The function should use call by value.


#include <stdio.h>


void oddEven1(int N);
int oddEven2(int N);

int main(){

    int N;
    printf("Enter the number : ");
    scanf("%d",&N);

    oddEven1(N);

    if(oddEven2(N)){

        printf("oddEven2 - %d is Even Number.\n",N);
        
    }else{
        printf("oddEven2 - %d is Odd Number.\n",N);
    }



    return 0;
}

/*

Name : oddEven1
Return Datatype : void
parameters : int N (integer type)
Short discription: its used to print whether the given number is odd or even

*/


void oddEven1(int N){

    if(N%2==0){

        printf("oddEven1 - %d is Even Number.\n",N);
    }else{

        printf("oddEven1 - %d is Odd Number.\n",N);
    }


}

/*

Name : oddEven1
Return Datatype : int
parameters : int N (integer type)
Short discription: its used to check if the given number is odd or even

*/

int oddEven2(int N){

    if(N%2==0){

        return 1;
    
    }

    return 0;
}