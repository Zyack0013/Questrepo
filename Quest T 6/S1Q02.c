// 2. Array Element Categorization
// Problem Statement: Categorize elements of a single-dimensional array into positive, negative, and zero values. Use:
// A const variable to define the size of the array.
// A for loop for traversal.
// if-else statements to classify each element into separate arrays using static storage.


#include <stdio.h>

#define SIZE 10  


void classify(int arr[]);

int main(){


    int const size = SIZE;
    int arr[size];

    for(int i=0; i < size; i++){

        printf("Enter %d in 10 integers : ",i);
        scanf("%d",&arr[i]);
    }

    classify(arr);

    return 0;

}

void classify(int arr[]){

    static int pos[SIZE];
    static int neg[SIZE];
    static int zeros[SIZE];
    int pcount=0,ncount=0,zcount=0;

    for(int i = 0; i < SIZE; i++){

        if(arr[i]>0){

            pos[pcount++]= arr[i];

        }else 
        if(arr[i]<0){

            neg[ncount++] = arr[i];

        }else{

            zeros[zcount++] = arr[i];

        }
    }

    printf("\n The positive values are : \n");

    for(int i=0; i<pcount; i++){

        printf("\t%d ",pos[i]);
    }

    printf("\n The negative values are : \n");

    for(int i=0; i<ncount; i++){

        printf("\t%d ",neg[i]);
    }

    printf("\n The zeros values are : \n");

    for(int i=0; i<zcount; i++){

        printf("\t%d ",zeros[i]);
    }

}


