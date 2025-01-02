// 10. Assembly Line Optimization
// Requirements:
// Input: Timing intervals between stations (array of floats).
// Output: Adjusted timing intervals.
// Function: Modifies the array values using pointers.
// Constraints: Timing intervals must remain positive.




#include <stdio.h>


void optimizeTimings(float *timings, int size);

int main() {
    
    float timings[] = {5.5, -3.2, 8.0, 6.7, -1.0};
    int size = sizeof(timings) / sizeof(timings[0]);

    
    printf("Original Timing Intervals:\n");
    for (int i = 0; i < size; i++) {
        printf("Station %d: %.2f seconds\n", i + 1, timings[i]);
    }

    
    optimizeTimings(timings, size);

   
    printf("\nOptimized Timing Intervals:\n");
    for (int i = 0; i < size; i++) {
        printf("Station %d: %.2f seconds\n", i + 1, timings[i]);
    }

    return 0;
}

/*

Name : optimizeTimings
Return Datatype : void
parameters : float *timings, int size
Short discription: Fn that modifies the array values using pointers

*/

void optimizeTimings(float *timings, int size) {

    for (int i = 0; i < size; i++) {

        if (*(timings + i) < 0) {

            *(timings + i) = 0.0;  
            printf("Warning: Timing at station %d was negative. Adjusted to 0.00 seconds.\n", i + 1);

        }
    }
}
