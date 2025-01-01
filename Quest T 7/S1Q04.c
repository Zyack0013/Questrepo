// 4.Factorial Calculation
//  Create a function to compute the factorial of a given number passed to it. Ensure the original number remains unaltered.


#include <stdio.h>

void factorial1 (int N);
int factorial2(int N);

int main(){

    int N,result=0;

    printf("Enter the number : \n");
    scanf("%d",&N);

    factorial1(N);

    result=factorial2(N);

    printf("The factorial2 of %d is %d \n",N,result);

    return 0;
}
/*

Name : factorial1
Return Datatype : void
parameters : int N (integer type)
Short discription: its used to print the factorial of a given number

*/

void factorial1 (int N){

    int result = 1;

    for(int i = 1;i <= N; i++){

        result *= i;

    }

    printf("The factorial1 of %d is %d \n",N,result);

}

/*

Name : factorial2
Return Datatype : int
parameters : int N (integer type)
Short discription: its used to return the factorial of a given number

*/

int factorial2(int N){

    int result = 1;

    for(int i = 1;i <= N; i++){

        result *= i;

    }

    return result;
}