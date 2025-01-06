// 6.Artificial Intelligence
// Neural Network Weight Adjuster
// Function Prototype: void adjustWeights(double *weights, int size, double learningRate)
// Data Types: double*, int, double
// Concepts: Pointers, arrays, functions, loops.
// Details: Adjust neural network weights using a given learning rate, with weights passed by reference.


#include <stdio.h>


void readData(double *weights,int size);
void adjustWeights(double *weights, int size, double learningRate);

int main() {

    double weights[] = {0.5, -0.2, 0.8, 0.1, -0.5};
    int size = 5;
    double learningRate = 0.05;

    printf("\nWeights before adjustment:\n");
    readData(weights,size);

    adjustWeights(weights,size,learningRate);

    printf("\nWeights after adjustment:\n");
    readData(weights,size);


    return 0;
}
void adjustWeights(double *weights, int size, double learningRate){

    for (int i = 0; i < size; i++) {

        weights[i] -= learningRate * weights[i]; 
    
    }

}

void readData(double *weights,int size) {

    for (int i = 0; i < size; i++) {

        printf("Weight %d = %.2f\n",i+1,weights[i]);

    }

}