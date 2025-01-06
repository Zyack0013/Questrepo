// 10.Training Data Generator
// Function Prototype: double* generateTrainingData(const double *baseData, int size, int multiplier)
// Data Types: const double*, int, double*
// Concepts: Arrays, functions returning pointers, loops.
// Details: Generate training data by applying a multiplier to base data, returning a pointer to the new data array.


#include <stdio.h>

double* generateTrainingData(double const *baseData, int size, int multiplier);

int main() {

    int size;
    int multiplier;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {

        printf("Invalid size. Exiting program.\n");
        return 1;
    }

    double baseData[size];

    printf("Enter %d elements for the base array:\n", size);

    for (int i = 0; i < size; i++) {

        scanf("%lf", &baseData[i]);

    }

    printf("Enter the multiplier: ");
    scanf("%d", &multiplier);

    double *trainingData = generateTrainingData(baseData,size,multiplier);

    printf("\nBase Data: ");
    for(int i = 0; i < size; i++) {
        
        printf("%.2lf ", baseData[i]);
    
    }

    printf("\nTraining Data: ");
    
    for(int i = 0; i < size; i++) {

        printf("%.2lf ", trainingData[i]);

    }
    printf("\n");



    return 0;
}

double* generateTrainingData(double const *baseData, int size, int multiplier){

    static double trainingData[100]; 

    for (int i = 0; i < size; i++) {

        trainingData[i] = baseData[i] * multiplier;
    
    }

    return trainingData;

}