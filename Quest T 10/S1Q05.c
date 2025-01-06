// 5.Data Classifier
// Function Prototype: void classifyData(const double *data, int size, char *labels[], double threshold)
// Data Types: const double*, int, char*[], double
// Concepts: Decision-making, arrays, functions, pointers.
// Details: Classify data points into categories based on a threshold, updating an array of labels.

#include <stdio.h>

void classifyData(double const *data, int size, char *labels[], double threshold);

int main() {

    double data[] ={9.9,21.3,4.3,31.1,13.6,72.8,39.7};
    double threshold = 30;
    int size = 7;
    char *labels[size];

    classifyData(data,size,labels,threshold);

    printf("Data Classification Results : \n");
    
    for (int i = 0; i < size; i++) {

        printf("Data %d = %.2f --> Label: %s\n", i+1, data[i],labels[i]);
    }

    return 0;
}

void classifyData(double const *data, int size, char *labels[], double threshold) {

    for(int i = 0;i < size;i++) {

        if(data[i]>threshold) {

            labels[i] = "High";

        }else 
        if(data[i]<threshold) {

            labels[i] = "Low";

        }else {

            labels[i] = "Equal";
        }
    }


}