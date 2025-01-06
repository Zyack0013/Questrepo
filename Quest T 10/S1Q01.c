// 1.Statistical Analysis Tool
// Function Prototype: void computeStats(const double *array, int size, double *average, double *variance)
// Data Types: const double*, int, double*
// Concepts: Pointers, arrays, functions, passing constant data, pass by reference.
// Details: Compute the average and variance of an array of experimental results, ensuring the function uses pointers for accessing the data and modifying the results.



#include <stdio.h>
#include <math.h>


void getData(double data[],int size);
void computeStats(const double *array, int size, double *average, double *variance);

int main() {

    int size;
    printf("Enter the number of experiments conducted : ");
    scanf("%d",&size);
  
    double data[size],average = 0.0,variance = 0.0;

    getData(data,size);

    computeStats(data,size,&average,&variance);

    printf("Average: %.2f\n",average);
    printf("Variance: %.2f\n",variance);


    return 0;
}

void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the result of experiment %d : ",i+1);
        scanf("%lf",&data[i]);
    }

}


void computeStats(const double *array, int size, double *average, double *variance){

    double sum = 0.0;
    double sumSquaredDiff = 0.0;

    for(int i = 0;i < size;i++) {

        sum += array[i];
    }

    *average = sum/size;

    for(int i = 0;i < size;i++) {

        sumSquaredDiff += (array[i] - *average) * (array[i] - *average);

    }

    *variance = sumSquaredDiff/size;

}