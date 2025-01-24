// 6. Thermodynamics State Calculator
// Description:
//  Calculate thermodynamic states of a system based on input parameters like pressure, volume, and temperature.
// Specifications:
// Structure: Represents thermodynamic properties (P, V, T, and entropy).
// Array: Stores states over a range of conditions.
// Union: Handles dependent properties like energy or entropy.
// Strings: Represent state descriptions.
// const Pointers: Protect thermodynamic data.
// Double Pointers: Allocate state data dynamically for simulation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    
    double energy;   
    double entropy;  
} ThermodynamicProperty;

typedef struct {
    const char *description;  
    double pressure;          
    double volume;            
    double temperature;       
    ThermodynamicProperty property; 
    char propertyType[10];    
} ThermodynamicState;


void addState(ThermodynamicState **states, int *size);
void displayStates(ThermodynamicState *states, int size);
void freeStates(ThermodynamicState **states, int *size);

int main() {

    ThermodynamicState *states = NULL; 
    int size = 0;                      
    int choice;

    while (1) {
        printf("\n--- Thermodynamics State Calculator ---\n");
        printf("1. Add Thermodynamic State\n");
        printf("2. Display Thermodynamic States\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                addState(&states, &size);
                break;
            case 2:
                displayStates(states, size);
                break;
            case 3:
                freeStates(&states, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }
    return 0;
}

void addState(ThermodynamicState **states, int *size) {
 
    *states = realloc(*states, (*size + 1) * sizeof(ThermodynamicState));
   
    if (*states == NULL) {
  
        printf("Memory allocation failed!\n");
        return;
    }

    ThermodynamicState *newState = &(*states)[*size];
    char description[50];
    printf("Enter the state description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0'; 
    newState->description = strdup(description);

    printf("Enter the pressure (P) in Pascals: ");
    scanf("%lf", &newState->pressure);
    printf("Enter the volume (V) in cubic meters: ");
    scanf("%lf", &newState->volume);
    printf("Enter the temperature (T) in Kelvin: ");
    scanf("%lf", &newState->temperature);

    printf("Enter the property type ('energy' or 'entropy'): ");
    getchar(); 
    fgets(newState->propertyType, sizeof(newState->propertyType), stdin);
    newState->propertyType[strcspn(newState->propertyType, "\n")] = '\0'; 

    if (strcmp(newState->propertyType, "energy") == 0) {
  
        printf("Enter the internal energy in Joules: ");
        scanf("%lf", &newState->property.energy);
 
    } else 
    if (strcmp(newState->propertyType, "entropy") == 0) {

        printf("Enter the entropy in J/K: ");
        scanf("%lf", &newState->property.entropy);
    } else {

        printf("Invalid property type! Defaulting to energy = 0.0.\n");
        newState->property.energy = 0.0;
        strcpy(newState->propertyType, "energy");
    }

    (*size)++;
    printf("Thermodynamic state added successfully!\n");
}

void displayStates(ThermodynamicState *states, int size) {

    if (size == 0) {

        printf("No thermodynamic states available to display.\n");
        return;

    }

    printf("\n--- Thermodynamic States ---\n");

    for (int i = 0; i < size; i++) {
        
        printf("\nState %d:\n", i + 1);
        printf("Description: %s\n", states[i].description);
        printf("Pressure: %.2lf Pa\n", states[i].pressure);
        printf("Volume: %.2lf m³\n", states[i].volume);
        printf("Temperature: %.2lf K\n", states[i].temperature);

        if (strcmp(states[i].propertyType, "energy") == 0) {
        
            printf("Energy: %.2lf J\n", states[i].property.energy);
        
        }else 
        if (strcmp(states[i].propertyType, "entropy") == 0) {
        
            printf("Entropy: %.2lf J/K\n", states[i].property.entropy);
        }
    }
}


void freeStates(ThermodynamicState **states, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*states)[i].description);

    }
    free(*states);
    *states = NULL;
    *size = 0;
}
