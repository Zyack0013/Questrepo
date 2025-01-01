// Sum of Digits
//  Implement a function that computes the sum of the digits of a Nber passed as an argument.


#include <stdio.h>

void sumDigit1(int N);
int sumDigit2(int N);


int main(){

    int N,sum=0;

    printf("Enter the digit : \n");
    scanf("%d",&N);

    sumDigit1(N);

    sum = sumDigit2(N);

    printf("The sum2 of Digits = %d\n",sum);



    return 0;
}

/*
Name : sumDigit1
Return Datatype : void
parameters : int N 
Short discription: its used to print the sum of digits  of a given number

*/


void sumDigit1(int N){

    int sum=0;

    N = (N<0) ? -N : N;

    while (N != 0) {

        sum += N % 10;  
        N /= 10;
    }

    printf("The sum1 of Digits = %d\n",sum);

}

/*
Name : sumDigit2
Return Datatype : int
parameters : int N 
Short discription: its used to return the sum of digits  of a given number

*/

int sumDigit2(int N){

    int sum=0;

    N = (N<0) ? -N : N;

    while (N != 0) {

        sum += N % 10;  
        N /= 10;
    }

    return sum;
}