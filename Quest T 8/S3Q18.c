// 18. Process Temperature Control
// Requirements:
// Input: Current temperature (float).
// Output: Adjusted temperature.
// Function: Adjusts temperature using pointers.
// Constraints: Temperature must stay within a specified range.


#include <stdio.h>


void adjustTemperature(float *temperature, float minTemp, float maxTemp);

int main() {
    
    float temperature = 75.0;  

    
    float minTemp = 50.0;  
    float maxTemp = 100.0; 

    
    printf("Initial Temperature: %.2f°C\n", temperature);

    
    adjustTemperature(&temperature, minTemp, maxTemp);

    
    printf("Adjusted Temperature: %.2f°C\n", temperature);

    return 0;
}

/*

Name : adjustTemperature
Return Datatype : void
parameters : float *temperature,minTemp, maxTemp
Short discription: Fn that adjusts temperature using pointers.

*/

void adjustTemperature(float *temperature, float minTemp, float maxTemp) {
    
    if (*temperature < minTemp) {

        printf("Temperature below minimum allowed limit! Adjusting to %.2f°C...\n", minTemp);
        *temperature = minTemp;  
    } else 
    if (*temperature > maxTemp) {

        printf("Temperature above maximum allowed limit! Adjusting to %.2f°C...\n", maxTemp);
        *temperature = maxTemp;  
    }
}
