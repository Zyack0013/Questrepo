// 7. Implement a function that takes the weight of a package and calculates shipping costs based on weight brackets (e.g., $5 for up to 5kg, $10 for 5-10kg). The original weight should remain unchanged.
// Function Prototype:
// float calculateShippingCost(float weight);


#include <stdio.h>

float calculateShippingCost(float weight);

int main() {

    float packageWeight;

    
    printf("Enter the weight of the package (in kg): ");
    scanf("%f", &packageWeight);

    
    float shippingCost = calculateShippingCost(packageWeight);

    
    printf("The shipping cost for a package weighing %.2f kg is: $%.2f\n", packageWeight, shippingCost);

    return 0;
}

/*

Name : calculateShippingCost
Return Datatype : float
parameters : float weight
Short discription: its used to return the shipping costs based on weight brackets (e.g., $5 for up to 5kg, $10 for 5-10kg)

*/

float calculateShippingCost(float weight) {

    if (weight <= 0) {

        return 0; 

    } else 
    if (weight <= 5) {

        return 5.0; 

    } else 
    if (weight <= 10){

        return 10.0; 

    } else {

        return 15.0; 

    }
}
