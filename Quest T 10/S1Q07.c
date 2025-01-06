// 7.AI Model Evaluator
// Function Prototype: void evaluateModels(const double *accuracies, int size, double *bestAccuracy)
// Data Types: const double*, int, double*
// Concepts: Loops, arrays, functions, pointers.
// Details: Evaluate multiple AI models, determining the best accuracy and updating it by reference.


#include <stdio.h>

void evaluateModels(double const *accuracies, int size, double *bestAccuracy);

int main() {

    double accuracies[] ={87.2, 90.9, 86.5, 91.8, 89.6};
    int size =5;
    double bestAccuracy = 0.0;

    evaluateModels(accuracies,size,&bestAccuracy);

    printf("Best Model Accuracy: %.2f\n",bestAccuracy);

    return 0;
}

void evaluateModels(double const *accuracies, int size, double *bestAccuracy) {

    *bestAccuracy = 0.0;

    for (int i = 0; i < size; i++) {
    
        if (accuracies[i] > *bestAccuracy) {

            *bestAccuracy = accuracies[i];
        }
    }


}
