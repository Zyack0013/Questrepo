// 4. Configuration-Based Matrix Operations
// Problem Statement: Perform matrix addition and multiplication. Use:
// A const global variable to define the maximum size of the matrix.
// static variables to hold intermediate results.
// if statements to check for matrix compatibility.
// Nested for loops for matrix calculations.
// Key Concepts Covered: Type qualifiers (const), Storage classes (static), Decision-making (if), Looping (nested for).


#include <stdio.h>

#define MAX_SIZE 3  

void mAdd(int A[MAX_SIZE][MAX_SIZE],int B[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE]);
void mMul(int A[MAX_SIZE][MAX_SIZE],int B[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE]);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE]);

int main(){

    int maxA[MAX_SIZE][MAX_SIZE]={
        {8, 2, 1},
        {4, 5, 1},
        {7, 3, 1}
    };
    
    int maxB[MAX_SIZE][MAX_SIZE]={
        {1, 3, 5},
        {2, 1, 4},
        {9, 2, 1}
    };

    
    static int rAdd[MAX_SIZE][MAX_SIZE];
    static int rMul[MAX_SIZE][MAX_SIZE];

    mAdd(maxA,maxB,rAdd);
    printf("Matrix Addition Result:\n");
    printMatrix(rAdd);

    mMul(maxA, maxB, rMul);
    printf("Matrix Multiplication Result:\n");
    printMatrix(rMul);

    return 0;
}


void mAdd(int A[MAX_SIZE][MAX_SIZE],int B[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE]){
    

    if(MAX_SIZE==MAX_SIZE){
        
        for (int i=0; i<MAX_SIZE;i++){

            for (int j=0;j<MAX_SIZE; j++){

                result[i][j] = A[i][j]+B[i][j];

            }
        }
    }else{
        printf("Incompatible size.\n");
    }
}


void mMul(int A[MAX_SIZE][MAX_SIZE],int B[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE]){

    if (MAX_SIZE==MAX_SIZE){

        for(int i=0;i< MAX_SIZE;i++){

            for (int j = 0; j < MAX_SIZE; j++){

                result[i][j]=0;

                for (int k=0;k<MAX_SIZE;k++){

                    result[i][j] += A[i][k]*B[k][j];

                }
            }
        }
    }else{

        printf("Incompatible Size.\n");
    
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE]){

    for(int i=0;i<MAX_SIZE;i++){

        for(int j=0;j<MAX_SIZE;j++){

            printf("%d ",matrix[i][j]);
        
        }

        printf("\n");
    }
}
