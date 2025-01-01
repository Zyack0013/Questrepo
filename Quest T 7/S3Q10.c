// 10. Create a function that checks if a customer is eligible for a senior citizen discount based on their age. The function should take age as input and return whether they qualify without changing the age value.
// Function Prototype:
// bool isEligibleForSeniorDiscount(int age);


#include <stdio.h>
#include <stdbool.h>  


bool isEligibleForSeniorDiscount(int age);

int main() {

    int age;

    printf("Enter the customer's age: ");
    scanf("%d", &age);

   
    if (isEligibleForSeniorDiscount(age)) {

        printf("The customer is eligible for a senior citizen discount.\n");

    } else {

        printf("The customer is not eligible for a senior citizen discount.\n");

    }

    return 0;
}

/*

Name : isEligibleForSeniorDiscount
Return Datatype : bool
parameters : int age
Short discription: function that take age as input and return whether they qualify(True or false)

*/

bool isEligibleForSeniorDiscount(int age) {
    
    if (age >= 65) {
        return true;
    }
    return false;
}
