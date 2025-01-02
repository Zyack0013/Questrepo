// 1. Machine Efficiency Calculation
// Requirements:
// Input: Machine's input power and output power as floats.
// Output: Efficiency as a float.
// Function: Accepts pointers to input power and output power, calculates efficiency, and updates the result via a pointer.
// Constraints: Efficiency = (Output Power / Input Power) * 100.


#include <stdio.h>


void calculateEfficiency(float *a,float *b,float *c);


int main() {

    float input_power,output_power,efficiency;

    printf("Enter the input power : ");
    scanf("%f",&input_power);

    printf("Enter the output power : ");
    scanf("%f",&output_power);

    calculateEfficiency(&input_power,&output_power,&efficiency);

    printf("The efficiency of the machine is %.2f",efficiency);


    return 0;
}

/*

Name : calculateEfficiency
Return Datatype : void
parameters : float *input_power,*output_power,*efficiency
Short discription: Fn that accepts pointers to input power and output power, calculates efficiency, and updates the result via a pointer.

*/

void calculateEfficiency(float *a,float *b,float *c) {

    if(*a != 0) {

        *c = (*b / *a)*100;
    }else {

        printf("No input power");
        *c = 0;
    }


}