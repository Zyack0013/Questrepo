// 3. Machine Speed Calculation
// Input: Two floating-point numbers: belt speed (m/s) and pulley diameter (m).
// Output: The RPM of the machine.
// Function:
// float rpm(float beltSpeed, float pulleyDia);


#include <stdio.h>

#define PI 3.14159265359

float rpm(float beltSpeed,float pulleyDia);

int main(){

    float beltSpeed,pulleyDia,rpmResult;

    printf("Enter the belt speed : ");
    scanf("%f",&beltSpeed);

    printf("Enter the pulley diameter : ");
    scanf("%f",&pulleyDia);

    rpmResult = rpm(beltSpeed,pulleyDia);

    if(pulleyDia > 0){

        printf("The RPM of the machine is: %.2f\n",rpmResult);

    }

    return 0;
}


float rpm(float beltSpeed,float pulleyDia){

    if(pulleyDia<= 0){

        printf("Invalid pulley diameter. It must be greater than zero.\n");
        return 0.0;
    }

    float circumference = PI * pulleyDia; 
    float rpm = (beltSpeed / circumference) * 60; 
    return rpm;
}