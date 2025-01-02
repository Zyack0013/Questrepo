// 4. Robotic Arm Positioning
// Requirements:
// Input: Current x, y, z coordinates (integers) and movement delta values.
// Output: Updated coordinates.
// Function: Takes pointers to x, y, z and updates them based on delta values.
// Constraints: Validate that the coordinates stay within the workspace boundaries.


#include <stdio.h>


void updatePosition(int *x, int *y, int *z, int deltaX, int deltaY, int deltaZ, int minBound, int maxBound);

int main() {

    int x = 10, y = 20, z = 25;      
    int deltaX = 4, deltaY = -11, deltaZ = 9; 
    int minBound = 0, maxBound = 25; 

    printf("Initial Position: (x = %d, y = %d, z = %d)\n", x, y, z);

    updatePosition(&x, &y, &z, deltaX, deltaY, deltaZ, minBound, maxBound);

    printf("Updated Position: (x = %d, y = %d, z = %d)\n", x, y, z);

    return 0;
}

/*

Name : updatePosition
Return Datatype : void
parameters : int *x,*y,*z,deltaX,deltaY,deltaZ,minBound,maxBound
Short discription: Fn that takes pointers to x, y, z and updates them based on delta values.

*/



void updatePosition(int *x, int *y, int *z, int deltaX, int deltaY, int deltaZ, int minBound, int maxBound) {


    *x += deltaX;

    if (*x < minBound) {
        
        *x = minBound;
    } 
    if (*x > maxBound) {

        *x = maxBound;
    }


    *y += deltaY;

    if (*y < minBound) {

        *y = minBound;
    }
    if (*y > maxBound) {

        *y = maxBound;
    }

    *z += deltaZ;

    if (*z < minBound) {

        *z = minBound;
    }
    if (*z > maxBound) {

        *z = maxBound;
    }
}
