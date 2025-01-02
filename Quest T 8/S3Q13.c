// 13. Production Rate Monitor
// Requirements:
// Input: Current production rate (integer) and adjustment factor.
// Output: Updated production rate.
// Function: Modifies the production rate via a pointer.
// Constraints: Production rate must be within permissible limits.


#include <stdio.h>


void adjustProductionRate(int *productionRate, float adjustmentFactor, int minRate, int maxRate);

int main() {
   
    int productionRate = 100; 
    float adjustmentFactor = 1.2; 
    int minRate = 50;  
    int maxRate = 200; 

    
    printf("Initial Production Rate: %d\n", productionRate);

    
    adjustProductionRate(&productionRate, adjustmentFactor, minRate, maxRate);

 
    printf("Updated Production Rate: %d\n", productionRate);

    return 0;
}

/*

Name : adjustProductionRate
Return Datatype : void
parameters : int *productionRate, minRate,maxRate, float adjustmentFactor
Short discription: Fn that modifies the production rate via a pointer.

*/


void adjustProductionRate(int *productionRate, float adjustmentFactor, int minRate, int maxRate) {
   
    int newRate = (int)(*productionRate * adjustmentFactor);

    
    if (newRate < minRate) {

        *productionRate = minRate; 

    } else 
    if (newRate > maxRate) {

        *productionRate = maxRate; 

    } else {
        *productionRate = newRate; 
    }
}
