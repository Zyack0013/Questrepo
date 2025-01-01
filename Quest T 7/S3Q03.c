// 3. Implement a function that accepts the price of an item and a sales tax rate. The function should return the total price after tax without altering the original price.
// Function Prototype:
// float calculateTotalPrice(float itemPrice, float taxRate);


#include <stdio.h>

float calculateTotalPrice(float itemPrice, float taxRate);

int main() {

    float itemPrice, taxRate, totalPrice;

    
    printf("Enter the price of the item: ");
    scanf("%f", &itemPrice);

    
    printf("Enter the sales tax rate (in percentage): ");
    scanf("%f", &taxRate);

    
    totalPrice = calculateTotalPrice(itemPrice, taxRate);

    
    printf("The total price after applying %.2f%% tax is: %.2f\n", taxRate, totalPrice);

    return 0;
}

/*

Name : calculateTotalPrice
Return Datatype : float
parameters : float itemPrice, taxRate
Short discription: its used to return the total price after tax 

*/

float calculateTotalPrice(float itemPrice, float taxRate){
    
    float totalPrice = itemPrice + (itemPrice * taxRate / 100);

    return totalPrice;
}