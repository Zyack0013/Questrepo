// 4.Data Anomaly Detector
// Function Prototype: void detectAnomalies(const double *data, int size, double threshold, int *anomalyCount)
// Data Types: const double*, int, double, int*
// Concepts: Decision-making, arrays, pointers, functions.
// Details: Detect anomalies in a dataset based on a threshold, updating the anomaly count by reference.



#include <stdio.h>

void detectAnomalies(double const *data, int size, double threshold, int *anomalyCount);

int main() {

    double data[] = {9.9,21.3,4.3,31.1,13.6,72.8,39.7};
    int size =7,anomalyCount=0;
    double threshold = 50;

    detectAnomalies(data,size,threshold,&anomalyCount);

    printf("Total anomalies detected: %d\n", anomalyCount);


    return 0;
}

void detectAnomalies(double const *data, int size, double threshold, int *anomalyCount) {

    *anomalyCount = 0;

    printf("Analyzing data for anomalies (Threshold: %.2f)\n",threshold);

    for (int i = 0;i < size;i++) {

        if (data[i] > threshold) {

            (*anomalyCount)++; 
            printf("Anomaly detected at index %d: Value = %.2f\n",i,data[i]);
        }
    }

    if (*anomalyCount == 0) {

        printf("No anomalies detected.\n");

    }


}