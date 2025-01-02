// 5. Temperature Control in Furnace
// Requirements:
// Input: Current temperature (float) and desired range.
// Output: Adjusted temperature.
// Function: Uses pointers to adjust temperature within the range.
// Constraints: Temperature adjustments must not exceed safety limits.



#include <stdio.h>

// Function prototype
void adjustTemperature(float *currentTemp, float minTemp, float maxTemp);

int main() {
    float currentTemperature; 
    float minTemperature = 50.0;    
    float maxTemperature = 100.0;   

    printf("Enter the current temperature : \n");
    scanf("%f",&currentTemperature);

    
    adjustTemperature(&currentTemperature, minTemperature, maxTemperature);

    printf("Adjusted temperature: %.2f°C\n", currentTemperature);

    return 0;
}

/*

Name : adjustTemperature
Return Datatype : void
parameters : float *currentTemp,minTemp,maxTemp
Short discription: Fn that uses pointers to adjust temperature within the range..

*/

void adjustTemperature(float *currentTemp, float minTemp, float maxTemp) {

    if (*currentTemp < minTemp) {

        printf("Temperature below safe limit!!!.\nIncreasing to minimum safe limit\n");
        *currentTemp = minTemp;

    } else 
    if (*currentTemp > maxTemp){

        printf("Temperature above safe limit!!!.\nReducing to maximum safe limit.\n");
        *currentTemp = maxTemp;

    } else{

        printf("Temperature is within the safe range. No adjustment needed.\n");

    }
}
