// 3. Determine Voting Eligibility with Criteria:
//  A person can vote if:
// Their age is greater than or equal to 18 (relational operator).
// They are a registered citizen, represented by a specific bit set in their ID number (bit masking and bitwise AND).
//  Write a program to verify these conditions using logical operators.

#include <stdio.h>

int main(){

    int age,id,idbit;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your ID number: ");
    scanf("%d", &id);

    printf("Enter specific bit set in their ID number: ");
    scanf("%d", &idbit);

    if(age>=18 && id&(1<<idbit)){
        printf("You are eligible for Voiting");
    }else {
        printf("You are not eligible");
    }

    
    return 0;
}