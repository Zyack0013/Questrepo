// 6. Medicine Dosage Validator
// Create a program to validate medicine dosage for 10 patients based on weight and age.
// Use decision-making statements to determine if the dosage is within safe limits.
// Use volatile for real-time input of weight and age, and store results in an array.
// Loop through the array to display valid/invalid statuses for each patient.


#include <stdio.h>

#define PATIENT 10
#define MIN_WEIGHT 50
#define MAX_WEIGHT 100
#define MIN_AGE 18
#define MAX_AGE 65

void dosageValid(volatile int weight[], volatile int age[], int dosage[]);

int main() {

    volatile int weight[PATIENT];  
    volatile int age[PATIENT];     
    int dosage[PATIENT];           

    printf("Enter the weight (in kg) and age (in years) for 10 patients:\n");
    for (int i = 0; i < PATIENT; i++) {

        printf("Patient %d:\n", i + 1);
        printf("Enter weight (kg): ");
        scanf("%d", &weight[i]);
        printf("Enter age (years): ");
        scanf("%d", &age[i]);
        
    }

    
    dosageValid(weight, age, dosage);

    return 0;
}

void dosageValid(volatile int weight[], volatile int age[], int dosage[]){

    for (int i = 0; i < PATIENT; i++) {
        
        if (weight[i] < MIN_WEIGHT || weight[i] > MAX_WEIGHT || age[i] < MIN_AGE || age[i] > MAX_AGE){

            printf("Patient %d: Invalid dosage - Weight: %d kg, Age: %d years\n", i + 1, weight[i], age[i]);
        
        }else{

            dosage[i] = weight[i] * 5;
            printf("Patient %d: Valid dosage - Weight: %d kg, Age: %d years, Dosage: %d mg\n", i + 1, weight[i], age[i], dosage[i]);
        
        }
    }
}
