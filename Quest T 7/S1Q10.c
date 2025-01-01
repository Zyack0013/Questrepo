// Prime Number Check
//  Write a program where a function checks if a given number is prime. Pass the number as an argument by value.


#include <stdio.h>

void isPrime1(int N);
int isPrime2(int N);

int main(){

    int N;

    printf("Enter the number : ");
    scanf("%d",&N);

    isPrime1(N);

    if(isPrime2(N)){
        printf("isP2- %d is prime number\n",N);
    }else{
        printf("isP2- %d is not prime number\n",N);
    }

    return 0;
}

/*
Name : isPrime1
Return Datatype : void
parameters : int N 
Short discription: its used to print whether given number is prime or not

*/

void isPrime1(int N){

    if(N < 0){   
        printf("isP1- %d is not prime number\n",N);
        return;
    }

    if(N == 1){   
        printf("isP1- %d is not prime number\n",N);
        return;
    }

   for(int i = 2; i*i <= N; i++){

    if(N % i == 0){

        printf("isP1- %d is not prime number\n",N);
        return;
    }
   }
   printf("isP1- %d is a prime number.\n",N);


}

/*
Name : isPrime2
Return Datatype : int
parameters : int N 
Short discription: its used to return 1 or 0 after checking if given number is prime or not

*/

int isPrime2(int N){

    if(N<=1){
        
        return 0;
    }

   for(int i = 2; i*i <= N; i++){

    if(N%i == 0){

        return 0;
    }
   }
   return 1;


    
}
