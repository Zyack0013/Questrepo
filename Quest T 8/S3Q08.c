// 8. Welding Machine Configuration
// Requirements:
// Input: Voltage (float) and current (float).
// Output: Updated machine configuration.
// Function: Accepts pointers to voltage and current and modifies their values.
// Constraints: Validate that voltage and current stay within specified operating ranges.


#include <stdio.h>

void configureMachine(float *voltage, float *current, float maxVoltage, float minVoltage, float maxCurrent, float minCurrent);

int main() {
    
    float voltage, current;
    
    float maxVoltage = 240.0, minVoltage = 100.0;
    float maxCurrent = 200.0, minCurrent = 50.0;

    
    printf("Enter the voltage: ");
    scanf("%f", &voltage);

    printf("Enter the current: ");
    scanf("%f", &current);

   
    configureMachine(&voltage, &current, maxVoltage, minVoltage, maxCurrent, minCurrent);

   
    printf("Updated Configuration:\n");
    printf("Voltage: %.2f V\n", voltage);
    printf("Current: %.2f A\n", current);

    return 0;
}


/*

Name : configureMachine
Return Datatype : void
parameters : float *voltage,*current,maxVoltage,minVoltage,maxCurrent,minCurrent
Short discription: Fn that accepts pointers to voltage and current and modifies their values.

*/

void configureMachine(float *voltage, float *current, float maxVoltage, float minVoltage, float maxCurrent, float minCurrent) {
    
    if (*voltage > maxVoltage) {

        *voltage = maxVoltage;
        printf("Warning: Voltage exceeded the maximum limit. Adjusted to %.2f V.\n", maxVoltage);

    } else 
    if(*voltage < minVoltage) {

        *voltage = minVoltage;
        printf("Warning: Voltage was below the minimum limit. Adjusted to %.2f V.\n", minVoltage);

    }

   
    if (*current > maxCurrent) {

        *current = maxCurrent;
        printf("Warning: Current exceeded the maximum limit. Adjusted to %.2f A.\n", maxCurrent);

    } else 
    if(*current < minCurrent) {

        *current = minCurrent;
        printf("Warning: Current was below the minimum limit. Adjusted to %.2f A.\n", minCurrent);

    }
}
