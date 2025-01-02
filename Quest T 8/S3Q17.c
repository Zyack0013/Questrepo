// 17. Packaging Machine Settings
// Requirements:
// Input: Machine settings like speed (float) and wrap tension (float).
// Output: Updated settings.
// Function: Modifies settings via pointers.
// Constraints: Validate settings remain within safe operating limits.


#include <stdio.h>


void updateMachineSettings(float *speed, float *wrapTension, float maxSpeed, float maxTension);

int main() {
    
    float speed = 50.0;        
    float wrapTension = 10.0;  

    
    float maxSpeed = 100.0;    
    float maxTension = 20.0;   

    
    printf("Initial Machine Settings:\n");
    printf("Speed: %.2f meters/min\n", speed);
    printf("Wrap Tension: %.2f kg\n", wrapTension);

   
    updateMachineSettings(&speed, &wrapTension, maxSpeed, maxTension);

    
    printf("\nUpdated Machine Settings:\n");
    printf("Speed: %.2f meters/min\n", speed);
    printf("Wrap Tension: %.2f kg\n", wrapTension);

    return 0;
}

/*

Name : updateMachineSettings
Return Datatype : void
parameters : float *speed,*wrapTension,maxSpeed,maxTension
Short discription: Fn that modifies settings via pointers

*/

void updateMachineSettings(float *speed, float *wrapTension, float maxSpeed, float maxTension) {
    
    if (*speed > maxSpeed) {

        printf("\nWarning: Speed exceeds maximum allowed limit! Adjusting to %.2f meters/min...\n", maxSpeed);
        *speed = maxSpeed;  
    }

    
    if (*wrapTension > maxTension) {

        printf("Warning: Wrap tension exceeds maximum allowed limit! Adjusting to %.2f kg...\n", maxTension);
        *wrapTension = maxTension;  
}

}