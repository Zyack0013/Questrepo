// 13.Object Recognition System
// Function Prototype: void recognizeObjects(const double *features, int size, char *objectLabels[])
// Data Types: const double*, int, char*[]
// Concepts: Decision-making, arrays, functions, pointers.
// Details: Recognize objects based on feature vectors, updating an array of object labels.



#include <stdio.h>
#include <string.h>


void recognizeObjects(double const *features, int size, char *objectLabels[]);

int main() {

    int size = 5;
    double features[] = {1.2, 5.8, 3.0, 0.5, 7.6};
    char *objectLabels[size];
    
    // for (int i = 0; i < size; i++) {
    //     objectLabels[i] = NULL;
    // }

    recognizeObjects(features,size,objectLabels);

    printf("Object Recognition Results\n |------------------------| \n");

    for(int i = 0; i < size; i++) {

        printf("Object %d: Feature = %.2f, Label = %s\n", i, features[i], objectLabels[i]);
    
    }

    return 0;
}

void recognizeObjects(double const *features, int size, char *objectLabels[]) {

    for(int i = 0; i < size; i++) {

        if(features[i] < 1.0) {

            objectLabels[i] = "Small Object";

        } else 
        if(features[i] >= 1.0 && features[i] <= 5.0) {

            objectLabels[i] = "Medium Object";

        } else 
        if(features[i] > 5.0) {

            objectLabels[i] = "Large Object";

        } else {

            objectLabels[i] = "Unknown Object";

        }
    }


}