// 4. Design a function that takes the amount spent by a customer and returns the loyalty points earned based on a specific conversion rate (e.g., 1 point for every $10 spent). The original amount spent should remain unchanged.
// Function Prototype:
// int calculateLoyaltyPoints(float amountSpent);


#include <stdio.h>


int calculateLoyaltyPoints(float amountSpent);

int main() {

    float amountSpent;
    int loyaltyPoints;

    
    printf("Enter the amount spent by the customer: ");
    scanf("%f", &amountSpent);

    
    loyaltyPoints = calculateLoyaltyPoints(amountSpent);

    
    printf("The customer earned %d loyalty points for spending Rs.%.2f.\n", loyaltyPoints, amountSpent);

    return 0;
}

/*

Name : calculateLoyaltyPoints
Return Datatype : float
parameters : float amountSpent
Short discription: its used to return the loyalty points earned based on a specific conversion rate  

*/

int calculateLoyaltyPoints(float amountSpent){

    int points = (int)(amountSpent / 10); 
    return points;
}