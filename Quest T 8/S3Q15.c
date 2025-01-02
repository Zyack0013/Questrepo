// 15. Product Quality Inspection
// Requirements:
// Input: Quality score (integer) for each product in a batch.
// Output: Updated quality metrics.
// Function: Updates quality metrics using pointers.
// Constraints: Ensure quality scores remain within 0-100.




#include <stdio.h>


void updateQualityMetrics(int *qualityScores, int batchSize);

int main() {
    
    int qualityScores[5] = {85, 90, 76, 92, 88};
    int batchSize = sizeof(qualityScores) / sizeof(qualityScores[0]);

    
    printf("Quality scores before update:\n");

    for(int i = 0; i < batchSize; i++) {

        printf("Product %d: %d\n", i + 1, qualityScores[i]);

    }

    
    updateQualityMetrics(qualityScores, batchSize);

    
    printf("\nUpdated quality scores:\n");
    for(int i = 0; i < batchSize; i++) {
        printf("Product %d: %d\n", i + 1, qualityScores[i]);
    }

    return 0;
}

/*

Name : updateQualityMetrics
Return Datatype : void
parameters : int *qualityScores,batchSize
Short discription: Fn that updates quality metrics using pointers.

*/

void updateQualityMetrics(int *qualityScores, int batchSize) {

    for(int i = 0; i < batchSize; i++) {
        
        if (*(qualityScores + i) > 100) {

            *(qualityScores + i) = 100;

        } else
        if (*(qualityScores + i) < 0) {

            *(qualityScores + i) = 0;
        }
    }
}
