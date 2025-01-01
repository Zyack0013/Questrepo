// 6. Create a function that takes an item's price and a refund percentage as input. The function should return the refund amount without changing the original item's price.
// Function Prototype:
// float calculateRefund(float itemPrice, float refundPercentage);





#include <stdio.h>


float calculateRefund(float itemPrice, float refundPercentage);

int main() {

    float itemPrice, refundPercentage;

    
    printf("Enter the price of the item: ");
    scanf("%f", &itemPrice);
    printf("Enter the refund percentage: ");
    scanf("%f", &refundPercentage);

  
    float refundAmount = calculateRefund(itemPrice, refundPercentage);

   
    printf("The refund amount is: %.2f\n", refundAmount);

    return 0;
}

/*

Name : calculateRefund
Return Datatype : float
parameters : float itemPrice, refundPercentage
Short discription: its used to return the refund amount 

*/

float calculateRefund(float itemPrice, float refundPercentage) {

    return (itemPrice * refundPercentage) / 100.0;

}
