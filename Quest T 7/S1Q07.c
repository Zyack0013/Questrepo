// 7.Reverse a Number
//  Create a function that takes an integer and returns its reverse. Demonstrate how call by value affects the original number.


#include <stdio.h>

void reverse1(int N);
int reverse2(int N);

int main(){

    int N,rev;

    printf("Enter the integer : ");
    scanf("%d",&N);

    reverse1(N);
    rev = reverse2(N);

    printf("The reverse2 of %d is %d\n",N,rev);



    return 0;
}

/*
Name : reverse1
Return Datatype : void
parameters : int N 
Short discription: its used to print the reverse of a given number

*/

void reverse1(int N){

    int rev=0;
    int temp=N;

    while(N!=0){

        int dig = N%10;
        rev = rev*10 + dig;
        N= N/10;

    }

    printf("The Reverse1 of %d is %d\n",temp,rev);

}


/*
Name : reverse2
Return Datatype : int
parameters : int N 
Short discription: its used to return the reverse of a given number

*/


int reverse2(int N){

     int rev=0;

    while(N!=0){

        int dig = N%10;
        rev = rev*10 + dig;
        N= N/10;

    }

    return rev;

}
