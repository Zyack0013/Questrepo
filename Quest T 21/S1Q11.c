// 11. Plasma Dynamics Simulator
// Description:
//  Simulate the behavior of plasma under various conditions.
// Specifications:
// Structure: Represents plasma parameters (density, temperature, and electric field).
// Array: Stores simulation results.
// Union: Handles either density or temperature data.
// Strings: Represent plasma types.
// const Pointers: Protect plasma parameters.
// Double Pointers: Manage dynamic allocation for simulation data.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    
    const char *type;      
    double density;        
    double temperature;    
    double electricField;  
} Plasma;


typedef union {

    double density;        
    double temperature;    

} PlasmaData;


void addPlasma(Plasma **plasmas, PlasmaData **data, int *size);
void displayPlasmas(Plasma *plasmas, PlasmaData *data, int size);
void freePlasmas(Plasma **plasmas, PlasmaData **data, int *size);

int main() {

    Plasma *plasmas = NULL;
    PlasmaData *data = NULL;        
    int size = 0;                   
    int choice;

    while (1) {

        printf("\n--- Plasma Dynamics Simulator ---\n");
        printf("1. Add Plasma Parameters\n");
        printf("2. Display Plasma Parameters\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addPlasma(&plasmas, &data, &size);
                break;
            case 2:
                displayPlasmas(plasmas, data, size);
                break;
            case 3:
                freePlasmas(&plasmas, &data, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}


void addPlasma(Plasma **plasmas, PlasmaData **data, int *size) {
    
    *plasmas = realloc(*plasmas, (*size + 1) * sizeof(Plasma));
    *data = realloc(*data, (*size + 1) * sizeof(PlasmaData));
   
    if (*plasmas == NULL || *data == NULL) {
   
        printf("Memory allocation failed!\n");
        return;
    }

    Plasma *newPlasma = &(*plasmas)[*size];
    PlasmaData *newData = &(*data)[*size];

    char type[50];
    printf("Enter the plasma type: ");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = '\0'; 
    newPlasma->type = strdup(type);

    printf("Enter the plasma density (particles/m^3): ");
    scanf("%lf", &newPlasma->density);
    printf("Enter the plasma temperature (Kelvin): ");
    scanf("%lf", &newPlasma->temperature);
    printf("Enter the electric field strength (V/m): ");
    scanf("%lf", &newPlasma->electricField);

    
    int choice;
    printf("Do you want to store (1) Density or (2) Temperature in the union? ");
    scanf("%d", &choice);
    getchar(); 
    
    if (choice == 1) {
    
        newData->density = newPlasma->density;
    
    } else 
    if (choice == 2) {
    
        newData->temperature = newPlasma->temperature;
    
    } else {
    
        printf("Invalid choice! Storing density by default.\n");
        newData->density = newPlasma->density;
    
    }

    (*size)++;
    printf("Plasma parameters added successfully!\n");
}


void displayPlasmas(Plasma *plasmas, PlasmaData *data, int size) {

    if (size == 0) {

        printf("No plasma parameters to display.\n");
        return;

    }

    printf("\n--- Plasma Parameters ---\n");
  
    for (int i = 0; i < size; i++) {
        
        printf("\nPlasma %d:\n", i + 1);
        printf("Type: %s\n", plasmas[i].type);
        printf("Density: %.2e particles/m^3\n", plasmas[i].density);
        printf("Temperature: %.2f K\n", plasmas[i].temperature);
        printf("Electric Field: %.2f V/m\n", plasmas[i].electricField);

        
        printf("Union Data: ");
        if (data[i].density == plasmas[i].density) {

            printf("Density: %.2e particles/m^3\n", data[i].density);

        } else {

            printf("Temperature: %.2f K\n", data[i].temperature);
        }
    }
}

void freePlasmas(Plasma **plasmas, PlasmaData **data, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*plasmas)[i].type); 

    }
    free(*plasmas);
    free(*data);
    *plasmas = NULL;
    *data = NULL;
    *size = 0;
}
