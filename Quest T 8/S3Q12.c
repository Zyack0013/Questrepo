// 12. Energy Consumption Tracker
// Requirements:
// Input: Energy usage data for machines (array of floats).
// Output: Total energy consumed (float).
// Function: Calculates and updates total energy using pointers.
// Constraints: Validate that no energy usage value is negative.


#include <stdio.h>


void calculateTotalEnergy(float *energyUsage, int size, float *totalEnergy);

int main() {
    
    float energyUsage[] = {50.5, 75.0, 90.2, 60.0, -10.0}; 
    int size = sizeof(energyUsage) / sizeof(energyUsage[0]);
    float totalEnergy = 0.0;

    
    calculateTotalEnergy(energyUsage, size, &totalEnergy);

    printf("Total Energy Consumed: %.2f units\n", totalEnergy);

    return 0;
}

/*

Name : calculateTotalEnergy
Return Datatype : void
parameters : float *energyUsage, *totalEnergy, int size
Short discription: Fn that calculates and updates total energy using pointers.

*/


void calculateTotalEnergy(float *energyUsage, int size, float *totalEnergy) {
    
    *totalEnergy = 0.0; 

    for (int i = 0; i < size; i++) {

        if (energyUsage[i] < 0) {

            printf("Invalid energy usage at index %d: %.2f (ignoring)\n", i, energyUsage[i]);
            continue; 
        }
        *totalEnergy += *(energyUsage + i); 
    }
}
