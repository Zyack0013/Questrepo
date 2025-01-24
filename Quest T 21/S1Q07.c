// 7. Nuclear Reaction Tracker
// Description:
//  Track the parameters of nuclear reactions like fission and fusion processes.
// Specifications:
// Structure: Represents reaction details (reactants, products, energy released).
// Array: Holds data for multiple reactions.
// Union: Represents either energy release or product details.
// Strings: Represent reactant and product names.
// const Pointers: Protect reaction details.
// Double Pointers: Dynamically allocate memory for reaction data.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef union {

    double energyReleased;  
    char products[100];     

} ReactionData;


typedef struct {

    const char *reactants;     
    const char *reactionType;  
    ReactionData data;         
    char dataType[10];         

} NuclearReaction;


void addReaction(NuclearReaction **reactions, int *size);
void displayReactions(NuclearReaction *reactions, int size);
void freeReactions(NuclearReaction **reactions, int *size);

int main() {

    NuclearReaction *reactions = NULL; 
    int size = 0;                      
    int choice;

    while (1) {

        printf("\n--- Nuclear Reaction Tracker ---\n");
        printf("1. Add Nuclear Reaction\n");
        printf("2. Display Nuclear Reactions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addReaction(&reactions, &size);
                break;
            case 2:
                displayReactions(reactions, size);
                break;
            case 3:
                freeReactions(&reactions, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
        }
    }
    return 0;
}

void addReaction(NuclearReaction **reactions, int *size) {

    *reactions = realloc(*reactions, (*size + 1) * sizeof(NuclearReaction));

    if (*reactions == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    NuclearReaction *newReaction = &(*reactions)[*size];
    char reactants[100], reactionType[50];
    printf("Enter the reactants (comma-separated): ");
    fgets(reactants, sizeof(reactants), stdin);
    reactants[strcspn(reactants, "\n")] = '\0'; 
    newReaction->reactants = strdup(reactants);

    printf("Enter the reaction type (e.g., fission, fusion): ");
    fgets(reactionType, sizeof(reactionType), stdin);
    reactionType[strcspn(reactionType, "\n")] = '\0'; 
    newReaction->reactionType = strdup(reactionType);

    printf("Enter the data type ('energy' or 'products'): ");
    fgets(newReaction->dataType, sizeof(newReaction->dataType), stdin);
    newReaction->dataType[strcspn(newReaction->dataType, "\n")] = '\0'; 

    if (strcmp(newReaction->dataType, "energy") == 0) {
       
        printf("Enter the energy released (in MeV): ");
        scanf("%lf", &newReaction->data.energyReleased);
        getchar(); 
    } else 
    if (strcmp(newReaction->dataType, "products") == 0) {
    
        printf("Enter the products (comma-separated): ");
        fgets(newReaction->data.products, sizeof(newReaction->data.products), stdin);
        newReaction->data.products[strcspn(newReaction->data.products, "\n")] = '\0'; 
    } else {
      
        printf("Invalid data type! Defaulting to energyReleased = 0.0.\n");
        newReaction->data.energyReleased = 0.0;
        strcpy(newReaction->dataType, "energy");
    }

    (*size)++;
    printf("Nuclear reaction added successfully!\n");
}


void displayReactions(NuclearReaction *reactions, int size) {

    if (size == 0) {

        printf("No nuclear reactions available to display.\n");
        return;

    }

    printf("\n--- Nuclear Reactions ---\n");

    for (int i = 0; i < size; i++) {

        printf("\nReaction %d:\n", i + 1);
        printf("Reactants: %s\n", reactions[i].reactants);
        printf("Reaction Type: %s\n", reactions[i].reactionType);

        if (strcmp(reactions[i].dataType, "energy") == 0) {
            printf("Energy Released: %.2lf MeV\n", reactions[i].data.energyReleased);
        } else if (strcmp(reactions[i].dataType, "products") == 0) {
            printf("Products: %s\n", reactions[i].data.products);
        }
    }
}


void freeReactions(NuclearReaction **reactions, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*reactions)[i].reactants);
        free((void *)(*reactions)[i].reactionType);

    }

    free(*reactions);
    *reactions = NULL;
    *size = 0;
}
