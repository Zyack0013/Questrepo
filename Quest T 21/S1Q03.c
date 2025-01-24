// 3. Atomic Energy Level Tracker
// Description:
//  Track the energy levels of atoms and the transitions between them.
// Specifications:
// Structure: Contains atomic details (element name, energy levels, and transition probabilities).
// Array: Stores energy levels for different atoms.
// Union: Represents different energy states.
// Strings: Represent element names.
// const Pointers: Protect atomic data.
// Double Pointers: Allocate memory for dynamically adding new elements.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef union {

    float groundStateEnergy;  
    float excitedStateEnergy; 
} EnergyState;


typedef struct {

    char const *elementName;  
    int numEnergyLevels;      
    float *energyLevels;      
    EnergyState state;
    float transitionProbability; 
    
} Atom;


void addAtom(Atom **atoms, int *size);
void displayAtoms(Atom *atoms, int size);
void freeAtoms(Atom **atoms, int *size);

int main() {
    Atom *atoms = NULL;  
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- Atomic Energy Level Tracker ---\n");
        printf("1. Add Atom\n");
        printf("2. Display Atoms\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addAtom(&atoms, &size);
                break;
            case 2:
                displayAtoms(atoms, size);
                break;
            case 3:
                freeAtoms(&atoms, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}

void addAtom(Atom **atoms, int *size) {

    *atoms = realloc(*atoms, (*size + 1) * sizeof(Atom));
    
    if (*atoms == NULL) {
    
        printf("Memory allocation failed!\n");
        return;
    
    }

    Atom *newAtom = &(*atoms)[*size];
    char elementName[30];
    printf("Enter the element name: ");
    fgets(elementName, sizeof(elementName), stdin);
    elementName[strcspn(elementName, "\n")] = '\0'; 
    newAtom->elementName = strdup(elementName);

    printf("Enter the number of energy levels: ");
    scanf("%d", &newAtom->numEnergyLevels);
    getchar(); 

    newAtom->energyLevels = malloc(newAtom->numEnergyLevels * sizeof(float));
    if (newAtom->energyLevels == NULL) {
    
        printf("Memory allocation for energy levels failed!\n");
        free((void *)newAtom->elementName);
        return;
    
    }

    printf("Enter the energy levels (in eV):\n");
    
    for (int i = 0; i < newAtom->numEnergyLevels; i++) {
        
        printf("Energy level %d: ", i + 1);
        scanf("%f", &newAtom->energyLevels[i]);
    
    }
    getchar(); 

    printf("Enter the transition probability (0.0 - 1.0): ");
    scanf("%f", &newAtom->transitionProbability);
    getchar(); 

    printf("Is the atom in:\n1. Ground state\n2. Excited state\n");
    int stateChoice;
    scanf("%d", &stateChoice);
    getchar(); 

    if (stateChoice == 1) {

        printf("Enter the energy of the ground state (in eV): ");
        scanf("%f", &newAtom->state.groundStateEnergy);
        getchar();

    } else 
    if (stateChoice == 2) {

        printf("Enter the energy of the excited state (in eV): ");
        scanf("%f", &newAtom->state.excitedStateEnergy);
        getchar();

    } else {

        printf("Invalid choice! Defaulting to ground state energy = 0.0 eV.\n");
        newAtom->state.groundStateEnergy = 0.0f;


    }

    (*size)++;
    printf("Atom added successfully!\n");
}

void displayAtoms(Atom *atoms, int size) {

    if (size == 0) {

        printf("No atoms available to display.\n");
        return;
    }

    printf("\n--- Atom Details ---\n");
    for (int i = 0; i < size; i++) {

        printf("\nAtom %d:\n", i + 1);
        printf("Element Name: %s\n", atoms[i].elementName);
        printf("Number of Energy Levels: %d\n", atoms[i].numEnergyLevels);
        printf("Energy Levels (in eV): ");

        for (int j = 0; j < atoms[i].numEnergyLevels; j++) {

            printf("%.2f ", atoms[i].energyLevels[j]);

        }
        printf("\nTransition Probability: %.2f\n", atoms[i].transitionProbability);

        if (atoms[i].state.groundStateEnergy > 0) {

            printf("Current State: Ground State (%.2f eV)\n", atoms[i].state.groundStateEnergy);

        } else {

            printf("Current State: Excited State (%.2f eV)\n", atoms[i].state.excitedStateEnergy);

        }
    }
}


void freeAtoms(Atom **atoms, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*atoms)[i].elementName);
        free((*atoms)[i].energyLevels);

    }
    free(*atoms);
    *atoms = NULL;
    *size = 0;
}
