// 4. Quantum State Representation System
// Description:
//  Develop a program to represent quantum states and their evolution over time.
// Specifications:
// Structure: Holds state properties (wavefunction amplitude, phase, and energy).
// Array: Represents the wavefunction across multiple points.
// Union: Stores amplitude or phase information.
// Strings: Describe state labels (e.g., "ground state," "excited state").
// const Pointers: Protect state properties.
// Double Pointers: Manage quantum states dynamically.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef union {
  
    double amplitude; 
    double phase;     

} QuantumProperty;

typedef struct {
    const char *stateLabel;       
    double energy;               
    QuantumProperty property;     
    char propertyType[10];        
    double *wavefunction;         
    int numPoints;                
} QuantumState;


void addQuantumState(QuantumState **states, int *size);
void displayQuantumStates(QuantumState *states, int size);
void freeQuantumStates(QuantumState **states, int *size);

int main() {

    QuantumState *quantumStates = NULL; 
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- Quantum State Representation System ---\n");
        printf("1. Add Quantum State\n");
        printf("2. Display Quantum States\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addQuantumState(&quantumStates, &size);
                break;
            case 2:
                displayQuantumStates(quantumStates, size);
                break;
            case 3:
                freeQuantumStates(&quantumStates, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }
    return 0;
}


void addQuantumState(QuantumState **states, int *size) {
 
    *states = realloc(*states, (*size + 1) * sizeof(QuantumState));

    if (*states == NULL) {

        printf("Memory allocation failed!\n");
        return;

    }

    QuantumState *newState = &(*states)[*size];
    char stateLabel[50];
    printf("Enter the state label (e.g., 'ground state', 'excited state'): ");
    fgets(stateLabel, sizeof(stateLabel), stdin);
    stateLabel[strcspn(stateLabel, "\n")] = '\0'; 
    newState->stateLabel = strdup(stateLabel);

    printf("Enter the energy of the state (in eV): ");
    scanf("%lf", &newState->energy);
    getchar(); 

    printf("Enter the type of property (Amplitude/Phase): ");
    fgets(newState->propertyType, sizeof(newState->propertyType), stdin);
    newState->propertyType[strcspn(newState->propertyType, "\n")] = '\0'; 

    if (strcmp(newState->propertyType, "Amplitude") == 0) {

        printf("Enter the wavefunction amplitude: ");
        scanf("%lf", &newState->property.amplitude);

    } else 
    if (strcmp(newState->propertyType, "Phase") == 0) {

        printf("Enter the wavefunction phase (in radians): ");
        scanf("%lf", &newState->property.phase);

    } else {

        printf("Invalid property type! Defaulting to Amplitude = 0.0.\n");
        newState->property.amplitude = 0.0;
        strcpy(newState->propertyType, "Amplitude");

    }
    getchar(); 

    printf("Enter the number of points in the wavefunction: ");
    scanf("%d", &newState->numPoints);
    getchar(); 

    newState->wavefunction = malloc(newState->numPoints * sizeof(double));

    if (newState->wavefunction == NULL) {

        printf("Memory allocation for wavefunction failed!\n");
        return;
    }

    printf("Enter the wavefunction values:\n");

    for (int i = 0; i < newState->numPoints; i++) {

        printf("Point %d: ", i + 1);
        scanf("%lf", &newState->wavefunction[i]);

    }
    getchar(); 

    (*size)++;
    printf("Quantum state added successfully!\n");
}

void displayQuantumStates(QuantumState *states, int size) {
    
    if (size == 0) {
    
        printf("No quantum states available to display.\n");
        return;
    
    }

    printf("\n--- Quantum State Details ---\n");
    for (int i = 0; i < size; i++) {
        
        printf("\nQuantum State %d:\n", i + 1);
        printf("State Label: %s\n", states[i].stateLabel);
        printf("Energy: %.2lf eV\n", states[i].energy);
        printf("Property Type: %s\n", states[i].propertyType);

        if (strcmp(states[i].propertyType, "Amplitude") == 0) {
        
            printf("Amplitude: %.2lf\n", states[i].property.amplitude);
        
        } else 
        if (strcmp(states[i].propertyType, "Phase") == 0) {
        
            printf("Phase: %.2lf radians\n", states[i].property.phase);
        
        }

        printf("Wavefunction:\n");

        for (int j = 0; j < states[i].numPoints; j++) {

            printf("  Point %d: %.2lf\n", j + 1, states[i].wavefunction[j]);

        }
    }
}


void freeQuantumStates(QuantumState **states, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*states)[i].stateLabel);
        free((*states)[i].wavefunction);

    }

    free(*states);
    *states = NULL;
    *size = 0;
}
