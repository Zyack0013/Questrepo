// 11. CNC Machine Coordinates
// Requirements:
// Input: Current x, y, z coordinates (floats).
// Output: Updated coordinates.
// Function: Accepts pointers to x, y, z values and updates them.
// Constraints: Ensure updated coordinates remain within machine limits.


#include <stdio.h>


void updateCoordinates(float *x, float *y, float *z, float deltaX, float deltaY, float deltaZ, float minLimit, float maxLimit);

int main() {
    
    float x = 10.5, y = 20.0, z = 15.2;
    
    float deltaX = 5.0, deltaY = -25.0, deltaZ = 10.0;
    
    float minLimit = 0.0, maxLimit = 50.0;

    
    printf("Original Coordinates:\n");
    printf("X: %.2f, Y: %.2f, Z: %.2f\n", x, y, z);

    
    updateCoordinates(&x, &y, &z, deltaX, deltaY, deltaZ, minLimit, maxLimit);

    
    printf("\nUpdated Coordinates:\n");
    printf("X: %.2f, Y: %.2f, Z: %.2f\n", x, y, z);

    return 0;
}

/*

Name : updateCoordinates
Return Datatype : void
parameters : int *x,*y,*z,deltaX,deltaY,deltaZ,minLimit,maxLimit
Short discription: Fn that takes pointers to x, y, z and updates them

*/


void updateCoordinates(float *x, float *y, float *z, float deltaX, float deltaY, float deltaZ, float minLimit, float maxLimit) {
    
    *x += deltaX;
    if (*x < minLimit) {

        *x = minLimit;
        printf("X-coordinate adjusted to minimum limit: %.2f\n", minLimit);

    } else 
    if (*x > maxLimit) {

        *x = maxLimit;
        printf("X-coordinate adjusted to maximum limit: %.2f\n", maxLimit);

    }

    
    *y += deltaY;
    if (*y < minLimit) {

        *y = minLimit;
        printf("Y-coordinate adjusted to minimum limit: %.2f\n", minLimit);

    } else 
    if (*y > maxLimit) {

        *y = maxLimit;
        printf("Y-coordinate adjusted to maximum limit: %.2f\n", maxLimit);
    }

   
    *z += deltaZ;
    if (*z < minLimit) {

        *z = minLimit;
        printf("Z-coordinate adjusted to minimum limit: %.2f\n", minLimit);

    } else 
    if (*z > maxLimit) {

        *z = maxLimit;
        printf("Z-coordinate adjusted to maximum limit: %.2f\n", maxLimit);
    }
}
