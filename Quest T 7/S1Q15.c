// 1.Palindrome Nber Check
//  Create a function that checks whether a given Nber is a palindrome. Pass the Nber by value and return the result.


#include <stdio.h>

void isPalin1(int N);
int isPalin2(int N);

int main(){

    int N;

    printf("Enter the number : ");
    scanf("%d",&N);

    isPalin1(N);

    if(isPalin2(N)){

        printf("F2-%d is a palindrome number.\n",N);
    }else{

        printf("F2-%d is not a palindrome number.\n",N);
    }


    return 0;
}

void isPalin1(int N){

    int ogN = N;
    int revN = 0;
    int rem;

    while (N != 0){

        rem = N%10;
        revN = revN*10+rem;
        N /= 10;
    }

    if (ogN==revN){

        printf("F1-%d is a palindrome number.\n",ogN);

    } else{

        printf("F1-%d is not a palindrome number.\n",ogN);

    }

}

int isPalin2(int N){

    int ogN = N;
    int revN = 0;
    int rem;

    while (N != 0){

        rem = N%10;
        revN = revN*10+rem;
        N /= 10;
    }

    if (ogN==revN){

        return 1; 

    } else{

        return 0;  

    }
}