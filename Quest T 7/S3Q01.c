// 1. Write a function that takes the original price of an item and a discount percentage as parameters. The function should return the discounted price without modifying the original price.
// Function Prototype:
// void calculateDiscount(float originalPrice, float discountPercentage);


#include <stdio.h>


void calculateDiscount(float originalPrice, float discountPercentage);

int main() {

    float price, discount;

    
    printf("Enter the original price: ");
    scanf("%f", &price);

    printf("Enter the discount percentage: ");
    scanf("%f", &discount);

    
    calculateDiscount(price, discount);

    return 0;
}

/*
Name : calculateDiscount
Return Datatype : void
parameters : float originalPrice, discountPercentage
Short discription: its used to print the discounted price

*/

void calculateDiscount(float originalPrice, float discountPercentage){

    if (originalPrice < 0 || discountPercentage < 0 || discountPercentage > 100){

        printf("Error: Invalid original price or discount percentage.\n");
        return;

    }

    float discountedPrice = originalPrice * (1 - discountPercentage / 100);
    
    printf("The discounted price is: %.2f\n", discountedPrice);

}