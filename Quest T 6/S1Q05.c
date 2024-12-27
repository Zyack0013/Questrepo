// 5. Array Rotation by N Positions
// Problem Statement: Rotate the elements of a single-dimensional array to the left by N positions. Use:
// A const variable for the rotation count.
// A static array to store the rotated values.
// A while loop for performing the rotation.


#include <stdio.h>

int const size = 10;

void getArray(int arr[]);


int main(){

    int arr[size];
    int const rot = 4;
    int rotArr[size];

    getArray(arr);

    int i=0;
    while(i < size){

        rotArr[i]=arr[(i + rot)%size];
        i++;
    }

    printf("THe rotated array %d position : ",rot);
    for(int i=0; i< size; i++){

        printf("%d ",rotArr[i]);
    }
    printf("\n");


    return 0;


}

void getArray(int arr[]){

    for(int i = 0; i < size; i++){

        printf("Enter the %d element : ",i+1);
        scanf("%d",&arr[i]);

    }

}