// 8. Design a function that converts an amount from one currency to another based on an exchange rate provided as input. The original amount should not be altered.
// Function Prototype:
// float convertCurrency(float amount, float exchangeRate);



#include <stdio.h>

float convertCurrency(float amount, float exchangeRate);

int main() {

    float amount, exchangeRate;

   
    printf("Enter the amount to convert: ");
    scanf("%f", &amount);
    
    printf("Enter the exchange rate: ");
    scanf("%f", &exchangeRate);

    float convertedAmount = convertCurrency(amount, exchangeRate);

    
    printf("Converted amount: %.2f\n", convertedAmount);

    return 0;
}

/*

Name : convertCurrency
Return Datatype : float
parameters : float amount,exchangeRate
Short discription: its used to converts an amount from one currency to another based on an exchange rate

*/

float convertCurrency(float amount, float exchangeRate){

    return amount * exchangeRate;

}
