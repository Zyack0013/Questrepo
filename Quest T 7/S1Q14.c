// 14.Matrix Trace Calculation
//  Write a program where a function computes the trace of a 2x2 matrix (sum of its diagonal elements). Pass the matrix elements individually as arguments.

#include <stdio.h>

void digSum1(int arr[2][2]);
int digSum2(int arr[2][2]);

int main(){

    int arr[2][2],trace;

    for(int i=0; i<2; i++){

        for(int j = 0; j<2; j++){

            printf("Enter element at arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }

    }

    digSum1(arr);

    trace= digSum2(arr);

    printf("F2-The trace of the matrix is: %d\n",trace);


    return 0;
}


void digSum1(int arr[2][2]){

    int sum = arr[0][0] + arr[1][1];

    printf("F1-The trace of the matrix is: %d\n", sum);

}

int digSum2(int arr[2][2]){

    int sum = arr[0][0] + arr[1][1];

    return sum;

}