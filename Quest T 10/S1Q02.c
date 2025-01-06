// 2.Data Normalization
// Function Prototype: double* normalizeData(const double *array, int size)
// Data Types: const double*, int, double*
// Concepts: Arrays, functions returning pointers, loops.
// Details: Normalize data points in an array, returning a pointer to the new normalized array.


#include <stdio.h>
#include <stdlib.h>


void getData(double data[],int size);
double* normalizeData(const double *array, int size);

int main() {

    int size;
    printf("Enter the number of data : ");
    scanf("%d",&size);

    double data[size];

    getData(data,size);

    double *normalized = normalizeData(data, size);

    printf("Normalized Data:\n");

    for (int i = 0; i < size; i++) {

        printf("%.2f ", normalized[i]);

    }
    printf("\n");

    free(normalized);


    return 0;
}


void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the data %d : ",i+1);
        scanf("%lf",&data[i]);
    }

}

double* normalizeData(const double *array, int size) {

    double min = array[0], max = array[0];

    for (int i = 1; i < size; i++) {

        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    
    double *normalized = (double*)malloc(size * sizeof(double));

    if (normalized == NULL) {

        printf("Memory allocation failed.\n");
        exit(1);
    }

    
    for (int i = 0; i < size; i++) {

        normalized[i] = (array[i] - min) / (max - min);
    }

    return normalized;

}