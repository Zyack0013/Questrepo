// 20. Shift Performance Analysis
// Requirements:
// Input: Production data for each shift (array of integers).
// Output: Updated performance metrics.
// Function: Calculates and updates overall performance using pointers.
// Constraints: Validate data inputs before calculations.


#include <stdio.h>


void analyzeShiftPerformance(int *shiftData, int size, int *performanceMetrics);

int main() {
    
    int shiftData[] = {200, 150, 180, 220, 160};  
    int size = sizeof(shiftData) / sizeof(shiftData[0]);

    
    int performanceMetrics[2]; 

    
    printf("Shift Production Data:\n");
    for (int i = 0; i < size; i++) {

        printf("Shift %d: %d units\n", i + 1, shiftData[i]);

    }

    
    analyzeShiftPerformance(shiftData, size, performanceMetrics);

    
    printf("\nPerformance Metrics:\n");
    printf("Total Production: %d units\n", performanceMetrics[0]);
    printf("Average Production: %.2f units\n", performanceMetrics[1]);

    return 0;
}

/*

Name : analyzeShiftPerformance
Return Datatype : void
parameters : int *shiftData,size, *performanceMetrics
Short discription: Fn that modifies the scrap count via pointers.

*/

void analyzeShiftPerformance(int *shiftData, int size, int *performanceMetrics) {

    if (size <= 0) {

        printf("Error: Invalid shift data size.\n");
        return;
    }

    int totalProduction = 0;

    
    for (int i = 0; i < size; i++) {

        if (*(shiftData + i) < 0) {

            printf("Warning: Negative production data at shift %d. Setting to 0.\n", i + 1);
            *(shiftData + i) = 0; 

        }
        totalProduction += *(shiftData + i);  
    }

    
    float averageProduction = (float)totalProduction / size;

    
    performanceMetrics[0] = totalProduction;
    performanceMetrics[1] = averageProduction;
}
