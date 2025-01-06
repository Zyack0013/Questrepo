// 3.Experimental Report Generator
// Function Prototype: void generateReport(const double *results, const char *descriptions[], int size)
// Data Types: const double*, const char*[], int
// Concepts: Strings, arrays, functions, passing constant data.
// Details: Generate a report summarizing experimental results and their descriptions, using constant data to ensure the input is not modified.

#include <stdio.h>


void generateReport(const double *results, const char *descriptions[], int size);

int main() {

    int size = 4;

    double results[] = {8.9, 7.3, 8.1, 5.9};
    char const *descriptions[] = {

        "Temperature Stability Test",
        "Pressure Monitoring Test",
        "Voltage Fluctuation Test",
        "Structural Load Test"

    };

    generateReport(results,descriptions, size);;
    


    return 0;
}

void generateReport(double const *results, char const *descriptions[], int size) {

    printf("Experimental Results Report\n");
    printf("\n");
    for (int i = 0; i < size; i++) {

        printf("%d. %s\n", i + 1, descriptions[i]);
        printf("   Result: %.2f\n", results[i]);
    }
    printf("|--------------------------|\n");

}