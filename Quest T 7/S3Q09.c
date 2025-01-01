// 9. Write a function that takes two prices from different vendors and returns the lower price without modifying either input price.
// Function Prototype:
// float findLowerPrice(float priceA, float priceB);


#include <stdio.h>


float findLowerPrice(float priceA, float priceB);

int main() {

    float priceA, priceB;

 
    printf("Enter the price from Vendor A: ");
    scanf("%f", &priceA);
    
    printf("Enter the price from Vendor B: ");
    scanf("%f", &priceB);

 
    float lowerPrice = findLowerPrice(priceA, priceB);

 
    printf("The lower price is: %.2f\n", lowerPrice);

    return 0;
}

/*

Name : findLowerPrice
Return Datatype : float
parameters : float priceA,priceB
Short discription: Fn that takes two prices from different vendors and returns the lower price

*/

float findLowerPrice(float priceA, float priceB) {
    
    if (priceA < priceB) {
        return priceA;
    }
    return priceB;
}
