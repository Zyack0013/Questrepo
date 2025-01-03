// 7. Satellite Telemetry Analysis
// Pointers: Traverse telemetry data arrays.
// Arrays: Store telemetry parameters (e.g., power, temperature, voltage).
// Functions:
// void analyze_telemetry(const double *data, int size): Computes statistical metrics for telemetry data.
// void filter_outliers(double *data, int size): Removes outliers from the telemetry data array.
// Pass Arrays as Pointers: Pass telemetry data arrays to both functions.

#include <stdio.h>
#include <math.h>


void analyze_telemetry(double const *data, int size);
void filter_outliers(double *data, int *size);

int main() {
    
    double telemetry_data[] = {10.5, 12.0, 8.5, 11.0, 100.0, 9.8, 10.1, 10.9, 200.0, 9.6};
    int size = sizeof(telemetry_data) / sizeof(telemetry_data[0]);

    printf("Original Telemetry Data:\n");

    for (int i = 0; i < size; i++) {

        printf("%.2f ", telemetry_data[i]);

    }
    printf("\n");

    
    analyze_telemetry(telemetry_data, size);

    
    filter_outliers(telemetry_data, &size);

    printf("\nFiltered Telemetry Data (after removing outliers):\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", telemetry_data[i]);
    }
    printf("\n");

    return 0;
}


void analyze_telemetry(double const *data, int size) {
    
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        
        sum += data[i];
    
    }

    double mean = sum / size;
    double variance = 0.0;

    for (int i = 0; i < size; i++) {

        variance += (data[i] - mean) * (data[i] - mean);
    }

    double stddev = sqrt(variance / size);

    printf("\nTelemetry Data Analysis:\n");
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stddev);
}


void filter_outliers(double *data, int *size) {
    
    for (int i = 0; i < *size - 1; i++) {

        for (int j = i + 1; j < *size; j++) {

            if (data[i] > data[j]) {

                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;

            }
        }
    }

    
    int q1_index = *size / 4;
    int q3_index = *size * 3 / 4;
    double Q1 = data[q1_index];
    double Q3 = data[q3_index];

    
    double IQR = Q3 - Q1;

    
    double lower_bound = Q1 - 1.5 * IQR;
    double upper_bound = Q3 + 1.5 * IQR;

    
    int new_size = 0;

    for (int i = 0; i < *size; i++) {

        if (data[i] >= lower_bound && data[i] <= upper_bound) {

            data[new_size++] = data[i];
            
        }
    }

    *size = new_size;
}
