// 5. Write a function that receives an array of item prices and the number of items. The function should return the total cost of the order without modifying the individual item prices.
// Function Prototype:
// float calculateOrderTotal(float prices[], int numberOfItems);


#include <stdio.h>


float calculateOrderTotal(float prices[], int numberOfItems);

int main() {

    int numberOfItems;

    
    printf("Enter the number of items: ");
    scanf("%d", &numberOfItems);

    float prices[numberOfItems];

    
    for (int i = 0; i < numberOfItems; i++) {

        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &prices[i]);

    }

    
    float totalCost = calculateOrderTotal(prices, numberOfItems);

    
    printf("The total cost of the order is: %.2f\n", totalCost);

    return 0;
}

/*

Name : calculateOrderTotal
Return Datatype : float
parameters : float prices[],int numberOfItems;
Short discription: its used to return the total cost of the order 

*/

float calculateOrderTotal(float prices[], int numberOfItems) {
    
    float total = 0;

    
    for (int i = 0; i < numberOfItems; i++) {

        total += prices[i];
    }

    return total;
}
