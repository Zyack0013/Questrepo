// 2. Conveyor Belt Speed Adjustment
// Requirements:
// Input: Current speed (float) and adjustment value (float).
// Output: Updated speed.
// Function: Uses pointers to adjust the speed dynamically.
// Constraints: Ensure speed remains within the allowable range (0 to 100 units).


#include <stdio.h>

void speedAdjust(float *speed,float *adjustment_value);

int main() {

    float speed,adjustment_value;

    printf("Enter the speed : ");
    scanf("%f",&speed);

    printf("Enter the adjustment value : ");
    scanf("%f",&adjustment_value);

    speedAdjust(&speed,&adjustment_value);

    printf("The speed after update : %.2f",speed);

    return 0;
}
/*

Name : speedAdjust
Return Datatype : void
parameters : float *speed,*adjustment_value
Short discription: Fn that Uses pointers to adjust the speed 

*/
void speedAdjust(float *speed,float *adjustment_value){

    *speed += *adjustment_value;

    if(*speed > 100){

        *speed = 100.0;
    }else
    if(*speed < 0) {

        *speed = 0.0;
    }


}