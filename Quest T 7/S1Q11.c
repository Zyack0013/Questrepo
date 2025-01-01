// 11.Fibonacci Sequence Check
//  Create a function that checks whether a given number belongs to the Fibonacci sequence. Pass the number by value.

#include <stdio.h>
#include <math.h>

int square(int N);
void fibSeq1(int N);
int fibSeq2(int N);


int main(){

    int N;

    printf("Enter the number : ");
    scanf("%d",&N);

    fibSeq1(N);

    if(fibSeq2(N)){

        printf("%d is a fibonacci2 number.\n",N);

    }else{

        printf("%d is not a fibonacci2 number.\n",N);
    }

    return 0;
}


int square(int N){

    int sqrt_N = (int)sqrt(N);
    return (sqrt_N * sqrt_N == N);

}

void fibSeq1(int N){

    if(square(5 * N * N + 4) || square(5 * N * N - 4)){

        printf("%d is a fibonacci1 number.\n",N);

    }else{

        printf("%d is not a fibonacci1 number.\n",N);
    }
}

int fibSeq2(int N){

    if(square(5 * N * N + 4) || square(5 * N * N - 4)){

        return 1;

    }else{

       return 0;
    }

}